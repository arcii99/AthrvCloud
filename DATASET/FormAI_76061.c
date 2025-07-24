//FormAI DATASET v1.0 Category: String manipulation ; Style: single-threaded
#include <stdio.h>
#include <string.h>

/*
* This program demonstrates a unique approach to single-threaded string manipulation.
* It takes a user input string and converts it to all uppercase letters using pointer arithmetic.
* It then counts the number of vowels in the uppercase string and replaces them with the character 'X'.
* Finally, it prints the modified string and the number of vowels replaced.
*/

int main() {
    char str[100];
    int vowels = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    // Convert all characters to uppercase using pointer arithmetic
    for (char* ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr >= 'a' && *ptr <= 'z')
            *ptr -= 32;
    }

    // Count the number of vowels and replace them with 'X'
    for (char* ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U') {
            vowels++;
            *ptr = 'X';
        }
    }

    printf("Modified string: %s\n", str);
    printf("Number of vowels replaced: %d\n", vowels);

    return 0;
}