//FormAI DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>

void printChar(int n, char c) {
    for(int i = 0; i < n; i++) {
        printf("%c", c);
    }
}

int main() {
    int n;
    do {
        printf("Enter an odd integer greater than or equal to 5: ");
        scanf("%d", &n);
    } while(n < 5 || n % 2 == 0); 

    int mid = n / 2;

    for(int row = 0; row < n; row++) {
        // Print top half
        if(row < mid + 1) {
            printChar(mid - row, ' ');
            printf("*");
            if(row > 0) {
                printChar(2 * row - 1, ' ');
                printf("*");
            }
            printf("\n");
        }
        // Print bottom half
        else {
            printChar(row - mid, ' ');
            printf("*");
            if(row < n - 1) {
                printChar(2 * (n - row - 2) + 1, ' ');
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}