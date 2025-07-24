//FormAI DATASET v1.0 Category: Text processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000
#define MAX_WORDS 100

int main()
{
    char text[MAX_CHARS], delimiter[] = " ,\n";
    char *words[MAX_WORDS];
    int i, n = 0;

    printf("Welcome to our medieval text processing program!\n");
    printf("Please input your text:\n");
    fgets(text, MAX_CHARS, stdin);

    words[n] = strtok(text, delimiter);
    while (words[n] != NULL && n < MAX_WORDS)
    {
        n++;
        words[n] = strtok(NULL, delimiter);
    }

    printf("You have inputted a total of %d words.\n", n);
    printf("The words you inputted are:\n");

    for (i = 0; i < n; i++)
    {
        printf("'%s'", words[i]);

        if (strlen(words[i]) % 2 == 0)
        {
            printf(", which is a word of even length.\n");
        }
        else
        {
            printf(", which is a word of odd length.\n");
        }
    }

    return 0;
}