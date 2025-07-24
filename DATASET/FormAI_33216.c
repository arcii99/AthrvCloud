//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: future-proof
#include <stdio.h>
#include <string.h>

//define the C Cat dictionary (English to C Cat)
const char* dictionary[] = {"hello", "meow", "world", "purr", "goodbye", "hiss"};

//translate function that takes in an English string and outputs a C Cat string
char* translate(char* englishString) {

    //convert all characters to lowercase
    for(int i = 0; i < strlen(englishString); i++) {
        englishString[i] = tolower(englishString[i]);
    }

    //tokenize the English string
    char* token = strtok(englishString, " ");
    char cCatString[100] = "";

    //loop through tokens and translate each word
    while (token != NULL) {
        //find translation in dictionary
        int index = -1;
        for(int i = 0; i < 6; i++) {
            if(strcmp(token, dictionary[i]) == 0) {
                index = i;
                break;
            }
        }

        //if translation found, append to cCatString
        if(index != -1) {
            strcat(cCatString, dictionary[index + 1]);
        } else {
            //if translation not found, append original word
            strcat(cCatString, token);
        }
        strcat(cCatString, " ");
        token = strtok(NULL, " ");
    }

    //remove trailing space
    cCatString[strlen(cCatString)-1] = '\0';

    //return translated C Cat string
    return cCatString;
}

int main() {
    //example usage
    char englishString[] = "Hello world, goodbye cruel world";
    char* cCatString = translate(englishString);

    printf("%s\n", cCatString); //output: "meow purr, hiss cruel purr"
    return 0;
}