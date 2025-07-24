//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: funny
#include <stdio.h>
#include <string.h>

int main() 
{
    char input[1000]; // array to hold user input
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please enter your text to be translated:\n");
    fgets(input, 1000, stdin); // taking user input

    printf("Translating your text...\n");
    int length = strlen(input);

    for (int i = 0; i < length; i++) { // loop through each character
        if (input[i] == 'C') {
            input[i] = 'Z'; // replace C with Z
        }
        else if (input[i] == 'c') {
            input[i] = 'z'; // replace c with z
        }
        else if (input[i] == ' ') {
            input[i] = '_'; // replace space with underscore
        }
        else if (input[i] == '.') {
            input[i] = '!'; // replace . with !
        }
    }

    printf("Your translated text is:\n%s", input); // print the translated text
    
    printf("\nWould you like to translate more text? (y/n)\n");
    char choice;
    scanf("%c", &choice);
    if (choice == 'y') {
        printf("\n");
        main(); // call main function again for more translations
    }
    else {
        printf("Thank you for using the C Alien Language Translator!");
    }
    return 0;
}