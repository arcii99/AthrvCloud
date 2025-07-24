//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: immersive
#include<stdio.h>
#include<string.h>

// function to check if the input string is a cat language phrase or not
int checkPhrase(char* phrase) {
    int len = strlen(phrase);
    
    // check if the string ends with "meow" or not
    if (len >= 4 
       && phrase[len - 1] == 'w' 
       && phrase[len - 2] == 'o' 
       && phrase[len - 3] == 'e' 
       && phrase[len - 4] == 'm') {
        return 1;
    }
    
    return 0;
}

int main() {
    char input[100];
    
    printf("Welcome to the Cat Language Translator!\n");
    printf("Enter a phrase in cat language: ");
    scanf("%[^\n]", input); // read input until the user hits enter
    
    if (checkPhrase(input)) {
        printf("Translation: Meow meow meow...\n");
    } else {
        printf("Translation: Sorry, I only understand phrases in cat language.\n");
    }
    
    return 0;
}