//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: puzzling
#include <stdio.h>
#include <string.h>

char c_cat_words[10][20] = {"meow", "purr", "hiss", "scratch", "kibble", "nap", "climb", "play", "furry", "tail"};

char english_words[10][20] = {"hello", "love", "angry", "itch", "food", "sleep", "jump", "fun", "fuzzy", "back"};

int main()
{
    char sentence[100];
    char word[20];
    int i, j;

    printf("Enter a sentence in C Cat Language: ");
    gets(sentence);

    printf("\nTranslated to English: ");

    for(i=0; sentence[i]!='\0'; i++)
    {
        j=0;

        while(sentence[i]!=' ' && sentence[i]!='\0')
        {
            word[j] = sentence[i];
            j++;
            i++;
        }

        word[j] = '\0';

        for(j=0; j<10; j++)
        {
            if(strcmp(word, c_cat_words[j]) == 0)
            {
                printf("%s ", english_words[j]);
                break;
            }
        }

        if(j == 10)
        {
            printf("%s ", word);
        }
    }

    return 0;
}