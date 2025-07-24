//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: excited
// Welcome to the C Cat Language Translator!
// This program will convert your written sentences into meows and purrs that only cats can understand.

#include <stdio.h>
#include <string.h>

// Define our "cat vocabulary" using arrays of meows and purrs
const char * meows[7] = {"meow", "purr", "hiss", "yowl", "chirp", "growl", "mew"};
const char * purrs[4] = {"purrr", "prrt", "prrrrow", "purrup"};

// Function to convert a sentence into cat language
void translate_to_cat(char * sentence, int length) {
    // Loop through each character in the sentence to translate each word
    for (int i = 0; i < length; i++) {
        // Check if the current character is a space or punctuation
        if (sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == ',' || sentence[i] == '!' || sentence[i] == '?') {
            printf("%c", sentence[i]); // Print the punctuation character as-is
        } else {
            int cat_word_index = (int)sentence[i] % 7; // Use the ASCII value of the letter to choose a corresponding meow
            printf("%s ", meows[cat_word_index]); // Print the meow directly after the letter
        }
    }
    printf("%s\n", purrs[length % 4]); // End the sentence with a purr based on the sentence length
}

// Main function to get input from the user and start the translation process
int main() {
    char sentence[100];
    printf("Enter a sentence to translate into cat language: ");
    fgets(sentence, 100, stdin); // Use fgets to safely read input from the user
    int sentence_length = strlen(sentence) - 1; // Remove the trailing newline character from fgets
    printf("Translation: ");
    translate_to_cat(sentence, sentence_length);
    return 0;
}

// End of program