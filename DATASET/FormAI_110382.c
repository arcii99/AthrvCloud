//FormAI DATASET v1.0 Category: QR code generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    QRcode *qrCode;
    int version = 0;
    QRecLevel level = QR_ECLEVEL_L;
    int case_sensitive = 1;
    int eight_bit = 0;
    char *data = NULL;
    unsigned int length = 0;
    FILE *file = NULL;
    char* filename = NULL;
    
    // get input data
    printf("Enter the data to encode: ");
    scanf("%m[^\n]", &data);
    length = strlen(data);

    // generate QR code
    qrCode = QRcode_encodeString(data, version, level, QR_MODE_8, case_sensitive);
    if (qrCode == NULL) {
        printf("Failed to generate QR code\n");
        return EXIT_FAILURE;
    }

    // save QR code as file
    printf("Enter the file name to save QR code: ");
    scanf("%ms", &filename);

    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Failed to open file\n");
        return EXIT_FAILURE;
    }

    fwrite(qrCode->data, sizeof(unsigned char), qrCode->width * qrCode->width, file);
    fclose(file);

    // clean up
    QRcode_free(qrCode);
    free(data);
    free(filename);

    return EXIT_SUCCESS;
}