//FormAI DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to Dr. Chuckles' Text Improver\n");
    printf("Enter your text to make it more fun: ");
    char input[100];
    fgets(input, 100, stdin);
    
    char output[1000];
    int output_position = 0;
    int input_position = 0;
    int length = strlen(input);
    
    while (input_position < length) {
        if (input[input_position] == ' ') {
            output[output_position++] = input[input_position++];
        } else if (input[input_position] == 'e') {
            output[output_position++] = 'h';
            output[output_position++] = 'e';
            input_position++;
        } else if (input[input_position] == 'r') {
            output[output_position++] = 'a';
            output[output_position++] = 'r';
            input_position++;
        } else if (input[input_position] == 'i') {
            output[output_position++] = 'y';
            output[output_position++] = 'o';
            output[output_position++] = 'h';
            output[output_position++] = 'o';
            input_position++;
        } else if (input[input_position] == 'o') {
            output[output_position++] = 'o';
            output[output_position++] = 'h';
            output[output_position++] = 'o';
            input_position++;
        } else if (input[input_position] == 'u') {
            output[output_position++] = 'w';
            output[output_position++] = 'o';
            output[output_position++] = 'o';
            input_position++;
        } else if (input[input_position] == 'a') {
            output[output_position++] = 'a';
            output[output_position++] = 'r';
            output[output_position++] = 'r';
            output[output_position++] = 'r';
            input_position++;
        } else {
            output[output_position++] = input[input_position++];
        }
    }
    
    output[output_position++] = '\0';
    printf("Here is your improved text: %s", output);
    return 0;
}