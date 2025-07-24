//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// Function to translate input to C Cat language
void translateToCCat(char input[]) {
    int len = strlen(input);
    for(int i=0; i<len; i++) {
        char c = input[i];
        switch(c) {
            case 'a':
                printf("%s", "<^ ^>");
                break;
            case 'b':
                printf("%s", "(=^e.e^=)o_");
                break;
            case 'c':
                printf("%s", "|\\_\\_\\|..(*.*)");
                break;
            case 'd':
                printf("%s", ">^..^<");
                break;
            case 'e':
                printf("%s", "|\\_/|");
                break;
            case 'f':
                printf("%s", "~(=^‥^)/");
                break;
            case 'g':
                printf("%s", ">^_^<");
                break;
            case 'h':
                printf("%s", "|__|~");
                break;
            case 'i':
                printf("%s", "|~\\___/");
                break;
            case 'j':
                printf("%s", "\\@( * O * )@/");
                break;
            case 'k':
                printf("%s", "/>v.v<\\");
                break;
            case 'l':
                printf("%s", "(^_^)v");
                break;
            case 'm':
                printf("%s", ">^_^<");
                break;
            case 'n':
                printf("%s", "|\\_._/|");
                break;
            case 'o':
                printf("%s", "(=~.^)=~");
                break;
            case 'p':
                printf("%s", "|\\/^\\|");
                break;
            case 'q':
                printf("%s", "(O^.^O)");
                break;
            case 'r':
                printf("%s", "|\\_\\|\\_\\");
                break;
            case 's':
                printf("%s", ">^.^<");
                break;
            case 't':
                printf("%s", "^/^\\/^");
                break;
            case 'u':
                printf("%s", "|_/ \\_|");
                break;
            case 'v':
                printf("%s", "\\(/@.@)/");
                break;
            case 'w':
                printf("%s", "\\(^o^)/");
                break;
            case 'x':
                printf("%s", "\\(-_-)/");
                break;
            case 'y':
                printf("%s", "\\(^.o)/");
                break;
            case 'z':
                printf("%s", "/(=^_^=)\\" );
                break;
            default:
                printf("%c", c);
        }
    }
}

// Main function to get input and call translation function
int main() {
    char input[100];
    printf("Enter text to be translated to C Cat language: ");
    scanf("%[^\n]", input);
    printf("C Cat translation: ");
    translateToCCat(input);
    return 0;
}