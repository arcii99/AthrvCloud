//FormAI DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;
    unsigned long long int factorial = 1;

    start = clock(); // Starting the clock to measure the time taken to execute the code

    for (int i = 1; i <= 20; i++) { // Finding the factorial of number 20
        factorial *= i;
    }

    end = clock(); // Ending the clock to measure the time taken to execute the code
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The factorial of 20 is: %llu\n", factorial);
    printf("Time taken to find the factorial of 20: %lf seconds\n", cpu_time_used);

    return 0;
}