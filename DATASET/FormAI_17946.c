//FormAI DATASET v1.0 Category: Text Summarizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50  // maximum length of a word
#define MAX_SENT_LEN 1000  // maximum length of a sentence
#define MAX_SUMM_LEN 500  // maximum length of the summary

void summarize(char* text, char* summary, int num_sentences){
    char* words[MAX_SENT_LEN / 2];  // array of pointers to each word
    int sentence_lengths[MAX_SENT_LEN / 2];  // array of sentence lengths
    char* sentences[MAX_SENT_LEN / 2];  // array of pointers to each sentence
    int num_words = 0;
    int num_sentences_found = 0;
    int num_chars = 0;
    int i, j;

    // Separate words and count total number of characters
    char* word = strtok(text, " ");
    while (word != NULL && num_words < MAX_SENT_LEN / 2) {
        words[num_words] = word;
        num_chars += strlen(word) + 1;
        word = strtok(NULL, " ");
        num_words++;
    }

    // Determine sentence boundaries and count sentence lengths
    int prev_word_end = 0;
    for (i = 0; i < num_words && num_sentences_found < MAX_SENT_LEN / 2; i++) {
        if (words[i][strlen(words[i]) - 1] == '.' || words[i][strlen(words[i]) - 1] == '?' || words[i][strlen(words[i]) - 1] == '!') {
            sentence_lengths[num_sentences_found] = i - prev_word_end + 1;
            prev_word_end = i + 1;
            num_sentences_found++;
        }
    }

    // Determine which sentences to include in the summary
    int sentence_scores[MAX_SENT_LEN / 2];
    memset(sentence_scores, 0, num_sentences_found * sizeof(int));

    for (i = 0; i < num_sentences_found; i++) {
        for (j = 0; j < sentence_lengths[i]; j++) {
            sentence_scores[i] += strlen(words[j + prev_word_end - sentence_lengths[i]]) + 1;
        }
    }

    for (i = 0; i < num_sentences && i < num_sentences_found; i++) {
        int max_score = 0;
        int max_index = 0;
        for (j = 0; j < num_sentences_found; j++) {
            if (sentence_scores[j] > max_score) {
                max_score = sentence_scores[j];
                max_index = j;
            }
        }
        sentences[i] = words + prev_word_end - sentence_lengths[max_index];
        sentence_scores[max_index] = 0;
    }
    sprintf(summary, "");
    for (i = 0; i < num_sentences && i < num_sentences_found; i++) {
        strcat(summary, sentences[i]);
        if (i != num_sentences - 1 && i != num_sentences_found - 1) strcat(summary, " ");
    }
}

int main() {
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris elementum mattis urna, vel convallis lacus mollis eu. Aliquam suscipit tellus malesuada eros feugiat scelerisque. Praesent ullamcorper, nibh vitae gravida rutrum, velit quam semper quam, eu convallis arcu purus ac ante. Sed eget lorem vitae elit tempor hendrerit. Phasellus euismod elit sit amet augue volutpat tempus. Suspendisse in lacus vel dui semper ultricies vitae id lacus. Cras in sem nec turpis porttitor commodo sit amet sed libero. Donec sodales, velit vel lobortis pulvinar, nunc lacus interdum dui, sit amet mollis ex ante nec augue.";
    char summary[MAX_SUMM_LEN];
    int num_sentences = 2;
    summarize(text, summary, num_sentences);
    printf("%s", summary);
    return 0;
}