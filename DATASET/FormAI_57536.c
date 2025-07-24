//FormAI DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char myString[1000];
    printf("Enter a string: ");
    fgets(myString, 1000, stdin);
    printf("Original String: %s\n", myString);

    // Reversing the string
    char reversedString[1000];
    int i, j = 0;
    for (i = strlen(myString) - 1; i >= 0; i--) {
        reversedString[j++] = myString[i];
    }
    reversedString[j] = '\0';
    printf("Reversed String: %s\n", reversedString);

    // Converting the string to uppercase
    char uppercaseString[1000];
    for (i = 0; i < strlen(myString); i++) {
        uppercaseString[i] = toupper(myString[i]);
    }
    uppercaseString[i] = '\0';
    printf("Uppercase String: %s\n", uppercaseString);

    // Replacing all vowels with asterisks
    char newString[1000];
    for (i = 0; i < strlen(myString); i++) {
        switch (myString[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                newString[i] = '*';
                break;
            default:
                newString[i] = myString[i];
                break;
        }
    }
    newString[i] = '\0';
    printf("New String: %s\n", newString);

    return 0;
}