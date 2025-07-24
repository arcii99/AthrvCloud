//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100    // Maximum length of a word
#define MAX_WORDS 100000    // Maximum number of words

int main() {

    char input_str[1000000];    // Input string to be read
    char curr_word[MAX_WORD_LEN+1];    // Current word being processed
    char freq_words[MAX_WORDS][MAX_WORD_LEN+1];    // Array to store words with highest frequency
    int freq_count[MAX_WORDS] = {0};    // Array to store frequency of words
    int max_freq = 0;    // Maximum frequency of a word
    int num_words = 0;    // Total number of words processed
    int i, j;

    // Read input string
    printf("Enter a string: ");
    fgets(input_str, sizeof(input_str), stdin);

    // Convert string to lowercase
    for(i = 0; input_str[i]; i++) {
        input_str[i] = tolower(input_str[i]);
    }

    // Process words in input string
    for(i = 0; input_str[i]; i++) {

        // Skip all non-alpha characters
        if(!isalpha(input_str[i])) {
            continue;
        }

        // Build current word
        for(j = 0; input_str[i+j] && isalpha(input_str[i+j]); j++) {
            curr_word[j] = input_str[i+j];
        }
        curr_word[j] = '\0';

        // Update frequency count for current word
        freq_count[num_words] = 1;
        for(j = 0; j < num_words; j++) {
            if(strcmp(curr_word, freq_words[j]) == 0) {
                freq_count[j]++;
                if(freq_count[j] > max_freq) {
                    max_freq = freq_count[j];
                }
                break;
            }
        }

        // Add current word to word list if new
        if(j == num_words) {
            strcpy(freq_words[num_words], curr_word);
            num_words++;
        }

        i += strlen(curr_word) - 1;
    }

    // Print words with highest frequency
    printf("\nWords with highest frequency:\n");
    for(i = 0; i < num_words; i++) {
        if(freq_count[i] == max_freq) {
            printf("%s\n", freq_words[i]);
        }
    }
    
    return 0;
}