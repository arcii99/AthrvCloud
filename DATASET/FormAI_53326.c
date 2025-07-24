//FormAI DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    int count = 0;

    printf("Greetings noble sir!\nEnter thy sentence here:\n");

    //user input
    fgets(sentence, 1000, stdin);

    //counting words
    for (int i = 0; i <= strlen(sentence); i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t' || sentence[i] == '\0')
        {
            count++;
        }
    }

    printf("The word count of thy sentence is %d.\n", count);

    printf("Verily, the count is complete.\nThe word count tool has served thee well.");

    return 0;
}