//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main()
{	
    char alien_lang[] = "zyxwvutsrqponmlkjihgfedcba"; //alien language

    int i, j, k, l;
    char input[100], output[100], temp;

    printf("Enter an alien language sentence to translate: ");
    fgets(input, 100, stdin); //get input string from user

    for(i = 0; i < strlen(input); i++) {
        if(input[i] != ' ') { //if character is not a space
            for(j = 0; j < strlen(alien_lang); j++) {
                if(input[i] == alien_lang[j]) { //if it matches with the alien language
                    k = j + 1; //save index of the alien language character
                    break;
                }
            }

            for(l = 0; l < strlen(alien_lang); l++) {
                if(input[i+1] == alien_lang[l]) { //if the next character matches with the alien language
                    temp = alien_lang[k]; //swap current alien language character with the next alien language character
                    alien_lang[k] = alien_lang[l];
                    alien_lang[l] = temp;
                    break;
                }
            }

            output[i] = alien_lang[k]; //replace current character with alien language character
        } else {
            output[i] = ' '; //if space, output space
        }
    }

    printf("Translated sentence: %s\n", output); //print translated sentence
    
    return 0;
}