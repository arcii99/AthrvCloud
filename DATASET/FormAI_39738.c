//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: cheerful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char input[100]; // Maximum length of user input
    char sanitized[100]; // Sanitized user input
    int i, j = 0; // Counter variables
    
    printf("Welcome to the User Input Sanitizer Program!\n");
    printf("Please enter your input: ");
    fgets(input, 100, stdin); // Get user input
    
    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) { // Check if character is alphabetic
            sanitized[j] = input[i]; // Add to sanitized string
            j++;
        }
    }
    
    sanitized[j] = '\0'; // Terminate sanitized string
    
    printf("Your sanitized input is: %s\n", sanitized);
    
    printf("Would you like to add any additional characters to remove (y/n)?");
    char answer = getchar();
    if (answer == 'y') {
        printf("Please enter the characters to remove: ");
        char chars_to_remove[10];
        scanf("%s", chars_to_remove);
        for (i = 0; i < strlen(sanitized); i++) {
            for (j = 0; j < strlen(chars_to_remove); j++) {
                if (sanitized[i] == chars_to_remove[j]) { // Check if character needs to be removed
                    sanitized[i] = ' '; // Replace with a space
                }
            }
        }
        
        printf("Your final sanitized input is: %s\n", sanitized);
    }
    else {
        printf("Thank you for using the User Input Sanitizer Program!\n");
    }
    
    return 0;
}