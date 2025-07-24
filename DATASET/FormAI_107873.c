//FormAI DATASET v1.0 Category: Text Summarizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_LENGTH 1000

typedef struct {
    char sentence[MAX_LENGTH];
    int score;
} Sentence;

int main(void) {

    // Read in the input text
    char input_text[MAX_SENTENCES][MAX_LENGTH];
    int sentence_count = 0;

    printf("Enter the text you want to summarize:\n");
    while (1) {
        fgets(input_text[sentence_count], MAX_LENGTH, stdin);
        if (input_text[sentence_count][0] == '\n') {
            break;
        }
        sentence_count++;
    }

    // Tokenize the sentences and count word frequency
    char* words[MAX_SENTENCES][MAX_LENGTH];
    int word_count = 0;
    int word_frequency[MAX_SENTENCES][MAX_LENGTH] = {0};

    for (int i = 0; i < sentence_count; i++) {
        char* token = strtok(input_text[i], " \n");

        while (token != NULL) {
            int j;
            for (j = 0; j < word_count; j++) {
                if (strcmp(token, words[j][0]) == 0) {
                    word_frequency[i][j]++;
                    break;
                }
            }
            if (j == word_count) {
                strcpy(words[word_count][0], token);
                word_frequency[i][word_count]++;
                word_count++;
            }
            token = strtok(NULL, " \n");
        }
    }

    // Calculate sentence scores
    Sentence sentences[sentence_count];

    for (int i = 0; i < sentence_count; i++) {
        sentences[i].score = 0;

        char* token = strtok(input_text[i], " \n");

        while (token != NULL) {
            for (int j = 0; j < word_count; j++) {
                if (strcmp(token, words[j][0]) == 0) {
                    sentences[i].score += word_frequency[i][j];
                    break;
                }
            }
            token = strtok(NULL, " \n");
        }

        strcpy(sentences[i].sentence, input_text[i]);
    }

    // Sort sentences by score
    for (int i = 0; i < sentence_count - 1; i++) {
        for (int j = i + 1; j < sentence_count; j++) {
            if (sentences[i].score < sentences[j].score) {
                Sentence temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }

    // Print the top 5 sentences
    printf("Summary:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s", sentences[i].sentence);
    }

    return 0;
}