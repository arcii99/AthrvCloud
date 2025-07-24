//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char alienLanguage[100];
    char englishTranslation[100];

    printf("Enter the alien language : ");
    fgets(alienLanguage, 100, stdin);

    for (int i = 0; alienLanguage[i] != 0; i++)
    {
        switch (alienLanguage[i])
        {
            case '!': englishTranslation[i] = 'a'; break;
            case '#': englishTranslation[i] = 'b'; break;
            case '@': englishTranslation[i] = 'c'; break;
            case '$': englishTranslation[i] = 'd'; break;
            case '%': englishTranslation[i] = 'e'; break;
            case '^': englishTranslation[i] = 'f'; break;
            case '&': englishTranslation[i] = 'g'; break;
            case '*': englishTranslation[i] = 'h'; break;
            case '(': englishTranslation[i] = 'i'; break;
            case ')': englishTranslation[i] = 'j'; break;
            case '-': englishTranslation[i] = 'k'; break;
            case '_': englishTranslation[i] = 'l'; break;
            case '+': englishTranslation[i] = 'm'; break;
            case '=': englishTranslation[i] = 'n'; break;
            case '[': englishTranslation[i] = 'o'; break;
            case ']': englishTranslation[i] = 'p'; break;
            case '{': englishTranslation[i] = 'q'; break;
            case '}': englishTranslation[i] = 'r'; break;
            case ';': englishTranslation[i] = 's'; break;
            case ':': englishTranslation[i] = 't'; break;
            case '\'': englishTranslation[i] = 'u'; break;
            case '\"': englishTranslation[i] = 'v'; break;
            case ',': englishTranslation[i] = 'w'; break;
            case '<': englishTranslation[i] = 'x'; break;
            case '.': englishTranslation[i] = 'y'; break;
            case '>': englishTranslation[i] = 'z'; break;
            case '/': englishTranslation[i] = ' '; break;
            case '?': englishTranslation[i] = '\n'; break;
            default: englishTranslation[i] = alienLanguage[i];
        }

        englishTranslation[i+1] = '\0';
    }

    printf("The translated text is : %s", englishTranslation);

    return 0;
}