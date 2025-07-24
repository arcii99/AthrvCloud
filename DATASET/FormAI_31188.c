//FormAI DATASET v1.0 Category: Text Summarizer ; Style: lively
#include <stdio.h>
#include <string.h>
#define MAX_LEN 500

int main()
{
    char input[MAX_LEN];
    char summary[MAX_LEN];
    int length, i, j, count;
    printf("Enter text to summarize: ");
    fgets(input, MAX_LEN, stdin);

    // Remove newline character from input
    length = strlen(input);
    if (input[length-1] == '\n')
        input[length-1] = '\0';

    // Loop through input and count words
    count = 1;
    for (i = 0; i < length; i++)
    {
        if (input[i] == ' ')
            count++;
    }

    // Calculate number of words to include in summary
    if (count <= 10)
        j = count;
    else
        j = count / 2;

    // Loop through input and copy selected words to summary
    count = 0;
    for (i = 0; i < length && count < j; i++)
    {
        if (input[i] == ' ')
            count++;
        summary[i] = input[i];
    }
    summary[i] = '\0';

    // Print summary
    printf("\nSummary: %s\n", summary);
    return 0;
}