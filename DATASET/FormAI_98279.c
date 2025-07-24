//FormAI DATASET v1.0 Category: QR code generator ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Define size of QR code
    int rows = 25;
    int cols = 25;

    // Create a 2D array to represent QR code
    int qr_code[rows][cols];

    // Iterate through the array and assign random binary values to each element
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            qr_code[i][j] = rand() % 2;
        }
    }

    // Print QR code to console
    printf("QR CODE:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(qr_code[i][j] == 0){
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    // Encrypt QR code using simple XOR encryption algorithm
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            qr_code[i][j] = qr_code[i][j] ^ rand() % 256;
        }
    }

    // Print encrypted QR code to console
    printf("\nENCRYPTED QR CODE:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(qr_code[i][j] == 0){
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    // Decrypt encrypted QR code using same XOR encryption algorithm
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            qr_code[i][j] = qr_code[i][j] ^ rand() % 256;
        }
    }

    // Print decrypted QR code to console
    printf("\nDECRYPTED QR CODE:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(qr_code[i][j] == 0){
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    return 0;
}