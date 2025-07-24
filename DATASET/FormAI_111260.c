//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: medieval
#include <stdio.h>
#include <string.h>

char* translate(char* englishSentence){
    char catSentence[1000];
    char* token;
    char* translation = "";
    int sentenceLength = strlen(englishSentence);
    strcpy(catSentence, englishSentence);

    token = strtok(catSentence, " ");
    while(token != NULL){
        if(strcmp(token, "i") == 0){
            translation = strcat(translation, "meow");
        }
        else if(strcmp(token, "you") == 0){
            translation = strcat(translation, "purr");
        }
        else if(strcmp(token, "love") == 0){
            translation = strcat(translation, "hiss");
        }
        else if(strcmp(token, "food") == 0){
            translation = strcat(translation, "chirp");
        }
        else{
            translation = strcat(translation, token);
        }

        translation = strcat(translation, " ");
        token = strtok(NULL, " ");
    }

    return translation;
}

int main(int argc, char **argv){
    char* sentence = "i love food";
    char* translated = translate(sentence);
    printf("%s", translated);

    return 0;
}