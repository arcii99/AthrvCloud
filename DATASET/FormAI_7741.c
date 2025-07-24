//FormAI DATASET v1.0 Category: Text processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    printf("Welcome to the Happy Text Processor!\n");
    printf("Please enter some text to process: ");

    char userInput[100];
    fgets(userInput, sizeof(userInput), stdin);

    int length = strlen(userInput);

    printf("Your text has a length of: %d\n", length);

    printf("Converting all characters to uppercase...\n");

    int i;
    char upperCaseInput[length];

    for (i = 0; i < length; i++) {
        upperCaseInput[i] = toupper(userInput[i]);
    }

    printf("Your new text is: %s", upperCaseInput);

    return 0;
}