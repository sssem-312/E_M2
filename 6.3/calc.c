#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <dlfcn.h>
#include <dirent.h>
#include <locale.h>
#include <string.h>

typedef double (*operation_func)(int, ...);

typedef struct {
    const char* name;
    operation_func func;
} operation;

#define NUM_OPERATIONS 6

double sum(int num_args, ...);
double dif(int num_args, ...);
double mult(int num_args, ...);
double divM(int num_args, ...);
double max(int num_args, ...);
double min(int num_args, ...);

operation operations[NUM_OPERATIONS];

void load_operations(const char *lib_name);

int main() {
    int choice;
    double result;
    int num_args;

    // Загрузка операций из библиотек
    load_operations("./libs/libsum.so");
    load_operations("./libs/libdif.so");
    load_operations("./libs/libmult.so");
    load_operations("./libs/libdivM.so");
    load_operations("./libs/libmax.so");
    load_operations("./libs/libmin.so");

    while (1) {
        printf("\nВыберите действие: \n");

        for (int i = 0; i < NUM_OPERATIONS; i++) {
            printf("%d. %s\n", i + 1, operations[i].name);
        }

        printf("%d. Выход\n", NUM_OPERATIONS + 1);
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > NUM_OPERATIONS + 1) {
            printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
            continue;
        }

        if (choice == NUM_OPERATIONS + 1) {
            printf("Выход...\n");
            break;
        }

        printf("Введите количество чисел: ");
        scanf("%d", &num_args);
        if (num_args < 1) {
            printf("Количество чисел должно быть больше 0.\n");
            continue;
        }

        double numbers[num_args];
        printf("Введите числа: ");
        for (int i = 0; i < num_args; i++) {
            scanf("%lf", &numbers[i]);
        }

        // Вызов функции через массив операций
        result = operations[choice - 1].func(num_args, numbers[0], num_args > 1 ? numbers[1] : 0,
                                              num_args > 2 ? numbers[2] : 0, num_args > 3 ? numbers[3] : 0,
                                              num_args > 4 ? numbers[4] : 0);

        printf("Результат: %.2f\n\n", result);
    }

    return 0;
}

void load_operations(const char *lib_name) {
    void *handle = dlopen(lib_name, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Ошибка загрузки библиотеки %s: %s\n", lib_name, dlerror());
        return;
    }

    // Определение имени функции в этой библиотеке.
    if (strstr(lib_name, "libsum.so")) {
        operations[0].name = "Суммирование";
        operations[0].func = (operation_func)dlsym(handle, "sum");
    } else if (strstr(lib_name, "libdif.so")) {
        operations[1].name = "Вычитание";
        operations[1].func = (operation_func)dlsym(handle, "dif");
    } else if (strstr(lib_name, "libmult.so")) {
        operations[2].name = "Умножение";
        operations[2].func = (operation_func)dlsym(handle, "mult");
    } else if (strstr(lib_name, "libdivM.so")) {
        operations[3].name = "Деление";
        operations[3].func = (operation_func)dlsym(handle, "divM");
    } else if (strstr(lib_name, "libmax.so")) {
        operations[4].name = "Максимум";
        operations[4].func = (operation_func)dlsym(handle, "max");
    } else if (strstr(lib_name, "libmin.so")) {
        operations[5].name = "Минимум";
        operations[5].func = (operation_func)dlsym(handle, "min");
    }

    if (dlerror() != NULL) {
        fprintf(stderr, "Ошибка при загрузке функции из библиотеки %s: %s\n", lib_name, dlerror());
    }
}