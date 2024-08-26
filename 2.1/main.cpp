#include "2.1.h"

int main() 
{ 
 setlocale(LC_ALL, "Russian"); 
    struct PhoneBook a; 
    fseek(stdin, 0, SEEK_END); 
    menu(); 
    int input; 
    a.n = 0; 
    int n, m; 
    int count = 1; 
    while (1) 
    { 
        printf("\n Что вы хотите сделать? "); 
        scanf(" %d", &input); 
        printf("\n"); 
        if (input == 0) break; 
 
        switch (input) 
        { 
        case 1: 
            printf(" Сколько контактов вы хотите добавить? "); 
            scanf(" %d", &n); 
            printf("\n"); 
            SetContacts(&a, n); 
            break; 
 
        case 2:
            Print(a); 
            break; 
 
        case 3:
            printf(" Какой контакт вы хотите удалить? Выберите номер от 1 до %d ", a.n); 
            scanf(" %d", &m);
			printf("\n"); 
            Delete(&a, m - 1); 
            break; 
 
        case 4:
            printf(" Данные по какому контакту вы хотите изменить? Выберите номер от 1 до %d ", a.n); 
            scanf(" %d", &n); 
            printf("\n"); 
            SetContact(&a, n - 1); 
            break; 
 
        default: 
            break; 
        } 
        menu(); 
    } 
 
    return 0; 
}