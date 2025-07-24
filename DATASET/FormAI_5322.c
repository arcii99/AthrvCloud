//FormAI DATASET v1.0 Category: Text Summarizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100000
#define MAX_SENTENCES 10000
#define MAX_SUMMARY_SIZE 1000

int main() {
    char input[MAX_INPUT_SIZE];
    char sentences[MAX_SENTENCES][MAX_INPUT_SIZE];
    char summary[MAX_SUMMARY_SIZE];
    int sentence_scores[MAX_SENTENCES] = {0};
    int sentence_count = 0;
    int summary_count = 0;

    // Read input from user
    printf("Enter the text to summarize:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Convert input to lowercase
    for(int i = 0; i < strlen(input); i++){
        input[i] = tolower(input[i]);
    }

    // Tokenize input into sentences
    char* token = strtok(input, ".?!:");
    while(token != NULL && sentence_count < MAX_SENTENCES){
        strcpy(sentences[sentence_count], token);
        sentence_count++;
        token = strtok(NULL, ".?!:");
    }

    // Calculate score for each sentence
    for(int i = 0; i < sentence_count; i++){
        char* word = strtok(sentences[i], " ");
        while(word != NULL){
            if(strcmp(word, "important") == 0 || strcmp(word, "essential") == 0){
                sentence_scores[i]++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Create summary of top 3 sentences
    while(summary_count < 3){
        int highest_score = -1;
        int highest_score_index = -1;
        for(int i = 0; i < sentence_count; i++){
            if(sentence_scores[i] > highest_score){
                highest_score = sentence_scores[i];
                highest_score_index = i;
            }
        }
        if(highest_score_index != -1){
            strcat(summary, sentences[highest_score_index]);
            strcat(summary, ". ");
            sentence_scores[highest_score_index] = -1;
            summary_count++;
        }
    }

    // Print summary
    printf("Summary: %s\n", summary);

    return 0;
}