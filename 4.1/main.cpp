#include "4.1.h"

int main() {
    setlocale(LC_ALL, "Russian");
    struct PhoneBook phoneBook;
    phoneBook.head = NULL;
    phoneBook.tail = NULL;;

    menu();
    int input;
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
                break;
            case 2:
                PrintContacts(&phoneBook);
                break;
            case 3:
                DeleteContact(&phoneBook);
                break;
            case 4:
                EditContact(&phoneBook);
                break;
            default:
                printf(" Некорректный ввод. Пожалуйста, попробуйте снова.\n");
                break;
        }
        menu();
    }
    return 0;
}
