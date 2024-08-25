#include <stdarg.h>

double dif(int num_args, ...){ // Вычитание
    va_list args;
    va_start(args, num_args);
    double a = va_arg(args, double);
    double b = va_arg(args, double);
    va_end(args);
    return a - b;
}