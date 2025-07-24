//FormAI DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define helper function to count words
int countWords(char *text)
{
    int count = 0;
    char prevChar = ' ';

    for (int i = 0; i <= strlen(text); i++)
    {
        if ((text[i] == ' ' || text[i] == '\n' || text[i] == '\0') && prevChar != ' ')
        {
            count++;
        }
        prevChar = text[i];
    }
    return count;
}

//main function for word count tool
int main()
{
    char text[1000];
    printf("Welcome to the Happy Word Count Tool!\n");
    printf("Please enter the text you wish to count: ");

    fgets(text, sizeof(text), stdin);
    int numberOfWords = countWords(text);
    printf("The number of words in the text is: %d\n", numberOfWords);
    printf("Yay! Happy Counting!\n");

    return 0;
}