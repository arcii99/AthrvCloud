//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// declare a compress function
void compress(char* inputString);

int main() {
    // welcome message for the user
    printf("Hi there! Let's compress some strings!\n");

    // get user input
    char inputString[100];
    printf("Please enter a string to compress (max 100 characters): ");
    scanf("%99s", inputString);

    // pass the string to the compress function
    compress(inputString);

    // farewell message for the user
    printf("\nAll done! Have a great day!\n");

    return 0;
}

// define the compress function
void compress(char* inputString){

    // create a new string to store the compressed version
    char compressedString[100];
    memset(compressedString, 0, sizeof(compressedString));

    // find the length of the input string
    int length = strlen(inputString);

    // check for an empty string
    if (length == 0) {
        printf("Oops, you entered an empty string! Please try again.\n");
        exit(0);
    }

    // count the occurrences of each character
    int count = 1;
    char currentChar = inputString[0];
    int compressedIndex = 0;
    for (int i=1; i<length; i++) {
        if (inputString[i] == currentChar) {
            count++;
        }
        else {
            // add the compressed version of the character to the output string
            compressedString[compressedIndex++] = currentChar;
            compressedString[compressedIndex++] = count + '0';
            
            // reset the count and currentChar variables
            count = 1;
            currentChar = inputString[i];
        }
    }

    // add the last character and its count to the output string
    compressedString[compressedIndex++] = currentChar;
    compressedString[compressedIndex++] = count + '0';

    printf("Here's the compressed version of your string: %s\n", compressedString);
}