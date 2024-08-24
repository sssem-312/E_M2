#include "2.3.h"

double sum(int num_args, ...) { // Суммирование
    va_list args;
    va_start(args, num_args);
    double result = 0.0;
    for(int i = 0; i < num_args; i++){
        result += va_arg(args, double);
    }
    va_end(args);
    return result;
}

double dif(int num_args, ...){ // Вычитание
    va_list args;
    va_start(args, num_args);
    double a = va_arg(args, double);
    double b = va_arg(args, double);
    va_end(args);
    return a - b;
}
   
double mult(int num_args, ...) { // Умножение
    va_list args;
    va_start(args, num_args);
    double result = 0.0;
    for(int i = 0; i < num_args; i++){
        result *= va_arg(args, double);
    }
    va_end(args);
    return result;
}

double divM(int num_args, ...){ // Деление
    va_list args;
    va_start(args, num_args);
    double a = va_arg(args, double);
    double b = va_arg(args, double);
    va_end(args);
    return a / b;
}

double max(int num_args, ...){ // Максимум
    va_list args;
    va_start(args, num_args);
    double result = 0.0;
    for(int i = 0; i < num_args; i++){
        double current = va_arg(args, double);
        if(result < current){
            result = current;
        }
    }
    va_end(args);
    return result;
}

double min(int num_args, ...){ // Минимум
    va_list args;
    va_start(args, num_args);
    double result = -1;
    for(int i = 0; i < num_args; i++){
        double current = va_arg(args, double);
        if(result == -1) {
            result = current;
        }
        if(current < result) {
            result = current;
        }
    }
    va_end(args);
    return result;
}
