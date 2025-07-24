//FormAI DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

int main() {
    int qr[MAX_SIZE][MAX_SIZE];
    int size, i, j, x, y;

    // Initialize QR code to all zeros
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            qr[i][j] = 0;
        }
    }

    // Get size of QR code from user input
    printf("Enter size of QR code (maximum is %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Check for valid input size
    if (size > MAX_SIZE) {
        printf("Invalid size, maximum is %d!", MAX_SIZE);
        exit(1);
    }

    // Set finder patterns
    qr[0][0] = 1;
    qr[0][size-1] = 1;
    qr[size-1][0] = 1;

    // Set alignment patterns
    if (size >= 3) {
        int num_align = (size - 7) / 2 + 1;
        int align[MAX_SIZE];

        // Calculate positions of alignment patterns
        for (i = 0; i < num_align; i++) {
            align[i] = 6 + i*2;
        }

        // Set alignment pattern positions
        for (i = 0; i < num_align; i++) {
            for (j = 0; j < num_align; j++) {
                if (!((i == 0 && j == 0) || (i == 0 && j == num_align-1) || (i == num_align-1 && j == 0))) {
                    qr[align[i]][align[j]] = 2;
                }
            }
        }
    }

    // Set timing patterns
    for (i = 8; i < size-8; i++) {
        qr[i][6] = i % 2;
        qr[6][i] = i % 2;
    }

    // Set dark module
    qr[size-8][8] = 1;

    // Set version information
    if (size >= 7) {
        int version[MAX_SIZE*2];
        int vsize;

        // Generate version information bits
        for (i = 0; i < size*2-17; i++) {
            version[i] = i % 2;
        }

        // Get size of version information bits
        if (size >= 7 && size <= 13) vsize = 18;
        else if (size >= 14 && size <= 20) vsize = 22;
        else if (size >= 21 && size <= 27) vsize = 26;
        else if (size >= 28 && size <= 34) vsize = 30;
        else if (size >= 35 && size <= 41) vsize = 34;

        // Set version information bits
        for (i = 0; i < vsize; i++) {
            if (i < 6 || i >= vsize-8 || (i >= 12 && i < vsize-4)) {
                qr[i][size-11+(i%2)] = version[i];
                qr[size-11+(i%2)][i] = version[i];
            } else {
                qr[i][size-9+(i%2)] = version[i];
                qr[size-9+(i%2)][i] = version[i];
            }
        }
    }

    // Set data bits
    printf("Enter message (up to %d characters): ", (size*size-19)/8);
    char message[(size*size-19)/8];
    scanf("%s", message);

    int bit_index = 0;
    int dir = -1;
    for (x = size-1; x >= 0; x -= 2) {
        if (x == size-1) x--;
        for (y = dir > 0 ? 0 : size-1; y >= 0 && y < size; y += dir) {
            if (qr[x][y] == 0) {
                qr[x][y] = message[bit_index / 8] & (1 << (7 - (bit_index % 8))) ? 1 : 0;
                bit_index++;
                if (bit_index >= strlen(message)*8) break;
            }
        }
        dir *= -1;
    }

    // Print QR code
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d", qr[i][j]);
        }
        printf("\n");
    }

    return 0;
}