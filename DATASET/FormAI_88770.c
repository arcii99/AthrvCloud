//FormAI DATASET v1.0 Category: String manipulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 50

/* Function Declarations */
void reverseString(char* inputString);
void replaceSubstring(char* inputString, char* oldSubstring, char* newSubstring);

int main() {
    char input[MAX_STRING_SIZE];
    printf("Enter a string: ");
    fgets(input, MAX_STRING_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';

    // Reversing the string
    printf("Reversed String: ");
    reverseString(input);
    printf("\n");

    // Replacing a subtring
    char oldSubstring[MAX_STRING_SIZE], newSubstring[MAX_STRING_SIZE];
    printf("Enter the substring to replace: ");
    fgets(oldSubstring, MAX_STRING_SIZE, stdin);
    oldSubstring[strcspn(oldSubstring, "\n")] = '\0';
    printf("Enter the new substring: ");
    fgets(newSubstring, MAX_STRING_SIZE, stdin);
    newSubstring[strcspn(newSubstring, "\n")] = '\0';

    printf("String after substring replacement: ");
    replaceSubstring(input, oldSubstring, newSubstring);
    printf("\n");

    return 0;
}

/* Function Definitions */
void reverseString(char* inputString) {
    int stringLength = strlen(inputString);
    for (int i = stringLength - 1; i >= 0; i--) {
        printf("%c", inputString[i]);
    }
}

void replaceSubstring(char* inputString, char* oldSubstring, char* newSubstring) {
    char* token;
    while ((token = strstr(inputString, oldSubstring))) {
        *token = '\0';
        printf("%s%s", inputString, newSubstring);
        inputString = token + strlen(oldSubstring);
    }
    printf("%s", inputString);
}