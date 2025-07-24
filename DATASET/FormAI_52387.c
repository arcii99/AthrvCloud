//FormAI DATASET v1.0 Category: QR code generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Welcome message
    printf("Welcome to the C QR Code generator!\n");
    printf("Are you ready to create something surreal?\n");
    
    // Get input from user
    char userInput[10];
    printf("Type 'yes' to proceed. Type 'no' to exit.: ");
    scanf("%s", userInput);
    
    // Check user input
    if (strcmp(userInput, "no") == 0) {
        printf("No problem, come back later when you're ready to create!\n");
        exit(0);
    } else if (strcmp(userInput, "yes") != 0) {
        printf("I didn't understand your input. Let's start again.\n");
        main(); // recursion for retries
    }
    
    // Get user's surreal message
    char surrealCode[100];
    printf("Please enter your surreal message (max 100 characters): ");
    getchar(); // clear buffer
    fgets(surrealCode, 100, stdin);

    // Generate QR code
    int i, j;
    for (i = 0; i < strlen(surrealCode); i++) {
        for (j = 0; j < strlen(surrealCode); j++) {
            if (surrealCode[i] == surrealCode[j]) {
                printf("0");
            } else {
                printf("1");
            }
        }
        printf("\n");
    }
    
    // Exit message
    printf("Thank you for using the C QR Code generator!\n");
    printf("Your surreal QR code is ready!\n");
    return 0;
}