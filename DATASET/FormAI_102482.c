//FormAI DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_SENTENCE_LENGTH 200
#define MAX_SUMMARY_LENGTH 500

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int frequency;
    double score;
} Sentence;

int is_sentence_end(char c) {
    return c == '.' || c == '!' || c == '?';
}

void summarize_text(char *text, char *summary) {
    // Step 1: Split text into individual sentences
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int sentence_count = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (is_sentence_end(text[i])) {
            sentences[sentence_count][i % MAX_SENTENCE_LENGTH] = text[i];
            sentence_count++;
        } else {
            sentences[sentence_count][i % MAX_SENTENCE_LENGTH] = text[i];
        }
        if (sentence_count == MAX_SENTENCES) {
            break;
        }
    }

    // Step 2: Count the frequency of words in each sentence
    Sentence sentence_stats[MAX_SENTENCES];
    for (int i = 0; i < sentence_count; i++) {
        char *token = strtok(sentences[i], " ");
        while (token != NULL) {
            int token_length = strlen(token);
            if (token[token_length - 1] == '.' || token[token_length - 1] == ',' || token[token_length - 1] == ':' || token[token_length - 1] == ';') {
                token_length--;
            }
            if (token_length > 1) {
                int found = 0;
                for (int j = 0; j < i; j++) {
                    if (strcmp(token, sentence_stats[j].sentence) == 0) {
                        found = 1;
                        sentence_stats[j].frequency++;
                        break;
                    }
                }
                if (!found) {
                    Sentence new_sentence;
                    strcpy(new_sentence.sentence, token);
                    new_sentence.frequency = 1;
                    new_sentence.score = 0;
                    sentence_stats[i] = new_sentence;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    // Step 3: Calculate the score of each sentence
    for (int i = 0; i < sentence_count; i++) {
        char *token = strtok(sentences[i], " ");
        while (token != NULL) {
            int token_length = strlen(token);
            if (token[token_length - 1] == '.' || token[token_length - 1] == ',' || token[token_length - 1] == ':' || token[token_length - 1] == ';') {
                token_length--;
            }
            if (token_length > 1) {
                for (int j = 0; j < sentence_count; j++) {
                    if (strcmp(token, sentence_stats[j].sentence) == 0) {
                        sentence_stats[i].score += sentence_stats[j].frequency;
                        break;
                    }
                }
            }
            token = strtok(NULL, " ");
        }
    }

    // Step 4: Sort sentences by score
    for (int i = 0; i < sentence_count; i++) {
        for (int j = i + 1; j < sentence_count; j++) {
            if (sentence_stats[j].score > sentence_stats[i].score) {
                Sentence temp = sentence_stats[i];
                sentence_stats[i] = sentence_stats[j];
                sentence_stats[j] = temp;
            }
        }
    }

    // Step 5: Combine sentences into a summary
    int summary_length = 0;
    for (int i = 0; i < sentence_count; i++) {
        if (summary_length + strlen(sentence_stats[i].sentence) < MAX_SUMMARY_LENGTH) {
            strcat(summary, sentence_stats[i].sentence);
            strcat(summary, " ");
            summary_length += strlen(sentence_stats[i].sentence) + 1;
        } else {
            break;
        }
    }
}

int main() {
    char text[] = "This is a sample text. It contains multiple sentences. Some sentences are longer than others. The quick brown fox jumps over the lazy dog. Jack and Jill went up the hill. They fetched a pail of water. This is the end of the sample text.";
    char summary[MAX_SUMMARY_LENGTH] = "";
    summarize_text(text, summary);
    printf("Original text:\n%s\n\n", text);
    printf("Summary:\n%s\n", summary);
    return 0;
}