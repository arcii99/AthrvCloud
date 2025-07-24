//FormAI DATASET v1.0 Category: QR code generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_SIZE 21
// Length of generated QR code

int main()
{
    char qr[QR_SIZE][QR_SIZE]; // The QR code array
    int i, j;

    // Seed the random generator with the time
    srand(time(NULL));

    // Initialize the QR code array to all zeros
    for(i = 0; i < QR_SIZE; i++) {
        for(j = 0; j < QR_SIZE; j++) {
            qr[i][j] = '0';
        }
    }

    // Set the top left corner to a random value from A-F
    qr[0][0] = rand() % 6 + 'A';

    // Loop over the QR code and randomly generate each value
    for(i = 0; i < QR_SIZE; i++) {
        for(j = 0; j < QR_SIZE; j++) {
            // Skip the top left corner as it has already been set
            if(i == 0 && j == 0) {
                continue;
            }

            // Generate a random value
            int value = rand() % 2;

            if(value == 0) {
                qr[i][j] = '0';
            } else {
                qr[i][j] = '1';
            }
        }
    }

    // Print the generated QR code
    for(i = 0; i < QR_SIZE; i++) {
        for(j = 0; j < QR_SIZE; j++) {
            printf("%c", qr[i][j]);
        }
        printf("\n");
    }

    return 0;
}