//FormAI DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

// Define a struct to hold the arguments passed to the thread
typedef struct {
    int num1;
    int num2;
    char op;
    int *result;
} calc_thread_args;

// Define a function that performs the calculation
void *calculate(void *args) {
    // Cast the args to the correct type
    calc_thread_args *thread_args = (calc_thread_args *) args;

    // Check what operation needs to be performed
    switch (thread_args->op) {
        case '+':
            *thread_args->result = thread_args->num1 + thread_args->num2;
            break;
        case '-':
            *thread_args->result = thread_args->num1 - thread_args->num2;
            break;
        case '*':
            *thread_args->result = thread_args->num1 * thread_args->num2;
            break;
        case '/':
            if (thread_args->num2 == 0) {
                printf("Error: division by zero\n");
                exit(EXIT_FAILURE);
            }
            *thread_args->result = thread_args->num1 / thread_args->num2;
            break;
        default:
            printf("Error: invalid operator\n");
            exit(EXIT_FAILURE);
    }

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Set up the arguments for the calculation
    calc_thread_args add_args = {rand() % 100, rand() % 100, '+', NULL};
    calc_thread_args sub_args = {rand() % 100, rand() % 100, '-', NULL};
    calc_thread_args mul_args = {rand() % 100, rand() % 100, '*', NULL};
    calc_thread_args div_args = {rand() % 100, rand() % 100 + 1, '/', NULL};

    // Set up the result variables
    int add_result, sub_result, mul_result, div_result;

    // Set the result pointers in the args structs
    add_args.result = &add_result;
    sub_args.result = &sub_result;
    mul_args.result = &mul_result;
    div_args.result = &div_result;

    // Set up four threads to perform the calculations
    pthread_t add_thread, sub_thread, mul_thread, div_thread;

    pthread_create(&add_thread, NULL, calculate, (void *) &add_args);
    pthread_create(&sub_thread, NULL, calculate, (void *) &sub_args);
    pthread_create(&mul_thread, NULL, calculate, (void *) &mul_args);
    pthread_create(&div_thread, NULL, calculate, (void *) &div_args);

    // Wait for the threads to finish
    pthread_join(add_thread, NULL);
    pthread_join(sub_thread, NULL);
    pthread_join(mul_thread, NULL);
    pthread_join(div_thread, NULL);

    // Print the results
    printf("%d + %d = %d\n", add_args.num1, add_args.num2, add_result);
    printf("%d - %d = %d\n", sub_args.num1, sub_args.num2, sub_result);
    printf("%d * %d = %d\n", mul_args.num1, mul_args.num2, mul_result);
    printf("%d / %d = %d\n", div_args.num1, div_args.num2, div_result);

    return 0;
}