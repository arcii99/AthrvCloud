//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ROWS 8
#define COLS 8

char ascii_art[ROWS][COLS];

void generate_art(char text[]) {
    int len = strlen(text);
    int row = 0, col = 0;

    for(int i=0; i<len; i++) {
        char character = toupper(text[i]);
        if(character == ' ') {
            col++; //skip to next column
            continue;
        }
        int ascii_code = (int) character;
        for(int x=0; x<ROWS; x++) {
            for(int y=0; y<COLS; y++) {
                ascii_art[x][col*COLS+y] = ((ascii_code >> (x*COLS+y)) & 1) ? '#' : ' ';
            }
        }
        col++;
    }
    row = ROWS;
}

int main() {
    char text[50];
    printf("Enter text to generate ASCII art: ");
    scanf("%[^\n]", text);
    generate_art(text);

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<strlen(text)*COLS; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    return 0;
}