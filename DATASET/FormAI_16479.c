//FormAI DATASET v1.0 Category: String manipulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char string[MAX_SIZE];
    char buffer[MAX_SIZE];
    int choice = 1;
    
    while (choice != 0) {
        printf("Enter a string: ");
        fgets(string, MAX_SIZE, stdin);
    
        printf("\nSelect a string manipulation option:\n");
        printf("1. Reverse the string\n");
        printf("2. Remove all whitespace\n");
        printf("3. Convert to uppercase\n");
        printf("4. Convert to lowercase\n");
        printf("5. Count the number of vowels\n");
        printf("0. Exit\n");
        
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1: // Reverse the string
                int i, j;
                for (i = strlen(string) - 1, j = 0; i >= 0; i--, j++) {
                    buffer[j] = string[i];
                }
                buffer[j] = '\0';
                printf("\nReversed string: %s\n", buffer);
                break;
            case 2: // Remove all whitespace
                int k = 0;
                for (int i = 0; string[i] != '\0'; i++) {
                    if (string[i] != ' ') {
                        buffer[k] = string[i];
                        k++;
                    }
                }
                buffer[k] = '\0';
                printf("\nString with whitespace removed: %s\n", buffer);
                break;
            case 3: // Convert to uppercase
                for (int i = 0; string[i] != '\0'; i++) {
                    buffer[i] = toupper(string[i]);
                }
                printf("\nUppercase string: %s\n", buffer);
                break;
            case 4: // Convert to lowercase
                for (int i = 0; string[i] != '\0'; i++) {
                    buffer[i] = tolower(string[i]);
                }
                printf("\nLowercase string: %s\n", buffer);
                break;
            case 5: // Count the number of vowels
                int count = 0;
                for (int i = 0; string[i] != '\0'; i++) {
                    char c = tolower(string[i]);
                    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                        count++;
                    }
                }
                printf("\nNumber of vowels: %d\n", count);
                break;
            case 0: // Exit
                printf("\nGoodbye!\n");
                break;
            default: // Invalid input
                printf("\nInvalid input.\n");
                break;
        }
    }
    
    return 0;
}