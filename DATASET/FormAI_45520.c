//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: statistical
#include <stdio.h>
#include <string.h>

int main(){

    char english[][50] = {"meow", "purr", "hiss", "scratch", "claw"};
    char cat[][50] = {"I'm hungry", "I'm happy", "I'm angry", "I need attention", "I need to sharpen my claws"};

    int numWords = sizeof(english) / sizeof(english[0]); //Calculate the number of words in the array

    char input[50]; //Declare an input string variable

    printf("Enter a word in English: ");
    scanf("%s", input);

    int i;
    int found = 0;

    for(i = 0; i < numWords; i++){
        if(strcmp(input, english[i]) == 0){ //If the word is found
            printf("In cat language: %s\n", cat[i]); //Print the equivalent cat word
            found = 1;
            break;
        }
    }

    if(!found){ //If word is not found
        printf("Sorry, I don't know what that means in cat language.\n");
    }

    return 0;
}