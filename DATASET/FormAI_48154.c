//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <string.h>

// Define the C Alien Language structure
struct C_Alphabet {
    char letter;
    int value;
};

// Define the C Alien Alphabet
struct C_Alphabet c_alphabet[] = {
    {'a', 10},
    {'b', 11},
    {'c', 12},
    {'d', 13},
    {'e', 14},
    {'f', 15},
    {'g', 16},
    {'h', 17},
    {'i', 18},
    {'j', 19},
    {'k', 20},
    {'l', 21},
    {'m', 22},
    {'n', 23},
    {'o', 24},
    {'p', 25},
    {'q', 26},
    {'r', 27},
    {'s', 28},
    {'t', 29},
    {'u', 30},
    {'v', 31},
    {'w', 32},
    {'x', 33},
    {'y', 34},
    {'z', 35}
};

// Function to translate a C Alien word
int c_translate(char* word) {
    int value = 0;

    // Loop through each letter of the word
    for (int i = 0; i < strlen(word); i++) {
        char letter = word[i];
        int letter_value = 0;

        // Find the value of the letter in the C Alien Alphabet
        for (int j = 0; j < 26; j++) {
            if (c_alphabet[j].letter == letter) {
                letter_value = c_alphabet[j].value;
                break;
            }
        }

        // Add the value of the letter to the total value of the word
        value += letter_value * (i + 1);
    }

    return value;
}

int main() {
    // Welcome message
    printf("Welcome to the C Alien Language Translator!\n\n");

    // Wait for user input
    printf("Enter a C Alien word to translate: ");
    char word[50];
    fgets(word, 50, stdin);

    // Remove the newline character from the end of the input
    word[strcspn(word, "\n")] = 0;

    // Translate the word and display the result to the user
    int value = c_translate(word);
    printf("\nThe C Alien word \"%s\" has a value of %d.\n", word, value);

    // Exit message
    printf("\nThank you for using the C Alien Language Translator!\n");

    return 0;
}