//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main()
{
    char english_phrase[1000], cat_phrase[1000];
    int length, i;

    printf("Enter an English phrase:\n");
    fgets(english_phrase, sizeof(english_phrase), stdin);

    length = strlen(english_phrase);

    for (i = 0; i < length; i++)
    {
        if (english_phrase[i] == ' ')
            strcat(cat_phrase, " meow");
        else if (english_phrase[i] == 'a' || english_phrase[i] == 'A')
            strcat(cat_phrase, " mew");
        else if (english_phrase[i] == 'e' || english_phrase[i] == 'E')
            strcat(cat_phrase, " meoww");
        else if (english_phrase[i] == 'i' || english_phrase[i] == 'I')
            strcat(cat_phrase, " mreow");
        else if (english_phrase[i] == 'o' || english_phrase[i] == 'O')
            strcat(cat_phrase, " meowww");
        else if (english_phrase[i] == 'u' || english_phrase[i] == 'U')
            strcat(cat_phrase, " miao");
        else
            strcat(cat_phrase, "purr");
    }

    printf("\nThe English phrase \"%s\" is translated to Cat Language as \"%s\".\n", english_phrase, cat_phrase);

    return 0;
}