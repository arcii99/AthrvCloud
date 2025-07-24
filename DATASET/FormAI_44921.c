//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;

    printf("Welcome to the Text Processor!\n");
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    for (int i = 0; i < strlen(sentence); i++) {
        if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')) {
            // Check if the character is a vowel
            if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u' || sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U') {
                vowels++;
            }
            // If not a vowel, it is a consonant
            else {
                consonants++;
            }
        }
        // Check if the character is a digit
        else if (sentence[i] >= '0' && sentence[i] <= '9') {
            digits++;
        }
        // If not a digit or a letter, it is a space
        else if (sentence[i] == ' ') {
            spaces++;
        }
    }

    // Print the results
    printf("\nWow! Here's what I found: \n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);

    printf("\nThanks for using the Text Processor! Have a nice day :)\n");
    return 0;
}