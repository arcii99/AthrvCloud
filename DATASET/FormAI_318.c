//FormAI DATASET v1.0 Category: String manipulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char userInput[100];
    char targetString[100];

    printf("Please enter a string: ");
    fgets(userInput, 100, stdin);

    printf("Your string is: %s\n", userInput);

    printf("Please enter the target string that you want to modify: ");
    fgets(targetString, 100, stdin);

    printf("Your target string is: %s\n", targetString);

    int inputLength = strlen(userInput);
    int targetLength = strlen(targetString);
    int newLength = (inputLength / targetLength + 1) * targetLength;
    char* newString = (char*) calloc(newLength, sizeof(char));

    for (int i = 0, j = 0; i < inputLength && j < newLength; i++, j++) {
        if (j % targetLength == 0) {
            j = 0;
        }
        newString[j] = targetString[j];
    }

    printf("New string is: %s\n", newString);

    free(newString);

    return 0;
}