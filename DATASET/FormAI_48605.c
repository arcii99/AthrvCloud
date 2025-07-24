//FormAI DATASET v1.0 Category: Text processing ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    char output[1000];

    printf("Enter some text in medieval style: ");
    fgets(input, sizeof(input), stdin);

    int input_length = strlen(input);
    int output_index = 0;

    for(int i = 0; i < input_length; i++) {
        if(input[i] == 'a') {
            output[output_index++] = 'e';
        }
        else if(input[i] == 'o') {
            output[output_index++] = 'u';
        }
        else if(input[i] == 'i') {
            output[output_index++] = 'y';
        }
        else if(input[i] == 'm') {
            output[output_index++] = 'n';
            output[output_index++] = 'e';
        }
        else if(input[i] == 'p') {
            output[output_index++] = 'f';
            output[output_index++] = 'i';
            output[output_index++] = 'e';
        }
        else if(input[i] == 'k') {
            output[output_index++] = 'c';
            output[output_index++] = 'h';
        }
        else if(input[i] == 'q') {
            output[output_index++] = 'k';
            output[output_index++] = 'u';
        }
        else if(input[i] == 'c') {
            output[output_index++] = 'k';
        }
        else if(input[i] == 'h') {
            output[output_index++] = 'g';
        }
        else if(input[i] == 'w') {
            output[output_index++] = 'v';
        }
        else if(input[i] == 'x') {
            output[output_index++] = 'c';
            output[output_index++] = 's';
        }
        else if(input[i] == 'z') {
            output[output_index++] = 's';
        }
        else {
            output[output_index++] = input[i];
        }
    }

    printf("In modern English, it says: %s\n", output);
    return 0;
}