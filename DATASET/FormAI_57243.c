//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: authentic
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    printf("Welcome to the C Alien Language Translator\n");
    printf("Enter a sentence to translate: ");
    fgets(input, 100, stdin);
    
    for(int i=0; i<strlen(input); i++)
    {
        switch(input[i])
        {
            case 'a':
                printf("boop ");
                break;
            case 'b':
                printf("beep ");
                break;
            case 'c':
                printf("bloop ");
                break;
            case 'd':
                printf("blip ");
                break;
            case 'e':
                printf("blop ");
                break;
            case 'f':
                printf("blap ");
                break;
            case 'g':
                printf("bep ");
                break;
            case 'h':
                printf("bleep ");
                break;
            case 'i':
                printf("blup ");
                break;
            case 'j':
                printf("blimp ");
                break;
            case 'k':
                printf("bloop ");
                break;
            case 'l':
                printf("blat ");
                break;
            case 'm':
                printf("blaap ");
                break;
            case 'n':
                printf("beep ");
                break;
            case 'o':
                printf("blurp ");
                break;
            case 'p':
                printf("blip ");
                break;
            case 'q':
                printf("blorp ");
                break;
            case 'r':
                printf("beep ");
                break;
            case 's':
                printf("blit ");
                break;
            case 't':
                printf("blop ");
                break;
            case 'u':
                printf("blump ");
                break;
            case 'v':
                printf("blap ");
                break;
            case 'w':
                printf("blurp ");
                break;
            case 'x':
                printf("boop ");
                break;
            case 'y':
                printf("blot ");
                break;
            case 'z':
                printf("beep ");
                break;
            case ' ':
                printf(" ");
                break;
            default:
                printf("%c", input[i]);
        }
    }
    printf("\n");
    return 0;
}