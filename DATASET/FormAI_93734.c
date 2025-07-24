//FormAI DATASET v1.0 Category: Compression algorithms ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000], output[1000]; //declare input and output buffer
    printf("Enter input string: ");
    scanf("%s", input); //get input from user

    int input_len = strlen(input); //calculate length of input
    int output_len = 2 * input_len; //set length of output buffer

    int count = 1, output_index = 0; //initialize count and output index
    char current_char = input[0]; //set current character to first character of input

    //loop through input characters, starting from second character
    for (int i = 1; i < input_len; i++) {
        if (input[i] == current_char) { //if current character is same as previous character
            count++; //increment count
        } else { //if current character is different from previous character
            //add compressed representation of previous character to output buffer
            output[output_index++] = current_char;
            output[output_index++] = count + '0';
            current_char = input[i]; //set current character to current input character
            count = 1; //reset count
        }

        if (output_index >= output_len) { //if output buffer is full
            printf("Output buffer is full.\n");
            break;
        }
    }

    //add compressed representation of last character to output buffer
    output[output_index++] = current_char;
    output[output_index++] = count + '0';

    printf("Compressed string: %s\n", output); //print compressed string

    return 0;
}