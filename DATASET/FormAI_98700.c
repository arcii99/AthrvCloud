//FormAI DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

char* compress(char* input_string) {
    char* compressed_string = (char*) malloc(BUFFER_SIZE*sizeof(char));
    int input_length = strlen(input_string);
    int compressed_length = 0;
    int i, count;
    char current_char;
    for(i = 0; i < input_length; i++) {
        count = 1;
        current_char = input_string[i];
        while(input_string[i+1] == current_char) {
            count++;
            i++;
        }
        if(count > 1) {
            compressed_length += sprintf(&compressed_string[compressed_length], "%d%c", count, current_char);
        } else {
            compressed_length += sprintf(&compressed_string[compressed_length], "%c", current_char);
        }
    }
    if(compressed_length < input_length) {
        compressed_string = (char*) realloc(compressed_string, compressed_length*sizeof(char));
        return compressed_string;
    } else {
        return input_string;
    }
}

int main() {
    char input_string[BUFFER_SIZE];
    char* result;
    printf("Enter a string to compress: ");
    fgets(input_string, BUFFER_SIZE, stdin);
    input_string[strcspn(input_string, "\n")] = 0;
    printf("Original string: %s\n", input_string);
    result = compress(input_string);
    printf("Compressed string: %s\n", result);
    free(result);
    return 0;
}