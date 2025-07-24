//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter a phrase in C Cat language to be translated: ");
    char phrase[100];
    fgets(phrase, 100, stdin);

    char translation[100] = "";
    int i = 0;
    while(i < strlen(phrase)) {
        if(phrase[i] == 'c' || phrase[i] == 'C') {
            strcat(translation, "meow");
        }
        else if(phrase[i] == 't' || phrase[i] == 'T') {
            strcat(translation, "purr");
        }
        else if(phrase[i] == 'w' || phrase[i] == 'W') {
            strcat(translation, "hiss");
        }
        else if(phrase[i] == 'k' || phrase[i] == 'K') {
            strcat(translation, "yowl");
        }
        else {
            strcat(translation, " ");
        }
        i++;
    }

    printf("Your phrase in English is: %s\n", translation);

    return 0;
}