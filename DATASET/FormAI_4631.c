//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main() {
    char phrase[100];
    int i,j;
    printf("Please enter a phrase in English:\n");
    scanf("%[^\n]%*c", phrase);
    printf("Translation in C Cat Language:\n");

    for(i=0; i<strlen(phrase); i++) {
        switch (phrase[i])
        {
            case 'a':
                printf("meow ");
                break;
            case 'b':
                printf("purr ");
                break;
            case 'c':
                printf("hiss ");
                break;
            case 'd':
                printf("scratch ");
                break;
            case 'e':
                printf("lick ");
                break;
            case 'f':
                printf("pounce ");
                break;
            case 'g':
                printf("claw ");
                break;
            case 'h':
                printf("sniff ");
                break;
            case 'i':
                printf("chase ");
                break;
            case 'j':
                printf("curl ");
                break;
            case 'k':
                printf("leap ");
                break;
            case 'l':
                printf("nip ");
                break;
            case 'm':
                printf("paw ");
                break;
            case 'n':
                printf("jump ");
                break;
            case 'o':
                printf("purr ");
                break;
            case 'p':
                printf("sleep ");
                break;
            case 'q':
                printf("snarl ");
                break;
            case 'r':
                printf("stretch ");
                break;
            case 's':
                printf("bat ");
                break;
            case 't':
                printf("swat ");
                break;
            case 'u':
                printf("nuzzle ");
                break;
            case 'v':
                printf("slink ");
                break;
            case 'w':
                printf("yowl ");
                break;
            case 'x':
                printf("watch ");
                break;
            case 'y':
                printf("lick ");
                break;
            case 'z':
                printf("nap ");
                break;
            case ' ':
                printf(" ");
                break;
            default:
                printf("%c", phrase[i]);
                break;
        }
    }
    printf("\n");
    return 0;
}