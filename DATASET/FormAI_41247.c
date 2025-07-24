//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <string.h>

char *alien_vocab[] = {"klaatu", "barada", "nikto"}; // defining the alien vocabulary

char *english_meaning[] = {"Hello", "Goodbye", "Thank You"}; // defining the english meanings

char *alien_speak[] = {"Klaatu", "Barada", "Nikto"}; // defining the alien speak to have first letter capitalized

int main()
{
    char input[20]; // input string
    
    printf("Enter an alien word: ");
    scanf("%s", input); // storing user input in input variable 

    for(int i=0; i<3; i++) { // loop through all possible alien words
        if(strcmp(input, alien_vocab[i]) == 0) { // if input matches the alien word
            printf("The translation in English is: %s\n", english_meaning[i]); // print the english meaning
            printf("In Alien Speak, it is: %s", alien_speak[i]); // print the alien speak
            return 0; // end program
        }
    }

    printf("Sorry, I cannot translate that word."); // if input does not match any alien word

    return 0;
}