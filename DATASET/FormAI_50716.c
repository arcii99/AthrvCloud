//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: careful
#include<stdio.h>
#include<string.h>

int main(){

    char alien_language[5][20] = {"la", "va", "ro", "ki", "na"}; // Alien words
    char english_translation[5][20] = {"hello", "goodbye", "thank you", "please", "sorry"}; // English words

    char input[20];
    printf("Enter a word in the Alien Language: ");
    scanf("%s", input);

    int i;
    for(i=0; i<5; i++){
        if(strcmp(input, alien_language[i]) == 0){ // If input is the same as an alien word
            printf("English Translation: %s\n", english_translation[i]); // Print the corresponding English word
            break;
        }
    }

    if(i == 5){ // If input is not one of the alien words
        printf("I'm sorry, I don't understand.\n"); // Print that the translator does not understand
    }

    return 0;
}