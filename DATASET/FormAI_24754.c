//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function to print C pattern
void printCPattern(int n) {
    int i, j, k;
    for(i=1; i<=n; i++) {
        for(j=1; j<=(n-i); j++) {
            printf(" ");
        }
        for(k=1; k<=(2*i-1); k++) {
            printf("*");
        }
        printf("\n");
    }
    for(i=n-1; i>=1; i--) {
        for(j=1; j<=(n-i); j++) {
            printf(" ");
        }
        for(k=1; k<=(2*i-1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Welcome to the Curious C Pattern Generator\n");
    printf("Please enter a number between 1 and 20: ");
    scanf("%d", &n);
    if(n < 1 || n > 20) {
        printf("Invalid Input, try again.\n");
        exit(0);
    }
    printf("Here's your Curious C Pattern with %d rows:\n", n);
    printCPattern(n);
    printf("Thank you for using the Curious C Pattern Generator!\n");
    return 0;
}