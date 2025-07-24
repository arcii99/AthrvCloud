//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 1000

int main()
{
    char input_string[MAX_STRING_SIZE];
    char output_string[MAX_STRING_SIZE] = "";
    int i, j;

    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_SIZE, stdin);

    for (i = 0; i < strlen(input_string); i++) {
        if (input_string[i] == 't') {
            output_string[strlen(output_string)] = '7';
        } else if (input_string[i] == 'a') {
            output_string[strlen(output_string)] = '4';
        } else if (input_string[i] == 'o') {
            output_string[strlen(output_string)] = '0';
        } else if (input_string[i] == 's') {
            output_string[strlen(output_string)] = '5';
        } else {
            output_string[strlen(output_string)] = input_string[i];
        }
    }

    printf("Output string: %s\n", output_string);

    return 0;
}