//FormAI DATASET v1.0 Category: Text Summarizer ; Style: invasive
#include <stdio.h>
#include <string.h>

void summarize(char* originalText);

int main()
{
    char originalText[500];

    printf("Enter the text to summarize:\n");
    fgets(originalText, 500, stdin);

    summarize(originalText);

    return 0;
}

void summarize(char* originalText)
{
    char* sentence;
    char sentences[50][500];
    int i, j, sentencesCount = 0;
    int sentenceSentenceCount[50] = {0};
    char* word;
    char words[500][30];
    int wordsCount = 0;
    int sentenceWordCount[50] = {0};
    float sentenceScore[50] = {0.0};

    // divide original text into sentences
    sentence = strtok(originalText, ".!?\n");
    while (sentence != NULL)
    {
        strcpy(sentences[sentencesCount++], sentence);
        sentence = strtok(NULL, ".!?\n");
    }

    // divide each sentence into words
    for (i = 0; i < sentencesCount; i++)
    {
        word = strtok(sentences[i], " \n");
        while (word != NULL)
        {
            strcpy(words[wordsCount++], word);
            word = strtok(NULL, " \n");
        }
    }

    // count the number of words in each sentence
    for (i = 0; i < sentencesCount; i++)
    {
        for (j = 0; j < wordsCount; j++)
        {
            if (strstr(sentences[i], words[j]) != NULL)
            {
                sentenceWordCount[i]++;
            }
        }
    }

    // count the number of sentences containing each word
    for (i = 0; i < wordsCount; i++)
    {
        for (j = 0; j < sentencesCount; j++)
        {
            if (strstr(sentences[j], words[i]) != NULL)
            {
                sentenceSentenceCount[j]++;
            }
        }
    }

    // calculate score for each sentence
    for (i = 0; i < sentencesCount; i++)
    {
        for (j = 0; j < wordsCount; j++)
        {
            if (strstr(sentences[i], words[j]) != NULL)
            {
                sentenceScore[i] += 1.0 / sentenceSentenceCount[i];
            }
        }
        sentenceScore[i] *= (float)sentenceWordCount[i] / wordsCount;
    }

    // output the most important sentence
    int mostImportant = 0;
    for (i = 1; i < sentencesCount; i++)
    {
        if (sentenceScore[i] > sentenceScore[mostImportant])
        {
            mostImportant = i;
        }
    }
    printf("The summary is: %s\n", sentences[mostImportant]);
}