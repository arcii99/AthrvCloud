//FormAI DATASET v1.0 Category: Word Count Tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[1000];
    int wordCount = 0;

    printf("Enter a sentence or paragraph:\n");
    fgets(text, sizeof(text), stdin);

    char *token = strtok(text, " ");
    
    while (token != NULL) {
        wordCount++;
        token = strtok(NULL, " ");
    }

    printf("Total word count: %d\n", wordCount);

    return 0;
}