//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constant
#define MAX_SIZE 100

int main() {
    // Declare variables
    char str[MAX_SIZE], ch;
    int i = 0, j = 0, len = 0, count = 0;

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    // Get length of string
    len = strlen(str);

    // Convert string to lowercase
    for(i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }

    // Count frequency of each word in string
    for(i = 0; i < len; i++) {
        // Check for alphabets
        if(isalpha(str[i])) {
            ch = str[i];
            count = 1;

            // Loop through the string, comparing each character with the first character
            for(j = i + 1; j < len; j++) {
                if(ch == str[j]) {
                    count++;
                    str[j] = ' ';
                }
            }

            // Print the frequency of each word
            printf("%c - %d\n", ch, count);
        }
    }

    // Wait for input to exit
    printf("\nPress ENTER to exit.");
    getchar();
    return 0;
}