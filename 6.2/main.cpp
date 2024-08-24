#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

#include "mdyn.h"

int main() {
    setlocale(LC_ALL, "Russian");
    struct PhoneBook phoneBook;
    phoneBook.head = NULL;
    phoneBook.tail = NULL;
    phoneBook.n = 0;

    menu();
    int input, index;
    while (1) {
        printf("\n Что вы хотите сделать? ");
        scanf(" %d", &input);
        printf("\n");

        if (input == 0) {
            freePhoneBook(&phoneBook);
            break;
        }
        switch (input) {
            case 1:
                AddContact(&phoneBook);
                menu();
                break;
            case 2:
                PrintContacts(&phoneBook);
                menu();
                break;
            case 3:
                printf(" Какой контакт вы хотите удалить? Выберите номер от 1 до %d: ", phoneBook.n);
                scanf(" %d", &index);
                printf("\n");
                DeleteContact(&phoneBook, index - 1);
                menu();
                break;
            default:
                printf("Некорректный ввод. Пожалуйста, попробуйте снова.\n");
                menu();
                break;
        }
    }
    return 0;
}
