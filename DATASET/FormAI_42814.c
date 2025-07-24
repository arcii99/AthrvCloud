//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_SENTENCE_LEN 1000
#define SUMMARY_LENGTH 5

char* get_sentence(char* text, int start_index);
int count_words(char* sentence);
float calculate_sentence_score(char* sentence, char** keywords, int num_keywords);

int main() {
    char* text = "The quick brown fox jumps over the lazy dog. "
                 "The quick brown fox is known for it's speed and agility. "
                 "The lazy dog likes to sleep all day. "
                 "The quick brown fox is a predator. "
                 "The brown fox and the lazy dog have nothing in common. "
                 "Foxes are native to many regions around the world. "
                 "Dogs are domesticated animals that were originally wolves.";

    char* keywords[] = { "fox", "dog", "lazy", "predator", "agility", "speed" };
    int num_keywords = sizeof(keywords)/sizeof(keywords[0]);

    char* sentences[MAX_SENTENCES];
    int num_sentences = 0;

    // Split the text into sentences and store them in an array
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentences[num_sentences] = get_sentence(text, i);
            num_sentences++;
        }
    }

    // Calculate the score of each sentence and store them in an array
    float sentence_scores[num_sentences];
    for (int i = 0; i < num_sentences; i++) {
        sentence_scores[i] = calculate_sentence_score(sentences[i], keywords, num_keywords);
    }

    // Sort the sentences by score (highest to lowest)
    for (int i = 0; i < num_sentences - 1; i++) {
        for (int j = i + 1; j < num_sentences; j++) {
            if (sentence_scores[j] > sentence_scores[i]) {
                float temp_score = sentence_scores[i];
                sentence_scores[i] = sentence_scores[j];
                sentence_scores[j] = temp_score;

                char* temp_sentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp_sentence;
            }
        }
    }

    // Print the summary (first SUMMARY_LENGTH sentences with highest scores)
    printf("Summary:\n");
    for (int i = 0; i < SUMMARY_LENGTH; i++) {
        printf("%s\n", sentences[i]);
    }

    // Free memory
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }
}

// Helper function to get a sentence from the text
char* get_sentence(char* text, int start_index) {
    char* sentence = malloc(MAX_SENTENCE_LEN);
    int sentence_length = 0;
    for (int i = start_index; i >= 0; i--) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            i++;  // Start at the first character of the sentence
            break;
        }
    }
    for (int i = start_index; i < strlen(text) && sentence_length < MAX_SENTENCE_LEN - 1; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            break;
        }
        sentence[sentence_length] = text[i];
        sentence_length++;
    }
    sentence[sentence_length] = '\0';
    return sentence;
}

// Helper function to count the number of words in a sentence
int count_words(char* sentence) {
    int count = 0;
    char* temp = strtok(sentence, " ");
    while (temp != NULL) {
        count++;
        temp = strtok(NULL, " ");
    }
    return count;
}

// Helper function to calculate the score of a sentence based on the appearance of certain keywords
float calculate_sentence_score(char* sentence, char** keywords, int num_keywords) {
    float score = 0;
    char* copy = strdup(sentence);
    char* token = strtok(copy, " ");
    while (token != NULL) {
        for (int i = 0; i < num_keywords; i++) {
            if (strcmp(token, keywords[i]) == 0) {
                score += 1.0 / (float)count_words(sentence);
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    free(copy);
    return score;
}