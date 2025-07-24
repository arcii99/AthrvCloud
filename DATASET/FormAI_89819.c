//FormAI DATASET v1.0 Category: Pattern printing ; Style: complete
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of lines: "); // prompt user to enter number of lines
    scanf("%d", &n); // read user input
    
    // pattern printing loop
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n || i == j || i + j == n + 1) {
                printf("* "); // print asterisk for corners and diagonals
            }
            else {
                printf("  "); // print space for inner square
            }
        }
        printf("\n"); // move to next line
    }
    
    return 0; // exit program
}