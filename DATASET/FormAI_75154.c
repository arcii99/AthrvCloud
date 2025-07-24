//FormAI DATASET v1.0 Category: Text Summarizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SENTENCES 5
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    float score;
} Sentence;

int main() {
    /* Collect input text */
    char input_text[1000];
    printf("Please enter the text you would like to summarize:\n");
    fgets(input_text, 1000, stdin);

    /* Split input text into individual sentences */
    char* sentence_ptrs[NUM_SENTENCES];
    int sentence_lengths[NUM_SENTENCES];
    int num_sentences = 0;
    char* sentence_start = &input_text[0];
    for (int i = 0; i < strlen(input_text); i++) {
        if (input_text[i] == '.' || input_text[i] == '?' || input_text[i] == '!') {
            input_text[i] = '\0';
            sentence_ptrs[num_sentences] = sentence_start;
            sentence_lengths[num_sentences] = i - (sentence_start - input_text) + 1;
            sentence_start = &input_text[i+1];
            num_sentences++;
        }
    }

    /* Score each sentence based on length and common words */
    Sentence sentences[NUM_SENTENCES];
    int common_word_count;
    for (int i = 0; i < num_sentences; i++) {
        common_word_count = 0;
        for (int j = 0; j < sentence_lengths[i]; j++) {
            if (sentence_ptrs[i][j] == 't' && sentence_ptrs[i][j+1] == 'h' && sentence_ptrs[i][j+2] == 'e') {
                common_word_count++;
            }
        }
        sentences[i].score = (float) common_word_count / (float) sentence_lengths[i];
        strncpy(sentences[i].sentence, sentence_ptrs[i], sentence_lengths[i]);
    }

    /* Sort sentences by score */
    Sentence temp_sentence;
    for (int i = 0; i < num_sentences - 1; i++) {
        for (int j = i+1; j < num_sentences; j++) {
            if (sentences[i].score < sentences[j].score) {
                temp_sentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp_sentence;
            }
        }
    }

    /* Print top 3 sentences */
    printf("\nHere is your summarized text:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s", sentences[i].sentence);
    }

    return 0;
}