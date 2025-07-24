//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to get the frequency of each word
int get_word_frequency(char *word, char **words_list, int *frequency_list, int num_words) {
    for (int i=0; i<num_words; i++) {
        if (strcmp(words_list[i], word) == 0) {
            // word already exists in list, increase frequency count
            frequency_list[i]++;
            return frequency_list[i];
        }
    }

    // word doesn't exist in list, add it
    words_list[num_words] = (char*)malloc(strlen(word)+1);
    strcpy(words_list[num_words], word);
    frequency_list[num_words] = 1;
    return 1;
}

// Function to print the word frequency list
void print_word_frequency(char **words_list, int *frequency_list, int num_words) {
    printf("\nWord Frequency List:\n");
    printf("---------------------\n");

    for (int i=0; i<num_words; i++) {
        printf("%s: %d\n", words_list[i], frequency_list[i]);
    }
}

int main() {
    char input_str[1000];

    printf("Enter a string: ");
    gets(input_str);

    char **words_list = (char**)malloc(sizeof(char*) * 1000); // Maximum of 1000 words
    int *frequency_list = (int*)malloc(sizeof(int) * 1000); // Frequency of each word
    int num_words = 0;

    char *token = strtok(input_str, " ,.-"); // Delimiters are space, comma, dot, and dash

    while (token != NULL) {
        // Convert token to lowercase
        for (int i=0; i<strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        int frequency = get_word_frequency(token, words_list, frequency_list, num_words);
        printf("'%s' appears %d time(s).\n", token, frequency);

        num_words++;
        token = strtok(NULL, " ,.-");
    }

    print_word_frequency(words_list, frequency_list, num_words);

    // Free dynamically allocated memory
    for (int i=0; i<num_words; i++) {
        free(words_list[i]);
    }
    free(words_list);
    free(frequency_list);

    return 0;
}