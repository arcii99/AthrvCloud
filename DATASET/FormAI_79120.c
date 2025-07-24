//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include <stdio.h>
#include <string.h>

int main(){
    char c_cat_language[100], translated_language[100];
    printf("Input a sentence in C Cat Language: ");
    fgets(c_cat_language, sizeof(c_cat_language), stdin);
    
    // Loop through each character in input
    for(int i=0; i<strlen(c_cat_language); i++){
        switch(c_cat_language[i]){
            case 'C':
                translated_language[i] = 'Meow';
                break;
            case 'c':
                translated_language[i] = 'mew';
                break;
            case ' ':
                translated_language[i] = ' ';
                break;
            case '\n':
                translated_language[i] = '\0';
                break;
            default:
                printf("Invalid input");
                return 0;
        }
    }
    printf("Translated sentence: %s", translated_language);
    return 0;
}