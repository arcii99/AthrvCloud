//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: ephemeral
#include <stdio.h>

int main() {
    char word[100]; // array to store input word
    int checksum = 0; // variable to store the sum of ASCII values
    int i = 0; // counter variable
    
    printf("Welcome to the Checksum Calculator!\n");
    printf("Please enter a word: ");
    scanf("%s", word); // get user input
    
    while (word[i] != '\0') { // loop through each character in the word
        checksum += (int)word[i]; // add the ASCII value of each character to the checksum
        i++; // increment the counter variable
    }
    
    printf("The checksum of \"%s\" is: %d\n", word, checksum); // print the result
    
    return 0; // end the program
}