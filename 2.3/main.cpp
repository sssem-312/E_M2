#include "2.3.h"

operation operations[] = {
    {" Суммирование", sum},
    {" Вычитание", dif},
    {" Умножение", mult},
    {" Деление", divM},
    {" Максимум", max},
    {" Минимум", min}
};

int main(){
    int choice;
    double result;
    int num_args;

    while(1){
        printf("\n Выберите действие: \n");
        
        for(int i = 0; i < NUM_OPERATIONS; i++){
            printf(" %d. %s\n", i + 1,operations[i].name);
        }

        printf(" %ld. Выход\n", NUM_OPERATIONS + 1);
        printf(" Ваш выбор: ");
        scanf(" %d", &choice);

        if(choice < 1 || choice > NUM_OPERATIONS + 1) {
            printf(" Неверный выбор. Пожалуйста, попробуйте снова.\n");
            continue;
        }

        if(choice == NUM_OPERATIONS + 1) {
            printf(" Выход...\n");
            break;
        }

        printf(" Введите количество чисел: ");
        scanf(" %d", &num_args);
        if(num_args < 1) {
            printf(" Количество чисел должно быть больше 0.\n");
            continue;
        }

        double numbers[num_args];
        printf(" Введите числа: ");
        for(int i = 0; i < num_args; i++){
            scanf(" %1lf", &numbers[i]);
        }

        switch(num_args){
            case 1:
                result = operations[choice - 1].func(num_args, numbers[0]);
                break;
            case 2:
                result = operations[choice - 1].func(num_args, numbers[0], numbers[1]);
                break;
            case 3:
                result = operations[choice - 1].func(num_args, numbers[0], numbers[1], numbers[2]);
                break;
            case 4:
                result = operations[choice - 1].func(num_args, numbers[0], numbers[1], numbers[2], numbers[3]);
                break;
            case 5:
                result = operations[choice - 1].func(num_args, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
                break;
        }

        printf(" Результат: %.2f\n\n", result);
    }

    return 0;
}