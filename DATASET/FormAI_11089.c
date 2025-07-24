//FormAI DATASET v1.0 Category: Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Number {
    double value;
    bool is_negative;
} Number;

void print_result(Number result) {
    printf("Result: %s%.2f\n", result.is_negative ? "-" : "", result.value);
}

void add_numbers(Number x, Number y, void (*callback)(Number)) {
    Number result = { x.value + y.value, false };
    (*callback)(result);
}

void subtract_numbers(Number x, Number y, void (*callback)(Number)) {
    Number result = { x.value - y.value, false };
    (*callback)(result);
}

void multiply_numbers(Number x, Number y, void (*callback)(Number)) {
    Number result = { x.value * y.value, false };
    (*callback)(result);
}

void divide_numbers(Number x, Number y, void (*callback)(Number)) {
    if (y.value == 0) {
        printf("Error: Division by zero\n");
        exit(EXIT_FAILURE);
    }

    Number result = { x.value / y.value, false };
    (*callback)(result);
}

int main() {
    Number x = { 4.5, false };
    Number y = { 2.0, true };

    add_numbers(x, y, print_result);
    subtract_numbers(x, y, print_result);
    multiply_numbers(x, y, print_result);
    divide_numbers(x, y, print_result);

    return 0;
}