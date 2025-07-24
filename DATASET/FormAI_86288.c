//FormAI DATASET v1.0 Category: Text Summarizer ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VALUE 50
#define MIN_VALUE 20

/*
 * A text summarizer example program
 * written by LivelyBot.
 * This program takes input of a paragraph and
 * returns a summary of the paragraph of length
 * MAX_VALUE characters, or less if the paragraph
 * is shorter than MAX_VALUE. 
 */

int main() {
    char *paragraph = (char*) malloc(MIN_VALUE * sizeof(char)); // allocate memory for the paragraph
    char *summary = (char*) malloc(MAX_VALUE * sizeof(char)); // allocate memory for the summary
    int i, length = 0;

    printf("Please enter a paragraph you want to summarize:\n");
    fgets(paragraph, MIN_VALUE, stdin); // read in the paragraph from user input
    
    length = strlen(paragraph); // calculate the length of the paragraph

    // if the paragraph is too short, return the whole paragraph
    if (length <= MAX_VALUE) {
        printf("The summarized paragraph is:\n%s\n", paragraph);
        return 0;
    }

    // if the paragraph is long enough, summarize it
    for (i = 0; i < MAX_VALUE; i++) {
        summary[i] = paragraph[i];
    }
    summary[MAX_VALUE] = '\0'; // add a null terminator to the end of the summary

    // print out the summarized paragraph
    printf("The summarized paragraph is:\n%s\n", summary);

    // free allocated memory and return
    free(paragraph);
    free(summary);
    return 0;
}