//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to translate a sentence to C Cat Language
void translateToCCat(char sentence[]){
    int i = 0; 
    printf("\nC Cat Translation: ");
    // Iterate through each character in the sentence
    while(sentence[i] != '\0'){
        if(sentence[i] == 'c' || sentence[i] == 'C'){ // If the character is 'c' or 'C'
            printf("meow"); // Translate to "meow"
        }
        else if(sentence[i] == 'a' || sentence[i] == 'A'){ // If the character is 'a' or 'A'
            printf("purr"); // Translate to "purr"
        }
        else if(sentence[i] == 't' || sentence[i] == 'T'){ // If the character is 't' or 'T'
            printf("hiss"); // Translate to "hiss"
        }
        else if(sentence[i] == ' '){ // If the character is a space
            printf(" "); // Print the space
        }
        else{ // If the character is not 'c', 'C', 'a', 'A', 't', or 'T'
            printf("%c", sentence[i]); // Print the character as is
        }
        i++; // Move on to the next character
    }
}

int main(){
    char sentence[100];
    printf("Enter a sentence to translate to C Cat Language: ");
    fgets(sentence, 100, stdin); // Get input sentence from user

    translateToCCat(sentence); // Translate the sentence to C Cat Language

    return 0;
}