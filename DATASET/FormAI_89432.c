//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: artistic
#include <stdio.h>
#include <string.h>

void alienLanguageTranslator(char* text);

int main() {

    char text[100];

    printf("Enter the text in Alien Language: ");
    fgets(text, 100, stdin);

    alienLanguageTranslator(text);

    return 0;
}

void alienLanguageTranslator(char* text) {

    int index = 0;
    int length = strlen(text);

    printf("Translation in English Language: ");

    while(index < length) {

        if(text[index] == 'a') {

            if(text[index+1] == 'b')
                printf("z");
            else if(text[index+1] == 'c')
                printf("y");
            else if(text[index+1] == 'd')
                printf("h");
            else if(text[index+1] == 'e')
                printf("f");
            else if(text[index+1] == 'f')
                printf("e");
            else if(text[index+1] == 'g')
                printf("x");
            else if(text[index+1] == 'h')
                printf("d");
            else if(text[index+1] == 'i')
                printf("j");
            else if(text[index+1] == 'j')
                printf("i");
            else if(text[index+1] == 'k')
                printf("w");
            else if(text[index+1] == 'l')
                printf("v");
            else if(text[index+1] == 'm')
                printf("u");
            else if(text[index+1] == 'n')
                printf("t");
            else if(text[index+1] == 'o')
                printf("s");
            else if(text[index+1] == 'p')
                printf("r");
            else if(text[index+1] == 'q')
                printf("q");
            else if(text[index+1] == 'r')
                printf("p");
            else if(text[index+1] == 's')
                printf("o");
            else if(text[index+1] == 't')
                printf("n");
            else if(text[index+1] == 'u')
                printf("m");
            else if(text[index+1] == 'v')
                printf("l");
            else if(text[index+1] == 'w')
                printf("k");
            else if(text[index+1] == 'x')
                printf("g");
            else if(text[index+1] == 'y')
                printf("c");
            else if(text[index+1] == 'z')
                printf("b");

            index+=2;
        }
        else {

            printf("%c", text[index]);
            index++;
        }
    }

    printf("\n");
}