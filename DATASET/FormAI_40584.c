//FormAI DATASET v1.0 Category: Text processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_text(char* text) {
    int len = strlen(text);
    char* output = (char*) malloc(len + 1);
    int output_index = 0;
    for(int i = 0; i < len; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z') { // convert uppercase to lowercase
            output[output_index] = text[i] + ('a' - 'A');
            output_index++;
        }
        else if(text[i] >= 'a' && text[i] <= 'z') { // convert lowercase to uppercase
            output[output_index] = text[i] - ('a' - 'A');
            output_index++;
        }
        else if(text[i] == ' ') { // add an underscore for spaces
            output[output_index] = '_';
            output_index++;
        }
        else {
            // ignore any other characters
        }
    }
    output[output_index] = '\0'; // add null terminator
    printf("%s\n", output); // print processed text
    free(output); // free dynamically allocated memory
}

int main() {
    char* input = (char*) malloc(1000); // allocate memory for input
    printf("Enter some text to process: ");
    fgets(input, 1000, stdin); // read input from stdin
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline from input
    process_text(input); // process input
    free(input); // free dynamically allocated memory
    return 0;
}