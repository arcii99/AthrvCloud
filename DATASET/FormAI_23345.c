//FormAI DATASET v1.0 Category: Text Summarizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 50
#define MAX_SUMMARY_LEN 200

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
    double score;
} WordFrequency;

int compare_word_frequency(const void* a, const void* b) {
    WordFrequency* f1 = (WordFrequency*)a;
    WordFrequency* f2 = (WordFrequency*)b;
    return (f2->score - f1->score) * 1000; // Higher scores first
}

int count_sentences(const char* text) {
    int count = 0;
    for (const char* p = text; *p != '\0'; p++) {
        if (*p == '.' || *p == '?' || *p == '!') {
            count++;
        }
    }
    return count;
}

void summarize_text(const char* text, char* summary) {
    int num_sentences = count_sentences(text);
    if (num_sentences == 0) {
        return;
    }
    WordFrequency* freqs = (WordFrequency*)malloc(sizeof(WordFrequency) * num_sentences * 20);
    int num_words = 0;
    const char* word_start = NULL;
    bool sentence_start = true;
    for (const char* p = text; *p != '\0'; p++) {
        if (*p == '.' || *p == '?' || *p == '!') {
            if (sentence_start) {
                // Empty sentence
                continue;
            }
            if (word_start != NULL) {
                // End of last word in sentence
                int len = p - word_start;
                if (len <= MAX_WORD_LEN) {
                    char word[MAX_WORD_LEN + 1];
                    strncpy(word, word_start, len);
                    word[len] = '\0';
                    bool found = false;
                    for (int i = 0; i < num_words; i++) {
                        if (strcmp(freqs[i].word, word) == 0) {
                            freqs[i].count++;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        strncpy(freqs[num_words].word, word, len);
                        freqs[num_words].word[len] = '\0';
                        freqs[num_words].count = 1;
                        num_words++;
                    }
                }
            }
            sentence_start = true;
        } else if (isalpha(*p)) {
            if (sentence_start) {
                sentence_start = false;
                word_start = p;
            }
        } else {
            sentence_start = false;
        }
    }
    // Compute word scores
    for (int i = 0; i < num_words; i++) {
        freqs[i].score = (double)freqs[i].count / (double)num_sentences;
    }
    // Sort words by score
    qsort(freqs, num_words, sizeof(WordFrequency), compare_word_frequency);
    // Build summary
    int len = 0;
    for (int i = 0; i < num_words && len < MAX_SUMMARY_LEN; i++) {
        if (freqs[i].score > 0.0) {
            int word_len = strlen(freqs[i].word);
            if (len + word_len + 1 <= MAX_SUMMARY_LEN) {
                if (len > 0) {
                    summary[len++] = ' ';
                }
                strncpy(summary + len, freqs[i].word, word_len);
                len += word_len;
            } else {
                break;
            }
        }
    }
    summary[len] = '\0';
    free(freqs);
}

int main() {
    const char* text = "The quick brown fox jumps over the lazy dog. "
                       "The quick brown fox jumps over the lazy dog! "
                       "The quick brown fox jumps over the lazy dog? "
                       "This is a sentence. This is another sentence. "
                       "This is a very very very very very very very very very long sentence. ";
    char summary[MAX_SUMMARY_LEN + 1];
    summarize_text(text, summary);
    printf("Text summary: %s\n", summary);
    return 0;
}