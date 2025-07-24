//FormAI DATASET v1.0 Category: Text Summarizer ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCES 10
#define MAX_SUMMARY_LEN 100

int main() {
    char text[1000], summary[MAX_SUMMARY_LEN];
    char *sentences[MAX_SENTENCES], *p;
    int sentence_count = 0, i;
    float sentence_scores[MAX_SENTENCES] = {0};

    // get input text from user
    printf("Enter text to summarize:\n");
    fgets(text, sizeof(text), stdin);

    // split text into sentences and store in array
    p = strtok(text, ".?!"); // split text where a period, question mark or exclamation mark occurs
    while (p != NULL && sentence_count < MAX_SENTENCES) {
        sentences[sentence_count++] = p;
        p = strtok(NULL, ".?!");
    }

    // rate each sentence by counting number of keywords found
    char *keywords[] = {"the", "of", "and", "to", "in", "that", "is", "for", "it", "with", "was", "as", "on", "not", "by", "be", "which", "or", "from", "at", "have", "an", "but", "also", "this", "their", "they", "been", "has", "were"};
    for (i = 0; i < sentence_count; i++) {
        int keywords_found = 0;
        p = strtok(sentences[i], " ");
        while (p != NULL) {
            // check if word is a keyword
            int j, match = 0;
            for (j = 0; j < sizeof(keywords)/sizeof(keywords[0]); j++) {
                if (strcmp(p, keywords[j]) == 0) {
                    match = 1;
                    break;
                }
            }
            if (match) keywords_found++;
            p = strtok(NULL, " ");
        }
        sentence_scores[i] = (float)keywords_found / strlen(sentences[i]);
    }

    // select top sentences to include in summary
    float max_score;
    int max_index;
    for (i = 0; i < MAX_SUMMARY_LEN && i < sentence_count; i++) {
        max_score = 0;
        for (int j = 0; j < sentence_count; j++) {
            if (sentence_scores[j] > max_score) {
                max_score = sentence_scores[j];
                max_index = j;
            }
        }
        strcat(summary, sentences[max_index]);
        strcat(summary, ". ");
        sentence_scores[max_index] = 0; // mark sentence as used
    }

    // print summary
    printf("Summary:\n%s", summary);

    return 0;
}