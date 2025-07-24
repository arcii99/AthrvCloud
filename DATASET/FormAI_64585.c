//FormAI DATASET v1.0 Category: Text Summarizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define MAX_SUMMARY_LEN 300

int wordCount(char *text); //function to count words in the text
void summarize(char *text, char *summary); //function to generate summary from the text

int main() {
    char text[MAX_LEN]; //input text
    char summary[MAX_SUMMARY_LEN]; //output summary
    
    printf("Enter the text:\n");
    fgets(text, MAX_LEN, stdin); //read input text from user
    
    printf("\nGenerating summary...\n");
    summarize(text, summary); //generate summary from input text
    
    printf("\nSummary:\n%s", summary); //print the generated summary
    
    return 0; //exit program
}

int wordCount(char *text) {
    int count = 0;
    char prev = ' ';
    
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] != ' ' && prev == ' ') {
            count++;
        }
        prev = text[i];
    }
    
    return count;
}

void summarize(char *text, char *summary) {
    char *token = strtok(text, " "); //get first word
    int count = 0; //initialize word count
    int summary_len = 0; //initialize summary length
    
    while (token != NULL) {
        if (count <= 10) { //consider first 10 words
            strcat(summary, token); //append word to summary
            strcat(summary, " "); //add space after word
            summary_len += strlen(token); //update summary length
            count++; //update word count
        }
        token = strtok(NULL, " "); //get next word
    }
    
    if (wordCount(text) > 10) { //if input text has more than 10 words
        strcat(summary, "..."); //add ellipsis to indicate summary is incomplete
        summary_len += 3; //update summary length
    }
    
    if (summary_len > MAX_SUMMARY_LEN) { //if summary length exceeds maximum summary length
        summary[MAX_SUMMARY_LEN - 3] = '.'; //replace last three characters with ellipsis
        summary[MAX_SUMMARY_LEN - 2] = '.';
        summary[MAX_SUMMARY_LEN - 1] = '.';
        summary[MAX_SUMMARY_LEN] = '\0'; //terminate string
    }
}