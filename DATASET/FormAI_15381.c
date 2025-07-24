//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 1000000

int main() {
    int arr[ARR_SIZE];

    /* Fill array with random numbers between 1 and 100 */
    srand(time(NULL)); // Seed for random number generator
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }

    /* Find and print the maximum number */
    int max = arr[0];
    for (int i = 1; i < ARR_SIZE; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("The maximum number in the array is %d\n", max);

    /* Find and print the average of the numbers */
    double sum = 0;
    for (int i = 0; i < ARR_SIZE; i++) {
        sum += arr[i];
    }
    double avg = sum / ARR_SIZE;
    printf("The average of the numbers in the array is %.2lf\n", avg);

    /* Find and print the number of even numbers */
    int even_count = 0;
    for (int i = 0; i < ARR_SIZE; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        }
    }
    printf("There are %d even numbers in the array\n", even_count);

    return 0;
}