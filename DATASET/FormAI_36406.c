//FormAI DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define MAX_SENTENCES 100

int main()
{
    char text[MAX_LEN];
    char sentences[MAX_SENTENCES][MAX_LEN];
    int sentence_lengths[MAX_SENTENCES];
    int num_sentences = 0;

    // prompt user for input text
    printf("Enter the text to be summarized: ");
    fgets(text, MAX_LEN, stdin);

    // split text into sentences and count sentence lengths
    char* sentence = strtok(text, ".!?");
    while (sentence != NULL && num_sentences < MAX_SENTENCES) {
        strcpy(sentences[num_sentences], sentence);
        sentence_lengths[num_sentences] = strlen(sentence);
        num_sentences++;

        sentence = strtok(NULL, ".!?");
    }

    // determine summary length based on number of sentences
    int summary_length;
    if (num_sentences < 5) {
        summary_length = num_sentences;
    } else {
        summary_length = num_sentences / 2;
    }

    // sort sentences by length (shortest to longest)
    for (int i = 0; i < num_sentences - 1; i++) {
        for (int j = i + 1; j < num_sentences; j++) {
            if (sentence_lengths[i] > sentence_lengths[j]) {
                char temp[MAX_LEN];
                strcpy(temp, sentences[i]);
                strcpy(sentences[i], sentences[j]);
                strcpy(sentences[j], temp);

                int temp_length = sentence_lengths[i];
                sentence_lengths[i] = sentence_lengths[j];
                sentence_lengths[j] = temp_length;
            }
        }
    }

    // output summary
    printf("Summary:\n");
    for (int i = 0; i < summary_length; i++) {
        printf("%d. %s.\n", i+1, sentences[i]);
    }

    return 0;
}