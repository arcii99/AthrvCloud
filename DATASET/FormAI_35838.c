//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateArt(char* input, int row) {
    if (row == 0) {
        return;
    }
    int l = strlen(input);
    char output[l*6]; // The output ASCII is 6 times larger than the input
    int k = 0;

    for (int i = 0; i < l; i++) {
        if (input[i] == ' ') {
            // Add space to each line of output
            for (int j = 0; j < 6; j++) {
                output[k++] = ' ';
            }
        } else {
            switch(input[i]) {
                case 'A':
                    output[k++] = '  /\\  ';
                    output[k++] = ' /  \\ ';
                    output[k++] = '/ /\\ \\';
                    output[k++] = '\\ \\/ /';
                    output[k++] = ' \\  / ';
                    output[k++] = '  \\/  ';
                    break;
                case 'B':
                    output[k++] = ' ____ ';
                    output[k++] = '| ___\\';
                    output[k++] = '| |__ ';
                    output[k++] = '|___ \\';
                    output[k++] = ' ___) |';
                    output[k++] = '|____/ ';
                    break;
                case 'C':
                    output[k++] = '  ____ ';
                    output[k++] = ' / ___|';
                    output[k++] = '| |    ';
                    output[k++] = '| |    ';
                    output[k++] = '| |___ ';
                    output[k++] = ' \\____|';
                    break;
                // Add more letters and characters here using switch case statements
                default:
                    printf("Invalid character: %c", input[i]);
            }
        }
        output[k++] = '\n';
    }
    printf("%s", output);
    generateArt(input, row-1); // Recurse with one less row each time
}

int main() {
    printf("Welcome to the ASCII Art Generator!\n");
    char input[] = "HELLO WORLD";
    int row = 5;
    generateArt(input, row);
    return 0;
}