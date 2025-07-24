//FormAI DATASET v1.0 Category: Text Summarizer ; Style: brave
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void summarize(char *text, int max_length);

int main(){
    printf("Welcome to the Brave Text Summarizer!");
    printf("\nEnter your text: ");

    char text[1000];
    fgets(text, 1000, stdin);

    int max_length;
    printf("\nEnter the maximum length for the summary: ");
    scanf("%d", &max_length);

    printf("\nSummarizing...\n");
    summarize(text, max_length);

    return 0;
}

void summarize(char *text, int max_length){
    char *token = strtok(text, " ");
    char summary[1000] = "";

    while(token != NULL){
        if((strlen(summary) + strlen(token)) < max_length){
            strcat(summary, token);
            strcat(summary, " ");
        }
        else{
            strcat(summary, "...");
            break;
        }

        token = strtok(NULL, " ");
    }

    printf("Summary: %s", summary);
}