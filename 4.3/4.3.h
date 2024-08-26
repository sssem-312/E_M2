#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

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

struct Contact {
    Name name;
    char phoneNumberMain[L_NUMBER];
    Info info;
};

struct PhoneBook {
    struct Contact contact;
    struct PhoneBook* left;
    struct PhoneBook* right;
};

void SetContact(struct Contact* c);
struct PhoneBook* AddContact(struct PhoneBook* root, struct Contact contact);
void PrintContacts(struct PhoneBook* root);
struct PhoneBook* FindMin(struct PhoneBook* node);
struct PhoneBook* DeleteContact(struct PhoneBook* root, char* phoneNumber);
void EditContact(struct PhoneBook* root, char* lastName);
void menu();
void FreeMemory(struct PhoneBook* root);

