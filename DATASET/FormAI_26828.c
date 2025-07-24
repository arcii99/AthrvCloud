//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_LENGTH 200
#define MAX_WORDS_IN_SENTENCE 20

typedef struct Sentence
{
    char *words[MAX_WORDS_IN_SENTENCE];  
    int num_words;  
} Sentence;

typedef struct Summary
{
    Sentence sentences[MAX_SENTENCES];  
    int num_sentences;  
} Summary;

void remove_punctuation(char *string)  
{
    char *p = string;
    while (*p != '\0')
    {
        if (!isalnum(*p) && *p != ' ')
        {
            memmove(p, p + 1, strlen(p));
        }
        else
        {
            p++;
        }
    }
}

void remove_spaces(char *string)  
{
    char *p = string;
    while (*p != '\0')
    {
        if (*p == ' ' && *(p + 1) == ' ')
        {
            memmove(p, p + 1, strlen(p));
        }
        else
        {
            p++;
        }
    }
}

int count_words(char *string)  
{
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

void tokenize_sentence(char *sentence_str, Sentence *sentence)
{
    char *word = strtok(sentence_str, " ");
    sentence->num_words = 0;
    while (word != NULL && sentence->num_words <= MAX_WORDS_IN_SENTENCE)
    {
        sentence->words[sentence->num_words] = word;
        sentence->num_words++;
        word = strtok(NULL, " ");
    }
}

void parse_sentences(char *text, Summary *summary)  
{
    char *sentence_str = strtok(text, ".");  
    summary->num_sentences = 0;  
    while (sentence_str != NULL && summary->num_sentences <= MAX_SENTENCES)
    {
        tokenize_sentence(sentence_str, &summary->sentences[summary->num_sentences]);
        summary->num_sentences++;

        sentence_str = strtok(NULL, ".");  
    }
}

void summarize(char *text, char *summary_buffer, int max_summary_length)
{
    Summary summary;
    parse_sentences(text, &summary);

    summary_buffer[0] = '\0';  
    int summary_length = 0;

    for (int i = 0; i < summary.num_sentences; i++)
    {
        for (int j = 0; j < summary.sentences[i].num_words; j++)
        {
            strncat(summary_buffer, summary.sentences[i].words[j], max_summary_length - summary_length - 1);
            summary_length += strlen(summary.sentences[i].words[j]);
            strncat(summary_buffer, " ", max_summary_length - summary_length - 1);
            summary_length++;
        }
        strncat(summary_buffer, ".", max_summary_length - summary_length - 1);
        summary_length++;

        if (summary_length >= max_summary_length)
            break;
    }
}

int main()
{
    char text[] = "This is a sample text. It contains multiple sentences. Some of these sentences are long while others are short.";

    char summary_buffer[MAX_LENGTH];
    summarize(text, summary_buffer, MAX_LENGTH);

    printf("Original text:\n%s\n\n", text);
    printf("Summary:\n%s\n", summary_buffer);

    return 0;
}