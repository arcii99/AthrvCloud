//FormAI DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *sentence);

int main(void)
{
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    int num_words = countWords(sentence);
    printf("The sentence contains %d words.", num_words);
    return 0;
}

int countWords(char *sentence)
{
    int count = 0;
    char *token = strtok(sentence, " \n\t\r");
    while(token != NULL)
    {
        count++;
        token = strtok(NULL, " \n\t\r");
    }
    return count;
}