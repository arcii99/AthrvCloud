//FormAI DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include <stdio.h> //The standard input/output library
#include <string.h> //The string manipulation library

int main(void) {

    //Define variables
    char input[1000]; //The input string to count
    int count = 0; //The count of words in the input string
    int length = 0; //The length of the input string (including whitespace)
    int i; //A loop counter

    //Print instructions to the user
    printf("Welcome to the puzzling word count tool! Please enter a string to count:\n");

    //Read in the user's input
    fgets(input, sizeof(input), stdin);

    //Calculate the length of the input string (including whitespace)
    length = strlen(input);

    //Iterate through each character in the input string
    for (i = 0; i < length; i++) {

        //If the current character is whitespace AND the previous character was not whitespace, then increment the word count
        if ((input[i] == ' ' || input[i] == '\n' || input[i] == '\t') && input[i-1] != ' ' && input[i-1] != '\n' && input[i-1] != '\t') {
            count++;
        }

    }

    //Add one to the word count to include the final word in the input string
    count++;

    //Print the word count to the user
    printf("The word count is: %d\n", count);

    //Exit the program
    return 0;

}