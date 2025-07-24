//FormAI DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD 50
#define MAX_DICT_WORDS 500

char* dictionary[MAX_DICT_WORDS] = { "the", "and", "of", "a", "to", "in", "that", "is", "with", "for", "be", "on", "not", "by", "or", "but", "from", "you", "are", "all", "have", "an", "can", "my", "we", "this", "at", "which", "it", "would", "do", "if", "your", "them", "said", "their", "me", "when", "up", "out", "he", "then", "no", "what", "so", "her", "him", "like", "some", "into", "has", "more", "there", "any", "only", "could", "should", "very", "man", "his", "too", "now", "may", "well", "us", "will", "time" };

int main(void) {
    char input[MAX_WORD];
    int dictionary_length = sizeof(dictionary) / sizeof(dictionary[0]);

    printf("Welcome to the medieval spell checker! Please enter a word to check its spelling:\n");

    while (fgets(input, MAX_WORD, stdin)) {
        char* end_of_word;
        if ((end_of_word = strchr(input, '\n')) != NULL) {
            *end_of_word = '\0';
        }

        int found = 0;
        for (int i = 0; i < strlen(input); i++) {
            if (isalpha(input[i]) == 0) {
                printf("Alas! \'%s\' is not a word in good standing in this realm. Please enter another word if you so desire:\n", input);
                found = 1;
                break;
            }
        }

        if (found == 1) {
            continue;
        }

        for (int i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        int match_found = 0;
        for (int i = 0; i < dictionary_length; i++) {
            if (strcmp(input, dictionary[i]) == 0) {
                match_found = 1;
                break;
            }
        }

        if (match_found == 1) {
            printf("Huzzah! \'%s\' is a word in good standing in this realm. Please enter another word if you so desire:\n", input);
        } else {
            printf("Alas! \'%s\' is not a word in good standing in this realm. Please enter another word if you so desire:\n", input);
        }
    }

    return 0;
}