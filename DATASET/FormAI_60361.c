//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char userInput[20];
    int maxLength = 20;

    printf("Enter a word or phrase: \n");

    fgets(userInput, maxLength, stdin);  //get user input as a string

    int length = strlen(userInput);

    //initialize array of ASCII art characters
    char artChars[59] = { ' ', '.', '\'', '`', '^', '"', ',', ':', ';', 'I', 'l', '!', 'i', '>', '<', '~', '+', '_', '-', '?', ']', '[', '}', '{', '1', ')', '(', 'L', 'o', '0', 'K', 'X', '%', '@', '#', '&', '$', '*', 'l', 't', 'f', 'x', 'r', 'n', '/', '\\', '|', '(', ')', 'v', 'u', 'c', 'j', 'z', '2', '3', '4', '5', '6', '7', '8', '9', 'T' };

    for (int i = 0; i < length; i++) {
        char currentChar = userInput[i];
        int index = (int)currentChar % 59;  //get an index to map to an ASCII art character
        printf("%c", artChars[index]);
    }

    return 0;
}