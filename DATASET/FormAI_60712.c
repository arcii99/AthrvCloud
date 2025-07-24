//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    char translated[1000];
    int i;
    int length;

    printf("Enter a sentence in the C Alien Language:\n");
    gets(sentence);

    length = strlen(sentence);

    for(i = 0; i < length; i++)
    {
        switch(sentence[i])
        {
            case '*':
                translated[i] = 'a';
                break;
            case '&':
                translated[i] = 'b';
                break;
            case '#':
                translated[i] = 'c';
                break;
            case '!':
                translated[i] = 'd';
                break;
            case '+':
                translated[i] = 'e';
                break;
            case '/':
                translated[i] = 'f';
                break;
            case '@':
                translated[i] = 'g';
                break;
            case '$':
                translated[i] = 'h';
                break;
            case '%':
                translated[i] = 'i';
                break;
            case '^':
                translated[i] = 'j';
                break;
            case '(':
                translated[i] = 'k';
                break;
            case ')':
                translated[i] = 'l';
                break;
            case '=':
                translated[i] = 'm';
                break;
            case '|':
                translated[i] = 'n';
                break;
            case '~':
                translated[i] = 'o';
                break;
            case '<':
                translated[i] = 'p';
                break;
            case '>':
                translated[i] = 'q';
                break;
            case '?':
                translated[i] = 'r';
                break;
            case ';':
                translated[i] = 's';
                break;
            case ':':
                translated[i] = 't';
                break;
            case ',':
                translated[i] = 'u';
                break;
            case '.':
                translated[i] = 'v';
                break;
            case '{':
                translated[i] = 'w';
                break;
            case '}':
                translated[i] = 'x';
                break;
            case '[':
                translated[i] = 'y';
                break;
            case ']':
                translated[i] = 'z';
                break;
            default:
                translated[i] = sentence[i];
                break;
        }
    }

    printf("\nYour sentence in English:\n%s", translated);

    return 0;
}