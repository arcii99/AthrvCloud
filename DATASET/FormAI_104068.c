//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct sentence {
    char text[MAX_SENTENCE_LENGTH];
    int word_count;
} Sentence;

void count_words(Sentence *s) {
    int count = 0;
    char *token = strtok(s->text, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    s->word_count = count;
}

int main() {
    Sentence sentences[MAX_SENTENCES];
    int sentence_count = 0;

    char *document = "The quick brown fox jumps over the lazy dog. The lazy dog barked loudly. The quick brown fox didn't seem to care.";
    
    char *token = strtok(document, ".");
    while (token != NULL) {
        Sentence *s = &sentences[sentence_count];
        strcpy(s->text, token);
        count_words(s);
        sentence_count++;
        token = strtok(NULL, ".");
    }

    // Sort sentences by word count in ascending order.
    for (int i = 0; i < sentence_count - 1; i++) {
        for (int j = i + 1; j < sentence_count; j++) {
            if (sentences[j].word_count < sentences[i].word_count) {
                Sentence temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }

    // Print summary by selecting the shortest and longest sentences.
    printf("Summary:\n");
    printf("%s\n", sentences[0].text);
    printf("%s\n", sentences[sentence_count - 1].text);

    return 0;
}