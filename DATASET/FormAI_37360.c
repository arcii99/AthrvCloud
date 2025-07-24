//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOC_LEN 1000
#define MAX_SUMMARY_LEN 200

void summarize(char *document, char *summary, int max_summary_len);

int main()
{
    char document[MAX_DOC_LEN];
    char summary[MAX_SUMMARY_LEN];

    printf("Enter the document to be summarized:\n");
    fgets(document, MAX_DOC_LEN, stdin);

    summarize(document, summary, MAX_SUMMARY_LEN);

    printf("Summary:\n%s\n", summary);

    return 0;
}

void summarize(char *document, char *summary, int max_summary_len)
{
    int num_sentences = 0;
    char *sentence = strtok(document, ".");
    while (sentence != NULL) {
        num_sentences++;
        sentence = strtok(NULL, ".");
    }

    if (num_sentences == 0) {
        strcpy(summary, "No sentences found in document");
        return;
    }

    int sentence_scores[num_sentences];
    memset(sentence_scores, 0, num_sentences * sizeof(int));

    char *word = strtok(document, " ");
    while (word != NULL) {
        for (int i = 0; i < num_sentences; i++) {
            if (strstr(document + i*strlen(sentence), word) != NULL) {
                sentence_scores[i]++;
            }
        }
        word = strtok(NULL, " ");
    }

    int max_score = 0;
    int max_score_idx = 0;
    for (int i = 0; i < num_sentences; i++) {
        if (sentence_scores[i] > max_score) {
            max_score_idx = i;
            max_score = sentence_scores[i];
        }
    }

    char *max_sentence = strtok(document + max_score_idx*strlen(sentence), ".");
    strncpy(summary, max_sentence, max_summary_len);

    if (strlen(max_sentence) >= max_summary_len - 3) {
        strcpy(summary + max_summary_len - 3, "...");
    }
}