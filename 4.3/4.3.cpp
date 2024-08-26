#include "4.3.h"

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
        scanf(" %s", contact->info.jobTitle);
        printf(" Адрес EMail: ");
        scanf(" %s", contact->info.eMailAddressMain);
        printf(" Доп. адрес EMail: ");
        scanf(" %s", contact->info.eMailAddressMore);
        printf(" Ссылки на соц.сети: ");
        scanf(" %s", contact->info.linkNetwork);
        contact->info.flag = true;
    }

}

struct PhoneBook* AddContact(struct PhoneBook* root, struct Contact contact) {
    if (root == NULL) {
        struct PhoneBook* newNode = (struct PhoneBook*)malloc(sizeof(struct PhoneBook));
        newNode->contact = contact;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (strcmp(contact.name.lastName, root->contact.name.lastName) < 0) {
        root->left = AddContact(root->left, contact);
    } else {
        root->right = AddContact(root->right, contact);
    }
    printf("\n Данные о контакте добавлены!\n");
    return root;
}

void PrintContacts(struct PhoneBook* root) {
    if (root == NULL) return;
    PrintContacts(root->left);
    struct Contact contact = root->contact;
    printf(" * Контакт *****\n");
    printf(" Имя: %s %s %s\n", contact.name.firstName, contact.name.secondName, contact.name.lastName);
    printf(" Номер телефона: %s\n", contact.phoneNumberMain);
    if (contact.info.flag) {
        printf(" Дополнительный номер телефона: %s\n", contact.info.phoneNumberMore);
        printf(" Место работы: %s\n", contact.info.jobPlace);
        printf(" Должность: %s\n", contact.info.jobTitle);
        printf(" Адрес EMail: %s\n", contact.info.eMailAddressMain);
        printf(" Доп. адрес EMail: %s\n", contact.info.eMailAddressMore);
        printf(" Ссылки на соц.сети: %s\n", contact.info.linkNetwork);
    }
    printf("\n");
    PrintContacts(root->right);
}

struct PhoneBook* FindMin(struct PhoneBook* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct PhoneBook* DeleteContact(struct PhoneBook* root, char* lastName) {
    if (root == NULL){
        printf("\n Список контактов пуст!\n");
        return NULL;
    }

    if (strcmp(lastName, root->contact.name.lastName) < 0) {
        root->left = DeleteContact(root->left, lastName);
    } else if (strcmp(lastName, root->contact.name.lastName) > 0) {
        root->right = DeleteContact(root->right, lastName);
    } else {
        if (root->left == NULL) {
            struct PhoneBook* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct PhoneBook* temp = root->left;
            free(root);
            return temp;
        }
        struct PhoneBook* temp = FindMin(root->right);
        root->contact = temp->contact;
        root->right = DeleteContact(root->right, temp->contact.name.lastName);
    }

    return root;
}

void EditContact(struct PhoneBook* root, char* lastName) {
    if (root == NULL) {
        printf("Контакт с фамилией '%s' не найден.\n", lastName);
        return;
    }

    if (strcmp(lastName, root->contact.name.lastName) < 0) {
        EditContact(root->left, lastName);
    } else if (strcmp(lastName, root->contact.name.lastName) > 0) {
        EditContact(root->right, lastName);
    } else {
        SetContact(&root->contact);
        printf("\n Данные о контакте с фамилией '%s' были обновлены!\n", lastName);
    }
}

void FreeMemory(struct PhoneBook* root) {
    if (root != NULL) {
        FreeMemory(root->left);
        FreeMemory(root->right);
        free(root);
    }
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


