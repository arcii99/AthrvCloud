//FormAI DATASET v1.0 Category: QR code generator ; Style: Linus Torvalds
/* Unique C QR Code generator written in Linus Torvalds style*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 21 // Dimensions for QR Code

int main() {
    int code[DIM][DIM] = {0}; // Initialize code array with zeros
    int row, col; // Variables for row and column in the code array
    int version = 1; // QR Code version
    int penPos = 0; // Pen state - 0 for up, 1 for down
    int direction = 0; // 0 for right, 1 for down, 2 for left, 3 for up
    
    /* Generate QR Code */
    for(int i = 0; i < 4; i++) { // Add QR Code header
        for(int j = 0; j < 8; j++) {
            code[i][j+1] = 1;
            code[DIM-1-i][j+1] = 1;
            code[j+1][i] = 1;
            code[j+1][DIM-1-i] = 1;
        }
    }
    for(int i = 0; i < DIM; i++) { // Add QR Code alignment patterns
        for(int j = 0; j < DIM; j++) {
            if((i % 4 == 2) && (j % 4 == 2)) {
                code[i][j] = 1; // Add alignment pattern
                code[i-1][j] = 1; // Add white border
                code[i+1][j] = 1; // Add white border
                code[i][j-1] = 1; // Add white border
                code[i][j+1] = 1; // Add white border
                code[i-2][j] = 0; // Remove timing pattern
                code[i+2][j] = 0; // Remove timing pattern
                code[i][j-2] = 0; // Remove timing pattern
                code[i][j+2] = 0; // Remove timing pattern
            }
        }
    }
    for(int i = 8; i < DIM-8; i++) { // Add QR Code timing patterns
        if(code[6][i] == 0) { // Horizontal timing pattern
            code[6][i] = 1;
        }
        if(code[i][6] == 0) { // Vertical timing pattern
            code[i][6] = 1;
        }
    }
    while(version <= 40) { // Add QR Code version information
        int bits[6];
        for(int i = 0; i < 6; i++) {
            if(version & (1 << i)) {
                bits[5-i] = 1;
            } else {
                bits[5-i] = 0;
            }
        }
        if(version <= 6) { // Add version information to second and third column from bottom
            for(int i = 0; i < 3; i++) {
                code[DIM-11+i][8] = bits[i];
                code[8][DIM-11+i] = bits[i];
            }
        } else { // Add version information to second and third row from right
            for(int i = 0; i < 3; i++) {
                code[5][DIM-9+i] = bits[i];
                code[DIM-9+i][5] = bits[i];
            }
        }
        version++;
    }
    code[DIM-8][8] = 1; // Add dark module
    
    /* Print QR Code */
    for(row = 0; row < DIM; row++) {
        for(col = 0; col < DIM; col++) {
            if(code[row][col] == 0) { // Print white pixel
                printf("\033[47m  \033[0m");
            } else { // Print black pixel
                printf("\033[40m  \033[0m");
            }
        }
        printf("\n");
    }
    
    return 0;
}