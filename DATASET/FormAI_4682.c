//FormAI DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

int is_alpha(const char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int is_uppercase(const char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_digit(const char c) {
    return (c >= '0' && c <= '9');
}

int is_valid_word(const char *word) {
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        if (!is_alpha(word[i]))
            return 0;
    }
    return 1;
}

int is_valid_number(const char *word) {
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        if (!is_digit(word[i]))
            return 0;
    }
    return 1;
}

int is_uppercase_word(const char *word) {
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        if (!is_uppercase(word[i]))
            return 0;
    }
    return 1;
}

void str_to_lower(char *word) {
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        if (is_uppercase(word[i]))
            word[i] = tolower(word[i]);
    }
}

void strip_punctuation(char *word) {
    int i, j;
    for (i = 0; word[i] != '\0'; i++) {
        if (!is_alpha(word[i]) && !is_digit(word[i])) {
            for (j = i; word[j] != '\0'; j++) {
                word[j] = word[j+1];
            }
            i--;
        }
    }
}

void strip_numbers(char *word) {
    int i, j;
    for (i = 0; word[i] != '\0'; i++) {
        if (is_digit(word[i])) {
            for (j = i; word[j] != '\0'; j++) {
                word[j] = word[j+1];
            }
            i--;
        }
    }
}

int is_in_dictionary(const char *word, const char **dictionary, const int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i]) == 0)
            return 1;
    }
    return 0;
}

void spell_check_word(const char *word, const char **dictionary, const int num_words) {
    char lower_case_word[MAX_WORD_LENGTH];
    strcpy(lower_case_word, word);
    str_to_lower(lower_case_word);
    strip_punctuation(lower_case_word);
    strip_numbers(lower_case_word);

    if (is_valid_word(lower_case_word)) {
        if (is_uppercase_word(word)) {
            if (is_in_dictionary(lower_case_word, dictionary, num_words))
                printf("%s is spelled correctly.\n", word);
            else
                printf("%s is spelled incorrectly.\n", word);
        } else {
            if (is_in_dictionary(lower_case_word, dictionary, num_words))
                printf("%s is spelled correctly.\n", word);
            else {
                printf("%s is spelled incorrectly. Suggestions: ", word);
                int i, j;
                char suggestion[MAX_WORD_LENGTH];
                for (i = 0; i < num_words; i++) {
                    if (strlen(dictionary[i]) < strlen(lower_case_word) + 2 &&
                        strlen(dictionary[i]) > strlen(lower_case_word) - 2) {
                        strcpy(suggestion, dictionary[i]);
                        str_to_lower(suggestion);
                        strip_numbers(suggestion);
                        strip_punctuation(suggestion);
                        if (strcmp(suggestion, lower_case_word) == 0 ||
                            strcmp(suggestion, "") == 0)
                            continue;

                        int match = 1;
                        for (j = 0; lower_case_word[j] != '\0'; j++) {
                            if (lower_case_word[j] != suggestion[j] &&
                                is_alpha(lower_case_word[j])) {
                                match = 0;
                                break;
                            }
                        }

                        if (match)
                            printf("%s, ", dictionary[i]);
                    }
                }
                printf("\n");
            }
        }
    } else if (is_valid_number(lower_case_word)) {
        printf("%s is a valid number.\n", word);
    } else {
        printf("%s is not a valid word or number.\n", word);
    }
}

int main() {
    const char *dictionary[] = {
        "word",
        "apple",
        "book",
        "tree",
        "house",
        "car",
        "bird",
        "dog",
        "cat",
        "mouse",
        "chair"
    };
    const int num_words = sizeof(dictionary)/sizeof(dictionary[0]);

    char sentence[] = "The quik brown fox jummped over the laazy dog.";

    char *word = strtok(sentence, " ");
    while (word) {
        spell_check_word(word, dictionary, num_words);
        word = strtok(NULL, " ");
    }

    return 0;
}