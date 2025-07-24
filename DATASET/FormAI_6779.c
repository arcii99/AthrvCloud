//FormAI DATASET v1.0 Category: String manipulation ; Style: content
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* This function reverses a string */
void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

/* This function removes all spaces from a string */
void remove_spaces(char str[]) {
    int len = strlen(str);
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            str[k] = str[i];
            k++;
        }
    }
    str[k] = '\0';
}

/* This function converts a string to uppercase */
void to_uppercase(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char str1[50] = "Hello World!";
    char str2[50] = "This is a sample string";
    
    // Print the original strings
    printf("Original String 1: %s\n", str1);
    printf("Original String 2: %s\n", str2);
    
    // Reverse the strings
    reverse(str1);
    reverse(str2);
    
    // Print the reversed strings
    printf("Reversed String 1: %s\n", str1);
    printf("Reversed String 2: %s\n", str2);
    
    // Remove spaces from the strings
    remove_spaces(str1);
    remove_spaces(str2);
    
    // Print the strings without spaces
    printf("String 1 without spaces: %s\n", str1);
    printf("String 2 without spaces: %s\n", str2);
    
    // Convert the strings to uppercase
    to_uppercase(str1);
    to_uppercase(str2);
    
    // Print the uppercase strings
    printf("Uppercase String 1: %s\n", str1);
    printf("Uppercase String 2: %s\n", str2);
    
    return 0;
}