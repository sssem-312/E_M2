/*
Написать программу для расчета маски прав доступа к файлу.
1)Пользователь может ввести права доступа в буквенном или цифровом
обозначении, ему должно быть показано соответствующее битовое
представление.

2)Пользователь может ввести имя файла, и ему отобразится буквенное,
цифровое и битовое представление прав доступа. Использовать функцию stat
для получения информации о файле. Сравнить результат с выводом,
например, ls -l.

3)Пользователь может изменить права доступа, определенные в первом или
втором пункте, введя команды модификации атрибутов (подобно команде
chmod). При этом отображается буквенное, цифровое и битовое
представление прав доступа. Изменение прав доступа не нужно применять к
файлу.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

// Функция для получения буквенного представления прав доступа
void get_file_permissions(mode_t mode, char *buf) {
    buf[0] = (mode & S_IRUSR) ? 'r' : '-';  // Пользователь: чтение
    buf[1] = (mode & S_IWUSR) ? 'w' : '-';  // Пользователь: запись
    buf[2] = (mode & S_IXUSR) ? 'x' : '-';  // Пользователь: выполнение
    buf[3] = (mode & S_IRGRP) ? 'r' : '-';  // Группа: чтение
    buf[4] = (mode & S_IWGRP) ? 'w' : '-';  // Группа: запись
    buf[5] = (mode & S_IXGRP) ? 'x' : '-';  // Группа: выполнение
    buf[6] = (mode & S_IROTH) ? 'r' : '-';  // Другие: чтение
    buf[7] = (mode & S_IWOTH) ? 'w' : '-';  // Другие: запись
    buf[8] = (mode & S_IXOTH) ? 'x' : '-';  // Другие: выполнение
    buf[9] = '\0';  // Завершающий ноль
}

// Функция для получения цифрового представления прав доступа
int get_numeric_permissions(mode_t mode) {
    int permissions = 0;
    permissions |= (mode & S_IRUSR) ? 0400 : 0;  // Пользователь: чтение
    permissions |= (mode & S_IWUSR) ? 0200 : 0;  // Пользователь: запись
    permissions |= (mode & S_IXUSR) ? 0100 : 0;  // Пользователь: выполнение
    permissions |= (mode & S_IRGRP) ? 0040 : 0;  // Группа: чтение
    permissions |= (mode & S_IWGRP) ? 0020 : 0;  // Группа: запись
    permissions |= (mode & S_IXGRP) ? 0010 : 0;  // Группа: выполнение
    permissions |= (mode & S_IROTH) ? 0004 : 0;  // Другие: чтение
    permissions |= (mode & S_IWOTH) ? 0002 : 0;  // Другие: запись
    permissions |= (mode & S_IXOTH) ? 0001 : 0;  // Другие: выполнение
    return permissions;
}

// Функция для изменения прав доступа в памяти (не на файле)
void modify_permissions(mode_t *mode, const char *command) {
    char who, op, perm;
    sscanf(command, "%c%c%c", &who, &op, &perm);

    int permission_mask = 0;
    switch (perm) {
        case 'r': permission_mask = S_IRUSR | S_IRGRP | S_IROTH; break;
        case 'w': permission_mask = S_IWUSR | S_IWGRP | S_IWOTH; break;
        case 'x': permission_mask = S_IXUSR | S_IXGRP | S_IXOTH; break;
        default: break; // Неправильное значение
    }

    if (op == '+') {
        switch (who) {
            case 'u': *mode |= (permission_mask & S_IRUSR); break; // Пользователь
            case 'g': *mode |= (permission_mask & S_IRGRP); break; // Группа
            case 'o': *mode |= (permission_mask & S_IROTH); break; // Другие
        }
    } else if (op == '-') {
        switch (who) {
            case 'u': *mode &= ~(permission_mask & S_IRUSR); break; // Пользователь
            case 'g': *mode &= ~(permission_mask & S_IRGRP); break; // Группа
            case 'o': *mode &= ~(permission_mask & S_IROTH); break; // Другие
        }
    }
}

// Функция для отображения битового представления прав доступа
void display_bitwise_permissions(mode_t mode) {
    printf("Битовое представление прав доступа: ");
    for (int i = 8; i >= 0; i--) {
        printf("%d", (mode >> i) & 1);
    }
    printf("\n");
}

// Функция для проверки корректного ввода маски
int is_valid_numeric_permissions(const char* input) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] < '0' || input[i] > '7') {
            return 0; // Недопустимый ввод
        }
    }
    return 1; // Корректный ввод
}

int is_valid_letter_permissions(const char* input) {
    if (strlen(input) != 9) {
        return 0; // Должно быть 9 символов для u, g, o
    }
    const char* valid_chars = "rwx";
    for (int i = 0; i < strlen(input); i++) {
        if (strchr(valid_chars, input[i]) == NULL && input[i] != '-') {
            return 0; // Недопустимый ввод
        }
    }
    return 1; // Корректный ввод
}

int main(int argc, char *argv[]) {
    char filename[256], command[10], permissions[10];
    struct stat fileStat;

    if (argc < 2) {
        printf("Использование: %s [маска доступа | имя файла]\n", argv[0]);
        return 1;
    }

    mode_t mode = 0;
    char *input = argv[1];

        if (is_valid_numeric_permissions(input)) {
            // Цифровое представление
            mode = strtol(input, NULL, 8);
            display_bitwise_permissions(mode);
            
            get_file_permissions(mode, permissions);
            int numericPermissions = get_numeric_permissions(mode);
            printf("Буквенное представление прав доступа: %s\n", permissions);
            printf("Цифровое представление прав доступа: %o\n", numericPermissions);
            printf("Введите команду модификации прав (например, u+w, g-r, o+x): ");
            scanf("%s", command);
            modify_permissions(&mode, command);
            get_file_permissions(mode, permissions);
            numericPermissions = get_numeric_permissions(mode);
            printf("Обновленные буквенные права доступа: %s\n", permissions);
            printf("Обновленные цифровые права доступа: %o\n", numericPermissions);
            display_bitwise_permissions(mode);

        } else if (is_valid_letter_permissions(input)) {
            // Буквенное представление
            int r = input[0] == 'r' ? 1 : 0;
            int w = input[1] == 'w' ? 1 : 0;
            int x = input[2] == 'x' ? 1 : 0;
            mode |= (r << 8) | (w << 7) | (x << 6); // Пользователь
            
            r = input[3] == 'r' ? 1 : 0;
            w = input[4] == 'w' ? 1 : 0;
            x = input[5] == 'x' ? 1 : 0;
            mode |= (r << 5) | (w << 4) | (x << 3); // Группа
            
            r = input[6] == 'r' ? 1 : 0;
            w = input[7] == 'w' ? 1 : 0;
            x = input[8] == 'x' ? 1 : 0;
            mode |= (r << 2) | (w << 1) | x; // Другие
            
            display_bitwise_permissions(mode);

            get_file_permissions(mode, permissions);
            int numericPermissions = get_numeric_permissions(mode);
            printf("Буквенное представление прав доступа: %s\n", permissions);
            printf("Цифровое представление прав доступа: %o\n", numericPermissions);
            printf("Введите команду модификации прав (например, u+w, g-r, o+x): ");
            scanf("%s", command);
            modify_permissions(&mode, command);
            get_file_permissions(mode, permissions);
            numericPermissions = get_numeric_permissions(mode);
            printf("Обновленные буквенные права доступа: %s\n", permissions);
            printf("Обновленные цифровые права доступа: %o\n", numericPermissions);
            display_bitwise_permissions(mode);

        } else {
            // Интерпретировать как имя файла
            strcpy(filename, input);
            if (stat(filename, &fileStat) < 0) {
                perror("Ошибка при получении информации о файле");
                return 1;
            }

            get_file_permissions(fileStat.st_mode, permissions);
            int numericPermissions = get_numeric_permissions(fileStat.st_mode);
            printf("Буквенное представление прав доступа: %s\n", permissions);
            printf("Цифровое представление прав доступа: %o\n", numericPermissions);
            display_bitwise_permissions(fileStat.st_mode);
            printf("Введите команду модификации прав (например, u+w, g-r, o+x): ");
            scanf("%s", command);
            modify_permissions(&fileStat.st_mode, command);
            get_file_permissions(fileStat.st_mode, permissions);
            numericPermissions = get_numeric_permissions(fileStat.st_mode);
            printf("Обновленные буквенные права доступа: %s\n", permissions);
            printf("Обновленные цифровые права доступа: %o\n", numericPermissions);
            display_bitwise_permissions(fileStat.st_mode);

            return 0;
        }

    return 0;
}