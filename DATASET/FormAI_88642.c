//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: careful
#include <stdio.h>
#include <string.h>

int main(){
    char c_cat_language[100];
    char translated_text[100];
    int length, i, j = 0;

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter your sentence in C Cat Language: ");
    scanf("%[^\n]%*c", c_cat_language);

    length = strlen(c_cat_language);

    // Translate C Cat Language to English
    for(i = 0; i < length; i++){
        if(c_cat_language[i] == 'c'){
            translated_text[j] = 'h';
            translated_text[j+1] = 'a';
            translated_text[j+2] = 't';
            j+=3;
        }
        else if(c_cat_language[i] == 'C'){
            translated_text[j] = 'H';
            translated_text[j+1] = 'A';
            translated_text[j+2] = 'T';
            j+=3;
        }
        else{
            translated_text[j] = c_cat_language[i];
            j++;
        }
    }
    translated_text[j] = '\0';

    printf("Translated Text: %s", translated_text);

    return 0;
}