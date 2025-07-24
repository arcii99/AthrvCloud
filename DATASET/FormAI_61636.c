//FormAI DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 50

void generate_summary(char text[]) {

    // Remove punctuations from the text
    for(int i = 0; text[i]; i++) {
        if(ispunct(text[i])) {
            text[i] = ' ';
        }
    }

    // Split the text into sentences
    char sentences[100][100];
    int sentence_count = 0;
    char* sentence = strtok(text, ".!?");

    while(sentence != NULL) {
        strcpy(sentences[sentence_count], sentence);
        sentence = strtok(NULL, ".!?");
        sentence_count++;
    }

    // Calculate the importance score for each sentence
    int importance_scores[sentence_count];
    for(int i = 0; i < sentence_count; i++) {
        importance_scores[i] = 0;

        for(int j = 0; j < strlen(sentences[i]); j++) {
            importance_scores[i] += (int) sentences[i][j];
        }
    }

    // Generate the summary
    int summary_length = 0;
    char summary[MAX_SUMMARY_LENGTH] = "";

    while(summary_length < MAX_SUMMARY_LENGTH && sentence_count > 0) {
        int max_score_index = 0;

        for(int i = 0; i < sentence_count; i++) {
            if(importance_scores[i] > importance_scores[max_score_index]) {
                max_score_index = i;
            }
        }

        int sentence_length = strlen(sentences[max_score_index]);
        if(summary_length + sentence_length < MAX_SUMMARY_LENGTH) {
            strcat(summary, sentences[max_score_index]);
            strcat(summary, ". ");
            summary_length += sentence_length + 2;
        }

        importance_scores[max_score_index] = 0;
        sentence_count--;
    }

    // Print the summary
    printf("\nSummary: %s\n", summary);
}

int main() {

    // Get the text from the user
    char text[1000];
    printf("Please enter the text you want to summarize: \n");
    fgets(text, sizeof(text), stdin);

    // Generate the summary
    generate_summary(text);

    return 0;
}