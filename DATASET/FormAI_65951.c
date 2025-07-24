//FormAI DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_WORDS 100000

// Function to check if the given character is an alphabetical character
int is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to convert the given string to lowercase
void to_lowercase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += ('a' - 'A');
        }
        i++;
    }
}

// Function to read dictionary words from a file and store them in a hash table
void read_dictionary_words(char *filename, char **dictionary_words, int *dictionary_word_count) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s!\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)) {
        to_lowercase(line);
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
            len--;
        }
        if (len > 0) {
            dictionary_words[*dictionary_word_count] = (char*) malloc((len + 1) * sizeof(char));
            strcpy(dictionary_words[*dictionary_word_count], line);
            (*dictionary_word_count)++;
        }
    }

    fclose(fp);
}

// Function to check if a given word is present in the dictionary using hash table
int is_word_in_dictionary(char *word, char **dictionary_words, int dictionary_word_count) {
    int i, j;
    for (i = 0; i < dictionary_word_count; i++) {
        if (strcmp(word, dictionary_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a given word is valid
int is_word_valid(char *word) {
    if (strlen(word) == 0) {
        return 0;
    }

    int i;
    for (i = 0; word[i] != '\0'; i++) {
        if (!is_alpha(word[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to check and correct spelling errors in a given sentence
void check_spelling(char *sentence, char **dictionary_words, int dictionary_word_count) {
    int i, j;
    char word[MAX_WORD_LENGTH] = "";

    printf("Corrected sentence: ");

    for (i = 0; sentence[i] != '\0'; i++) {
        if (is_alpha(sentence[i])) {
            int len = strlen(word);
            word[len] = sentence[i];
            word[len+1] = '\0';
        } else {
            // Found a non-alpha character, check and correct spelling of the previous word
            if (is_word_valid(word)) {
                if (!is_word_in_dictionary(word, dictionary_words, dictionary_word_count)) {
                    printf("[%s]", word);

                    // Find the correct word
                    int min_diff = MAX_WORD_LENGTH;
                    char correct_word[MAX_WORD_LENGTH] = "";

                    for (j = 0; j < dictionary_word_count; j++) {
                        if (abs(strlen(word) - strlen(dictionary_words[j])) <= min_diff) {
                            int k, diff = 0;
                            for (k = 0; word[k] != '\0' && dictionary_words[j][k] != '\0'; k++) {
                                if (word[k] != dictionary_words[j][k]) {
                                    diff++;
                                }
                            }
                            if (diff < min_diff) {
                                min_diff = diff;
                                strcpy(correct_word, dictionary_words[j]);
                            }
                        }
                    }

                    printf("{%s}", correct_word);
                } else {
                    printf("%s", word);
                }
            } else {
                printf("%s", word);
            }

            printf("%c", sentence[i]);

            // Reset the word
            memset(word, 0, sizeof word);
        }
    }

    printf("\n");
}

int main() {
    char *dictionary_words[MAX_DICTIONARY_WORDS];
    int dictionary_word_count = 0;
    read_dictionary_words("dictionary.txt", dictionary_words, &dictionary_word_count);

    char sentence[MAX_WORD_LENGTH * MAX_WORD_LENGTH];
    printf("Enter a sentence to check spelling errors: ");
    fgets(sentence, MAX_WORD_LENGTH * MAX_WORD_LENGTH, stdin);
    check_spelling(sentence, dictionary_words, dictionary_word_count);

    int i;
    for (i = 0; i < dictionary_word_count; i++) {
        free(dictionary_words[i]);
    }

    return 0;
}