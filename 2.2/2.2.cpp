#include "2.2.h"

int sum(int a, int b) 
{ 
    return a + b; 
} 
 
int dif(int a, int b) 
{ 
    return a - b; 
} 
 
int mult(int a, int b) 
{ 
    return a * b; 
} 
 
int divM(int a, int b) 
{ 
    return a / b; 
}  
 
int calc(int a, int b, char input) 
{ 
    int res; 
 
    switch (input) 
    { 
    case '+': 
        res = sum(a, b); 
        break; 
 
    case '-': 
        res = dif(a, b); 
        break; 
 
    case '*': 
        res = mult(a, b); 
        break; 
 
    case '/': 
        res = divM(a, b); 
        break; 
 
    default: 
        break; 
    } 
 
    return res; 
}