//FormAI DATASET v1.0 Category: Text Summarizer ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    printf("Welcome to my C Text Summarizer program!\n");
    printf("Just sit back, relax, and let me do the hard work for you!\n");

    char input[200];    // initialize the input string
    printf("\nEnter the text you want to summarize:\n");
    scanf("%[^\n]", input);    // use scanf to get input string with spaces

    char *summary = malloc(sizeof(char)*50);    // allocate 50 bytes for summary
    summary[0] = '\0';    // initialize summary to an empty string

    char *token = strtok(input, ".");    // use strtok to get first sentence
    while(token != NULL) {
        char *temp_summary = malloc(sizeof(char)*50);    // allocate 50 bytes for temporary summary
        temp_summary[0] = '\0';    // initialize temporary summary to an empty string

        strcat(temp_summary, token);    // add sentence to temporary summary
        strcat(temp_summary, ".");    // add period to end of sentence

        if(strlen(summary) + strlen(temp_summary) <= 50) {    // check if adding sentence to summary will exceed 50 characters
            strcat(summary, temp_summary);    // add sentence to summary
        }
        else {
            free(temp_summary);    // free temporary summary memory
            break;    // break out of while loop
        }

        token = strtok(NULL, ".");    // use strtok to get next sentence
    }

    printf("\nSummary:\n%s\n", summary);    // print summary

    free(summary);    // free summary memory

    printf("\nThank you for using my program! I hope you found it helpful!\n");

    return 0;
}