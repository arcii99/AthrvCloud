//FormAI DATASET v1.0 Category: QR code reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* define QR code struct */
typedef struct QRCode {
    int version;
    int errorCorrectionLevel;
    char* message;
}QRCode;

/* function to parse QR code string */
QRCode parseQRCode(char* codeString) {
    QRCode code;
    code.message = NULL;

    /* parse version and error correction level */
    sscanf(codeString, "v=%d&e=%d", &code.version, &code.errorCorrectionLevel);

    /* parse message */
    char* messageStart = strstr(codeString, "m=");
    if (messageStart != NULL) {
        messageStart += 2;
        code.message = (char*)malloc(sizeof(char) * strlen(messageStart) + 1);
        strcpy(code.message, messageStart);
    } else {
        printf("Error: QR code does not contain a message.\n");
    }

    return code;
}

int main() {
    char codeString[] = "v=2&e=1&m=Hello%20World!";

    /* parse QR code */
    QRCode code = parseQRCode(codeString);

    /* print QR code info */
    printf("Version: %d\n", code.version);
    printf("Error Correction Level: %d\n", code.errorCorrectionLevel);
    printf("Message: %s\n", code.message);

    /* free memory */
    free(code.message);

    return 0;
}