//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    char text[10000]; // input text for analysis
    char *tokens[MAX_NUM_WORDS]; // array of tokenized words
    int num_tokens = 0; // number of tokens
    WordCount word_counts[MAX_NUM_WORDS]; // array of word counts
    int num_words = 0; // number of distinct words

    // get input text
    printf("Enter the text to be analyzed:\n");
    fgets(text, sizeof(text), stdin);

    // tokenize input text
    char *token = strtok(text, " .,:;!?\n\t");
    while (token != NULL && num_tokens < MAX_NUM_WORDS) {
        // normalize token by converting to lowercase
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }
        tokens[num_tokens++] = token;
        token = strtok(NULL, " .,:;!?\n\t");
    }

    // count occurrences of each distinct word
    for (int i = 0; i < num_tokens; i++) {
        int found = 0;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(tokens[i], word_counts[j].word) == 0) {
                word_counts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strncpy(word_counts[num_words].word, tokens[i], MAX_WORD_LENGTH);
            word_counts[num_words].count = 1;
            num_words++;
        }
    }

    // print results in descending order of word count
    printf("\n---Word Count Results---\n");
    for (int i = 0; i < num_words; i++) {
        int max = i;
        for (int j = i + 1; j < num_words; j++) {
            if (word_counts[j].count > word_counts[max].count) {
                max = j;
            }
        }
        WordCount temp = word_counts[i];
        word_counts[i] = word_counts[max];
        word_counts[max] = temp;
        printf("%s:\t%d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}