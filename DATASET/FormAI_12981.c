//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: inquisitive
#include<stdio.h>
#include<string.h>

int main(){
    char inputText[1000];
    printf("Welcome to the C Cat Language Translator! \n");
    printf("Enter your text to be translated: ");
    fgets(inputText, 1000, stdin);
    inputText[strlen(inputText)-1] = '\0'; // Removing the newline character from input

    printf("\nGot it! Translating your text now...\n");

    // Loop through the inputText to convert the words
    for(int i=0; i<strlen(inputText); i++){
        if(inputText[i] == 'c' || inputText[i] == 'C'){
            printf("Meow! ");
        }
        else if(inputText[i] == 'a' || inputText[i] == 'A'){
            printf("Purr! ");
        }
        else if(inputText[i] == 't' || inputText[i] == 'T'){
            printf("Snuggle! ");
        }
        else if(inputText[i] == 'e' || inputText[i] == 'E'){
            printf("Rub! ");
        }
        else {
            printf("%c", inputText[i]);
        }
    }
    return 0;
}