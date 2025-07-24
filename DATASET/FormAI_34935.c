//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: calm
#include <stdio.h>
#include <string.h>

int main()
{
    char phrase[100];
    printf("Enter a phrase in C Cat Language: ");
    fgets(phrase, 100, stdin);
    int i;
    int len = strlen(phrase);

    for (i = 0; i < len; i++)
    {
        switch (phrase[i])
        {
            case 'p':
                printf("meow");
                break;
            case 'f':
                printf("purr");
                break;
            case 'c':
                printf("hiss");
                break;
            case 'm':
                printf("yawn");
                break;
            case 't':
                printf("lick");
                break;
            case 'b':
                printf("sniff");
                break;
            case 's':
                printf("scratch");
                break;
            case 'h':
                printf("sleep");
                break;
            case 'e':
                printf("wake up");
                break;
            case 'd':
                printf("stretch");
                break;
            case 'r':
                printf("pounce");
                break;
            case 'y':
                printf("chase");
                break;
            case 'k':
                printf("climb a tree");
                break;
            case 'n':
                printf("hunt");
                break;
            case 'o':
                printf("bring prey home");
                break;
            case 'l':
                printf("groom");
                break;
            case 'i':
                printf("play");
                break;
            case 'u':
                printf("drink milk");
                break;
            case 'z':
                printf("lick paw");
                break;
            case 'x':
                printf("roll over");
                break;
            case 'v':
                printf("hide");
                break;
            case 'w':
                printf("show affection");
                break;
            case 'g':
                printf("eat");
                break;
            case 'q':
                printf("stare blankly");
                break;
            default:
                printf("%c", phrase[i]);
        }
    }
    return 0;
}