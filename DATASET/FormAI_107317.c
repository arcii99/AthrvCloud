//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    // Welcome to the C Alien Language Translator!
    printf("Welcome to the C Alien Language Translator!\n\n");

    // Declare variables
    char c_alien_text[101];
    char c_translated_text[101] = "";

    // Get input from the user
    printf("Please enter your text in C Alien language: ");
    scanf("%[^\n]%*c", c_alien_text);

    // Translate the text
    for(int i=0; i < strlen(c_alien_text); i++){
        if(c_alien_text[i] == 'C'){
            strcat(c_translated_text, "K");
        }
        else if(c_alien_text[i] == 'c'){
            strcat(c_translated_text, "k");
        }
        else if(c_alien_text[i] == 'A'){
            strcat(c_translated_text, "Z");
        }
        else if(c_alien_text[i] == 'a'){
            strcat(c_translated_text, "z");
        }
        else if(c_alien_text[i] == 't'){
            strcat(c_translated_text, "d");
        }
        else if(c_alien_text[i] == 'T'){
            strcat(c_translated_text, "D");
        }
        else if(c_alien_text[i] == ' '){
            strcat(c_translated_text, " ");
        }
        else{
            strcat(c_translated_text, "X");
        }
    }

    // Print the translated text
    printf("Translated text: %s\n", c_translated_text);

    // Thank you for using the C Alien Language Translator!
    printf("\nThank you for using the C Alien Language Translator!");
}