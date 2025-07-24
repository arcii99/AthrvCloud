//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {

    char input[100];
    int i;

    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please enter your message: ");
    fgets(input, 100, stdin); // take input from user

    // convert input message to alien language
    for(i=0; i<strlen(input)-1; i++) {
        switch(input[i]) {
            case 'a':
                printf("*");
                break;
            case 'b':
                printf("!");
                break;
            case 'c':
                printf("#");
                break;
            case 'd':
                printf("?");
                break;
            case 'e':
                printf("&");
                break;
            case 'f':
                printf("$");
                break;
            case 'g':
                printf("@");
                break;
            case 'h':
                printf("+");
                break;
            case 'i':
                printf("-");
                break;
            case 'j':
                printf("=");
                break;
            case 'k':
                printf("^");
                break;
            case 'l':
                printf("(");
                break;
            case 'm':
                printf(")");
                break;
            case 'n':
                printf("/");
                break;
            case 'o':
                printf("~");
                break;
            case 'p':
                printf(">");
                break;
            case 'q':
                printf("<");
                break;
            case 'r':
                printf("`");
                break;
            case 's':
                printf("_");
                break;
            case 't':
                printf("|");
                break;
            case 'u':
                printf(".");
                break;
            case 'v':
                printf(",");
                break;
            case 'w':
                printf(":");
                break;
            case 'x':
                printf(";");
                break;
            case 'y':
                printf("[");
                break;
            case 'z':
                printf("]");
                break;
            case ' ':
                printf(" ");
                break;
            default:
                printf("%c", input[i]);
                break;
        }
    }

    printf("\nYour message has been translated into the Alien Language!\n");
    return 0;
}