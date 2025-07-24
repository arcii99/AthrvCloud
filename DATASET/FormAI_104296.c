//FormAI DATASET v1.0 Category: Word Count Tool ; Style: modular
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // maximum length of a word

/**
 * The `count_words` function counts the number of words in a given string.
 * @param input_str The string to count the words in.
 * @return int The number of words in the string.
 */
int count_words(char input_str[]) {
    int words = 0;
    int index = 0; // position in the string
    char current_char = input_str[0];

    // Loop through each character in the string.
    while (current_char != '\0') {
        // If we encounter a whitespace character, that means a word has ended.
        if (isspace(current_char)) {
            words++;
        } 

        index++;
        current_char = input_str[index];
    }

    return words;
}

/**
 * The `get_words` function extracts each word from a given string and 
 * populates the given words array with them.
 * @param input_str The string to extract words from.
 * @param words An array to store each word into.
 * @return int The number of words extracted.
 */
int get_words(char input_str[], char words[][MAX_WORD_LENGTH]) {
    int words_count = 0; // number of words extracted
    int word_index = 0; // position of the current word being extracted
    int index = 0; // position in the string
    char current_char = input_str[0];

    // Loop through each character in the string.
    while (current_char != '\0') {
        // If we encounter a whitespace character, that means a word has ended.
        if (isspace(current_char)) {
            words[words_count][word_index] = '\0'; // terminate the current word
            words_count++;
            word_index = 0;
        } else {
            words[words_count][word_index] = current_char;
            word_index++;
        }

        index++;
        current_char = input_str[index];
    }

    // Terminate the last word that was being extracted.
    words[words_count][word_index] = '\0';
    words_count++;

    return words_count;
}

int main() {
    char input_str[1000];
    char words[1000][MAX_WORD_LENGTH];
    int words_count;

    printf("Enter a sentence:\n");
    fgets(input_str, sizeof(input_str), stdin); // get input from user

    // Count the number of words in the input string.
    words_count = count_words(input_str);
    printf("\nThere are %d words in the sentence.\n\n", words_count);

    // Extract each word and store it into the `words` array.
    words_count = get_words(input_str, words);

    // Print each word in the `words` array.
    printf("Words extracted from the sentence:\n");
    for (int i = 0; i < words_count; i++) {
        printf("%s ", words[i]);
    }

    return 0;
}