//FormAI DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50];
    int choice;

    printf("Enter the first string: ");
    fgets(str1, 50, stdin);

    printf("Enter the second string: ");
    fgets(str2, 50, stdin);

    printf("\nOperations Menu: ");
    printf("\n1. Concatenate two strings");
    printf("\n2. Compare two strings");
    printf("\n3. Find length of a string");
    printf("\nEnter your choice: ");

    scanf("%d", &choice);

    switch (choice) {
        case 1: // Concatenate two strings
            strcat(str1, str2);
            printf("\nConcatenated string: %s", str1);
            break;

        case 2: // Compare two strings
            if (strcmp(str1, str2) == 0)
                printf("\nStrings are equal");
            else
                printf("\nStrings are not equal");
            break;

        case 3: // Find length of a string
            printf("\nLength of the first string: %d", strlen(str1));
            printf("\nLength of the second string: %d", strlen(str2));
            break;

        default:
            printf("\nInvalid choice!");
            break;
    }

    return 0;
}