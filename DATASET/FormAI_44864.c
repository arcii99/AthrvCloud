//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: surprised
#include <stdio.h>
#include <string.h>

char* translate(char* phrase);

int main(){
    char phrase[100];
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter a phrase to be translated:\n");
    fgets(phrase, 100, stdin);
    phrase[strcspn(phrase, "\n")] = 0;

    char* translated_phrase = translate(phrase);

    printf("Your phrase in the C Cat language is:\n");
    printf("%s\n", translated_phrase);

    return 0;
}

char* translate(char* phrase){
    int len = strlen(phrase);
    char* translated_phrase = malloc(len*2+1);
    int j = 0;
    for(int i = 0; i < len; i++){
        if(phrase[i] == 'c'){
            strcat(translated_phrase, "meow");
            j += 4;
        }
        else if(phrase[i] == 'C'){
            strcat(translated_phrase, "MEOW");
            j += 4;
        }
        else{
            translated_phrase[j] = phrase[i];
            j++;
        }
    }
    translated_phrase[j] = '\0';
    return translated_phrase;
}