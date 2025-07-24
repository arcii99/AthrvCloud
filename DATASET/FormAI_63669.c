//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: future-proof
#include <stdio.h>
#include <string.h>

void translate(char input[], char output[]);

int main() {
    char input[100], output[100];

    printf("Enter the input string in C Alien language: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove the newline character from input

    translate(input, output);

    printf("Translated string: %s", output);

    return 0;
}

void translate(char input[], char output[]) {
    int i, j;
    char temp;

    for(i = 0, j = 0; i < strlen(input); i++, j++) {
        temp = input[i];

        if(temp == 'C') { // If 'C' is found, replace it with 'A'
            output[j] = 'A';
            j++;
            output[j] = 'A';
        }
        else if(temp == 'M') { // If 'M' is found, replace it with 'E'
            output[j] = 'E';
            j++;
            output[j]= 'E';
        }
        else if(temp == 'Y') { // If 'Y' is found, replace it with 'I'
            output[j] = 'I';
        }
        else { // If character is not 'C', 'M' or 'Y', keep it as it is
            output[j] = temp;
        }
    }

    output[j] = '\0'; // Add the terminating null character to the output string
}