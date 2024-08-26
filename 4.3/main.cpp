#include "4.3.h"

int main() {
    setlocale(LC_ALL, "Russian");
    struct PhoneBook* phoneBook = NULL;
    
    menu();
    int input;
    char lastName[L_NAME];
    while (1) {
        printf("\n Что вы хотите сделать? ");
        scanf(" %d", &input);
        printf("\n");

        if (input == 0){
            FreeMemory(phoneBook);
            break;
        }
        switch (input) {
            case 1: {
                struct Contact newContact;
                SetContact(&newContact);
                phoneBook = AddContact(phoneBook, newContact);
                break;
            }
            case 2:
                PrintContacts(phoneBook);
                break;
            case 3: {
                printf(" Введите фамилию контакта для удаления: ");
                scanf(" %s", lastName);
                phoneBook = DeleteContact(phoneBook, lastName);
                printf("\n Контакт с фамилией '%s' удалён!\n", lastName);
                break;
            }
            case 4:
                printf(" Введите фамилию контакта для его изменения: ");
                scanf(" %s", lastName);
                EditContact(phoneBook, lastName);
                printf("\n Контакт с фамилией '%s' изменён!\n", lastName);
                break;
            default:
                break;
        }
        menu();
    }
    return 0;
}