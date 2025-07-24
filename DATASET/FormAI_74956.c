//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Wow! I can't believe I'm actually writing a program!\n");

    int i, j, k, sum = 0;
    int arr[5][5][5];

    printf("Enter 125 numbers to be stored in the 3D array:\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                sum += arr[i][j][k];
            }
        }
    }

    printf("The sum of all the numbers entered is: %d\n", sum);

    return 0;
}