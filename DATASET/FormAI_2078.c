//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int num;
    printf("Enter a positive integer to generate the Fibonacci sequence up to: ");
    scanf("%d", &num);
    if (num < 1) {
        printf("Invalid input.\n");
        return 0;
    }
    printf("Your eyes are in for a treat of a visual Fibonacci sequence!\n");
    sleep(2);

    int a = 0, b = 1, temp, i = 0, j = 0;
    while (i < num) {
        printf("   %d   \n", a); // center align the number visually
        temp = b;
        b = a + b;
        a = temp;
        i++;

        if (j++ >= 10) { // adds a new line for every 10 numbers
            printf("\n");
            j = 0;
        }
        usleep(200000); // slows down the output for visual effect
    }
    return 0;
}