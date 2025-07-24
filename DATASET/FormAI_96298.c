//FormAI DATASET v1.0 Category: Text Summarizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DOC_LENGTH 2000
#define MAX_SUMMARY_LENGTH 500
#define MAX_SENTENCE_LENGTH 100

char *remove_punctuation(char *text) {
    int len = strlen(text);
    char *clean_text = malloc(len + 1);
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (!ispunct(text[i]) || text[i] == '.' || text[i] == ',' || text[i] == '?') {
            clean_text[j++] = text[i];
        }
    }
    clean_text[j] = '\0';

    return clean_text;
}

int count_sentences(char *text) {
    int sentence_count = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.') {
            sentence_count++;
        }
    }

    return sentence_count;
}

float score_sentence(char *sentence, char *keywords) {
    char *clean_sentence = remove_punctuation(sentence);
    char *word = strtok(keywords, " ");
    int keyword_count = 0;

    while (word != NULL) {
        if (strstr(clean_sentence, word)) {
            keyword_count++;
        }
        word = strtok(NULL, " ");
    }

    free(clean_sentence);

    return (float) keyword_count / (float) count_sentences(sentence);
}

char *get_summary(char *doc, char *keywords) {
    char *clean_doc = remove_punctuation(doc);
    char *sentence = strtok(clean_doc, ".");
    float sentence_scores[MAX_DOC_LENGTH];
    int sentence_count = 0;
    char *summary = malloc(MAX_SUMMARY_LENGTH);
    strcpy(summary, "");

    while (sentence != NULL) {
        sentence_scores[sentence_count] = score_sentence(sentence, keywords);
        sentence_count++;
        sentence = strtok(NULL, ".");
    }

    for (int i = 0; i < MAX_SUMMARY_LENGTH / MAX_SENTENCE_LENGTH; i++) {
        float max_score = 0.0;
        int max_score_index = 0;

        for (int j = 0; j < sentence_count; j++) {
            if (sentence_scores[j] > max_score) {
                max_score = sentence_scores[j];
                max_score_index = j;
            }
        }

        char *temp_sentence = strtok(doc, ".");
        for (int k = 0; k < max_score_index; k++) {
            temp_sentence = strtok(NULL, ".");
        }

        strcat(summary, temp_sentence);
        strcat(summary, ". ");
        sentence_scores[max_score_index] = 0.0;
    }

    free(clean_doc);

    return summary;
}

int main() {
    char document[MAX_DOC_LENGTH] = "The quick brown fox jumps over the lazy dog. This is a sample document which can be used to test the summarizer. It contains several different sentences and punctuation marks, including question marks and commas. The purpose of the summarizer is to produce a summary of this document based on a set of keywords provided by the user.";
    char keywords[] = " summarizer document keywords ";

    char *summary = get_summary(document, keywords);

    printf("%s\n", summary);

    free(summary);

    return 0;
}