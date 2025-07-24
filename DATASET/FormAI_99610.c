//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: innovative
#include<stdio.h>
#include<string.h>

void main() {
    char input[100];
    printf("Enter a sentence in cat language: ");
    fgets(input, 100, stdin); // read input

    char output[1000] = ""; // initialize output string

    for(int i = 0; i < strlen(input); i++) { // iterate over input string
        if(input[i] == 'C' || input[i] == 'c') { // convert C to Meow
            strcat(output, "Meow");
        } else if(input[i] == 'A' || input[i] == 'a') { // convert A to Purr
            strcat(output, "Purr");
        } else if(input[i] == 'T' || input[i] == 't') { // convert T to Hiss
            strcat(output, "Hiss");
        } else if(input[i] == ' ') { // add spaces as is
            strcat(output, " ");
        } else { // add other characters unchanged
            output[strlen(output)] = input[i];
        }
    }

    printf("Your sentence in human language: %s", output); // output translated string
}