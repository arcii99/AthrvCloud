//FormAI DATASET v1.0 Category: QR code generator ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char binary[800]; // array to hold binary string
    char qrCode[150][150]; // array to hold QR code

    // generate random binary string
    for(int i=0; i<800; i++) {
        binary[i] = rand() % 2 + '0';
    }

    // initialize QR code with white squares
    for(int i=0; i<150; i++) {
        for(int j=0; j<150; j++) {
            qrCode[i][j] = ' ';
        }
    }

    // set start position
    int posX = 75;
    int posY = 75;

    // convert binary string to QR code
    int i = 0;
    while(i < strlen(binary)) {
        if(binary[i] == '1') { // black square
            qrCode[posX][posY] = '█';
        } else { // white square
            qrCode[posX][posY] = ' ';
        }
        // generate random direction
        int direction = rand() % 4;
        switch(direction) {
            case 0: // up
                posX--;
                break;
            case 1: // down
                posX++;
                break;
            case 2: // left
                posY--;
                break;
            case 3: // right
                posY++;
                break;
        }
        // check boundaries
        if(posX < 0) posX = 0;
        if(posX > 149) posX = 149;
        if(posY < 0) posY = 0;
        if(posY > 149) posY = 149;
        i++;
    }

    // print QR code
    for(int i=0; i<150; i++) {
        for(int j=0; j<150; j++) {
            printf("%c", qrCode[i][j]);
        }
        printf("\n");
    }

    return 0;
}