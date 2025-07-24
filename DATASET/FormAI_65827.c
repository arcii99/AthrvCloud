//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

int main()
{
    char ccat_sentence[100];
    printf("Enter a sentence in C Cat Language: ");
    scanf("%[^\n]%*c", ccat_sentence);

    const char *ccat_words[100] = {"meow", "purr", "hiss", "scratch", "claw", "furry", "tail", "whiskers", "biscuits", "fish", "milk", "nap", "play", "bird"};

    const char *english_translation[100] = {"Hello", "Good", "Angry", "Angry", "Hurt", "Friendly", "Happy", "Afraid", "Hungry", "Food", "Drink", "Sleep", "Play", "Fly"};

    char *ccat_token;
    ccat_token = strtok(ccat_sentence, " ");
    printf("\nEnglish Translation: ");
    while (ccat_token != NULL)
    {
        for (int i = 0; i < 14; i++)
        {
            if (strcmp(ccat_token, ccat_words[i]) == 0)
            {
                printf("%s ", english_translation[i]);
            }
        }
        ccat_token = strtok(NULL, " ");
    }
    return 0;
}