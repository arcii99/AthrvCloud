//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <string.h>

int main(){
    char alienLang[1000], translated[1000];
    int i, length; 

    printf("Enter the message in Alien Language (only using symbols X, Y, and Z): ");
    fgets(alienLang, 1000, stdin); // Taking user input
    length = strlen(alienLang);

    // Translation
    for(i=0; i<length; i++){
        switch(alienLang[i]){
            case 'X':
                translated[i] = 'A'; // X is translated to A
                break;
            case 'Y':
                translated[i] = 'E'; // Y is translated to E
                break;
            case 'Z':
                translated[i] = 'I'; // Z is translated to I
                break;
            default:
                translated[i] = alienLang[i];

        }
    }

    printf("Original Message: %s", alienLang); // Printing original message
    printf("Translated Message: %s", translated); // Printing translated message

    return 0;
}