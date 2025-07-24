//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: introspective
#include <stdio.h>

int main() {
    // Introspection message
    printf("Hello, I am a C Alien Language Translator program.\n");

    // Prompt user for input
    printf("Please enter a sentence in C Alien Language: ");
    char c_alien_sentence[100];
    scanf("%[^\n]", c_alien_sentence);

    // Translate to English
    int i = 0;
    while (c_alien_sentence[i] != '\0') {
        switch (c_alien_sentence[i]) {
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
                printf("%c", c_alien_sentence[i]);
        }
        i++;
    }

    // Introspection message
    printf("\nThank you for using the C Alien Language Translator program.\n");

    return 0;
}