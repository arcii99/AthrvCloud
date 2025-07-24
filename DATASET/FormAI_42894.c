//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[1000];
    int words = 0;

    printf("Enter some text: ");
    fgets(text, 1000, stdin);

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isspace(text[i]))
        {
            words++;
            while (!isspace(text[i]) && text[i] != '\0')
            {
                i++;
            }
        }
    }

    printf("Word count: %d\n", words);

    return 0;
}