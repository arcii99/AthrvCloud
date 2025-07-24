//FormAI DATASET v1.0 Category: Text Summarizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 5000
#define MAX_SUM_LEN 500

int main()
{
    char text[MAX_LEN], summary[MAX_SUM_LEN], *p;
    int i, j, sum_len, len;

    printf("Enter text to summarize:\n");
    fgets(text, MAX_LEN, stdin);

    // Remove new line character
    if ((p = strchr(text, '\n')) != NULL)
        *p = '\0';

    len = strlen(text);
    if (len > MAX_LEN)
    {
        printf("Text is too long, try again with a shorter text.\n");
        return 1;
    }

    // Summarize the text
    sum_len = 0;
    for (i = 0, j = 0; i < len && j < MAX_SUM_LEN; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            summary[j++] = text[i];
            summary[j] = ' ';
            sum_len++;

            if (sum_len >= MAX_SUM_LEN)
                break;
        }
        else if (text[i] != ',' && text[i] != ':' && text[i] != ';' && text[i] != '-')
        {
            summary[j++] = text[i];
            sum_len++;

            if (sum_len >= MAX_SUM_LEN)
                break;
        }
    }
    summary[j] = '\0';

    printf("Summary:\n%s\n", summary);

    return 0;
}