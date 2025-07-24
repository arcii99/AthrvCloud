//FormAI DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <string.h>

/* This program allows the user to enter a sentence or phrase and 
   replaces all vowels with the next letter in the alphabet */

int main() {
    char sentence[100];
    printf("Enter a sentence or phrase: ");
    fgets(sentence, sizeof(sentence), stdin); // get input sentence from user and store it in the "sentence" variable

    // loop through each character in the sentence 
    for (int i = 0; i < strlen(sentence); i++) {
        char current_char = sentence[i];

        // if the current character is a vowel, replace it with the next letter in the alphabet
        if (current_char == 'a' || current_char == 'e' || current_char == 'i' || current_char == 'o' || current_char == 'u') {
            current_char++; // add 1 to the character's ASCII value to get the next letter in the alphabet
            if (current_char > 'z') {
                current_char = 'a'; // if we go past "z", wrap around to "a"
            }
            sentence[i] = current_char; // set the updated character in the sentence
        }
    }

    printf("New sentence with vowels replaced: %s\n", sentence);

    return 0;
}