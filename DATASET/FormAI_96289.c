//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <string.h>

#define ROW_LENGTH 7
#define CHAR_WIDTH 5

void textArt(char *text) {
    int length = strlen(text);
    int num_rows = ROW_LENGTH;
    int num_cols = length * CHAR_WIDTH;
    char art[num_rows][num_cols];

    // Initialize art array with spaces
    for(int i = 0; i < num_rows; i++) {
        for(int j = 0; j < num_cols; j++) {
            art[i][j] = ' ';
        }
    }

    // Generate text art
    for(int i = 0; i < length; i++) {
        int col = i * CHAR_WIDTH;
        switch(text[i]) {
            case 'A':
                art[0][col+2] = '*';
                art[1][col+1] = '*';
                art[1][col+3] = '*';
                art[2][col] = '*';
                art[2][col+4] = '*';
                art[3][col] = '*';
                art[3][col+4] = '*';
                art[4][col] = '*';
                art[4][col+4] = '*';
                art[5][col] = '*';
                art[5][col+4] = '*';
                art[6][col] = '*';
                art[6][col+4] = '*';
                break;
            case 'B':
                art[0][col] = '*';
                art[0][col+1] = '*';
                art[0][col+2] = '*';
                art[1][col] = '*';
                art[1][col+3] = '*';
                art[2][col] = '*';
                art[2][col+1] = '*';
                art[2][col+2] = '*';
                art[2][col+3] = '*';
                art[3][col+3] = '*';
                art[4][col+3] = '*';
                art[5][col+3] = '*';
                art[5][col+2] = '*';
                art[5][col+1] = '*';
                art[6][col] = '*';
                art[6][col+1] = '*';
                art[6][col+2] = '*';
                break;
            case 'C':
                art[0][col+1] = '*';
                art[0][col+2] = '*';
                art[0][col+3] = '*';
                art[1][col] = '*';
                art[2][col] = '*';
                art[3][col] = '*';
                art[4][col] = '*';
                art[4][col+1] = '*';
                art[4][col+2] = '*';
                art[4][col+3] = '*';
                art[5][col] = '*';
                art[6][col+1] = '*';
                art[6][col+2] = '*';
                art[6][col+3] = '*';
                break;
            default:
                break;
        }
    }

    // Print text art
    for(int i = 0; i < num_rows; i++) {
        for(int j = 0; j < num_cols; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char text[] = "ABC";
    textArt(text);
    return 0;
}