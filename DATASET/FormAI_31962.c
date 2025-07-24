//FormAI DATASET v1.0 Category: Random ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to my random number generator!\n");
    printf("How many random numbers would you like to generate?\n");
    int n;
    scanf("%d", &n);
    printf("Great! Generating %d random numbers for you now...\n", n);
    srand(time(NULL)); // Seed the random number generator with the current time

    int i;
    for (i = 0; i < n; i++) {
        int rand_num = rand() % 101; // Generate a random number between 0 and 100
        printf("%d ", rand_num);
    }
    printf("\n");
    
    printf("Would you like to generate another set of random numbers? (y/n)\n");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        printf("How many random numbers would you like to generate this time?\n");
        int new_n;
        scanf("%d", &new_n);
        printf("Okay, generating %d new random numbers for you...\n", new_n);
        for (i = 0; i < new_n; i++) {
            int rand_num = rand() % 101;
            printf("%d ", rand_num);
        }
        printf("\n");
    }
    printf("Thank you for using my program!\n");
    return 0;
}