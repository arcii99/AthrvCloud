//FormAI DATASET v1.0 Category: Text Summarizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_SENTENCE_LENGTH 1000
#define SUMMARY_LENGTH 500

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int frequency;
} Sentence;

void generate_summary(char* text) {
    // Step 1: Split the text into sentences and tokenize each sentence
    char* sentences[MAX_SENTENCES];
    char* tokens[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int sentence_count = 0;
    char* sentence = strtok(text, ".!?");

    while (sentence != NULL) {
        sentences[sentence_count] = sentence;
        char* token;
        int token_count = 0;
        token = strtok(sentence, " ");
        while (token != NULL) {
            tokens[sentence_count][token_count] = token;
            token_count++;
            token = strtok(NULL, " ");
        }
        sentence_count++;
        sentence = strtok(NULL, ".!?");
    }

    // Step 2: Calculate the frequency of each word across all sentences
    int word_frequency[MAX_SENTENCES][MAX_SENTENCE_LENGTH] = {0};
    int word_count = 0;
    int sentence_index, token_index;

    for (sentence_index = 0; sentence_index < sentence_count; sentence_index++) {
        for (token_index = 0; tokens[sentence_index][token_index] != NULL; token_index++) {
            int word_already_counted = 0;
            int i;
            for (i = 0; i < word_count; i++) {
                if (strcmp(tokens[sentence_index][token_index], tokens[0][i]) == 0) {
                    word_frequency[sentence_index][i]++;
                    word_already_counted = 1;
                }
            }
            if (word_already_counted == 0) {
                strcpy(tokens[0][word_count], tokens[sentence_index][token_index]);
                word_frequency[sentence_index][word_count] = 1;
                word_count++;
            }
        }
    }

    // Step 3: Create a Sentence struct for each sentence
    Sentence sentence_array[MAX_SENTENCES];
    int i, j;
    for (i = 0; i < sentence_count; i++) {
        sentence_array[i].frequency = 0;
        for (j = 0; j < word_count; j++) {
            sentence_array[i].frequency += word_frequency[i][j];
        }
        strcpy(sentence_array[i].sentence, sentences[i]);
    }

    // Step 4: Sort the Sentence array in descending order of frequency
    int sorted = 0;
    while (sorted == 0) {
        sorted = 1;
        for (i = 0; i < sentence_count - 1; i++) {
            if (sentence_array[i+1].frequency > sentence_array[i].frequency) {
                Sentence temp = sentence_array[i];
                sentence_array[i] = sentence_array[i+1];
                sentence_array[i+1] = temp;
                sorted = 0;
            }
        }
    }

    // Step 5: Generate the summary
    char summary[SUMMARY_LENGTH] = "";
    int summary_length = 0;
    for (i = 0; i < sentence_count; i++) {
        if (summary_length + strlen(sentence_array[i].sentence) <= SUMMARY_LENGTH) {
            strcat(summary, sentence_array[i].sentence);
            strcat(summary, ". ");
            summary_length += strlen(sentence_array[i].sentence) + 2;
        } else {
            break;
        }
    }

    printf("Summary: %s\n", summary);
}

int main() {
    char text[] = "John was born in the small town of Clearwater. He lived there until he was 18, when he moved to the city to attend college. After graduation, he started working for a large corporation. He quickly climbed the ranks and became the CEO after only 5 years. Despite his success, John often felt unfulfilled, so he quit his job and started a non-profit organization. He now spends his time helping others and couldn't be happier.";

    generate_summary(text);

    return 0;
}