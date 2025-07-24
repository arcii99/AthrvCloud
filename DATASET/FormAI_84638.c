//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char inputString[50];
    char cleanString[50];
    printf("My darling, please input a string that needs to be sanitized: ");
    fflush(stdout);
    fgets(inputString, 50, stdin);
    int inputLength = strlen(inputString);
    int cleanIndex = 0;
    for (int i = 0; i < inputLength; i++) {
        if ((inputString[i] >= 'a' && inputString[i] <= 'z') || (inputString[i] >= 'A' && inputString[i] <= 'Z') || inputString[i] == ' ') {
            cleanString[cleanIndex] = inputString[i];
            cleanIndex++;
        } else {
            continue;
        }
    }
    cleanString[cleanIndex] = '\0';
    printf("My love, your sanitized string is: %s\n", cleanString);
    return 0;
}