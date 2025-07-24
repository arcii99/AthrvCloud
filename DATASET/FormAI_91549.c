//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SENTENCES 10000
#define MAX_SUMMARY_SIZE 500

void tokenize_sentences(char *text, char **sentences);
void tokenize_words(char *sentence, char **words);
int count_words(char *sentence);
int is_sentence_ending(char ch);
void summarize_text(char *text);

int main()
{
    char text[5000] = "This morning I woke up feeling great. I had a healthy breakfast and went to the gym. During my workout, I realized how much better I feel when I exercise. After the gym, I came home and started working on some projects. I was feeling productive and energized. Then, my boss called me and said I had to work overtime tonight. I was really surprised and a little disappointed. But, I know that hard work pays off in the end.";

    printf("Input Text:\n%s\n\n", text);

    summarize_text(text);

    return 0;
}

void tokenize_sentences(char *text, char **sentences)
{
    int i = 0, j = 0, k = 0;

    while(text[i] != '\0')
    {
        if(is_sentence_ending(text[i]))
        {
            sentences[j][k] = '\0';
            k = 0;
            j++;
        }
        else
        {
            sentences[j][k] = text[i];
            k++;
        }

        i++;
    }

    sentences[j][k] = '\0';
    sentences[j+1] = NULL;
}

void tokenize_words(char *sentence, char **words)
{
    int i = 0, j = 0, k = 0;

    while(sentence[i] != '\0')
    {
        if(sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\n')
        {
            words[j][k] = '\0';
            k = 0;
            j++;
        }
        else
        {
            words[j][k] = sentence[i];
            k++;
        }

        i++;
    }

    words[j][k] = '\0';
    words[j+1] = NULL;
}

int count_words(char *sentence)
{
    int count = 0, i = 0;

    while(sentence[i] != '\0')
    {
        if(sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\n')
        {
            count++;
        }

        i++;
    }

    return count+1;
}

int is_sentence_ending(char ch)
{
    if(ch == '.' || ch == '?' || ch == '!')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void summarize_text(char *text)
{
    char *sentences[MAX_SENTENCES];
    char *words[MAX_SENTENCES];
    int i = 0, total_words = 0, summary_size = 0;

    for(i=0;i<MAX_SENTENCES;i++)
    {
        sentences[i] = (char*)malloc(sizeof(char)*500);
    }

    tokenize_sentences(text, sentences);

    for(i=0;i<MAX_SENTENCES;i++)
    {
        words[i] = (char*)malloc(sizeof(char)*50);
    }

    i = 0;

    while(sentences[i] != NULL)
    {
        total_words += count_words(sentences[i]);
        tokenize_words(sentences[i], words);
        i++;
    }

    summary_size = total_words/10;

    if(summary_size <= 0)
    {
        summary_size = 1;
    }
    else if(summary_size > MAX_SUMMARY_SIZE)
    {
        summary_size = MAX_SUMMARY_SIZE;
    }

    printf("Summary:\n");

    i = 0;
    while(sentences[i] != NULL && i<summary_size)
    {
        printf("%s ", sentences[i]);
        i++;
    }
}