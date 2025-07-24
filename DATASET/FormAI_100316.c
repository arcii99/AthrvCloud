//FormAI DATASET v1.0 Category: Compression algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *input_string = "AAAABBBBCCCCDDDDEEE";
    char *output_string = malloc(strlen(input_string) * 2);
    int i = 0, j = 0, count = 1;

    while (input_string[i] != '\0') {
        if (input_string[i] == input_string[i+1]) {
            count++;
        }
        else {
            output_string[j++] = input_string[i];
            output_string[j++] = count + '0';
            count = 1;
        }
        i++;
    }
    output_string[j] = '\0';
    printf("Input String: %s\n", input_string);
    printf("Output String: %s\n", output_string);

    free(output_string);
    return 0;
}