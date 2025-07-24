//FormAI DATASET v1.0 Category: Benchmarking ; Style: decentralized
// This is a decentralised C benchmarking example program
// It will use multiple threads to perform various benchmark tests on different inputs

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h>

// defining constants
#define NUM_THREADS 10
#define ARRAY_SIZE 1000000

// function prototypes
void benchmark_test1(double *arr);
void benchmark_test2(double *arr);
void benchmark_test3(double *arr);
void benchmark_test4(double *arr);
void benchmark_test5(double *arr);

// function to generate random numbers
double random_generator() {
    double r = (double) rand() / RAND_MAX;
    return r;
}

// function to print array of doubles
void print_array(double *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

// struct to hold thread arguments
typedef struct thread_args {
    double *arr;
    int test_num;
    double result;
} thread_args_t;

// thread function to perform benchmark tests
void* benchmark_test(void* arg) {
    thread_args_t* args = (thread_args_t*)arg;
    int test_num = args->test_num;
    double* arr = args->arr;
    double result = 0;

    switch (test_num) {
        case 1:
            benchmark_test1(arr);
            break;
        case 2:
            benchmark_test2(arr);
            break;
        case 3:
            benchmark_test3(arr);
            break;
        case 4:
            benchmark_test4(arr);
            break;
        case 5:
            benchmark_test5(arr);
            break;
        default:
            printf("Unknown test number: %d\n", test_num);
            result = -1;
    }

    args->result = result;
    pthread_exit(NULL);
}

// main function
int main() {
    double arr[ARRAY_SIZE];
    pthread_t threads[NUM_THREADS];
    thread_args_t thread_args[NUM_THREADS];

    // initialize array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = random_generator();
    }

    // create threads to perform benchmark tests
    for (int i = 0; i < NUM_THREADS; i++) {
        int test_num = (i % 5) + 1;
        thread_args[i].arr = arr;
        thread_args[i].test_num = test_num;
        pthread_create(&threads[i], NULL, benchmark_test, (void *)&thread_args[i]);
    }

    // join threads and print results
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        printf("Thread %d completed test %d with result %f\n", i+1, thread_args[i].test_num, thread_args[i].result);
    }

    return 0;
}

// benchmark test 1 - sum of squares of array elements
void benchmark_test1(double *arr) {
    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += pow(arr[i], 2);
    }
}

// benchmark test 2 - product of array elements
void benchmark_test2(double *arr) {
    double prod = 1;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        prod *= arr[i];
    }
}

// benchmark test 3 - square root of sum of squares of array elements
void benchmark_test3(double *arr) {
    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += pow(arr[i], 2);
    }
    double result = sqrt(sum);
}

// benchmark test 4 - inverse of array elements
void benchmark_test4(double *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = 1 / arr[i];
    }
}

// benchmark test 5 - logarithm base 10 of array elements
void benchmark_test5(double *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = log10(arr[i]);
    }
}