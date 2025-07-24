//FormAI DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add_numbers(int, int, int*);
void subtract_numbers(int, int, int*);
void multiply_numbers(int, int, int*);
void divide_numbers(int, int, int*);
void print_results(int, int, int);

int main() {
    srand(time(NULL));
    
    int x = rand() % 50 + 1;
    int y = rand() % 50 + 1;
    int sum, difference, product, quotient;
    
    // asynchronous execution of functions
    #pragma omp parallel sections
    {
        #pragma omp section
        add_numbers(x, y, &sum);

        #pragma omp section
        subtract_numbers(x, y, &difference);

        #pragma omp section
        multiply_numbers(x, y, &product);

        #pragma omp section
        divide_numbers(x, y, &quotient);
    }

    // print results
    printf("The numbers are: %d and %d\n", x, y);
    print_results(x, y, sum);
    print_results(x, y, difference);
    print_results(x, y, product);
    print_results(x, y, quotient);

    return 0;
}

void add_numbers(int x, int y, int *sum) {
    *sum = x + y;
}

void subtract_numbers(int x, int y, int *difference) {
    *difference = x - y;
}

void multiply_numbers(int x, int y, int *product) {
    *product = x * y;
}

void divide_numbers(int x, int y, int *quotient) {
    if (y == 0) {
        *quotient = 0;
    } else {
        *quotient = x / y;
    }
}

void print_results(int x, int y, int result) {
    printf("%d and %d = %d\n", x, y, result);
}