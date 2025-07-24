//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 1000 // maximum length of summary

void summarize(char *input, int len);

int main()
{
    char input[MAX_LEN];
    int len;

    printf("Enter text to be summarized:\n");
    fgets(input, MAX_LEN, stdin);

    len = strlen(input);

    if(input[len-1]=='\n') {
        input[len-1]='\0';
    }

    summarize(input, len); // call summarize function

    return 0;
}

void summarize(char *input, int len)
{
    char summary[MAX_LEN];
    char stringBuffer[MAX_LEN];
    char *token;
    int summaryIndex = 0;
    int sentenceCount = 0;
    int i;

    printf("Original Text:\n%s\n\n", input);

    token = strtok(input, ".");

    while(token!=NULL && sentenceCount<3) { // limit summary to 3 sentences
        sentenceCount++;
        sprintf(stringBuffer, "%s.", token);
        strcat(summary, stringBuffer);
        token = strtok(NULL, ".");
    }

    printf("Summary:\n%s\n", summary);
}