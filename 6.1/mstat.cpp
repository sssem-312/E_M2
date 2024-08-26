#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mstat.h"

void SetContact(struct Contact* contact) {
    printf(" Имя: ");
    scanf(" %s", contact->name.firstName);
    printf(" Отчество: ");
    scanf(" %s", contact->name.secondName);
    printf(" Фамилия: ");
    scanf(" %s", contact->name.lastName);
    printf(" Номер телефона: ");
    scanf(" %s", contact->phoneNumberMain);
    printf(" Хотите ли вы внести дополнительные данные? y/n ");
    char answer[3];
    scanf(" %s", answer);
    if (answer[0] == 'y') {
        printf(" Дополнительный номер телефона: ");
        scanf(" %s", contact->info.phoneNumberMore);
        printf(" Место работы: ");
        scanf(" %s", contact->info.jobPlace);
        printf(" Должность: ");
        scanf("%s", contact->info.jobTitle);
        printf(" Адрес EMail: ");
        scanf(" %s", contact->info.eMailAddressMain);
        printf(" Доп. адрес EMail: ");
        scanf(" %s", contact->info.eMailAddressMore);
        printf(" Ссылки на соц.сети: ");
        scanf(" %s", contact->info.linkNetwork);
        contact->info.flag = true;
    }
}

void AddContact(struct PhoneBook* phoneBook) {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    SetContact(newContact);
    newContact->next = NULL;
    newContact->prev = NULL;

    if (phoneBook->head == NULL) {
        phoneBook->head = newContact;
        phoneBook->tail = newContact;
    } else {
        struct Contact* current = phoneBook->head;
        while (current != NULL && strcmp(newContact->name.lastName, current->name.lastName) > 0) {
            current = current->next;
        }
        if (current == phoneBook->head) {
            newContact->next = phoneBook->head;
            phoneBook->head->prev = newContact;
            phoneBook->head = newContact;
        } else if (current == NULL) {
            phoneBook->tail->next = newContact;
            newContact->prev = phoneBook->tail;
            phoneBook->tail = newContact;
        } else { 
            newContact->prev = current->prev;
            newContact->next = current;
            current->prev->next = newContact;
            current->prev = newContact;
        }
    }
    printf("\n Данные о контакте добавлены!\n");
}

void PrintContacts(struct PhoneBook* phoneBook) {
    struct Contact* current = phoneBook->head;
    while (current != NULL) {
        printf(" * Контакт *****\n");
        printf(" ФИО: %s %s %s\n", current->name.lastName, current->name.firstName, current->name.secondName);;
        printf(" Номер телефона: %s\n", current->phoneNumberMain);
        if (current->info.flag) {
            printf(" Дополнительный номер телефона: %s\n", current->info.phoneNumberMore);
            printf(" Место работы: %s\n", current->info.jobPlace);
            printf(" Должность: %s\n", current->info.jobTitle);
            printf(" Адрес EMail: %s\n", current->info.eMailAddressMain);
            printf(" Доп. адрес EMail: %s\n", current->info.eMailAddressMore);
            printf(" Ссылки на соц.сети: %s\n", current->info.linkNetwork);
        }
        printf("\n");
        current = current->next;
    }
}

void DeleteContact(struct PhoneBook* phoneBook) {
    if (phoneBook->head == NULL) {
        printf("\n Список контактов пуст!\n");
        return;
    }

    char lastName[L_NAME];
    printf(" Введите фамилию контакта для его удаления: ");
    scanf(" %s", lastName);

    struct Contact* current = phoneBook->head;

    while (current != NULL) {
        if (strcmp(current->name.lastName, lastName) == 0) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                phoneBook->head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else {
                phoneBook->tail = current->prev;
            }

            free(current);
            printf("\n Контакт с фамилией '%s' удалён!\n", lastName);
            return;
        }
        current = current->next;
    }
    printf("\n Контакт с фамилией '%s' не найден!\n", lastName);
}

void EditContact(struct PhoneBook* phoneBook) {
    if (phoneBook->head == NULL) {
        printf("\n Список контактов пуст!\n");
        return;
    }

    char lastName[L_NAME];
    printf(" Введите фамилию контакта для его изменения: ");
    scanf(" %s", lastName);

    struct Contact* current = phoneBook->head;
    while (current != NULL) {
        if (strcmp(current->name.lastName, lastName) == 0) {
            printf(" Выбранный контакт:\n");
            printf(" Имя: %s\n", current->name.firstName);
            printf(" Отчество: %s\n", current->name.secondName);
            printf(" Фамилия: %s\n", current->name.lastName);
            printf(" Номер телефона: %s\n", current->phoneNumberMain);
            if (current->info.flag) {
                printf(" Дополнительный номер телефона: %s\n", current->info.phoneNumberMore);
                printf(" Место работы: %s\n", current->info.jobPlace);
                printf(" Должность: %s\n", current->info.jobTitle);
                printf(" Адрес EMail: %s\n", current->info.eMailAddressMain);
                printf(" Доп. адрес EMail: %s\n", current->info.eMailAddressMore);
                printf(" Ссылки на соц.сети: %s\n", current->info.linkNetwork);
            }
            
            printf(" Введите новые данные для контакта:\n");
            SetContact(current);
            printf("\n Данные о контакте обновлены!\n");
            return;
        }
        current = current->next;
    }
    printf("\n Контакт с фамилией '%s' не найден!\n", lastName);
}

void menu() {
    printf(" ---------------- Меню -----------------\n");
    printf(" [1] Добавить контакт\n");
    printf(" [2] Список контактов\n");
    printf(" [3] Удалить контакт\n");
    printf(" [4] Изменить контакт\n");
    printf(" [0] Выход\n");
    printf(" ---------------------------------------\n");
}

void freePhoneBook(struct PhoneBook* phoneBook) {
    struct Contact* current = phoneBook->head;
    while (current != NULL) {
        struct Contact* next = current->next;
        free(current);
        current = next;
    }
    phoneBook->head = NULL;
    phoneBook->tail = NULL;
}