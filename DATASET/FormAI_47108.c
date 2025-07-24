//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SENTENCES 30

int main()
{
    char input[1000],*sentences[MAX_SENTENCES];
    int sentence_count=0,j=0;
    printf("Enter text to summarize:\n");
    gets(input);
    char *token=strtok(input,".");
    while(token!=NULL)
    {
        sentences[sentence_count++]=token;
        token=strtok(NULL,".");
    }
    printf("Summary:\n");
    for(int i=0;i<sentence_count;i++)
    {
        if(strlen(sentences[i])>20)
        {
            printf("%c",toupper(sentences[i][0]));
            for(j=1;sentences[i][j]!='\0';j++)
            {
                if(sentences[i][j]==' '&&sentences[i][j+1]==tolower(sentences[i][j+1]))
                {
                    printf("%c",toupper(sentences[i][j+1]));
                    j++;
                }
                else
                    printf("%c",tolower(sentences[i][j]));
            }
            printf(". ");
        }
    }
    return 0;
}