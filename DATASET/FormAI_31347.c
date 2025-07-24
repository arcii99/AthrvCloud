//FormAI DATASET v1.0 Category: Text Summarizer ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_SENTENCES 50
#define MAX_WORDS 100

int main() {
    char input[MAX_INPUT_LENGTH];
    char sentences[MAX_SENTENCES][MAX_INPUT_LENGTH];
    char words[MAX_SENTENCES][MAX_WORDS][MAX_INPUT_LENGTH];
    int num_sentences = 0;
    int num_words[MAX_SENTENCES];

    printf("Enter text to summarize:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // parse input into sentences
    char* sentence = strtok(input, ".!?\n");
    while (sentence != NULL) {
        strcpy(sentences[num_sentences], sentence);
        num_sentences++;
        sentence = strtok(NULL, ".!?\n");
    }

    // parse sentences into words
    for (int i = 0; i < num_sentences; i++) {
        char* word = strtok(sentences[i], " \n");
        int j = 0;
        while (word != NULL) {
            strcpy(words[i][j], word);
            num_words[i]++;
            j++;
            word = strtok(NULL, " \n");
        }
    }

    // print parsed input
    printf("Parsed input:\n");
    for (int i = 0; i < num_sentences; i++) {
        for (int j = 0; j < num_words[i]; j++) {
            printf("%s ", words[i][j]);
        }
        printf("\n");
    }

    return 0;
}