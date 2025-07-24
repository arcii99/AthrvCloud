//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: surprised
#include <stdio.h>

// defining a large array of integers
#define SIZE 1000000
int array[SIZE];

int main() {
    // initializing the array with ascending values
    for(int i = 0; i < SIZE; i++) {
        array[i] = i + 1;
    }

    // calculating the sum of all the elements of the array
    long long sum = 0;
    for(int i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    // printing the sum
    printf("The sum is: %lld", sum);

    return 0;
}