//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100

int main()
{
    char input[MAX_LINE_LENGTH];
    char summary[MAX_SUMMARY_LENGTH] = "";
    int summary_length = 0;
    int line_count = 0;

    printf("Enter the text to be summarized:\n");

    while(fgets(input, MAX_LINE_LENGTH, stdin) != NULL)
    {
        line_count++;

        if(line_count > 10) // only consider first 10 lines
            break;

        char* token = strtok(input, " ");

        while(token != NULL)
        {
            if(strlen(summary) + strlen(token) + 3 >= MAX_SUMMARY_LENGTH) // +3 for the ellipses and space
                break;

            strcat(summary, token);
            strcat(summary, " ");
            summary_length += strlen(token) + 1;

            token = strtok(NULL, " ");
        }
    }

    if(summary_length == 0)
        printf("Input text is empty.\n");
    else
        printf("Summary:\n%s...\n", summary);

    return 0;
}