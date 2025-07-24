//FormAI DATASET v1.0 Category: Text processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[1000], word[100];
    int count = 0, i;

    /* Ask user to input the text */
    printf("Enter a text:\n");
    fgets(text, sizeof(text), stdin);

    /* Ask user to enter a word to search */
    printf("Enter a word to search:\n");
    scanf("%s", word);

    /* Split the text into words */
    char *token = strtok(text, " ");
    while(token != NULL)
    {
        /* Check if the word matches */
        if(strcmp(token, word) == 0)
            count++;

        token = strtok(NULL, " ");
    }

    /* Print the number of matches */
    printf("Number of matches found for \"%s\": %d\n", word, count);

    return 0;
}