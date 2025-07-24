//FormAI DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_SUMMARY_SIZE 250

int main()
{
    char article[1000];
    char summary[MAX_SUMMARY_SIZE] = "";
    char *sentences[MAX_SENTENCES];
    int sentence_count = 0;

    // Get the article input from the user
    printf("Enter the article: ");
    fgets(article, sizeof(article), stdin);

    // Tokenize the article into sentences and store them in the sentences array
    char *token = strtok(article, ".\n");
    while (token != NULL && sentence_count < MAX_SENTENCES)
    {
        sentences[sentence_count++] = token;
        token = strtok(NULL, ".\n");
    }

    // Calculate the scores of each sentence
    int scores[MAX_SENTENCES] = {0};
    for (int i = 0; i < sentence_count; i++)
    {
        char *sentence = sentences[i];
        char *word = strtok(sentence, " ");
        while (word != NULL)
        {
            if (strstr("the a an and or but", word) == NULL)
            {
                scores[i]++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Get the top 5 sentences with the highest score
    int top_indexes[5] = {-1, -1, -1, -1, -1};
    for (int i = 0; i < 5; i++)
    {
        int max_score = -1;
        int max_index = -1;
        for (int j = 0; j < sentence_count; j++)
        {
            if (scores[j] > max_score && !contains(top_indexes, 5, j))
            {
                max_score = scores[j];
                max_index = j;
            }
        }
        top_indexes[i] = max_index;
    }

    // Sort the top sentences by their original order in the article
    sort(top_indexes, 5);
    
    // Concatenate the top sentences to form the summary
    for (int i = 0; i < 5; i++)
    {
        int index = top_indexes[i];
        char sentence[100];
        strcpy(sentence, sentences[index]);

        if (strlen(summary) + strlen(sentence) < MAX_SUMMARY_SIZE)
        {
            strcat(summary, sentence);
            strcat(summary, ".");
        }
    }

    // Display the summary
    printf("Summary: %s\n", summary);

    return 0;
}

// Helper function to check if an array contains a value
int contains(int *array, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            return 1;
        }
    }
    return 0;
}

// Helper function to sort an array of integers in ascending order
void sort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}