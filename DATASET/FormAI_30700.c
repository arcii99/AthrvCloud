//FormAI DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100]; //initialize a char array to store user input
    printf("Enter some text: "); 
    fgets(input, 100, stdin); //use fgets to read user input from standard input

    char *words[100]; //initialize an array of strings to store individual words from user input
    char *p = strtok(input, " "); //use strtok to split input into separate words at each space character
    int count = 0;
    while (p != NULL) {
        words[count++] = p; //add each word to the array of words
        p = strtok(NULL, " ");
    }

    printf("\nIndividual words: ");
    for (int i = 0; i < count; i++) {
        printf("%s ", words[i]); //print out each individual word in the array
    }

    printf("\n\nReversed words: ");
    for (int i = 0; i < count; i++) {
        int length = strlen(words[i]); //get the length of the current word
        char reversed[length]; //initialize a char array to store the reversed word
        for (int j = 0; j < length; j++) {
            reversed[j] = words[i][length-j-1]; //reverse the current word and store it in the reversed array
        }
        printf("%s ", reversed); //print out the reversed word
    }

    printf("\n\nUppercase words: ");
    for (int i = 0; i < count; i++) {
        int length = strlen(words[i]); //get the length of the current word
        char uppercase[length]; //initialize a char array to store the uppercase word
        for (int j = 0; j < length; j++) {
            uppercase[j] = toupper(words[i][j]); //convert each character in the current word to uppercase and store it in the uppercase array
        }
        printf("%s ", uppercase); //print out the uppercase word
    }

    return 0; //return success
}