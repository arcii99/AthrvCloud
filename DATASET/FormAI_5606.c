//FormAI DATASET v1.0 Category: Spam Detection System ; Style: asynchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000 // Maximum number of lines of text to analyze
#define MAX_LINE_LENGTH 100 // Maximum length of each line of text
#define THRESHOLD 0.7 // Minimum score required for text to be considered spam

typedef struct {
    int num_words;
    char** words;
} Line;

int num_lines = 0;
Line lines[MAX_LINES];

bool is_spam(char* line) {
    if (strlen(line) <= 1) return false; // Ignore empty lines
    char* word = strtok(line, " ");
    int spam_count = 0, total_words = 0;
    while (word != NULL) {
        for (int i = 0; i < num_lines; i++) {
            for (int j = 0; j < lines[i].num_words; j++) {
                if (strcmp(word, lines[i].words[j]) == 0) {
                    spam_count++;
                }
            }
        }
        total_words++;
        word = strtok(NULL, " ");
    }
    float score = (float)spam_count / total_words;
    return score >= THRESHOLD;
}

void add_line(char* line) {
    if (num_lines >= MAX_LINES) return; // Ignore lines that exceed maximum limit
    lines[num_lines].num_words = 0;
    lines[num_lines].words = malloc(MAX_LINE_LENGTH * sizeof(char*));
    char* word = strtok(line, " ");
    while (word != NULL) {
        lines[num_lines].words[lines[num_lines].num_words++] = word;
        word = strtok(NULL, " ");
    }
    num_lines++;
}

int main() {
    printf("Enter spam keywords (one per line, empty line to stop):\n");
    char keyword[MAX_LINE_LENGTH];
    while (fgets(keyword, MAX_LINE_LENGTH, stdin)) {
        if (strlen(keyword) <= 1) break; // Stop reading input on empty line
        add_line(keyword);
    }
    printf("Enter text to analyze (one line at a time, empty line to stop):\n");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        if (strlen(line) <= 1) break; // Stop reading input on empty line
        if (is_spam(line)) {
            printf("SPAM Detected: %s", line);
        } else {
            printf("Not spam: %s", line);
        }
    }
    return 0;
}