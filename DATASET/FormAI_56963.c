//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <string.h>

// Function to check if the given character is a vowel
int isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    return 0;
}

// Function to translate a word to Alien Language
void translate(char word[]) {
    int len = strlen(word);

    // Make all the vowels uppercase
    for (int i = 0; i < len; i++) {
        if (isVowel(word[i]))
            word[i] = toupper(word[i]);
    }

    // Add "G" and "O" after each vowel group
    for (int i = 0; i < len; i++) {
        if (isVowel(word[i])) {
            putchar(word[i]);
            int j = i + 1;
            while (j < len && isVowel(word[j]))
                j++;
            printf("G");
            i = j - 1;
        } else {
            putchar(word[i]);
        }
    }
    printf("O");

}

// Main program
int main() {
    char input[100];

    printf("Enter a word in Alien Language: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from fgets
    input[strcspn(input, "\n")] = 0;

    // Translate the input word
    translate(input);
    printf("\n");

    return 0;
}