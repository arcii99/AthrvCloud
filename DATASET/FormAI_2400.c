//FormAI DATASET v1.0 Category: Text Summarizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 5000
#define MAX_SUMMARY_SIZE 1000

int main()
{
    char input[MAX_INPUT_SIZE];
    char summary[MAX_SUMMARY_SIZE];
    int i, j, input_length, summary_length, count = 0;
    float threshold = 0.5;

    printf("Enter text to summarize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    input_length = strlen(input);
    summary_length = 0;

    for (i = 0; i < input_length; )
    {
        if (input[i] != '.' && input[i] != '?' && input[i] != '!')
        {
            summary[summary_length++] = input[i++];
            continue;
        }

        count = 0;

        for (j = i; j >= 0; j--)
        {
            if (input[j] == ' ')
            {
                count++;
            }

            if (count == 10 || j == 0)
            {
                break;
            }
        }

        if (j > 0 && input[j - 1] == ',')
        {
            j--;
        }

        if ((float)(i - j) / (float)input_length >= threshold)
        {
            break;
        }

        i++;
        summary[summary_length++] = input[j];
        summary[summary_length++] = input[j + 1];

        if (input[i - 1] != '!')
        {
            summary[summary_length++] = '\n';
        }
    }

    summary[summary_length] = '\0';

    printf("\nSummary:\n%s", summary);

    return 0;
}