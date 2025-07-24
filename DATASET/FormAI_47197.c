//FormAI DATASET v1.0 Category: QR code reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_CODE_SIZE 21   // Assuming max QR code size of 21x21
#define WHITE_PIXEL 255
#define BLACK_PIXEL 0

int main(int argc, char *argv[]) {
    int qrCode[QR_CODE_SIZE][QR_CODE_SIZE];
    char input[50];
    int i, j, k, l;
    int rowStart, colStart, rowEnd, colEnd;
    int foundStart, foundEnd;

    printf("Enter the QR code in white space separated format (0 for black and 255 for white): \n");
    for(i=0; i<QR_CODE_SIZE; i++) {
        fgets(input, 50, stdin);
        j = 0;
        k = 0;
        while(input[j] != '\n' && input[j] != '\0') {
            if(input[j] == ' ') {
                qrCode[i][k] = WHITE_PIXEL;
                k++;
            }
            else {
                qrCode[i][k] = BLACK_PIXEL;
                k++;
            }
            j++;
        }
    }

    // Find start and end of QR code
    foundStart = 0;
    foundEnd = 0;
    for(i=0; i<QR_CODE_SIZE; i++) {
        for(j=0; j<QR_CODE_SIZE; j++) {
            if(qrCode[i][j] == BLACK_PIXEL) {
                rowStart = i;
                colStart = j;
                foundStart = 1;
                break;
            }
        }
        if(foundStart) {
            break;
        }
    }
    for(i=QR_CODE_SIZE-1; i>-1; i--) {
        for(j=QR_CODE_SIZE-1; j>-1; j--) {
            if(qrCode[i][j] == BLACK_PIXEL) {
                rowEnd = i;
                colEnd = j;
                foundEnd = 1;
                break;
            }
        }
        if(foundEnd) {
            break;
        }
    }

    // Print the extracted QR code
    printf("Extracted QR code:\n");
    for(i=rowStart; i<=rowEnd; i++) {
        for(j=colStart; j<=colEnd; j++) {
            if(qrCode[i][j] == BLACK_PIXEL) {
                printf("X");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("QR code has been read successfully!\n");

    return 0;
}