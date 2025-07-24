//FormAI DATASET v1.0 Category: QR code generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random alphanumeric character
char randomChar() {
    int num = rand() % 62;
    if (num < 26) {
        return 'A' + num;
    } else if (num < 52) {
        return 'a' + (num - 26);
    } else {
        return '0' + (num - 52);
    }
}

// Function to generate a QR code and store it in a file
void generateQRCode(char* filename) {
    // Open file for writing
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Failed to create file %s\n", filename);
        return;
    }

    // Seed random number generator
    srand(time(NULL));

    // Generate random QR code string
    char code[20];
    for (int i = 0; i < 20; i++) {
        code[i] = randomChar();
    }

    // Write QR code to file
    fprintf(fp, "QR code: %s", code);

    // Close file
    fclose(fp);

    printf("QR code generated and saved to file %s\n", filename);
}

// Example usage
int main() {
    generateQRCode("myQRCode.txt");
    return 0;
}