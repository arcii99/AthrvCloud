//FormAI DATASET v1.0 Category: Data validation ; Style: energetic
#include <stdio.h>
#include <ctype.h>

int main() {

    char userInput[50];
    int isValid = 1;
    int containsLetter = 0;
    int containsDigit = 0;
    int i;

    printf("Welcome to Input Validation Program!\n");
    printf("Please enter a string that contains at least one letter and one digit:\n\n");

    do {
        printf("Input: ");
        scanf("%s", userInput);
        printf("\n");

        // Validate the input
        for(i = 0; userInput[i] != '\0'; i++) {
            if(isalpha(userInput[i])) {
                containsLetter = 1;
            }
            else if(isdigit(userInput[i])) {
                containsDigit = 1;
            }
            else {
                isValid = 0;
                break;
            }
        }

        // Check if input is valid
        if(!isValid || !containsLetter || !containsDigit) {
            printf("Invalid input. Please try again.\n\n");
        }
    } while(!isValid || !containsLetter || !containsDigit);

    printf("Input is valid!\n");
    printf("User inputted: %s\n\n", userInput);

    return 0;
}