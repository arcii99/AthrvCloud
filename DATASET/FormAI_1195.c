//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// A basic implementation of word frequency counter in C

#define MAX_DATA 10000 // define the maximum size of input string

int main() {
    // Declare variables and initialize them
    int i, j, freq[MAX_DATA], counter = 0;
    char data[MAX_DATA], words[MAX_DATA][50], temp[50];

    printf("Enter a string: ");
    fgets(data, MAX_DATA, stdin); // take input string from user

    // Replace all the punctuations with whitespace
    for(i = 0; data[i] != '\0'; i++) {
        if(ispunct(data[i])) {
            data[i] = ' ';
        }
    }

    // Convert all the characters to lower case
    for(i = 0; data[i] != '\0'; i++) {
        data[i] = tolower(data[i]);
    }

    // Split input string into words
    for(i = 0, j = 0; data[i] != '\0'; i++) {
        if(isalpha(data[i])) { // check if the current character is alphabetic
            temp[j++] = data[i]; // add character to temporary string
        }
        else { // if current character is not alphabetic
            temp[j] = '\0'; // terminate the temporary string
            if(j > 0) { // check if the temporary string is not empty
                strcpy(words[counter], temp); // copy the temporary string to the list of words
                freq[counter] = 1; // set the frequency of the word to 1
                counter++; // increment the counter
            }
            j = 0; // reset the temporary string index
        }
    }

    // Sort the list of words using bubble sort
    for(i = 0; i < counter-1; i++) {
        for(j = i+1; j < counter; j++) {
            if(strcmp(words[i], words[j]) > 0) {
                // swap words[i] with words[j]
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
                // swap freq[i] with freq[j]
                int tmp = freq[i];
                freq[i] = freq[j];
                freq[j] = tmp;
            }
        }
    }

    // Calculate frequency of each word
    for(i = 0; i < counter; i++) {
        for(j = i+1; j < counter; j++) {
            if(strcmp(words[i], words[j]) == 0) { // if the words are same
                freq[i]++; // increment the frequency of the word
                freq[j] = 0; // set the frequency of the duplicate word to 0
            }
        }
    }

    // Display the list of unique words with their frequencies
    printf("\nWord Frequency\n");
    for(i = 0; i < counter; i++) {
        if(freq[i] != 0) { // check if the frequency is not 0
            printf("%-15s %d\n", words[i], freq[i]);
        }
    }

    return 0; // end program
}