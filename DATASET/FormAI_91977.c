//FormAI DATASET v1.0 Category: Text Summarizer ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCES 1000
#define MAX_SENT_LEN 1000

/* function to get the frequency of each word in the document */
void get_frequencies(char *document, int *freq)
{
    char *word = strtok(document, " ");

    while(word != NULL)
    {
        freq[strtol(word, NULL, 36)]++;
        word = strtok(NULL, " ");
    }
}

/* function to extract sentences from the document */
int extract_sentences(char *document, char sentences[][MAX_SENT_LEN])
{
    int sentences_count = 0;
    char *sentence = strtok(document, ".!?");

    while(sentence != NULL)
    {
        strcpy(sentences[sentences_count], sentence);
        sentences_count++;
        sentence = strtok(NULL, ".!?");
    }

    return sentences_count;
}

/* function to calculate the score of each sentence based on its words frequency */
void score_sentences(char sentences[][MAX_SENT_LEN], int sentences_count, int *freq, float *score)
{
    for(int i=0; i<sentences_count; i++)
    {
        char *word = strtok(sentences[i], " ");
        float s = 0;

        while(word != NULL)
        {
            s += freq[strtol(word, NULL, 36)];
            word = strtok(NULL, " ");
        }

        score[i] = s / strlen(sentences[i]);
    }
}

/* function to sort the sentences based on their score */
void sort_sentences(char sentences[][MAX_SENT_LEN], int sentences_count, float *score)
{
    for(int i=0; i<sentences_count-1; i++)
    {
        for(int j=i+1; j<sentences_count; j++)
        {
            if(score[i] < score[j])
            {
                float temp_score = score[i];
                score[i] = score[j];
                score[j] = temp_score;

                char temp_sentence[MAX_SENT_LEN];
                strcpy(temp_sentence, sentences[i]);
                strcpy(sentences[i], sentences[j]);
                strcpy(sentences[j], temp_sentence);
            }
        }
    }
}

int main()
{
    char document[] = "C is a general-purpose, procedural computer programming language. It is widely used in low-level programming, embedded systems, and system programming for its efficiency and speed. It is also used in high-level programming languages such as Python for providing extension modules. C has a relatively small language core and a large standard library, so it can be used for various purposes. The syntax of C language is derived from the B language, which was developed by Ken Thompson in 1970s.";

    int freq[MAX_SENTENCES] = {0};
    get_frequencies(document, freq);

    char sentences[MAX_SENTENCES][MAX_SENT_LEN];
    int sentences_count = extract_sentences(document, sentences);

    float score[MAX_SENTENCES];
    score_sentences(sentences, sentences_count, freq, score);

    sort_sentences(sentences, sentences_count, score);

    printf("Summary:\n\n");
    for(int i=0; i<3; i++)
    {
        printf("%s.\n", sentences[i]);
    }

    return 0;
}