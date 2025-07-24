//FormAI DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// This is a program that takes a user's input, counts the number
// of spaces and words in the input, and outputs a special "thank you" message

int main() {
    char input[100];
    int num_spaces = 0, num_words = 0;
    printf("Please enter some text: ");
    fgets(input, 100, stdin);

    for(int i = 0; input[i] != '\0'; i++) {
        if(isspace(input[i]) && !isspace(input[i-1]))
            num_words++;
        else if(isspace(input[i]))
            num_spaces++;
    }

    printf("\nThank you for your input!\n");
    printf("Your input had %d words and %d spaces.\n", num_words, num_spaces);
    printf("Your input is greatly appreciated. Have a wonderful day!\n");

    return 0;
}