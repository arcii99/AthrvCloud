//FormAI DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QR_VERSION 1
#define QR_SIZE 21
#define QR_MAX_DATA 128

// QR code data structure
typedef struct {
    int size;
    char data[QR_MAX_DATA];
} QRCode;

// Function prototypes
void generateData(char data[QR_MAX_DATA]);
void encodeData(char data[QR_MAX_DATA], int bitstream[QR_SIZE][QR_SIZE]);
void printQRCode(int bitstream[QR_SIZE][QR_SIZE]);

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Generate data
    char data[QR_MAX_DATA];
    generateData(data);
    
    // Encode data
    int bitstream[QR_SIZE][QR_SIZE];
    encodeData(data, bitstream);
    
    // Print QR code
    printQRCode(bitstream);
    
    // Exit program
    return 0;
}

// Generates random data for QR code
void generateData(char data[QR_MAX_DATA]) {
    int i;
    for (i = 0; i < QR_MAX_DATA - 1; i++) {
        data[i] = rand() % 26 + 'A';
    }
    data[QR_MAX_DATA - 1] = '\0';
}

// Encodes data into QR code bitstream
void encodeData(char data[QR_MAX_DATA], int bitstream[QR_SIZE][QR_SIZE]) {
    // Initialize bitstream with quiet zone
    int i, j;
    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            bitstream[i][j] = 0;
        }
    }
    
    // Add timing patterns
    for (i = 8; i < QR_SIZE - 7; i++) {
        bitstream[6][i] = i % 2 == 0;
        bitstream[i][6] = i % 2 == 0;
    }
    
    // Add version information (if required)
    if (QR_VERSION >= 7) {
        for (i = 0; i < 6; i++) {
            bitstream[i][QR_SIZE - 9] = i % 2 == 0;
            bitstream[QR_SIZE - 9][i] = i % 2 == 0;
        }
    }
    
    // Add data to bitstream
    int x = QR_SIZE - 1, y = QR_SIZE - 1, direction = -1;
    for (i = strlen(data) - 1; i >= 0; i--) {
        char c = data[i];
        int mask;
        for (mask = 0x80; mask > 0; mask >>= 1) {
            if (x < 0) {
                y += direction * 2;
                direction *= -1;
                x = x == -1 ? 0 : -1;
            }
            if (y < 0) {
                x += direction * 2;
                direction *= -1;
                y = y == -1 ? 0 : -1;
            }
            bitstream[y][x] = !!(c & mask);
            x += direction;
        }
    }
}

// Prints QR code bitstream
void printQRCode(int bitstream[QR_SIZE][QR_SIZE]) {
    int i, j;
    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            putchar(bitstream[i][j] ? '#' : ' ');
        }
        putchar('\n');
    }
}