//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>

void main() {
    char sentence[100];
    int i;
    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter your sentence in the Alien Language:");
    gets(sentence);
    printf("\n");
    printf("Your sentence in English is:\n");
    for (i = 0; sentence[i] != '\0'; i++) {
        switch(sentence[i]) {
            case 'z':
                printf("a");
                break;
            case 'y':
                printf("b");
                break;
            case 'x':
                printf("c");
                break;
            case 'w':
                printf("d");
                break;
            case 'v':
                printf("e");
                break;
            case 'u':
                printf("f");
                break;
            case 't':
                printf("g");
                break;
            case 's':
                printf("h");
                break;
            case 'r':
                printf("i");
                break;
            case 'q':
                printf("j");
                break;
            case 'p':
                printf("k");
                break;
            case 'o':
                printf("l");
                break;
            case 'n':
                printf("m");
                break;
            case 'm':
                printf("n");
                break;
            case 'l':
                printf("o");
                break;
            case 'k':
                printf("p");
                break;
            case 'j':
                printf("q");
                break;
            case 'i':
                printf("r");
                break;
            case 'h':
                printf("s");
                break;
            case 'g':
                printf("t");
                break;
            case 'f':
                printf("u");
                break;
            case 'e':
                printf("v");
                break;
            case 'd':
                printf("w");
                break;
            case 'c':
                printf("x");
                break;
            case 'b':
                printf("y");
                break;
            case 'a':
                printf("z");
                break;
            default:
                printf("%c", sentence[i]);
                break;
        }
    }
    printf("\n");
    printf("Thank you for using the Alien Language Translator!");
}