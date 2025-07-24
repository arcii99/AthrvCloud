//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char text[1000]; // declare the text array
    printf("Enter text to summarize: ");
    fgets(text,1000,stdin); // get input from user
    
    // implement the summarization algorithm
    char* summary = strtok(text,"."); // break the text into sentences
    printf("Summary: ");
    while(summary != NULL)
    {
        printf("%s. ",summary); // print each sentence with a period
        summary = strtok(NULL,"."); // move to next sentence
    }

    return 0; // program end
}