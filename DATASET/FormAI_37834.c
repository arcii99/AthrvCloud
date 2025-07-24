//FormAI DATASET v1.0 Category: QR code reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Size of QR code grid
#define GRID_SIZE 21

// Error correction level
#define ERROR_CORRECTION_LEVEL 'L'

// QR code structure
typedef struct qrcode_t {
    char version;
    char data[200];
    int data_length;
    char error_correction_level;
    char mask_pattern;
} qrcode_t;

// QR code reader function
qrcode_t read_qr_code(char grid[GRID_SIZE][GRID_SIZE]) {
    qrcode_t qrcode;
    qrcode.version = '0';
    qrcode.error_correction_level = ERROR_CORRECTION_LEVEL;
    qrcode.mask_pattern = '0';

    // Check synchronization and format information patterns
    if (grid[8][13] != 1 || grid[13][8] != 1 ||
        grid[8][14] != 0 || grid[13][9] != 0 ||
        grid[8][15] != 1 || grid[13][10] != 1 ||
        grid[8][16] != 1 || grid[13][11] != 0 ||
        grid[8][17] != 1 || grid[13][12] != 1 ||
        grid[14][8] != 0 || grid[9][13] != 0 ||
        grid[15][8] != 1 || grid[10][13] != 1 ||
        grid[16][8] != 1 || grid[11][13] != 0 ||
        grid[17][8] != 1 || grid[12][13] != 1) {
        printf("Invalid QR code format.\n");
        exit(EXIT_FAILURE);
    }

    // Read version information pattern
    if (grid[6][14] == 1 && grid[7][14] == 0 && grid[8][14] == 0 &&
        grid[9][14] == 0 && grid[10][14] == 0 && grid[11][14] == 0) {
        qrcode.version = '1';
    } else if (grid[6][14] == 1 && grid[7][14] == 1 && grid[8][14] == 0 &&
               grid[9][14] == 0 && grid[10][14] == 0 && grid[11][14] == 0) {
        qrcode.version = '2';
    } else {
        printf("Invalid QR code version.\n");
        exit(EXIT_FAILURE);
    }

    // Read data code words
    int data_length = 0;
    bool up = true; // Start reading from top left
    int i = GRID_SIZE - 1, j = GRID_SIZE - 1;
    while (data_length < qrcode.data_length) {
        if (up) { // Move up
            while (i >= 0 && j < GRID_SIZE) {
                if (grid[i][j] == 1) { // Black module
                    qrcode.data[data_length++] = '1';
                } else if (grid[i][j] == 0) { // White module
                    qrcode.data[data_length++] = '0';
                }
                i--; j++;
            }
            i++; j--; // Adjust position to last white module
            if (j == GRID_SIZE - 1) { // Reached right edge
                i -= 2; // Move up two rows
                up = false;
            }
        } else { // Move down
            while (i < GRID_SIZE && j >= 0) {
                if (grid[i][j] == 1) { // Black module
                    qrcode.data[data_length++] = '1';
                } else if (grid[i][j] == 0) { // White module
                    qrcode.data[data_length++] = '0';
                }
                i++; j--;
            }
            i--; j++; // Adjust position to last white module
            if (i == GRID_SIZE - 1) { // Reached bottom edge
                j -= 2; // Move left two columns
                up = true;
            }
        }
    }

    return qrcode;
}

int main() {
    // Example QR code grid
    char grid[GRID_SIZE][GRID_SIZE] = {
        {0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0},
        {0,1,1,1,1,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0},
        {0,1,0,0,0,1,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0},
        {0,1,0,0,0,1,0,1,0,0,0,1,1,0,1,0,0,0,0,0,0},
        {0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0,1,1,0,1,0},
        {0,1,1,1,1,1,0,0,1,1,1,0,0,0,1,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,1,1,0,0},
        {0,1,1,1,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,1,0},
        {1,0,0,1,1,1,0,0,0,1,0,1,0,0,1,0,1,1,0,0,0},
        {1,0,1,1,0,1,0,1,0,1,1,0,0,1,1,1,0,0,0,0,1},
        {1,0,1,0,0,1,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0},
        {1,0,1,1,0,1,0,0,0,0,1,1,1,1,0,1,0,1,0,1,0},
        {1,0,0,1,1,1,0,1,1,1,1,0,1,0,1,0,0,0,1,1,0},
        {1,1,0,0,0,1,1,0,1,0,1,1,1,1,1,1,0,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0},
        {1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0},
        {1,0,1,1,1,0,0,1,1,0,1,0,1,1,0,0,0,0,1,1,1},
        {1,0,1,1,1,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1},
        {1,1,0,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,1,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,1,0}
    };

    qrcode_t qrcode = read_qr_code(grid);

    printf("QR code version: %c\n", qrcode.version);
    printf("QR code data: %s\n", qrcode.data);
    printf("QR code data length: %d\n", qrcode.data_length);
    printf("QR code error correction level: %c\n", qrcode.error_correction_level);
    printf("QR code mask pattern: %c\n", qrcode.mask_pattern);

    return 0;
}