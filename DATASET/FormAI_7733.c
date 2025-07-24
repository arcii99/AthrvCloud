//FormAI DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
    // Welcome message for the user
    printf("Welcome to the String Manipulator program!\n");
    
    // Ask the user to input a string
    char str[100];
    printf("Please enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character
    
    // Print the original string to the user
    printf("The string you entered is:\n%s\n", str);
    
    // Determine the length of the string
    int length = strlen(str);
    printf("The length of the string is %d.\n", length);
    
    // Convert the string to all uppercase characters
    for (int i = 0; i < length; i++) {
        str[i] = toupper(str[i]);
    }
    printf("The string in all uppercase is:\n%s\n", str);
    
    // Reverse the order of the string
    char reverse[100];
    int j = 0;
    for (int i = length - 1; i >= 0; i--) {
        reverse[j] = str[i];
        j++;
    }
    reverse[j] = '\0'; // Add null terminator
    printf("The reversed string is:\n%s\n", reverse);
    
    // Check if the string is a palindrome
    int palindrome = 1;
    for (int i = 0, j = length - 1; i < length / 2; i++, j--) {
        if (str[i] != str[j]) {
            palindrome = 0;
            break;
        }
    }
    if (palindrome == 1) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    // Replace all occurrences of a character
    char old_char, new_char;
    printf("Enter a character to replace: ");
    scanf(" %c", &old_char);
    printf("Enter the new character: ");
    scanf(" %c", &new_char);
    for (int i = 0; i < length; i++) {
        if (str[i] == old_char) {
            str[i] = new_char;
        }
    }
    printf("The string with replaced characters is:\n%s\n", str);
    
    // Exit message for the user
    printf("Thank you for using the String Manipulator program! Goodbye.\n");
    
    return 0;
}