//FormAI DATASET v1.0 Category: Text Summarizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void text_summarizer(char *text, int n){
    char *token;
    double count = 0;
    char *summary = malloc(sizeof(char)*n);
    memset(summary, 0, sizeof(summary));
    token = strtok(text, " ");
    
    while(token != NULL && strlen(summary) < n){
        count += (strlen(token) > 6) ? 1 : 0.5;
        strcat(summary, token);
        strcat(summary, " ");
        token = strtok(NULL, " ");
    }
    if(strlen(summary) >= n){
        summary[n-1] = '\0';
    }
    printf("Summary: %s...\n", summary);
}

int main(){
    char text[] = "The quick brown fox jumps over the lazy dog.";
    text_summarizer(text, 10);
    
    return 0;
}