//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void translate(char *input) {
    /* This function translates the input string into a cat language */
    
    int i, j, len;
    len = strlen(input);
    char output[(len*3)+1]; // Preparing an output array with ample space
    output[0] = '\0';
    
    for (i = 0; i < len; i++) {
        if (input[i] == ' ') {
            strcat(output, " ");
            continue;
        }
        for (j = 0; j < 3; j++) {
            strcat(output, "meow"); // "meow" is the equivalent of "a", "b", and "c"
        }
        if (i != len-1 && input[i+1] != ' ') {
            strcat(output, " ");
        }
    }
    
    printf("\nCat language translation: %s\n", output);
}

int main() {
    char input[100];
    printf("Enter a sentence to translate into cat language: ");
    fgets(input, 100, stdin); // Reading user input
    translate(input);
    return 0;
}