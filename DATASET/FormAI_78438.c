//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    char *word;
    int count = 0;

    printf("Enter a sentence: ");
    fgets(input, 100, stdin);

    printf("Enter the word to count: ");
    scanf("%s", word);

    char *ptr = strstr(input, word);
    while (ptr != NULL)
    {
        count++;
        ptr = strstr(ptr + 1, word);
    }

    printf("The word %s appears %d time(s) in the sentence.", word, count);

    return 0;
}