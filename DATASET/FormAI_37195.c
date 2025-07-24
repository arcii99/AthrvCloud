//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>

// Function to translate alien language to english
char* translate(char* alienPhrase){
    char* englishPhrase;
  
    // Implement your own logic to translate the alien language
    /* For example, let's say the alien language is just simple substitution cipher
        where a is replaced with z, b with y, c with x and so on. */
    for(int i=0; i<strlen(alienPhrase); i++){
        if(isalpha(alienPhrase[i])){
            englishPhrase[i] = 'a' + ('z' - tolower(alienPhrase[i]));
        }
        else{
            englishPhrase[i] = alienPhrase[i];
        }
    }
    englishPhrase[strlen(alienPhrase)] = '\0';
  
    return englishPhrase;
}

int main(){
    printf("Enter the alien language phrase: ");
    char alienPhrase[100];
    gets(alienPhrase);
  
    char* englishPhrase = translate(alienPhrase);
  
    printf("Translated phrase: %s", englishPhrase);

    return 0;
}