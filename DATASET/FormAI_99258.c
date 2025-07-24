//FormAI DATASET v1.0 Category: QR code reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_CODE_SIZE 21 // Size for CQRCode is always 21x21
#define QUIET_ZONE_SIZE 4 // Size for the quiet zone around the code

// This function checks if the given character is a valid binary value (0 or 1)
int is_valid_binary(char c) {
    return (c == '0' || c == '1');
}

// This function reads a CQRCode from the given file
int read_cqr_code(char* filename, int qr_code[][QR_CODE_SIZE]) {
    FILE *fp;

    // Open the file in binary mode
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    
    // Read data from the file
    unsigned char buffer[QR_CODE_SIZE + 1];
    int row = 0;
    while (fgets(buffer, QR_CODE_SIZE + 1, fp) != NULL) {
        // Check that the line has the correct number of characters
        if (strlen(buffer) != QR_CODE_SIZE + 1) {
            printf("Error reading file: incorrect number of characters in line %d.\n", row+1);
            fclose(fp);
            return 0;
        }
        // Check that the characters are valid binary values
        for (int i = 0; i < QR_CODE_SIZE; i++) {
            if (!is_valid_binary(buffer[i])) {
                printf("Error reading file: invalid character in line %d, position %d.\n", row+1, i+1);
                fclose(fp);
                return 0;
            }
            qr_code[row][i] = buffer[i] - '0'; // Convert the character to an integer value
        }
        row++;
    }
    
    // Check that the correct number of rows has been read
    if (row != QR_CODE_SIZE) {
        printf("Error reading file: incorrect number of rows.\n");
        fclose(fp);
        return 0;
    }
    
    fclose(fp);
    return 1;
}

// This function prints the contents of a CQRCode
void print_cqr_code(int qr_code[][QR_CODE_SIZE]) {
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        for (int j = 0; j < QR_CODE_SIZE; j++) {
            printf("%d ", qr_code[i][j]);
        }
        printf("\n");
    }
}

// This function checks if a QR code is a valid CQRCode
int is_cqr_code(int qr_code[][QR_CODE_SIZE]) {
    // Check the quiet zone
    for (int i = 0; i < QUIET_ZONE_SIZE; i++) {
        for (int j = 0; j < QR_CODE_SIZE; j++) {
            if (qr_code[i][j] != 0 || qr_code[QR_CODE_SIZE-1-i][j] != 0 || qr_code[j][i] != 0 || qr_code[j][QR_CODE_SIZE-1-i] != 0) {
                return 0;
            }
        }
    }
    // Check the format information
    if (qr_code[QUIET_ZONE_SIZE+1][8] != 1 || qr_code[QUIET_ZONE_SIZE+1][9] != 0) {
        return 0;
    }
    if (qr_code[8][QUIET_ZONE_SIZE+1] != 0 || qr_code[9][QUIET_ZONE_SIZE+1] != 1) {
        return 0;
    }
    // Check the version information
    for (int i = QR_CODE_SIZE-11; i < QR_CODE_SIZE-8; i++) {
        if (qr_code[i][8] != 1 || qr_code[i][9] != 0) {
            return 0;
        }
    }
    for (int i = QR_CODE_SIZE-8; i < QR_CODE_SIZE-5; i++) {
        if (qr_code[8][i] != 1 || qr_code[9][i] != 0) {
            return 0;
        }
    }
    return 1;
}

// This is the main function
int main(int argc, char* argv[]) {
    int qr_code[QR_CODE_SIZE][QR_CODE_SIZE];
    if (argc != 2) {
        printf("Please specify the name of the file containing the QR code.\n");
        return 1;
    }
    if (!read_cqr_code(argv[1], qr_code)) {
        return 1;
    }
    if (!is_cqr_code(qr_code)) {
        printf("Error: not a valid CQRCode.\n");
        return 1;
    }
    printf("CQRCode successfully read and validated.\n");
    return 0;
}