//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_INPUT_SIZE 10000
#define MAX_OUTPUT_SIZE 1000
#define MAX_SUMMARY_SIZE 300

char input[MAX_STRING_LENGTH], output[MAX_STRING_LENGTH], summary[MAX_SUMMARY_SIZE], *summarized_text;

int main()
{
    int i, j, k, input_length, output_length, summary_length;

    //Get user input
    printf("Enter the text to summarize:\n");
    scanf("%[^\n]%*c", input);

    //Remove extra spaces and convert to lowercase
    input_length = strlen(input);
    for (i = 0, j = 0; i < input_length; i++)
    {
        if ((input[i] != ' ' && input[i] != '\t') || (i > 0 && input[i-1] != ' ' && input[i-1] != '\t'))
        {
            output[j++] = tolower(input[i]);
        }
    }
    output[j] = '\0';
    output_length = strlen(output);
    
    //Create array of sentences
    int num_sentences = 0;
    char *sentences[MAX_INPUT_SIZE];
    char *pch = strtok(output, ".?!");

    while (pch != NULL)
    {
        sentences[num_sentences++] = pch;
        pch = strtok(NULL, ".?!");
    }
    
    //Calculate frequency of each word
    int num_words = 0;
    char *words[MAX_INPUT_SIZE];
    int frequency[MAX_INPUT_SIZE] = {0};
    pch = strtok(output, " ,.-");
    
    while (pch != NULL)
    {
        words[num_words++] = pch;
        pch = strtok(NULL, " ,.-");
    }
    
    for (i = 0; i < num_words; i++)
    {
        for (j = 0; j < num_words; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                frequency[i]++;
            }
        }
    }
    
    //Select the most important sentences based on word frequency
    int num_selected_sentences = 0;
    int selected_sentences[MAX_OUTPUT_SIZE];
    for (i = 0; i < output_length; i++)
    {
        if (output[i] == '.' || output[i] == '?' || output[i] == '!')
        {
            selected_sentences[num_selected_sentences] = i + 1;
            num_selected_sentences++;
        }
    }
     
    for (i = 0; i < num_selected_sentences; i++)
    {
        summary[summary_length++] = '\n';
        for (j = selected_sentences[i-1]; j < selected_sentences[i]; j++)
        {
            summary[summary_length++] = input[j];
        }
    }
    
    summarized_text = (char *) malloc(MAX_SUMMARY_SIZE * sizeof(char));
    strcpy(summarized_text, summary);
    printf("The summarized text is: %s\n", summarized_text);

    return 0;
}