//FormAI DATASET v1.0 Category: QR code generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {

    // Step 1: Process input data
    char *input_string = argv[1];   // Get input string from command line argument
    int input_length = strlen(input_string);  // Get input length
    if (input_length == 0) {
        printf("Error: No input provided!\n");
        return 1;
    }

    // Step 2: Generate QR code
    QRcode *qr;         // Declare QR code struct
    qr = QRcode_encodeString(input_string, 0, QR_ECLEVEL_L, QR_MODE_8, 1);   // Generate QR code
    if (qr == NULL) {
        printf("Error: Failed to generate QR code!\n");
        return 1;
    }
    
    // Step 3: Save QR code image
    FILE *outfile;      // Declare output file pointer
    char *filename = "qr_code.png";  // Define output filename
    outfile = fopen(filename, "wb");    // Open file for writing
    if (outfile == NULL) {
        printf("Error: Failed to open output file!\n");
        return 1;
    }
    fwrite(qr->data, qr->width * qr->width, 1, outfile);   // Write QR code data to file
    fclose(outfile);    // Close output file
    
    // Step 4: Free memory
    QRcode_free(qr);    // Free QR code memory
    
    // Step 5: Exit program
    printf("QR code saved as %s!\n", filename);
    return 0;
}