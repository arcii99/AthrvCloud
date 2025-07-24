//FormAI DATASET v1.0 Category: QR code reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursiveDecode(char *data, int length, char *decoded) {
    if (length <= 0) {
        return;
    }
    int i;
    for (i = 0; i < length; i++) {
        if (data[i] != ' ') {
            break;
        }
    }
    char decodedChar = (char) strtol(data + i, NULL, 2);
    char nextChar[9];
    memcpy(nextChar, data + i + 8, 8);
    nextChar[8] = '\0';
    strcat(decoded, &decodedChar);
    recursiveDecode(nextChar, length - i - 8, decoded);
}

char* readQRCode(char *qrCode) {
    int length = strlen(qrCode);
    char* decoded = malloc(length / 8);
    recursiveDecode(qrCode, length, decoded);
    return decoded;
}

int main() {
    char* qrCode = "01010100 01101000 01101001 01110011 00100000 01101001 01110011 00100000 01100001 00100000 01100101 01111000 01100001 01101101 01110000 01101100 01100101 00100000 01101111 01100110 00100000 01110011 01100101 01110010 01101001 01101111 01110101 01110011 00100000 01110011 01101001 01111000 01110100 01100101 01100101 01101110 00101100 00100000 01110011 01100101 01100101 00101100 00100000 01100011 01101111 01101101 01101101 01110101 01101110 01101001 01100011 01100001 01110100 01101001 01101111 01101110 00101110";
    char* decoded = readQRCode(qrCode);
    printf("%s\n", decoded);
    free(decoded);
    return 0;
}