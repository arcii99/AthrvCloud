//FormAI DATASET v1.0 Category: QR code generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// Define the QR code size
#define QR_SIZE 21

// Struct to hold the QR code
typedef struct {
    char qr[QR_SIZE][QR_SIZE];
} QRCode;

// Function to generate a random binary QR code
QRCode generateQR() {
    QRCode code;
    int i, j;
    srand(time(NULL));  // Seed the random number generator
    
    // Generate random 1's and 0's for the QR code
    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            code.qr[i][j] = rand() % 2 + 48;  // 48 is the ASCII code for '0'
        }
    }
    return code;
}

// Function to print the QR code to the console
void printQR(QRCode code) {
    int i, j;
    
    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            printf("%c ", code.qr[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the Hamming distance between two binary strings
int hammingDistance(char* s1, char* s2) {
    int i, d = 0;
    
    for (i = 0; i < QR_SIZE*QR_SIZE; i++) {
        if (s1[i] != s2[i]) {
            d++;
        }
    }
    return d;
}

// Function to check if two QR codes are similar
bool isSimilar(QRCode code1, QRCode code2) {
    char s1[QR_SIZE*QR_SIZE + 1], s2[QR_SIZE*QR_SIZE + 1];
    s1[QR_SIZE*QR_SIZE] = s2[QR_SIZE*QR_SIZE] = '\0';  // Null-terminate the strings
    int i, j;
    
    // Convert the QR codes to binary strings
    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            s1[i*QR_SIZE + j] = code1.qr[i][j];
            s2[i*QR_SIZE + j] = code2.qr[i][j];
        }
    }
    
    // Calculate the Hamming distance between the two codes
    if (hammingDistance(s1, s2) <= 10) {  // Hamming distance threshold of 10
        return true;
    } else {
        return false;
    }
}

// Main function
int main() {
    QRCode code1, code2;
    int i = 0;
    
    // Generate a random QR code and print it
    code1 = generateQR();
    printf("QR Code 1:\n");
    printQR(code1);
    
    // Generate new QR codes until a similar one is found
    do {
        code2 = generateQR();
        i++;
    } while (!isSimilar(code1, code2));
    printf("\nQR Code 2 found after %d iterations:\n", i);
    printQR(code2);
    
    return 0;
}