//FormAI DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <string.h>

int main()
{
    char text[500];
    printf("Please enter the text: ");
    fgets(text, 500, stdin);

    int wordCount = 0;
    int i = 0;

    while(text[i] != '\0')
    {
        if(text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
        {
            wordCount++;
        }
        i++;
    }

    printf("The word count for the entered text is: %d", wordCount+1);

    return 0;
}