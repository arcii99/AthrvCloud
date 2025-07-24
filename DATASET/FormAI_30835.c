//FormAI DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[100];
    int count = 0, check = 0, uppercount = 0;

    printf("Enter some text (up to 100 characters):\n");
    fgets(input, sizeof(input), stdin);

    for(int i = 0; input[i] != '\0'; i++) {
        if(isalpha(input[i])) {  // check if the character is a letter
            count++;
        }
        if(isupper(input[i])) { // check if the character is uppercase
            uppercount++;
        }
        if(input[i] == ' ' || input[i] == '\n') { // check if the word has ended
            if(count == uppercount) { // if count and uppercount matches, this is a word with all uppercased letters
                check++;
            }
            count = 0;
            uppercount = 0;
        }
    }

    printf("The number of words with all capital letters is: %d", check);

    return 0;
}