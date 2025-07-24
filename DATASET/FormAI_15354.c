//FormAI DATASET v1.0 Category: Text Summarizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 1000      // Maximum number of characters allowed in a sentence.
#define MAX_SENTENCES 100   // Maximum number of sentences allowed in a text.
#define MAX_SUMMARY 5       // Maximum number of sentences allowed in the summary.

char text[MAX_CHARS * MAX_SENTENCES];    // Holder for the entire text.
char sentences[MAX_SENTENCES][MAX_CHARS];    // Holder for individual sentences.
int sentence_count = 0;     // Number of sentences in the text.

// Function to break down the text into individual sentences.
void break_sentences(char text[]) {
    int i, j = 0, len = strlen(text);
    for (i = 0; i < len; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentences[sentence_count][j] = text[i];
            sentences[sentence_count][++j] = '\0';
            sentence_count++;
            j = 0;
        } else {
            sentences[sentence_count][j] = text[i];
            j++;
        }
    }
}

// Function to calculate the frequency of each word in the text.
void get_word_frequency(char* word, int* frequency) {
    int i, j;
    for (i = 0; i < sentence_count; i++) {
        for (j = 0; j < strlen(sentences[i]); j++) {
            if (isalpha(sentences[i][j])) {
                int k = 0;
                while (isalpha(sentences[i][j+k])) {
                    word[k] = tolower(sentences[i][j+k]);
                    k++;
                }
                word[k] = '\0';
                if (strlen(word) > 0) {
                    frequency[i]++;
                }
                j += k;
            }
        }
    }
}

// Function to find the most frequent word in the text.
void get_key_word(char* key, int* frequency) {
    int max_frequency = 0;
    for (int i = 0; i < sentence_count; i++) {
        if (frequency[i] > max_frequency) {
            max_frequency = frequency[i];
            strcpy(key, sentences[i]);
        }
    }
}

// Function to generate the summary of the text based on the key sentence.
void generate_summary(char* key, char summary[][MAX_CHARS]) {
    int i, j = 0, count = 0;
    for (i = 0; i < sentence_count; i++) {
        if (strstr(sentences[i], key) != NULL && count < MAX_SUMMARY) {
            strcpy(summary[j], sentences[i]);
            j++;
            count++;
        }
    }
}

int main() {
    char word[MAX_CHARS];
    int frequency[MAX_SENTENCES] = {0};
    char key[MAX_CHARS];
    char summary[MAX_SUMMARY][MAX_CHARS];
    FILE *file;

    file = fopen("sample.txt", "r");
    if (file) {
        char line[MAX_CHARS];
        while (fgets(line, sizeof(line), file)) {
            strcat(text, line);
        }
        fclose(file);
    }

    break_sentences(text);

    get_word_frequency(word, frequency);

    get_key_word(key, frequency);

    generate_summary(key, summary);

    printf("Summary:\n");
    for (int i = 0; i < MAX_SUMMARY; i++) {
        printf("%s", summary[i]);
    }

    return 0;
}