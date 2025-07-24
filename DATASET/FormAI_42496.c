//FormAI DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SUMMARY_LENGTH 100

struct Sentence {
    char text[MAX_SENTENCE_LENGTH];
    int score;
};

int get_word_count(char* sentence) {
    int count = 0;
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

int calculate_sentence_score(char* sentence) {
    int score = 0;
    int count = get_word_count(sentence);
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        if (strcmp(token, "the") == 0 || strcmp(token, "a") == 0 || strcmp(token, "an") == 0) {
            score += (4 - count);
        }
        if (strcmp(token, "is") == 0 || strcmp(token, "was") == 0) {
            score += (3 - count);
        }
        if (strcmp(token, "and") == 0) {
            score += (2 - count);
        }
        token = strtok(NULL, " ");
    }
    return score;
}

void summarize_text(char* text) {
    struct Sentence sentences[MAX_SENTENCE_LENGTH];
    int sentence_count = 0;
    char* token = strtok(text, ".");
    while (token != NULL) {
        strcpy(sentences[sentence_count].text, token);
        sentences[sentence_count].score = calculate_sentence_score(token);
        sentence_count++;
        token = strtok(NULL, ".");
    }
    int summary_count = 0;
    char* summary[MAX_SUMMARY_LENGTH];
    while (summary_count < 3 && sentence_count > 0) {
        int max_score = -1;
        int max_index = -1;
        for (int i = 0; i < sentence_count; i++) {
            if (sentences[i].score > max_score) {
                max_score = sentences[i].score;
                max_index = i;
            }
        }
        summary[summary_count] = sentences[max_index].text;
        sentences[max_index].score = -1;
        summary_count++;
        sentence_count--;
    }
    for (int i = 0; i < summary_count; i++) {
        printf("%s. ", summary[i]);
    }
}

int main() {
    char text[] = "On a bright sunny day, a dog chased a ball in the park. The ball was blue and the dog was brown. The children watched and cheered as the dog managed to catch the ball and bring it back to its owner. The owner praised the dog for a job well done.";
    summarize_text(text);
    return 0;
}