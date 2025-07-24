//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: introspective
#include <stdio.h>
#include <ctype.h>

int main() {
    char userInput[50];
    int i;

    printf("Please enter your input: ");
    scanf("%s", userInput);

    printf("\nYour original input was: %s\n", userInput);

    for(i = 0; userInput[i]; i++) {
        if(isalpha(userInput[i])) {
            if(islower(userInput[i])) {
                userInput[i] = toupper(userInput[i]);
            }
        }
        else if(isdigit(userInput[i])) {
            //If the input is a number, terminate the program
            printf("Input contains numeric values. Please try again.");
            return 0;
        }
        else {
            //If there are non-alphanumeric characters, remove them
            userInput[i] = '\0';
            break;
        }
    }

    printf("Your sanitized input is: %s", userInput);

    return 0;
}