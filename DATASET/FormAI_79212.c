//FormAI DATASET v1.0 Category: Random ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, num;
    int arr[10];
    srand(time(NULL));
    printf("Welcome to the happy C random program!\n\n");

    // Filling the array with random numbers
    printf("Generating 10 random numbers...\n");
    for(i = 0; i < 10; i++) {
        num = (rand() % 100) + 1;
        arr[i] = num;
        printf("%d ", num);
    }

    // Finding the maximum number
    int max_val = arr[0];
    for(i = 1; i < 10; i++) {
        if(arr[i] > max_val)
            max_val = arr[i];
    }
    printf("\n\nThe maximum number among the generated numbers is %d.\n", max_val);

    // Finding the minimum number
    int min_val = arr[0];
    for(i = 1; i < 10; i++) {
        if(arr[i] < min_val)
            min_val = arr[i];
    }
    printf("The minimum number among the generated numbers is %d.\n", min_val);

    return 0;
}