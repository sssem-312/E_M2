#define _CRT_SECURE_NO_WARNINGS 
 
#include <stdio.h> 
#include <string.h> 
#include <locale.h> 
  
#define L_NAME 10 
#define L_NUMBER 15 
#define ETC 20 
 
typedef struct 
{ 
 char firstName[L_NAME]; 
 char secondName[L_NAME]; 
 char lastName[L_NAME]; 
} Name; 
 
typedef struct 
{ 
 bool flag; 
 char phoneNumberMore[L_NUMBER]; 
 char jobPlace[ETC]; 
 char jobTitle[ETC]; 
 char eMailAddressMain[ETC]; 
 char eMailAddressMore[ETC]; 
 char linkNetwork[ETC]; 
} Info; 
 
struct Contact 
{ 
 int id; 
 Name name; 
 char phoneNumberMain[L_NUMBER]; 
 Info info; 
}; 
 
struct PhoneBook 
{ 
    struct Contact TBL[100]; 
    int n; 
}; 

void SetContact(struct PhoneBook* a, int i);
void SetContacts(struct PhoneBook* a, int n);
void Print(struct PhoneBook a);
void Delete(struct PhoneBook* a, int n);
void menu();