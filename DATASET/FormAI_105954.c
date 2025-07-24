//FormAI DATASET v1.0 Category: Text processing ; Style: ephemeral
#include <stdio.h>
#include <string.h>

/* This program takes user input as a string and replaces all vowels with asterisks (*).
   It then prints the modified string and the percentage of vowels replaced. */

int main() {
    char input[100];
    int vowels = 0;
    
    printf("Please enter a string: ");
    fgets(input, 100, stdin); // Get user input as string
    
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' ||
            input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
            input[i] = '*'; // Replace vowel with asterisk
            vowels++;
        }
    }
    
    printf("Modified string: %s\n", input);
    printf("Percentage of vowels replaced: %.2f%%\n", (float)vowels/(strlen(input)-1)*100); // Calculate and print percentage of vowels replaced
    return 0;
}