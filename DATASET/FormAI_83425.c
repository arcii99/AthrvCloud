//FormAI DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter a string to brave-ify: ");
    fgets(input, sizeof(input), stdin); // get user input

    int length = strlen(input); // get length of input string
    int i;

    for (i = 0; i < length; i++) {
        if (isalpha(input[i])) { // if character is an alphabetical letter
            if (i % 2 == 0) { // if character index is even
                input[i] = toupper(input[i]); // convert to uppercase
            } else { // if character index is odd
                input[i] = tolower(input[i]); // convert to lowercase
            }
        }
    }

    printf("Your brave-ified string is: %s\n", input); // output the modified string
    return 0;
}