#include <stdarg.h>

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