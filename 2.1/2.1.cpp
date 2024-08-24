#include "2.1.h"

void SetContact(struct PhoneBook* a, int i) 
{ 
 printf(" Имя: "); 
 scanf(" %s", a->TBL[i].name.firstName); 
 printf(" Отчество: "); 
 scanf(" %s", a->TBL[i].name.secondName); 
 printf(" Фамилия: "); 
 scanf(" %s", a->TBL[i].name.lastName); 
    printf(" Номер телефона: "); 
    scanf(" %s", a->TBL[i].phoneNumberMain); 
 printf(" Хотите ли вы внести дополнительные данные? y/n "); 
 char answer[3]; 
    scanf(" %s", answer); 
 if (answer[0] == 'y') { 
  printf(" Дополнительный номер телефона: "); 
  scanf(" %s", a->TBL[i].info.phoneNumberMore); 
  printf(" Место работы: "); 
  scanf(" %s", a->TBL[i].info.jobPlace); 
  printf(" Должность: "); 
  scanf( "%s", a->TBL[i].info.jobTitle); 
  printf(" Адрес EMail: "); 
  scanf(" %s", a->TBL[i].info.eMailAddressMain); 
  printf(" Доп. адрес EMail: "); 
  scanf(" %s", a->TBL[i].info.eMailAddressMore); 
  printf(" Ссылки на соц.сети: "); 
  scanf(" %s", a->TBL[i].info.linkNetwork); 
        a->TBL[i].info.flag = 1; 
 } 
 printf("\n Данные о контакте сохранены!\n"); 
} 
 
void SetContacts(struct PhoneBook* a, int n) 
{ 
    for (int i = a->n; i < a->n + n; i++) 
    { 
        printf(" Контакт %d: \n", i + 1); 
        SetContact(a, i); 
    } 
    a->n += n; 
    printf("\n Данные о контактах добавлены! \n\n"); 
} 
 
void Print(struct PhoneBook a) 
{ 
    for (int i = 0; i < a.n; i++) 
    { 
  printf(" * Контакт %d *****\n", i + 1); 
  printf(" Имя: %s\n", a.TBL[i].name.firstName); 
  printf(" Отчество: %s\n", a.TBL[i].name.secondName); 
  printf(" Фамилия: %s\n", a.TBL[i].name.lastName); 
        printf(" Номер телефона: %s\n", a.TBL[i].phoneNumberMain); 
  if (a.TBL[i].info.flag == 1) { 
   printf(" Дополнительный номер телефона: %s\n", a.TBL[i].info.phoneNumberMore); 
   printf(" Место работы: %s\n", a.TBL[i].info.jobPlace); 
   printf(" Должность: %s\n", a.TBL[i].info.jobTitle); 
   printf(" Адрес EMail: %s\n", a.TBL[i].info.eMailAddressMain); 
   printf(" Доп. адрес EMail: %s\n", a.TBL[i].info.eMailAddressMore); 
   printf(" Ссылки на соц.сети: %s\n", a.TBL[i].info.linkNetwork); 
 
  } 
        printf("\n"); 
    } 
} 
 
void Delete(struct PhoneBook* a, int n) 
{ 
    for (int i = n; i < a->n; i++) 
    { 
        a->TBL[i] = a->TBL[i + 1]; 
    } 
    (a->n)--; 
} 
 
void menu() 
{ 
    printf(" ---------------- Меню -----------------\n"); 
    printf(" [1] Добавить контакт\n"); 
    printf(" [2] Список контактов\n"); 
    printf(" [3] Удалить контакт\n"); 
    printf(" [4] Изменить контакт\n"); 
    printf(" [0] Выход\n"); 
    printf(" ---------------------------------------\n"); 
}