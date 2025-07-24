//FormAI DATASET v1.0 Category: String manipulation ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

void clear_string(char* str, int len) {
    memset(str, 0, len);
}

int main() {
    char input[MAX_LEN];
    char output[MAX_LEN];
    int input_len, output_len, i;

    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);
    input_len = strlen(input);
    if (input[input_len - 1] == '\n')
        input[input_len - 1] = '\0';
    input_len--;

    clear_string(output, MAX_LEN);
    output_len = 0;

    for (i = 0; i < input_len; i++) {
        if (('a' <= input[i] && input[i] <= 'z') || ('A' <= input[i] && input[i] <= 'Z'))
            output[output_len++] = input[i];
    }

    printf("Input string: %s\n", input);
    printf("Output string: %s\n", output);

    clear_string(input, MAX_LEN);
    input_len = 0;
    clear_string(output, MAX_LEN);
    output_len = 0;

    return 0;
}