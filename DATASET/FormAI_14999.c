//FormAI DATASET v1.0 Category: Text Summarizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 500

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int score;
} Sentence;

void summarize_text(char *text) {
    
    int num_sentences = 0, i, j;
    char **sentences = malloc(MAX_SENTENCES * sizeof(char*));
    Sentence *scored_sentences = malloc(MAX_SENTENCES * sizeof(Sentence));
    char *token;
    
    // Split the text into individual sentences
    token = strtok(text, ".!?");
    
    while (token != NULL && num_sentences < MAX_SENTENCES) {
        sentences[num_sentences] = token;
        num_sentences++;

        token = strtok(NULL, ".!?");
    }

    // Score each sentence based on the number of keywords it contains
    const char *keywords[] = {"computer", "programming", "technology", "algorithm", "data"};
    int num_keywords = 5;

    for (i = 0; i < num_sentences; i++) {
        scored_sentences[i].score = 0;
        
        for (j = 0; j < num_keywords; j++) {
            if (strstr(sentences[i], keywords[j]) != NULL) {
                scored_sentences[i].score++;
            }
        }

        strcpy(scored_sentences[i].sentence, sentences[i]);
    }

    // Sort the sentences by score in descending order
    Sentence temp;

    for (i = 0; i < num_sentences - 1; i++) {
        for (j = i + 1; j < num_sentences; j++) {
            if (scored_sentences[j].score > scored_sentences[i].score) {
                temp = scored_sentences[j];
                scored_sentences[j] = scored_sentences[i];
                scored_sentences[i] = temp;
            }
        }
    }

    // Print the top 3 scored sentences
    int num_printed = 0;

    for (i = 0; i < num_sentences && num_printed < 3; i++) {
        if (strlen(scored_sentences[i].sentence) > 1) {
            printf("%s. ", scored_sentences[i].sentence);
            num_printed++;
        }
    }

    // Free memory
    for (i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }

    free(sentences);
    free(scored_sentences);
}

int main() {
    char text[] = "Computer programming is the process of designing and building an executable computer program to accomplish a specific computing result or to perform a specific task. Programming involves tasks such as analysis, generating algorithms, profiling algorithms' accuracy and resource consumption, and the implementation of algorithms in a chosen programming language (commonly referred to as coding). The source code of a program is written in one or more languages that are intelligible to programmers, rather than machine code, which is directly executed by the central processing unit. The purpose of programming is to find a sequence of instructions that will automate the performance of a task for solving a given problem.";

    summarize_text(text);
    
    return 0;
}