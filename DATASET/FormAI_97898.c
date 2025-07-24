//FormAI DATASET v1.0 Category: String manipulation ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Define variables
    char inputString[100];
    char outputString[100];
    int length, choice, i, j;

    do {
        // Ask user for input and store in inputString
        printf("\nEnter a string: ");
        fgets(inputString, sizeof inputString, stdin);

        // Remove trailing newline character
        inputString[strcspn(inputString, "\n")] = 0;

        // Calculate length of inputString
        length = strlen(inputString);

        // Ask user for choice
        printf("\nChoose an option:");
        printf("\n1 - Reverse string");
        printf("\n2 - Remove a character");
        printf("\n3 - Replace a character");
        printf("\n4 - Uppercase/Lowercase conversion");
        printf("\n5 - Exit\n");
        scanf("%d", &choice);

        // Handle user's choice
        switch (choice) {
            case 1: // Reverse string
                for (i = length - 1, j = 0; i >= 0; i--, j++) {
                    outputString[j] = inputString[i];
                }
                outputString[length] = '\0';
                printf("\nReversed string: %s", outputString);
                break;

            case 2: // Remove a character
                char removeChar;
                printf("\nEnter the character to remove: ");
                scanf(" %c", &removeChar);
                int removedIndex = 0;
                for (i = 0, j = 0; i < length; i++) {
                    if (inputString[i] != removeChar) {
                        outputString[j] = inputString[i];
                        j++;
                    } else {
                        removedIndex++;
                    }
                }
                outputString[length - removedIndex] = '\0';
                printf("\nString with character removed: %s", outputString);
                break;

            case 3: // Replace a character
                char findChar, replaceChar;
                printf("\nEnter the character to replace: ");
                scanf(" %c", &findChar);
                printf("Enter the character to replace with: ");
                scanf(" %c", &replaceChar);
                for (i = 0; i < length; i++) {
                    outputString[i] = inputString[i] == findChar ? replaceChar : inputString[i];
                }
                outputString[length] = '\0';
                printf("\nString with character replaced: %s", outputString);
                break;

            case 4: // Uppercase/lowercase conversion
                char option;
                printf("\nChoose an option:");
                printf("\nU - Uppercase");
                printf("\nL - Lowercase\n");
                scanf(" %c", &option);
                for (i = 0; i < length; i++) {
                    outputString[i] = option == 'U' ? toupper(inputString[i]) : tolower(inputString[i]);
                }
                outputString[length] = '\0';
                printf("\nConverted string: %s", outputString);
                break;

            case 5: // Exit
                exit(0);

            default:
                printf("Invalid choice!");
                break;
        }
    } while (choice != 5);

    return 0;
}