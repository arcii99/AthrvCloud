//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void translate(char input[]) {
    // define alien letters
    char alienLetters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
                           'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
    // define corresponding human letters in romantic language
    char humanLetters[] = {'à', 'ä', 'é', 'è', 'ë', 'î', 'ï', 'ô', 'ö', 'ù', 'ü', 'ç', 'œ', 'ÿ', 
                           'â', 'ê', 'î', 'ô', 'û', 'ç', 'ë', 'ï', 'ü', 'ä', 'ö', 'ï', ' '};
    
    int length = strlen(input);
    printf("Your translated message is: \n");
    for (int i = 0; i < length; i++) {
        char currentChar = input[i];
        // search for the index of the current alien letter
        for (int j = 0; j < 27; j++) { //27 is the number of letters in the alienLetters array
            if (currentChar == alienLetters[j]) {
                printf("%c", humanLetters[j]); // print the corresponding human romantic letter
                break; // exit this loop and move to the next character
            }
        }
    }
}

int main(void) {
    char input[100]; // assume input is no longer than 100 characters
    printf("Welcome to the C Alien Language Translator!\n");
    
    while (1) { // loop until user inputs "exit"
        printf("\nType in the message you want to translate (or type 'exit' to quit): \n");
        scanf("%[^\n]", input);
        getchar(); // consume the newline character in stdin
        
        if (strcmp(input, "exit") == 0) {
            printf("\nThanks for using C Alien Language Translator! Goodbye!\n");
            break; // exit the while loop and end the program
        } else {
            translate(input);
        }
    }
    return 0;
}