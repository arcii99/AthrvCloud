//FormAI DATASET v1.0 Category: Text Summarizer ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000
#define SUMMARY_LENGTH 100

char *summarize(char *text) {
    char *summary = (char*)malloc(sizeof(char) * SUMMARY_LENGTH);
    char *buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE);
    int i, j, k, length = strlen(text), count = 0, sentence_count = 0;
    double sentence_score[length];
    memset(sentence_score, 0, sizeof(sentence_score));

    for (i=0; i<length; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentence_count++;
        }
    }

    for (i=0; i<SUMMARY_LENGTH && count<length && sentence_count>0; i++) {
        double max_score = 0;
        int max_index = 0;
        k = 0;

        for (j=0; j<length; j++) {
            if (text[j] == '.' || text[j] == '?' || text[j] == '!') {
                sentence_score[k] /= (double)(j+1);
                if (sentence_score[k] > max_score) {
                    max_score = sentence_score[k];
                    max_index = k;
                }
                k++;
            }
            else {
                sentence_score[k] += (double)(text[j]);
                count++;
            }
        }

        sentence_count--;
        strncpy(buffer, &text[max_index], strlen(&text[max_index]) - strlen(strchr(&text[max_index], '.')) + 1);
        buffer[strlen(&text[max_index]) - strlen(strchr(&text[max_index], '.')) + 1] = '\0';
        strcat(summary, buffer);
        memset(buffer, '\0', BUFFER_SIZE);
    }

    free(buffer);
    return summary;
}

int main() {
    char *text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus in condimentum ante. Vivamus condimentum bibendum faucibus. Maecenas sed posuere leo, nec lacinia erat. Sed pellentesque nunc ut risus fringilla elementum. Nunc euismod, lorem vitae consequat blandit, nulla neque gravida lorem, ac iaculis dui augue eu lectus. Sed at sapien massa. Sed porta varius lacus, quis sollicitudin velit aliquam sed. Sed ut sagittis velit. Phasellus efficitur non justo sed aliquam. Nam consequat at nisl a molestie. Sed eu tortor mauris.";

    printf("%s", summarize(text));
    return 0;
}