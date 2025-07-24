//FormAI DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char str[])
{
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to remove a character from a string
void removeChar(char str[], char ch)
{
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ch) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

// Function to count the number of words in a string
int countWords(char* str)
{
    int count = 0;
    int state = 0;
    while (*str) {
        if (*str == ' ' || *str == '\n' || *str == '\t') {
            state = 0;
        }
        else if (state == 0) {
            state = 1;
            count++;
        }
        str++;
    }
    return count;
}

// Main function
int main()
{
    char str[100];

    // Get input string from user
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // Remove newline character from input string
    str[strcspn(str, "\n")] = 0;

    // Print original string
    printf("Original string: %s\n", str);

    // Reverse the input string
    reverseString(str);
    printf("Reversed string: %s\n", str);

    // Remove the letter 'e' from the input string
    removeChar(str, 'e');
    printf("String with 'e' removed: %s\n", str);

    // Count the number of words in the input string
    int wordCount = countWords(str);
    printf("Number of words in the string: %d\n", wordCount);

    return 0;
}