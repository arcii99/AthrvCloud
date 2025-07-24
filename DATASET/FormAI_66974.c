//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to implement mathematical compression algorithm
void compression(char *input_str) {
    int length = strlen(input_str);
    int count = 1, pos = 0;
    char *output_str = (char*) malloc(length * sizeof(char));

    // iterate through the input string and compress it
    for(int i = 0; i < length; i++) {
        if(input_str[i] == input_str[i+1]) {
            count++;
        } else {
            output_str[pos++] = input_str[i];
            if(count > 1) {
                output_str[pos++] = (char) (count + '0');
                count = 1;
            }
        }
    }

    output_str[pos] = '\0';
    printf("Compressed String: %s\n", output_str);
    free(output_str);
}

int main() {
    char input_str[100];
    printf("Enter the string to compress: ");
    fgets(input_str, 100, stdin);

    // remove newline character from input string
    input_str[strcspn(input_str, "\n")] = 0;

    // call compression function to compress the input string
    compression(input_str);
    return 0;
}