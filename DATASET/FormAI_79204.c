//FormAI DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to remove punctuation from a string
void remove_punctuations(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (ispunct(str[i])) {
            i++;
        } else {
            str[j++] = str[i++];
        }
    }
    str[j] = '\0';
}

int main() {
    char text[10000];
    printf("Enter the text to be summarized:\n");
    fgets(text, 10000, stdin);

    // remove newline characters from the input
    char *pos;
    if ((pos = strchr(text, '\n')) != NULL) {
        *pos = '\0';
    }

    // remove punctuation from the text
    remove_punctuations(text);

    // count the number of characters in the input
    int text_len = strlen(text);

    // determine the length of each sentence
    int sentence_len[text_len];
    int sentence_count = 0;
    int len = 0;
    for (int i = 0; i < text_len; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentence_len[sentence_count++] = len;
            len = 0;
        } else {
            len++;
        }
    }

    // determine the average length of a sentence
    float avg_len = 0;
    for (int i = 0; i < sentence_count; i++) {
        avg_len += sentence_len[i];
    }
    avg_len /= sentence_count;

    // determine the sentences that should be included in the summary
    int summary_sentences[sentence_count];
    int summary_count = 0;
    for (int i = 0; i < sentence_count; i++) {
        if (sentence_len[i] > avg_len * 1.5) {
            summary_sentences[summary_count++] = i;
        }
    }

    // print the summary
    printf("Summary:\n");
    int start = 0;
    for (int i = 0; i < summary_count; i++) {
        for (int j = start; j < sentence_count; j++) {
            if (j == summary_sentences[i]) {
                int end = j;
                while (text[end] != '.' && text[end] != '?' && text[end] != '!') {
                    end++;
                }
                char summary[end - start + 2];
                strncpy(summary, &text[start], end - start + 1);
                summary[end - start + 1] = '\0';
                printf("%s ", summary);
                start = j + 1;
                break;
            }
        }
    }

    return 0;
}