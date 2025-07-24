//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: funny
#include <stdio.h>
#include <string.h>

int main()
{
    char alien_language[] = "ZxxYyXwWvUuTtSsrQqPpoNnmLlkJjIiHhGgfEedCbBaA";
    char english_language[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char input[1000];
    int length;

    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter the text you wish to translate:\n");

    fgets(input, 1000, stdin);
    length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            if (input[i] == english_language[j])
            {
                printf("%c", alien_language[j]);
                break;
            }
            else if (j == 51)
            {
                printf("%c", input[i]);
            }
        }
    }

    printf("\nTranslation complete!");

    return 0;
}