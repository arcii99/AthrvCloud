//FormAI DATASET v1.0 Category: Text Summarizer ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 10000 // Maximum length of input text
#define MAX_SUMMARY_LEN 100 // Maximum length of summary text

// Function prototype
void text_summarizer(char *text, char *summary);

int main()
{
    char input_text[MAX_LEN];
    char summary_text[MAX_SUMMARY_LEN];

    printf("Enter the input text: ");
    fgets(input_text, MAX_LEN, stdin);

    text_summarizer(input_text, summary_text);

    printf("\nSummary:\n%s\n", summary_text);

    return 0;
}

// Function to summarize the input text
void text_summarizer(char *text, char *summary)
{
    int i, count = 0;
    char *token;

    // Create an array to hold all the sentences
    char *sentences[MAX_LEN];
    memset(sentences, 0, MAX_LEN*sizeof(char*));

    // Tokenize input text into separate sentences
    token = strtok(text, ".");
    while(token != NULL)
    {
        sentences[count] = token; // Store each sentence in the array
        count++;
        token = strtok(NULL, ".");
    }

    // Create an array to hold all the sentence scores
    int scores[MAX_LEN];
    memset(scores, 0, MAX_LEN*sizeof(int));

    // Calculate scores for each sentence
    for(i = 0; i < count; i++)
    {
        int j = 0;

        // Count number of words in each sentence
        char *word = strtok(sentences[i], " ");
        while(word != NULL)
        {
            j++;
            word = strtok(NULL, " ");
        }

        // Assign score to each sentence based on word count
        scores[i] = j;

        // If sentence starts with a keyword, give it extra score
        if(i == 0 && (strstr(sentences[i], "reason") != NULL || strstr(sentences[i], "because") != NULL))
        {
            scores[i] += 3;
        }
        else if(strstr(sentences[i], "therefore") != NULL || strstr(sentences[i], "thus") != NULL)
        {
            scores[i] += 2;
        }
    }

    // Find the top 5 sentences with the highest scores
    int top_sentences[5];
    for(i = 0; i < 5; i++)
    {
        int max_score = 0;
        int max_idx = 0;

        // Find sentence with the highest score
        for(int j = 0; j < count; j++)
        {
            if(scores[j] > max_score)
            {
                max_score = scores[j];
                max_idx = j;
            }
        }

        top_sentences[i] = max_idx; // Store index of top sentence
        scores[max_idx] = 0; // Set score of top sentence to 0 to avoid selecting it again
    }

    // Combine the top sentences to form the summary
    for(i = 0; i < 5; i++)
    {
        strcat(summary, sentences[top_sentences[i]]);
        strcat(summary, ". ");
    }
}