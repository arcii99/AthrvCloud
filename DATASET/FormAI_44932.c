//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

int main() {
    char sentence[1000];
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int word_freq[MAX_NUM_WORDS];
    int num_words = 0;
    int i, j;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    // Tokenize the sentence into words
    char *token = strtok(sentence, " ");
    while(token != NULL) {
        strcpy(words[num_words], token);
        word_freq[num_words] = 0;
        num_words++;
        token = strtok(NULL, " ");
    }

    // Count the frequency of each word
    for(i = 0; i < num_words; i++) {
        for(j = 0; j < num_words; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                word_freq[i]++;
            }
        }
    }

    // Print the frequency of each word
    printf("Word Frequency:\n");
    for(i = 0; i < num_words; i++) {
        int is_duplicate = 0;
        for(j = 0; j < i; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                is_duplicate = 1;
                break;
            }
        }
        if(!is_duplicate) {
            printf("%s: %d\n", words[i], word_freq[i]);
        }
    }

    return 0;
}