//FormAI DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main()
{
    char input[MAX_LENGTH];
    printf("Enter a sentence or phrase: ");

    // read user input
    fgets(input, MAX_LENGTH, stdin);

    int count = 0;
    char *word = strtok(input, " "); // get first word

    // loop through the words in the input
    while (word != NULL)
    {
        count++; // increment word count
        word = strtok(NULL, " "); // get next word
    }

    printf("The sentence/phrase contains %d words.", count);

    return 0;
}