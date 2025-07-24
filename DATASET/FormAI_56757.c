//FormAI DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100 // maximum length of input string
#define SPAM_THRESHOLD 0.4 // threshold value to classify as spam

int main()
{
    char input[MAX_LEN];
    int len, i, count = 0;
    float ratio;

    // read input string
    printf("Enter a sentence:\n");
    fgets(input, MAX_LEN, stdin);

    // remove newline character
    len = strlen(input);
    if (input[len-1] == '\n')
        input[len-1] = '\0';

    // count number of occurrences of 'c'
    for (i = 0; i < len; i++)
    {
        if (input[i] == 'c')
            count++;
    }

    // calculate ratio of 'c' occurrences to total length
    ratio = (float)count / len;

    // classify as spam or not
    if (ratio > SPAM_THRESHOLD)
        printf("Spam detected!\n");
    else
        printf("Not spam.\n");

    return 0;
}