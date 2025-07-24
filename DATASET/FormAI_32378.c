//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: light-weight
#include<stdio.h>

int main() {
    char text[1000];
    int ascii_art[1000][1000];
    int row = 0, col = 0;

    printf("Enter some text: ");
    fgets(text, 1000, stdin);

    for(int i=0; text[i]!='\0'; i++) {
        if(text[i] == '\n') break;

        // calculate ascii value of each character
        int ascii_val = (int)text[i];

        // store ascii value in array
        ascii_art[row][col] = ascii_val;

        col++;
        if(col == 80) { // if 80 characters in a row, start new row
            row++;
            col = 0;
        }
    }

    printf("\n");

    // print the ascii art
    for(int i=0; i<=row; i++) {
        for(int j=0; j<80; j++) {
            if(ascii_art[i][j] == 0) break;
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    return 0;
}