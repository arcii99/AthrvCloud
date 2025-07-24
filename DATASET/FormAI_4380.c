//FormAI DATASET v1.0 Category: QR code generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printQR(char qr[][21], int size){
    int i,j;
    for(i=0;i<size;i++){
        printf("|");
        for(j=0;j<size;j++){
            printf("%c|",qr[i][j]);
        }
        printf("\n");
    }
}

int main(){

    srand(time(NULL));
    char qr[21][21];
    int qrSize = 21, i, j;
    for(i=0;i<qrSize;i++)
        for(j=0;j<qrSize;j++)
            qr[i][j] = ' ';

    // Setting up the border
    for(i=0;i<qrSize;i++){
        qr[i][0] = '#';
        qr[i][qrSize-1] = '#';
        qr[0][i] = '#';
        qr[qrSize-1][i] = '#';
    }

    // Setting up the mid row and column
    for(i=qrSize/3;i<(qrSize/3)*2;i++){
        qr[qrSize/2][i] = '#';
        qr[i][qrSize/2] = '#';
    }

    // Randomly generating the remaining blocks
    for(i=0;i<qrSize;i++){
        for(j=0;j<qrSize;j++){
            if(qr[i][j] == ' '){
                int x = rand()%2;
                if(x == 0)
                    qr[i][j] = '#';
                else
                    qr[i][j] = ' ';
            }
        }
    }

    // Printing the QR code
    printQR(qr, qrSize);

    return 0;
}