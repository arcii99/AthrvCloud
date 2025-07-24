//FormAI DATASET v1.0 Category: QR code generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate QR code
void generateQRCode(int version, char* data){

    // Initialize QR code data length
    int dataLength = strlen(data);

    // Initialize QR code version size
    int versionSize = ((version - 1) * 4) + 21;

    // Initialize QR code array
    char qrCode[versionSize][versionSize];

    // Initialize QR code array with empty spaces
    for(int i = 0; i < versionSize; i++){
        for(int j = 0; j < versionSize; j++){
            qrCode[i][j] = ' ';
        }
    }

    // Data encoding mode
    char mode = 'B';

    // QR code error correction level
    char ecLevel = 'H';

    // QR code data encoding format
    char dataEncoding[3] = { mode, ecLevel, '\0' };

    // Add data to QR code
    int count = 0;
    for(int i = versionSize - 1; i >= 0; i--){
        for(int j = versionSize - 1; j >= 0; j--){
            if(qrCode[j][i] == ' '){
                if(count < dataLength){
                    qrCode[j][i] = data[count];
                    count++;
                }
            }
        }
    }

    // Print QR code
    for(int i = 0; i < versionSize; i++){
        for(int j = 0; j < versionSize; j++){
            printf("%c", qrCode[i][j]);
        }
        printf("\n");
    }
}

int main(){

    // Initialize QR code version and data
    int version = 3;
    char* data = "Hello, world!";

    // Generate QR code
    generateQRCode(version, data);

    // Exit program
    return 0;
}