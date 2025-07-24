//FormAI DATASET v1.0 Category: Table Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int table[5][5], i, j, n;
    char c;
    srand((unsigned int)time(NULL)); // initializes random number generator 
    
    // fills the table with random numbers
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            table[i][j] = rand() % 100;
            printf("%d ", table[i][j]); // prints the table
        }
        printf("\n");
    }
    
    // asks the user for input
    printf("\nEnter a number between 1 to 25: ");
    scanf("%d", &n);
    
    // checks if the number is in the table
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (table[i][j] == n) { // if the number is in the table
                printf("\nCongratulations, you won!\n");
                return 0;
            }
        }
    }
    
    // if the number is not in the table
    printf("\nSorry, you lost!\n");
    return 0;
}