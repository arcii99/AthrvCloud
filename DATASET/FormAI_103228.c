//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main()
{
    char input[MAX_LENGTH], reversed[MAX_LENGTH];
    int i, j;
    
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    
    // Remove newline character from fgets
    input[strcspn(input, "\n")] = '\0';
    
    // Make all characters lowercase
    for (i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }
    
    // Reverse the string
    j = strlen(input) - 1;
    for (i = 0; i < strlen(input); i++) {
        reversed[i] = input[j];
        j--;
    }
    reversed[i] = '\0';
    
    // Compare original and reversed string
    if (strcmp(input, reversed) == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    return 0;
}