//FormAI DATASET v1.0 Category: Pattern printing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n = 10; // Change this variable to adjust size of pattern

    for(int i = -n; i <= n; i++) {
        for(int j = -n; j <= n; j++) {

            // Printing a diamond shape
            if(abs(i) + abs(j) <= n) {
                printf("*");
            } else {
                printf(" ");
            }

            // Printing an X shape
            if(abs(i) == abs(j)) {
                printf("x");
            } else {
                printf(" ");
            }

            // Printing a sine wave
            if(j % (n/4) == (int)(n/4 * sin((float)i/n*4))) {
                printf("~");
            } else {
                printf(" ");
            }

            // Printing a square shape
            if(abs(i) < n/2 && abs(j) < n/2) {
                printf("#");
            } else {
                printf(" ");
            }

            // Printing a circle shape
            if(sqrt(i*i + j*j) <= n/2) {
                printf("O");
            } else {
                printf(" ");
            }

            // Printing a plus shape
            if(abs(i) <= n/4 || abs(j) <= n/4) {
                printf("+");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}