//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int i;
    int sum = 0;
    int numbers[SIZE];

    srand(time(NULL));

    for(i = 0; i < SIZE; i++) {
        numbers[i] = rand() % 100;
    }

    for(i = 0; i < SIZE; i++) {
        if(numbers[i] % 2 == 0) {
            sum += numbers[i];
        }
    }

    printf("The sum of even numbers is %d\n", sum);

    return 0;
}