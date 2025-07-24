//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: shocked
#include <stdio.h>

int main() {
    printf("Shocked Cat Language Translator\n");
    printf("Enter the sentence in English: ");
    char sentence[100];
    fgets(sentence, 100, stdin);

    printf("Translated in C Cat language: ");
    for (int i = 0; sentence[i] != '\0'; i++) {
        switch(sentence[i]) {
            case 'a':
                printf("me");
                break;
            case 'b':
                printf("rawr");
                break;
            case 'c':
                printf("prr");
                break;
            case 'd':
                printf("mew");
                break;
            case 'e':
                printf("miaw");
                break;
            case 'f':
                printf("murr");
                break;
            case 'g':
                printf("purr");
                break;
            case 'h':
                printf("raowr");
                break;
            case 'i':
                printf("mooo");
                break;
            case 'j': 
                printf("hissss");
                break;
            case 'k':
                printf("rooo");
                break;
            case 'l':
                printf("miooww");
                break;
            case 'm':
                printf("miaor");
                break;
            case 'n':
                printf("mo");
                break;
            case 'o':
                printf("rorrr");
                break;
            case 'p':
                printf("meow");
                break;
            case 'q':
                printf("grrr");
                break;
            case 'r':
                printf("mrao");
                break;
            case 's':
                printf("mio");
                break;
            case 't':
                printf("miioaw");
                break;
            case 'u':
                printf("mau");
                break;
            case 'v':
                printf("rarr");
                break;
            case 'w':
                printf("maw");
                break;
            case 'x':
                printf("mroaww");
                break;
            case 'y':
                printf("mroao");
                break;
            case 'z':
                printf("howl");
                break;
            default:
                printf("%c", sentence[i]);
                break;
        }
    }
    printf("\n");
    return 0;
}