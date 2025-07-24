//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

void translate(char* text);

int main()
{
    char text[100];

    printf("Enter the text you want to translate: ");
    fgets(text, 100, stdin);

    printf("Translated text: ");
    translate(text);

    return 0;
}

void translate(char* text)
{
    int i;
    int length = strlen(text);

    for (i = 0; i < length; i++)
    {
        switch (text[i])
        {
            case 'a':
                printf("argh");
                break;
            case 'b':
                printf("blorg");
                break;
            case 'c':
                printf("clork");
                break;
            case 'd':
                printf("drox");
                break;
            case 'e':
                printf("eep");
                break;
            case 'f':
                printf("flum");
                break;
            case 'g':
                printf("glip");
                break;
            case 'h':
                printf("horp");
                break;
            case 'i':
                printf("ip");
                break;
            case 'j':
                printf("jibba");
                break;
            case 'k':
                printf("krunk");
                break;
            case 'l':
                printf("loot");
                break;
            case 'm':
                printf("mook");
                break;
            case 'n':
                printf("noom");
                break;
            case 'o':
                printf("oops");
                break;
            case 'p':
                printf("pong");
                break;
            case 'q':
                printf("quack");
                break;
            case 'r':
                printf("rip");
                break;
            case 's':
                printf("schlorp");
                break;
            case 't':
                printf("tunk");
                break;
            case 'u':
                printf("unph");
                break;
            case 'v':
                printf("vwoop");
                break;
            case 'w':
                printf("whee");
                break;
            case 'x':
                printf("xenum");
                break;
            case 'y':
                printf("yeg");
                break;
            case 'z':
                printf("zort");
                break;
            default:
                printf("%c", text[i]);
                break;
        }
    }
}