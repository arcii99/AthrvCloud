//FormAI DATASET v1.0 Category: QR code reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_SIZE 100
#define MAX_QR_VERSION 40
#define MAX_QR_DATA 998

typedef struct QR {
    int version;
    int size;
    char data[MAX_QR_DATA];
} QR;

bool isNumeric(char c) {
    return c >= '0' && c <= '9';
}

char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

bool isAlphaNumeric(char c) {
    c = toUpper(c);
    return (c >= 'A' && c <= 'Z') || isNumeric(c) || c == '$' || c == '%' || c == '*' || c == '+' || c == '-' || c == '.' || c == '/' || c == ':' || c == ' ';
}

int charToBits(char c) {
    if (isNumeric(c)) {
        return c - '0';
    } else if (isAlphaNumeric(c)) {
        c = toUpper(c);
        return c - 'A' + 10;
    } else {
        return -1;
    }
}

int bitsToChar(int bits) {
    if (bits >= 0 && bits <= 9) {
        return bits + '0';
    } else if (bits >= 10 && bits <= 35) {
        return bits - 10 + 'A';
    }
    return -1;
}

bool isValidQR(char qr[MAX_QR_SIZE][MAX_QR_SIZE], int size) {
    bool black = false;
    bool white = false;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (qr[i][j] == '0') {
                black = true;
            } else if (qr[i][j] == '1') {
                white = true;
            } else {
                return false;
            }
        }
    }
    return black && white;
}

void decodeMode(char qr[MAX_QR_SIZE][MAX_QR_SIZE], int size, int *row, int *col, int *length) {
    *row = size - 1;
    *col = size - 1;
    *length = 0;

    while (*row >= 0 && qr[*row][*col] == '0') {
        --*row;
    }

    if (*row < 0) {
        *row = 0;
        *col -= 2;
    } else {
        *row += 1;
    }

    while (*col >= 0 && qr[*row][*col] == '0') {
        --*col;
    }

    *col += 1;

    while (*col < size) {
        int bits = 0;
        for (int i = 0; i < 4; ++i) {
            if (*col >= size || qr[*row][*col] != '0') {
                *length /= 10;
                return;
            }
            bits = (bits << 1) | (qr[*row][*col] - '0');
            ++*col;
        }

        if (bits >= 10) {
            bits = (bits << 6) | ((qr[*row][*col] & 0x3F) << 0);
            ++*length;
            ++*col;
        }

        if (bits >= 45) {
            bits = (bits << 6) | ((qr[*row][*col] & 0x3F) << 0);
            ++*length;
            ++*col;
        }

        qr[*row][*col] = '\0';

        *length = (*length * 100) + (bits / 10);
        *length = (*length * 10) + (bits % 10);
    }
}

void decodeText(char qr[MAX_QR_SIZE][MAX_QR_SIZE], int size, char *text, int length) {
    int row = size - 1;
    int col = size - 1;
    int pos = 0;

    while (pos < length) {
        int bits = 0;

        for (int i = 0; i < 8; ++i) {
            if (col < 0 || qr[row][col] != '0') {
                text[pos] = '\0';
                return;
            }
            bits = (bits << 1) | (qr[row][col] - '0');
            --col;
        }

        text[pos] = bitsToChar(bits >> 4);
        ++pos;

        if (pos < length && !isNumeric(text[pos - 1])) {
            text[pos] = '\0';
            return;
        }

        if (pos < length) {
            bits = 0;

            for (int i = 0; i < 8; ++i) {
                if (col < 0 || qr[row][col] != '0') {
                    text[pos] = '\0';
                    return;
                }
                bits = (bits << 1) | (qr[row][col] - '0');
                --col;
            }

            text[pos] = bitsToChar(bits >> 4);
            ++pos;
        }
    }
}

bool isUTF8(char *text) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if ((text[i] & 0x80) != 0x00) {
            if ((text[i] & 0xE0) != 0xC0) {
                return false;
            }
            if ((text[i + 1] & 0xC0) != 0x80) {
                return false;
            }
            i += 1;
        }
    }
    return true;
}

bool readQR(QR *qr) {
    char line[MAX_QR_SIZE];
    char qrData[MAX_QR_SIZE][MAX_QR_SIZE];

    if (fgets(line, MAX_QR_SIZE, stdin) == NULL) {
        return false;
    }

    qr->size = strlen(line);
    int row = 0;
    do {
        for (int i = 0; i < qr->size; ++i) {
            qrData[row][i] = line[i];
        }
        ++row;
    } while (fgets(line, MAX_QR_SIZE, stdin) != NULL && row < qr->size);

    if (row != qr->size) {
        return false;
    }

    if (!isValidQR(qrData, qr->size)) {
        return false;
    }

    decodeMode(qrData, qr->size, &row, &qr->size, &qr->version);

    if (qr->version < 1 || qr->version > MAX_QR_VERSION) {
        return false;
    }

    decodeText(qrData, qr->size, qr->data, (qr->version - 1) * 4 - 17);

    return isUTF8(qr->data);
}

int main() {
    QR qr;
    printf("Enter a QR code:\n");

    while (readQR(&qr)) {
        printf("QR code version: %d\n", qr.version);
        printf("QR code size: %d\n", qr.size);
        printf("QR code data: %s\n", qr.data);
        printf("Enter another QR code:\n");
    }

    printf("Invalid QR code\n");
    return 0;
}