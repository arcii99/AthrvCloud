//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the C Alien Language alphabet and translate function
char alien_alphabet[] = {'m', 'p', 'z', 'o', 'g', 'q', 'w', 'x', 'y', 'f', 't', 'r', 'e', 'd', 'c', 'v', 'b', 'n', 'h', 'a', 's', 'j', 'k', 'l', 'u', 'i'};
char english_alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char* translate(char* alien_text){
    char* translated_text = (char*) malloc(strlen(alien_text));
    int length = strlen(alien_text);

    for (int i=0; i<length; i++){
        char alien_character = alien_text[i];
        int english_index;
        for (int j=0; j<26; j++){
            if (alien_character == alien_alphabet[j]){
                english_index = j;
                break;
            }
        }
        translated_text[i] = english_alphabet[english_index];
    }

    return translated_text;
}

// Main program that prompts user for input and outputs translation
int main(){
    char alien_text[100];
    printf("Enter Alien text: ");
    fgets(alien_text, 100, stdin);
    printf("Translation: %s\n", translate(alien_text));
    return 0;
}