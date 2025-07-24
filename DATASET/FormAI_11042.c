//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input[1000]; // variable to store user input
    int length, i;

    printf("Good morrow, gentle user! Pray tell, what tidings bringeth thee?\n"); // ask for user input
    fgets(input, sizeof(input), stdin); // get user input

    length = strlen(input); // get length of the input

    // loop through each character in the input and replace non-alphanumeric characters with spaces
    for(i = 0; i < length; i++){
        if(!isalnum(input[i])){ // check if the character is non-alphanumeric
            input[i] = ' '; // replace with space
        }
    }

    printf("Thou hast spoken thusly: %s\nThank thee for thy words, and fare thee well!\n", input); // print sanitized user input

    return 0;
}