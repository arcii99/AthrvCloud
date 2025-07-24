//FormAI DATASET v1.0 Category: QR code reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING 1024

bool isQRCode(const char* s) {
    if (strlen(s) == 21 && s[0] == 'C' && s[1] == '-') {
        for (int i = 2; i < 21; i++) {
            if (s[i] - '0' < 0 || s[i] - '0' > 9) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool decodeQRCode(const char* qrcode, char* sid) {
    if (!isQRCode(qrcode)) {
        return false;
    }
    memcpy(sid, qrcode + 2, 19);
    sid[19] = '\0';
    return true;
}

int main() {
    char line[MAX_STRING];
    char sid[MAX_STRING];
    printf("unique C QR code reader example program\n");
    printf("Please enter a QR code:\n");
    while (fgets(line, MAX_STRING, stdin)) {
        if (decodeQRCode(line, sid)) {
            printf("QR code: \"%s\" -> SID: \"%s\"\n", line, sid);
        } else {
            printf("Invalid QR code: \"%s\"\n", line);
        }
    }
    return EXIT_SUCCESS;
}