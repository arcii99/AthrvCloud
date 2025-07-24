//FormAI DATASET v1.0 Category: Text Summarizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_SIZE 50
#define MAX_TEXT_SIZE 1000

void print_summary(char *text);

int main()
{
    char text[MAX_TEXT_SIZE];
    printf("Greetings traveler, please share thy knowledge to be summarized: \n");
    fgets(text, MAX_TEXT_SIZE, stdin);
    print_summary(text);
    return 0;
}

void print_summary(char *text){
    char *summary = (char*) malloc(MAX_SUMMARY_SIZE*sizeof(char));
    char *token;
    char *delim = " \n";
    int word_count = 0;
    int i, j = 0;
    
    printf("\n\n\nWise One's Summary:\n");
    token = strtok(text, delim);
    while(token != NULL){
        if(word_count == MAX_SUMMARY_SIZE){
            break;
        }
        strcpy(&summary[j], token);
        j += strlen(token);
        summary[j] = ' ';
        j++;
        word_count++;
        token = strtok(NULL, delim);
    }
    summary[j-1] = '\0';
    
    printf("%s...\n", summary);
    
    free(summary);
}