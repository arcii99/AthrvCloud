//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 30
#define MAX_WORDS 1000

struct word {
    char text[MAX_WORD_LENGTH + 1];
    int frequency;
};

int main() {
    struct word words[MAX_WORDS];
    int num_words = 0;

    printf("Enter text:\n");
    char current_word[MAX_WORD_LENGTH + 1];
    while (scanf("%s", current_word) != EOF) {
        if (num_words == MAX_WORDS) {
            printf("Error: too many words!\n");
            exit(1);
        }

        int found_word = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(words[i].text, current_word) == 0) {
                words[i].frequency++;
                found_word = 1;
                break;
            }
        }

        if (!found_word) {
            strcpy(words[num_words].text, current_word);
            words[num_words].frequency = 1;
            num_words++;
        }
    }

    printf("Word Frequency Results:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].text, words[i].frequency);
    }

    return 0;
}