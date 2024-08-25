#include <stdarg.h>

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