//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cat Language Dictionary
char* catDictionary[] = {
    "meow", "hello",
    "purr", "thank you",
    "hiss", "leave me alone",
    "mew", "what's up",
    "yowl", "I'm hungry",
    "growl", "back off!",
    "scratch", "I want attention",
    "nip", "play with me",
    "tail twitch", "I'm irritated",
    "snore", "I'm sleepy",
    "lick", "I love you",
    "paw up", "I want something",
    "chirp", "I'm happy",
    "whine", "I'm sad"
};

int main(){
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a cat sound to translate:\n");

    char input[10];
    fgets(input, 10, stdin); //Get user input

    printf("\n");

    //Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    int i;
    for(i = 0; i < sizeof(catDictionary)/sizeof(catDictionary[0]); i += 2){
        //If input matches a cat sound in the dictionary
        if(strcmp(input, catDictionary[i]) == 0){
            printf("Translation: %s\n", catDictionary[i+1]);
            return 0; //End program
        }
    }
    
    //If input is not in the dictionary
    printf("Translation: I don't understand.\n");

    return 0;
}