//FormAI DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *str)
{
    int count = 1; // start the count as 1 because there will be atleast 1 word
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char inputString[1000];
    printf("Enter a string: ");
    fgets(inputString, 1000, stdin); //taking input using fgets

    int wordCount = countWords(inputString);
    printf("Word Count: %d\n", wordCount);

    return 0;
}