//FormAI DATASET v1.0 Category: Text Summarizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 1000

int count_words(char *sentence);
char **get_sentences(char *text);
void remove_punctuations(char *text);
char *get_summary(char *text);

int main()
{
    char text[5000];

    // getting input from the user
    printf("Enter the text:\n");
    fgets(text, 5000, stdin);

    // removing punctuations and converting to lowercase
    remove_punctuations(text);

    // getting sentences from the text
    char **sentences = get_sentences(text);

    // getting the number of sentences
    int num_sentences = 0;
    while (sentences[num_sentences])
        num_sentences++;

    // getting words from the input
    char *words[MAX_WORDS];
    int num_words = 0;

    // looping through each sentence
    for (int i = 0; i < num_sentences; i++)
    {
        char *sentence = sentences[i];

        // counting the number of words in the sentence
        int sentence_word_count = count_words(sentence);

        // adding the words to the words array
        for (int j = 0; j < sentence_word_count; j++)
        {
            // allocating memory to store the word
            char *word = malloc(strlen(sentence) * sizeof(char));

            // copying the word to the allocated memory
            strcpy(word, strtok(j == 0 ? sentence : NULL, " "));

            // adding the word to the words array
            words[num_words++] = word;
        }
    }

    // creating a frequency table
    int frequency[num_words];
    memset(frequency, 0, sizeof(frequency));
    for (int i = 0; i < num_words; i++)
    {
        for (int j = 0; j < num_words; j++)
        {
            // comparing with case-insensitivity
            if (strcasecmp(words[i], words[j]) == 0)
                frequency[i]++;
        }
    }

    // finding the most frequent words
    int max_frequency = 0;
    for (int i = 0; i < num_words; i++)
    {
        if (frequency[i] > max_frequency)
            max_frequency = frequency[i];
    }

    char *summary = get_summary(text);
    printf("Summary:\n%s\n", summary);

    // freeing memory
    for (int i = 0; i < num_words; i++)
    {
        free(words[i]);
    }
    for (int i = 0; i < num_sentences; i++)
    {
        free(sentences[i]);
    }
    free(summary);

    return 0;
}

/**
 * Counts the number of words in the given sentence
 */
int count_words(char *sentence)
{
    int count = 0;

    // counting the number of spaces
    for (int i = 0; i < strlen(sentence); i++)
    {
        if (isspace(sentence[i]))
            count++;
    }

    return count + 1;
}

/**
 * Returns an array of sentences from the given text
 */
char **get_sentences(char *text)
{
    char **sentences = malloc(MAX_SENTENCES * sizeof(char *));
    memset(sentences, 0, MAX_SENTENCES * sizeof(char *));
    int index = 0;

    char *sentence = strtok(text, ".!?\n");
    while (sentence != NULL && index < MAX_SENTENCES)
    {
        // allocating memory to store the sentence
        char *new_sentence = malloc(strlen(sentence) * sizeof(char));
        strcpy(new_sentence, sentence);

        // adding the sentence to the sentences array
        sentences[index++] = new_sentence;

        // getting the next sentence
        sentence = strtok(NULL, ".!?\n");
    }

    return sentences;
}

/**
 * Removes all punctuations from the given text and converts to lowercase
 */
void remove_punctuations(char *text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (ispunct(text[i]))
            text[i] = ' ';
        else
            text[i] = tolower(text[i]);
    }
}

/**
 * Returns a summary of the given text
 */
char *get_summary(char *text)
{
    // getting sentences from the text
    char **sentences = get_sentences(text);

    // getting the number of sentences
    int num_sentences = 0;
    while (sentences[num_sentences])
        num_sentences++;

    // creating a frequency table for the sentences
    int sentence_frequency[num_sentences];
    memset(sentence_frequency, 0, sizeof(sentence_frequency));
    for (int i = 0; i < num_sentences; i++)
    {
        char *sentence = sentences[i];
        int num_words = count_words(sentence);

        // counting the frequency of each word in the sentence
        for (int j = 0; j < num_words; j++)
        {
            char *word = strtok(j == 0 ? sentence : NULL, " ");
            for (int k = 0; k < num_sentences; k++)
            {
                if (k != i && strstr(sentences[k], word) != NULL)
                {
                    sentence_frequency[i]++;
                    break;
                }
            }
        }
    }

    // creating the summary
    char *summary = malloc(500 * sizeof(char));
    memset(summary, 0, 500 * sizeof(char));
    int summary_length = 0;
    int max_frequency = 0;
    for (int i = 0; i < num_sentences; i++)
    {
        if (sentence_frequency[i] > max_frequency)
            max_frequency = sentence_frequency[i];
    }
    for (int i = 0; i < num_sentences; i++)
    {
        if (sentence_frequency[i] == max_frequency && summary_length < 500)
        {
            strcat(summary, sentences[i]);
            summary_length += strlen(sentences[i]);
            strcat(summary, ". ");
            summary_length += 2;
        }
    }

    // freeing memory
    for (int i = 0; i < num_sentences; i++)
    {
        free(sentences[i]);
    }
    free(sentences);

    return summary;
}