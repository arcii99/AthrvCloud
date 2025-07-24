//FormAI DATASET v1.0 Category: QR code generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_VERSION 3 // Setting the version of QR code as 3
#define QR_SIZE 29 // Setting the QR code size as per version 3

typedef struct qr_data { // Structure to hold the QR code data
    int data[QR_SIZE][QR_SIZE]; // 2D matrix of data points
} qr_data;

int process_data(char* input_string, qr_data* qr_code); // Function to process input data and generate QR code matrix
void print_qr_code(qr_data* qr_code); // Function to print the QR code in the console

int main() {
    char input_string[100]; // Input string to generate QR code
    qr_data qr_code = {0}; // Initializing QR code data with 0
    printf("Enter the data to be encoded as QR code: ");
    scanf("%s", input_string); // Scanning input string from user
    int status = process_data(input_string, &qr_code); // Process input string and generate QR code matrix
    if (status == -1) { // Invalid input
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }
    print_qr_code(&qr_code); // Print QR code in the console
    return 0;
}

int process_data(char* input_string, qr_data* qr_code) {
    int data_length = strlen(input_string); // Length of input string
    if (data_length > QR_SIZE * QR_SIZE / 8) { // Input string too long to encode in the QR code
        return -1; // Invalid input
    }
    int i = 0, j = 0, index = 0; // Initializing indices for QR code matrix
    while (index < data_length) { // Looping through the input string to encode in QR code matrix
        unsigned char current_char = (unsigned char)input_string[index]; // Converting current character to unsigned char
        for (int k = 0; k < 8; k++) { // Looping through 8-bit representation of current character
            int bit = ((current_char >> k) & 1); // Extracting current bit
            qr_code->data[i][j] = bit; // Setting QR code matrix cell with current bit
            j++; // Incrementing column index
            if (j >= QR_SIZE) { // End of row
                i++; // Incrementing row index
                j = 0; // Resetting column index
            }
        }
        index++; // Incrementing input string index
    }
    return 0; // Successful QR code generation
}

void print_qr_code(qr_data* qr_code) {
    for (int i = 0; i < QR_SIZE; i++) { // Looping through rows of QR code matrix
        for (int j = 0; j < QR_SIZE; j++) { // Looping through columns of QR code matrix
            if (qr_code->data[i][j]) { // Cell with data
                printf("X"); // Printing X
            }
            else { // Cell without data
                printf(" "); // Printing whitespace
            }
        }
        printf("\n"); // End of row
    }
}