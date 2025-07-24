//FormAI DATASET v1.0 Category: Text Summarizer ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

typedef struct summary {
    int sentence_count;
    char sentences[MAX_SENTENCES][200];
} Summary;

Summary generate_summary(char *text) {
    Summary summary = { 0, { {0} } };
    int word_i = 0;
    int sentence_i = 0;
    char *word;
    char *sentence;

    /* Split text into sentences */
    sentence = strtok(text, ".!?");
    while (sentence != NULL) {
        strcpy(summary.sentences[sentence_i++], sentence);
        summary.sentence_count++;
        sentence = strtok(NULL, ".!?");
    }

    /* Split sentences into words */
    int word_count;
    char *words[MAX_WORDS];
    for (int i = 0; i < summary.sentence_count; i++) {
        sentence = summary.sentences[i];
        word = strtok(sentence, " ");
        word_count = 0;
        while (word != NULL) {
            words[word_count++] = word;
            word = strtok(NULL, " ");
        }
        /* Replace the sentence with the top few words */
        int top_word_count = word_count / 3;
        char new_sentence[200] = { 0 };
        for (int j = 0; j < top_word_count && j < word_count; j++) {
            strcat(new_sentence, words[j]);
            strcat(new_sentence, " ");
        }
        strcat(new_sentence, "...");
        strcpy(summary.sentences[i], new_sentence);
    }

    return summary;
}

int main(int argc, char *argv[]) {
    char *text = "The quick brown fox jumped over the lazy dog. The dog ignored the tired fox, who eventually gave up and went to sleep. The end.";
    Summary summary = generate_summary(text);
    printf("Original text: \n%s\n\n", text);
    printf("Summary: \n");
    for (int i = 0; i < summary.sentence_count; i++) {
        printf("%s ", summary.sentences[i]);
    }
    printf("\n");
    return 0;
}