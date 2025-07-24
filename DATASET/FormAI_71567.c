//FormAI DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 500

int main()
{
    char text[MAX_SENTENCES][MAX_SENTENCE_LENGTH]; //2D array to store sentences
    int freq[MAX_SENTENCES]; //array to store frequency of sentences
    char summary[MAX_SENTENCES][MAX_SENTENCE_LENGTH*2]; //2D array to store summary
    
    int total_sentences = 0;
    
    //reading text from user
    printf("Enter the text: \n");
    while(total_sentences < MAX_SENTENCES && fgets(text[total_sentences], MAX_SENTENCE_LENGTH, stdin) != NULL)
    {
        total_sentences++;
    }
    
    //converting all uppercase to lowercase
    for(int i = 0; i<total_sentences; i++)
    {
        for(int j = 0; j<strlen(text[i]); j++)
        {
            text[i][j] = tolower(text[i][j]);
        }
    }
    
    //counting frequency of each sentence
    for(int i = 0; i<total_sentences; i++)
    {
        freq[i] = 1;
        for(int j = i+1; j<total_sentences; j++)
        {
            if(strcmp(text[i], text[j]) == 0)
            {
                freq[i]++;
                text[j][0] = '\0'; //marking same sentences as blank
            }
        }
    }
    
    //creating summary by selecting sentences with highest frequency
    int sent_count = 0;
    for(int i = 0; i<total_sentences; i++)
    {
        if(text[i][0] != '\0')
        {
            strcpy(summary[sent_count], text[i]); //copying sentence to summary
            sent_count++;
        }
        if(sent_count >= 3) //summary contains 3 sentences only
        {
            break;
        }
    }
    
    //printing summary
    printf("\nSummary:\n");
    for(int i = 0; i<sent_count; i++)
    {
        printf("%s", summary[i]);
    }
    
    return 0;
}