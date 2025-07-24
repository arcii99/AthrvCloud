//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: medieval
#include <stdio.h>
#include <string.h>

void meowTranslator(char *word);

int main() {
    char word[50];
    
    printf("Enter a word to translate to meow language: \n");
    gets(word);
    
    meowTranslator(word);
    
    return 0;
}

void meowTranslator(char *word) {
    int i;
    int length = strlen(word);
    
    printf("\nMeow Language Translation: \n");

    for(i = 0; i < length; i++) {
        if(word[i] == 'a') {
            printf("meow ");
        } else if(word[i] == 'e') {
            printf("purr ");
        } else if(word[i] == 'i') {
            printf("hiss ");
        } else if(word[i] == 'o') {
            printf("yowl ");
        } else if(word[i] == 'u') {
            printf("scratch ");
        } else {
            printf("%c ", word[i]);
        }
    }
    
    printf("\n");
}