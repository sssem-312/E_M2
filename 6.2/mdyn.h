#ifndef MDYN_H
#define MDYN_H

#define L_NAME 10
#define L_NUMBER 15
#define ETC 20

typedef struct {
    char firstName[L_NAME];
    char secondName[L_NAME];
    char lastName[L_NAME];
} Name;

typedef struct {
    bool flag;
    char phoneNumberMore[L_NUMBER];
    char jobPlace[ETC];
    char jobTitle[ETC];
    char eMailAddressMain[ETC];
    char eMailAddressMore[ETC];
    char linkNetwork[ETC];
} Info;

struct Contact {;
    Name name;
    char phoneNumberMain[L_NUMBER];
    Info info;
    struct Contact* prev;
    struct Contact* next;
};

struct PhoneBook {
    struct Contact* head;
    struct Contact* tail;
};

void SetContact(struct Contact* contact);
void AddContact(struct PhoneBook* phoneBook);
void PrintContacts(struct PhoneBook* phoneBook);
void DeleteContact(struct PhoneBook* phoneBook);
void EditContact(struct PhoneBook* phoneBook);
void menu();
void freePhoneBook(struct PhoneBook* phoneBook);

#endif // MDYN_H
