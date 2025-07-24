//FormAI DATASET v1.0 Category: Text Summarizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_SENTENCE_LENGTH 1000

typedef struct sentence{
    char text[MAX_SENTENCE_LENGTH + 1];
    int score;
} Sentence;

int sentence_filter(char *sentence);
int word_filter(char *word);
void initialize_sentences(Sentence *sentences, int n_sentences);
void score_sentences(Sentence *sentences, int n_sentences, char *text);
void print_summary(Sentence *sentences, int n_sentences);

int main(int argc, char **argv) {
    char text[MAX_SENTENCES * MAX_SENTENCE_LENGTH + 1];
    int n_sentences = 0;
    Sentence sentences[MAX_SENTENCES];
    memset(text, 0, sizeof(text));
    memset(sentences, 0, sizeof(sentences));
    // Read input text from user
    printf("Enter text: \n");
    fgets(text, sizeof(text), stdin);
    // Remove new line character from input text
    text[strcspn(text, "\n")] = '\0';
    // Split input text into sentences
    char *p = strtok(text, ".!?");
    while (p != NULL && n_sentences < MAX_SENTENCES) {
        if (sentence_filter(p)) {
            // Filter sentence if it contains inappropriate words
            strcpy(sentences[n_sentences].text, p);
            n_sentences++;
        }
        p = strtok(NULL, ".!?");
    }
    // Initialize sentence scores to zero
    initialize_sentences(sentences, n_sentences);
    // Score each sentence
    score_sentences(sentences, n_sentences, text);
    // Print summary of top 3 sentences
    print_summary(sentences, n_sentences);
    return 0;
}

int sentence_filter(char *sentence) {
    // Filter sentence if it contains inappropriate words
    char *p = strtok(sentence, " ,;!?");
    while (p != NULL) {
        if (word_filter(p)) {
            return 0;
        }
        p = strtok(NULL, " ,;!?");
    }
    return 1;
}

int word_filter(char *word) {
    // Filter word if it is inappropriate
    char *inappropriate_words[] = {"bad", "wrong", "hate"};
    int n_words = sizeof(inappropriate_words) / sizeof(inappropriate_words[0]);
    for (int i = 0; i < n_words; i++) {
        if (strcmp(word, inappropriate_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void initialize_sentences(Sentence *sentences, int n_sentences) {
    // Initialize sentence scores to zero
    for (int i = 0; i < n_sentences; i++) {
        sentences[i].score = 0;
    }
}

void score_sentences(Sentence *sentences, int n_sentences, char *text) {
    // Score each sentence based on the number of times it appears in the text
    char *temp_text = strdup(text);
    char *p = strtok(temp_text, ".!?");
    while (p != NULL && n_sentences < MAX_SENTENCES) {
        for (int i = 0; i < n_sentences; i++) {
            if (strstr(sentences[i].text, p) != NULL) {
                sentences[i].score++;
            }
        }
        p = strtok(NULL, ".!?");
    }
    free(temp_text);
}

void print_summary(Sentence *sentences, int n_sentences) {
    // Print summary of top 3 sentences
    printf("Summary:\n");
    for (int i = 0; i < 3 && i < n_sentences; i++) {
        int max_index = 0;
        for (int j = 1; j < n_sentences; j++) {
            if (sentences[j].score > sentences[max_index].score) {
                max_index = j;
            }
        }
        printf("%d. %s\n", i + 1, sentences[max_index].text);
        sentences[max_index].score = -1;
    }
}