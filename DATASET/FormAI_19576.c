//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUMMARY_LEN 200

/* Function to clean up text by removing non-alphanumeric characters and converting to lower case */
char *clean_text(char *text)
{
    char *cleaned_text = (char*) malloc(strlen(text) + 1);
    int i = 0, j = 0;

    while (text[i] != '\0')
    {
        if (isalnum(text[i]))
            cleaned_text[j++] = tolower(text[i]);
        i++;
    }

    cleaned_text[j] = '\0';
    return cleaned_text;
}

/* Data structure to store word frequency */
typedef struct word_freq
{
    char *word;
    int freq;
} word_freq;

/* Function to compare words by frequency for sorting */
int compare_word_freq(const void *a, const void *b)
{
    word_freq *word_a = (word_freq*) a;
    word_freq *word_b = (word_freq*) b;

    return (word_b->freq - word_a->freq);
}

/* Function to summarize text by returning the most frequent words */
char *summarize_text(char *text)
{
    char *cleaned_text = clean_text(text);
    char *word = strtok(cleaned_text, " ");
    int num_words = 0;

    /* Count the number of words and store their frequencies */
    word_freq *word_freqs = (word_freq*) malloc(sizeof(word_freq));
    while (word != NULL && num_words < MAX_SUMMARY_LEN)
    {
        int found = 0;
        for (int i = 0; i < num_words; i++)
        {
            if (strcmp(word, word_freqs[i].word) == 0)
            {
                word_freqs[i].freq++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            num_words++;
            word_freqs = (word_freq*) realloc(word_freqs, sizeof(word_freq) * num_words);
            word_freqs[num_words-1].word = (char*) malloc(strlen(word) + 1);
            strcpy(word_freqs[num_words-1].word, word);
            word_freqs[num_words-1].freq = 1;
        }
        word = strtok(NULL, " ");
    }

    /* Sort the words by frequency */
    qsort(word_freqs, num_words, sizeof(word_freq), compare_word_freq);

    /* Generate the summary by combining the top words */
    char *summary = (char*) malloc(MAX_SUMMARY_LEN + 1);
    summary[0] = '\0';
    int summary_len = 0;
    for (int i = 0; i < num_words && summary_len < MAX_SUMMARY_LEN; i++)
    {
        int length = strlen(word_freqs[i].word);
        if (summary_len + length + 1 <= MAX_SUMMARY_LEN)
        {
            strcat(summary, word_freqs[i].word);
            strcat(summary, " ");
            summary_len += length + 1;
        }
        else
        {
            break;
        }
    }

    free(cleaned_text);
    for (int i = 0; i < num_words; i++)
        free(word_freqs[i].word);
    free(word_freqs);

    return summary;
}

/* Main function to test the summarize_text function */
int main(void)
{
    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    char *summary = summarize_text(text);

    printf("Text: %s\n", text);
    printf("Summary: %s\n", summary);

    free(summary);

    return 0;
}