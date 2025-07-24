//FormAI DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <string.h>
#define MAX_STRING_SIZE 100

int main(void) {
    char inputString[MAX_STRING_SIZE];
    char* p;

    printf("Enter a string (up to %d characters):\n", MAX_STRING_SIZE-1);
    fgets(inputString, MAX_STRING_SIZE, stdin);

    // Remove the trailing newline character at the end of the string 
    if ((p = strchr(inputString, '\n')) != NULL)
        *p = '\0';

    int stringLength = strlen(inputString);
    printf("Length of the input string: %d\n", stringLength);

    // Convert all characters to uppercase
    for (int i = 0; i < stringLength; i++)
        inputString[i] = toupper(inputString[i]);

    printf("The input string in uppercase: %s\n", inputString);

    // Reverse the string
    char reversedString[MAX_STRING_SIZE];
    int j = 0;
    for (int i = stringLength - 1; i >= 0; i--) 
        reversedString[j++] = inputString[i];
    reversedString[stringLength] = '\0';

    printf("The input string reversed: %s\n", reversedString);

    // Replace all vowels with asterisks 
    for (int i = 0; i < stringLength; i++) {
        switch (inputString[i]) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                inputString[i] = '*';
                break;
            default:
                break;
        }
    }
    printf("The input string with vowels replaced with '*': %s\n", inputString);

    // Count the number of words in the string
    int wordCount = 0;
    char* token = strtok(inputString, " ");
    while(token != NULL) {
        wordCount++;
        token = strtok(NULL, " ");
    }
    printf("Number of words in the input string: %d\n", wordCount);

    return 0;
}