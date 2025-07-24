//FormAI DATASET v1.0 Category: QR code generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_SIZE 21 // size of QR code (21 x 21)

int main(){
    char matrix[QR_SIZE][QR_SIZE]; // 2D matrix to store QR code
    memset(matrix, 0, sizeof(matrix)); // set all elements to 0 initially

    // generate random pattern for QR code
    srand(time(NULL));
    for(int i=0; i<QR_SIZE; i++){
        for(int j=0; j<QR_SIZE; j++){
            matrix[i][j] = rand() % 2 ? '#' : ' '; // randomly choose # or space
        }
    }

    // print QR code
    for(int i=0; i<QR_SIZE; i++){
        for(int j=0; j<QR_SIZE; j++){
            printf("%c ", matrix[i][j]); // print each element with a space in between
        }
        printf("\n"); // move to next row
    }

    return 0; // exit
}