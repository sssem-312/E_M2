#ifndef OPERATION_H
#define OPERATION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <locale.h>

typedef double (*operation_func)(int, ...);

typedef struct {
    const char* name;
    operation_func func;
} operation;

extern operation operations[];

#define NUM_OPERATIONS (sizeof(operations) / sizeof(operation))

double sum(int num_args, ...);
double dif(int num_args, ...);
double mult(int num_args, ...);
double divM(int num_args, ...);
double max(int num_args, ...);
double min(int num_args, ...);

#endif

