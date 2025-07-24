//FormAI DATASET v1.0 Category: Text Summarizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_SENTENCE_LEN 200

char *summarize(char *text, int max_sentences);

int main() {
    char *text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed scelerisque posuere mauris, sit amet varius sem luctus sed. Nullam lectus velit, vehicula mattis finibus nec, iaculis ac dui. Nam felis risus, bibendum eu arcu ut, pharetra ullamcorper purus. Quisque quis elit et justo cursus molestie ut et diam. Sed rhoncus, libero eget vulputate dignissim, elit tellus tincidunt orci, ut vulputate arcu libero vel elit. Morbi vitae erat metus. Curabitur malesuada tincidunt erat. Ut consectetur leo id ligula dapibus viverra. Duis euismod pellentesque leo sed aliquam. Aliquam eget dolor eu lorem tincidunt molestie sit amet nec metus. Nam convallis ante in enim finibus, id aliquam libero facilisis. Donec eget mauris ut neque egestas bibendum. Vivamus semper pretium dolor, eget feugiat mauris mattis sit amet. Nulla facilisi.";

    char *summary = summarize(text, 3);
    printf("%s\n", summary);

    free(summary);
    return 0;
}

char *summarize(char *text, int max_sentences) {
    char *sentences[MAX_SENTENCES];
    int num_sentences = 0;

    // split the text into sentences
    char *delim = ".?!";
    char *sentence = strtok(text, delim);
    while (sentence != NULL && num_sentences < MAX_SENTENCES) {
        sentences[num_sentences++] = sentence;
        sentence = strtok(NULL, delim);
    }

    // create an array of sentence scores
    int scores[MAX_SENTENCES] = {0};
    for (int i = 0; i < num_sentences; i++) {
        for (int j = 0; j < num_sentences; j++) {
            if (i == j) {
                continue;
            }

            int overlap = 0;
            char *word = strtok(sentences[i], " ");
            while (word != NULL) {
                if (strstr(sentences[j], word) != NULL) {
                    overlap++;
                }
                word = strtok(NULL, " ");
            }

            scores[i] += overlap;
        }
    }

    // sort the sentences by score
    for (int i = 0; i < num_sentences - 1; i++) {
        for (int j = i + 1; j < num_sentences; j++) {
            if (scores[i] < scores[j]) {
                int temp_score = scores[i];
                scores[i] = scores[j];
                scores[j] = temp_score;

                char *temp_sentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp_sentence;
            }
        }
    }

    // concatenate the top max_sentences sentences from the sorted array
    char *summary = malloc(MAX_SENTENCE_LEN * max_sentences + 1);
    summary[0] = '\0';
    for (int i = 0; i < max_sentences; i++) {
        strcat(summary, sentences[i]);
        strcat(summary, ". ");
    }

    return summary;
}