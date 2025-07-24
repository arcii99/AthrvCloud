//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: dynamic
#include <stdio.h>
#include <string.h>

char* translate(char* phrase) {
    char* translation = "";
    int length = strlen(phrase);
    for(int i=0; i<length; i++) {
        switch(phrase[i]) {
            case 'C':
            case 'c':
                translation = strcat(translation, "Meow ");
                break;
            case 'A':
            case 'a':
                translation = strcat(translation, "Purr ");
                break;
            case 'T':
            case 't':
                translation = strcat(translation, "Hiss ");
                break;
            default:
                translation = strcat(translation, " ");
        }
    }
    return translation;
}

int main() {
    char phrase[] = "Cats are amazing";
    printf("Original phrase: %s\n", phrase);
    printf("Translation: %s\n", translate(phrase));
    return 0;
}