//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to translate the alien language
char* alienLanguageTranslator(char* inputString) {
    char* outputString = (char*)malloc(sizeof(char)*strlen(inputString));
    strcpy(outputString, inputString);
    int i, j;
    for(i=0; outputString[i] != '\0'; i++) {
        for(j=i; outputString[j] != '\0'; j++) {
            if(outputString[j] != outputString[i]) {
                break;
            }
            outputString[j] = outputString[j] == '0' ? '1' : '0';
        }
    }
    return outputString;
}

//Main function to test the translator
int main() {

    char* inputString = "110001000011000111100000";
    char* outputString = alienLanguageTranslator(inputString);
    printf("Translated Alien Language: %s", outputString);

    return 0;
}