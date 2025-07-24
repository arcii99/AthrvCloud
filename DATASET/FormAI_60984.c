//FormAI DATASET v1.0 Category: Text processing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char input[100];
    char output[100];
    char delimiter[2] = " ";
    char * token;
    int count = 0;

    printf("Please enter a sentence with spaces: ");
    fgets(input, 100, stdin);

    token = strtok(input, delimiter); // Get the first token

    while (token != NULL) {
        int length = strlen(token);
        char reversed[length + 1];

        for (int i = length - 1, j = 0; i >= 0; i--, j++) {
            reversed[j] = token[i];
        }

        reversed[length] = '\0';
        strcat(output, reversed);
        strcat(output, " ");
        count++;
        token = strtok(NULL, delimiter); // Get the next token
    }

    printf("\nThe original sentence is: %s", input);
    printf("The reversed sentence is: %s\n", output);
    printf("The sentence has %d words.\n", count);

    return 0;
}