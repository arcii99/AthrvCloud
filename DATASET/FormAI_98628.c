//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: inquisitive
#include <stdio.h>
#include <string.h>

char* translate(char* phrase) {
    char c_cat_language[50];
    char c_cat[2] = "c";
    char space[2] = " ";
    char o_cat[2] = "o";
    int i = 0, j = 0, length = strlen(phrase);
    
    // loop through each character in the input phrase
    for(i = 0; i < length; i++) {
        // if the character is 'C', add "c" "o" to the output string
        if(phrase[i] == 'C') {
            c_cat_language[j] = c_cat[0];
            j++;
            c_cat_language[j] = o_cat[0];
            j++;
            c_cat_language[j] = space[0];
            j++;
        } else { // otherwise, just add the character to the output string
            c_cat_language[j] = phrase[i];
            j++;
        }
    }
    // add a null terminator to the end of the output string
    c_cat_language[j] = '\0';
    
    // return the translated phrase
    return c_cat_language;
}

int main() {
    char phrase[50];
    char* translated_phrase;
    
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a phrase to translate into C Cat language: ");
    scanf("%[^\n]s", phrase);
    
    // translate the input phrase
    translated_phrase = translate(phrase);
    
    // print the translated phrase
    printf("Here is your translated phrase: %s\n", translated_phrase);
    
    return 0;
}