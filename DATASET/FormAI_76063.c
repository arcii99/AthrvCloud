//FormAI DATASET v1.0 Category: Spell checking ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char word[20];
    char read_char = getchar();

    while (read_char != '\n')
    {
        int i = 0;
        while (isalpha(read_char))
        {
            word[i++] = tolower(read_char);
            read_char = getchar();
        }
        word[i] = '\0';

        if (strcmp(word, "spellcheck") == 0)
        {
            printf("Possible spelling mistake, did you mean spell check?\n");
        }
        else if (strcmp(word, "programing") == 0)
        {
            printf("Possible spelling mistake, did you mean programming?\n");
        }
        else if (strcmp(word, "communitee") == 0)
        {
            printf("Possible spelling mistake, did you mean community?\n");
        }

        while (read_char != '\n' && !isalpha(read_char))
        {
            read_char = getchar();
        }
    }
    return 0;
}