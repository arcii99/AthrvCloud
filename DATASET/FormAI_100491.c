//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    int i, j, k, t = 0, n = 20, temp;
    int a[n];

    // Generating random array of integers
    srand(time(0));
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    // Bubble sort
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                // Swapping
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                
                // Delay
                for (k = 0; k < 10000000; k++) {
                    t++;
                }
            }
        }
    }

    // Printing sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}