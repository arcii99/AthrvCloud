//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: minimalist
#include <stdio.h>

// function to print ASCII art of a letter
void printLetter(char letter) {
    int asciiValue = (int)letter; // get the ASCII value of the letter
    int i, j;
    for (i = 0; i < 8; i++) { // print 8 rows
        for (j = 0; j < 8; j++) { // print 8 columns
            if (asciiValue % 2 == 0) { // check if the least significant bit is 0 or 1
                printf(" "); // print a space
            } else {
                printf("#"); // print a hash symbol
            }
            asciiValue /= 2; // shift bits to the right
        }
        printf("\n"); // move to the next line
    }
}

int main() {
    char input; // create a variable to store user input
    printf("Enter a letter: ");
    scanf("%c", &input); // get user input
    printLetter(input); // call the function to print ASCII art
    return 0;
}