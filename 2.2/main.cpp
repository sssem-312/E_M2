#include "2.2.h"

int main() 
{ 
    setlocale(LC_ALL, "Russian"); 
 
    char ans[10]; 
    int a, b, res; 
 
    printf(" Добро пожаловать в калькулятор! \n"); 
 
    while (ans[0] != 'n') 
    { 
        printf(" Введите первый аргумент: "); 
        scanf(" %d", &a); 
        printf(" Введите второй аргумент: "); 
        scanf(" %d", &b); 
        char input; 
        printf(" Что вы хотите сделать? (+,-,*,/) "); 
        scanf(" %c", &input); 
        res = calc(a, b, input); 
        printf(" Результат: %d\n\n", res);
        printf(" Хотите продолжить вычисления? (y/n) ");
        scanf(" %s", ans);
    } 
 
    return 0; 
}
 