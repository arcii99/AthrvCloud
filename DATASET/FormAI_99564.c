//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char line[MAX_LINE_LENGTH];
    int num_vowels = 0;
    int num_consonants = 0;
    int num_digits = 0;
    int num_spaces = 0;
    int num_punctuation = 0;

    printf("Enter a sentence:\n");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Loop through each character in the line
    for (int i = 0; line[i] != '\0'; i++) {
        // Check if the character is a vowel or consonant
        if (isalpha(line[i])) {
            if (tolower(line[i]) == 'a' || tolower(line[i]) == 'e' || 
                tolower(line[i]) == 'i' || tolower(line[i]) == 'o' || 
                tolower(line[i]) == 'u') {
                num_vowels++;
            } else {
                num_consonants++;
            }
        } else if (isdigit(line[i])) {
            num_digits++;
        } else if (isspace(line[i])) {
            num_spaces++;
        } else {
            num_punctuation++;
        }
    }

    printf("Number of vowels: %d\n", num_vowels);
    printf("Number of consonants: %d\n", num_consonants);
    printf("Number of digits: %d\n", num_digits);
    printf("Number of spaces: %d\n", num_spaces);
    printf("Number of punctuation: %d\n", num_punctuation);

    return 0;
}