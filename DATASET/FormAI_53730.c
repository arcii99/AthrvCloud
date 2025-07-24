//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[100];
    printf("Enter the text: ");
    fgets(input, 100, stdin);

    int len = strlen(input);

    char ascii_art[7][len*6+1];

    for(int i=0; i<7; i++) {
        for(int j=0; j<len*6; j++) {
            ascii_art[i][j] = ' ';
        }
        ascii_art[i][len*6] = '\0';
    }

    for(int i=0; i<len; i++) {

        if(input[i] == ' ') {
            for(int k=0; k<7; k++) {
                ascii_art[k][i*6] = ' ';
            }
        }

        else {
            int offset = (int)input[i] - 65;

            if(offset < 0 || offset > 25) {
                printf("Invalid character: %c\n", input[i]);
                exit(0);
            }

            char *output[7];
            output[0] = "██╗  ██╗ ";
            output[1] = "██║ ██╔╝ ";
            output[2] = "█████╔╝  ";
            output[3] = "██╔═██╗  ";
            output[4] = "██║  ██╗ ";
            output[5] = "╚═╝  ╚═╝ ";
            output[6] = "          ";

            for(int k=0; k<7; k++) {
                for(int j=0; j<5; j++) {
                    ascii_art[k][i*6+j] = output[k][j+offset*6];
                }
            }
        }
    }

    printf("\n");

    for(int i=0; i<7; i++) {
        printf("%s\n", ascii_art[i]);
    }

    printf("\n");

    return 0;
}