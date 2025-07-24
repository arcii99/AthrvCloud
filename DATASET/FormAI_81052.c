//FormAI DATASET v1.0 Category: Text Summarizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_SUMMARY 200

void remove_punctuations(char *string)
{
    char punctuations[] = " .,!?:;";
    for(int i = 0; i < strlen(punctuations); i++)
    {
        for(int j = 0; j < strlen(string); j++)
        {
            if(string[j] == punctuations[i])
            {
                string[j] = ' ';
            }
        }
    }
}

void to_lowercase(char *string)
{
    for(int i = 0; i < strlen(string); i++)
    {
        if(string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = string[i] + ('a' - 'A');
        }
    }
}

int main()
{
    char input_string[10000];
    char sentences[MAX_SENTENCES][1000];
    char summary[MAX_SUMMARY][100];
    int sentence_lengths[MAX_SENTENCES] = {0};
    int summary_length = 0;
    printf("Enter text to be summarized:\n");
    fgets(input_string, 10000, stdin);
    input_string[strcspn(input_string, "\n")] = '\0';

    // Remove punctuations and convert input to lowercase
    remove_punctuations(input_string);
    to_lowercase(input_string);

    // Tokenize input into sentences
    char *token;
    token = strtok(input_string, ".");
    int sentence_count = 0;
    while(token != NULL)
    {
        strcpy(sentences[sentence_count], token);
        sentence_lengths[sentence_count] = strlen(sentences[sentence_count]);
        sentence_count++;
        token = strtok(NULL, ".");
    }

    // Determine summary length
    int i = 0;
    while(summary_length < MAX_SUMMARY && i < sentence_count)
    {
        if(sentence_lengths[i] > 0 && sentence_lengths[i] <= 50)
        {
            strncpy(summary[summary_length], sentences[i], sentence_lengths[i]);
            summary_length++;
        }
        i++;
    }

    // Print summary
    printf("\n------------------------------------------------\n");
    printf("SUMMARY: ");
    for(int i = 0; i < summary_length; i++)
    {
        printf("%s. ", summary[i]);
    }
    printf("\n------------------------------------------------\n");

    return 0;
}