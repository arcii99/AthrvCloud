//FormAI DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>
#include <string.h>
#define MAX_SENTENCES 1000
#define MAX_LENGTH 1000

char *summarize(char *article, int num_sentences) {
    char *sentences[MAX_SENTENCES];
    char *sentence;
    char *token;
    char *delim = ".?!";
    int sentence_count = 0;
    int i, j, k;

    // Tokenize the article into sentences
    sentence = strtok(article, delim); // Get the first sentence
    while (sentence != NULL && sentence_count < MAX_SENTENCES) {
        sentences[sentence_count++] = sentence; // Add the sentence to the array
        sentence = strtok(NULL, delim); // Get the next sentence
    }

    // Sort the sentences by length
    char *temp;
    for (i = 0; i < sentence_count-1; i++) {
        for (j = i+1; j < sentence_count; j++) {
            if (strlen(sentences[i]) > strlen(sentences[j])) {
                temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }

    // Concatenate the selected sentences into the summary
    char *summary = (char*) calloc(MAX_LENGTH, sizeof(char));
    for (i = 0; i < num_sentences; i++) {
        strcat(summary, sentences[i]);
        if (i < num_sentences-1) strcat(summary, " ");
    }

    return summary;
}

int main() {
    char article[MAX_LENGTH] = "A computer program is a collection of instructions that can be executed by a computer to perform a specific task. Some computer programs take a long time to run, particularly if they are processing a large amount of data. This is where text summarization comes in handy. Text summarization is the process of shortening a piece of text while preserving the most important information. There are two main types of text summarization: extractive and abstractive. Extractive summarization involves selecting the most important sentences from the original text and concatenating them together to form a summary. Abstractive summarization involves creating a summary that is not just a collection of sentences from the original text, but rather a new summary that captures the key information in the original text.";

    char *summary = summarize(article, 4); // Summarize the article into 4 sentences
    printf("%s", summary);

    return 0;
}