//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <string.h>

int main()
{
    char phrase[100];
    int i, j;
    printf("Enter phrase to be translated: ");
    fgets(phrase, 100, stdin);

    for (i = 0; i < strlen(phrase); i++) {
        switch(phrase[i]) {
            case 'a':
                printf("x");
                break;
            case 'b':
                printf("y");
                break;
            case 'c':
                printf("z");
                break;
            case 'd':
                printf("p");
                break;
            case 'e':
                printf("q");
                break;
            case 'f':
                printf("r");
                break;
            case 'g':
                printf("s");
                break;
            case 'h':
                printf("t");
                break;
            case 'i':
                printf("u");
                break;
            case 'j':
                printf("v");
                break;
            case 'k':
                printf("w");
                break;
            case 'l':
                printf("x");
                break;
            case 'm':
                printf("y");
                break;
            case 'n':
                printf("z");
                break;
            case 'o':
                printf("a");
                break;
            case 'p':
                printf("b");
                break;
            case 'q':
                printf("c");
                break;
            case 'r':
                printf("d");
                break;
            case 's':
                printf("e");
                break;
            case 't':
                printf("f");
                break;
            case 'u':
                printf("g");
                break;
            case 'v':
                printf("h");
                break;
            case 'w':
                printf("i");
                break;
            case 'x':
                printf("j");
                break;
            case 'y':
                printf("k");
                break;
            case 'z':
                printf("l");
                break;
            case ' ':
                printf(" ");
                break;
            default:
                printf("%c", phrase[i]);
        }
    }

    return 0;
}