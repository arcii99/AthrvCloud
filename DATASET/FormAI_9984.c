//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
/* This program manipulates a string by converting it to UPPERCASE and then TITLING it.
   The user will input a sentence and the program will use this concept to manipulate it. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char sentence[MAX_SIZE], modified[MAX_SIZE];
    int length, i;

    printf("Please enter a sentence that you would like to manipulate.\n");
    fgets(sentence, MAX_SIZE, stdin);

    length = strlen(sentence);

    for(i = 0; i < length; i++) {
        modified[i] = toupper(sentence[i]); 
        /* Convert each character to uppercase */
    }

    /* Title Case the UPPERCASED sentence */
    modified[0] = toupper(modified[0]);

    for(i = 0; i < length; i++) {
        if(modified[i] == ' ') {
            modified[i+1] = toupper(modified[i+1]);
        }
    }

    printf("Your original sentence was:\n%s\n", sentence);
    printf("Your modified sentence is:\n%s", modified);

    return 0;
}