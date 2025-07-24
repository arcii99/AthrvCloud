//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: innovative
#include <stdio.h>
#include <string.h>

char* translate(char word[]) {
    char translated[100];
    int len = strlen(word);
    int i;
    
    for (i = 0; i < len; i++) {
        switch (word[i]) {
            case 'c':
                strcat(translated, "meow");
                break;
            case 'C':
                strcat(translated, "MEOW");
                break;
            case 'a':
            case 'A':
                strcat(translated, "purr");
                break;
            case 't':
            case 'T':
                strcat(translated, "hiss");
                break;
            case 'o':
            case 'O':
                strcat(translated, "lick");
                break;
            default:
                // If the letter isn't in the dictionary, just add it as is
                char letter[2] = {word[i], '\0'};
                strcat(translated, letter);
        }
    }
    
    return translated;
}

int main() {
    char word[100];
    char* translated;
    
    printf("Enter a word in C Cat Language: ");
    scanf("%s", word);
    
    translated = translate(word);
    
    printf("The translation is: %s\n", translated);
    
    return 0;
}