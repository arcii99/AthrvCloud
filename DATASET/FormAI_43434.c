//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 10000
#define MAX_SENTENCES 1000
#define MAX_SUMMARY_SIZE 1000

int main(int argc, char const *argv[]) 
{
    printf("Initializing CyberText Summarizer v.21.16...\n");

    char input_text[MAX_INPUT_SIZE] = "";
    char summary[MAX_SUMMARY_SIZE] = "";
    char sentences[MAX_SENTENCES][MAX_INPUT_SIZE];
    int scores[MAX_SENTENCES] = {0};
    int num_sentences = 0;
    int summary_length = 0;
    int i,j;

    printf("Enter text to summarize:");

    //get user input and remove newline character
    fgets(input_text, MAX_INPUT_SIZE, stdin);
    input_text[strcspn(input_text, "\n")] = '\0';

    //parse input text into sentences
    char *token = strtok(input_text, ".");
    while(token != NULL)
    {
        strcpy(sentences[num_sentences], token);
        num_sentences++;
        token = strtok(NULL, ".");
    }

    //apply scoring algorithm to each sentence
    for(i = 0; i < num_sentences; i++)
    {
        char *word = strtok(sentences[i], " ");
        while(word != NULL)
        {
            if(strcmp(word, "cyber") == 0 || strcmp(word, "punk") == 0)
            {
                scores[i]++;
            }
            word = strtok(NULL, " ");
        }
    }

    //generate summary using sentences with the highest scores
    for(i = 0; i < num_sentences; i++)
    {
        for(j = i+1; j < num_sentences; j++)
        {
            if(scores[j] > scores[i])
            {
                int temp_score = scores[i];
                scores[i] = scores[j];
                scores[j] = temp_score;

                char temp_sentence[MAX_INPUT_SIZE];
                strcpy(temp_sentence, sentences[i]);
                strcpy(sentences[i], sentences[j]);
                strcpy(sentences[j], temp_sentence);
            }
        }
    }

    for(i = 0; i < num_sentences; i++)
    {
        if(summary_length + strlen(sentences[i]) < MAX_SUMMARY_SIZE)
        {
            strcat(summary, sentences[i]);
            strcat(summary, ".");
            summary_length += strlen(sentences[i]) + 1;
        }
        else
        {
            break;
        }
    }

    printf("\nCyberText Summary:\n");
    printf("%s", summary);

    return 0;
}