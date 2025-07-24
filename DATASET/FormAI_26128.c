//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
#include<stdio.h> 

void main() {
    // variable declaration
    char alien_language[7][10] = {"Yexe", "Trigo", "Waza", "Nybok", "Gorplax", "Vuton", "Kallix"};
    char english_translation[7][10] = {"Hello", "Goodbye", "Thank you", "Sorry", "Yes", "No", "Love"};

    char input[20];
    int i, j;

    printf("Welcome to the C Alien Language Translator! \n");
    printf("Please enter a phrase in Alien Language (Yexe, Trigo, Waza, Nybok, Gorplax, Vuton, Kallix): \n");

    // user input
    fgets(input, 20, stdin);

    // code to remove newline character from input
    for(i = 0; input[i] != '\0'; i++) {
        if(input[i] == '\n') {
            input[i] = '\0';
        }
    }

    // translation
    for(i = 0; i < 7; i++) {
        if(strcmp(alien_language[i], input) == 0) {
            printf("\n In English: %s \n", english_translation[i]);
            return;
        }
    }

    // if input language is not recognized
    printf("Sorry, the input language is not recognized. Please enter a valid input! \n");
}