//FormAI DATASET v1.0 Category: QR code generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the BCH code
long long calculateBCH(long long d, int n, int k) {
    long long g[n - k + 1];
    memset(g, 0, sizeof(g));

    for (int i = k; i <= n; i++) {
        long long tmp = d >> (n - i);

        if (tmp & 1) {
            for (int j = 1; j <= n - k; j++) {
                g[j] ^= (tmp >> (n - k - j)) & 1;
            }
        }
    }

    long long code = 0;

    for (int i = 1; i <= n - k; i++) {
        code |= g[i] << (n - k - i);
    }

    return code;
}

// Function to generate the QR code
void generateQRCode(char* inputString) {
    // Define the version and error correction level
    int version = 1;
    char level = 'L';

    // Define the data codewords
    int maxCodewords = 31;

    char* binaryString = malloc((strlen(inputString) * 8) + 1);
    binaryString[0] = '\0';

    for (int i = 0; i < strlen(inputString); i++) {
        char character = inputString[i];

        for (int j = 0; j < 8; j++) {
            if (character & 1) {
                strcat(binaryString, "1");
            } else {
                strcat(binaryString, "0");
            }

            character >>= 1;
        }
    }

    int numCodewords = strlen(binaryString) / 8;

    if (strlen(binaryString) % 8 > 0) {
        numCodewords++;
    }

    if (numCodewords > maxCodewords) {
        printf("Input string is too long.\n");
        return;
    }

    int n = 17 + (4 * version);
    int k = n - 1 - 10 - 4;

    long long data[numCodewords];
    memset(data, 0, sizeof(data));

    for (int i = 0; i < strlen(binaryString); i++) {
        data[i / 8] |= (binaryString[i] - '0') << (7 - (i % 8));
    }

    long long generator = (1 << k) | 0b10100110111;

    for (int i = 0; i < numCodewords; i++) {
        data[i] <<= (n - k - 8);

        for (int j = 0; j < 8; j++) {
            if (data[i] & (1LL << (n - k - 1 - j))) {
                data[i] ^= generator << (j);
            }
        }
    }

    long long dataCodewords[numCodewords];
    memset(dataCodewords, 0, sizeof(dataCodewords));

    for (int i = 0; i < numCodewords; i++) {
        dataCodewords[i] = (data[i] >> (n - 8)) & 0xff;
    }

    long long bch[2];
    memset(bch, 0, sizeof(bch));

    for (int i = 0; i < numCodewords; i++) {
        long long tmp = data[i] << 8;

        for (int j = 0; j < 8; j++) {
            if (tmp & (1LL << (n - k - 1 - j))) {
                tmp ^= generator << (j);
            }
        }

        bch[i % 2] ^= tmp;
    }

    long long eccCodewords[2];
    memset(eccCodewords, 0, sizeof(eccCodewords));

    for (int i = n - k; i > 0; i >>= 1) {
        if (i & 1) {
            eccCodewords[0] ^= generator;
            eccCodewords[1] ^= generator << 1;
        }

        generator = (generator >> 1) ^ (((generator & 1) != 0) ? 0b10100110111 : 0);
    }

    for (int i = 0; i < 2; i++) {
        eccCodewords[i] ^= bch[i];
    }

    long long qrCode = 0;
    qrCode |= (level - 'L') << 13;
    qrCode |= version << 10;

    for (int i = 0; i < numCodewords; i++) {
        qrCode |= dataCodewords[i] << (8 * (i % 2));
    }

    for (int i = 0; i < 2; i++) {
        qrCode |= eccCodewords[i] << (8 * i + n - k - 16);
    }

    long long maskPatterns[8] = {
            0b111011111000100,
            0b111001011110011,
            0b111110110101010,
            0b111100010011101,
            0b110011000101111,
            0b110001100011000,
            0b110110001000001,
            0b110100101110110
    };

    int mask = 0;
    int minPenalty = 1000000000;

    for (int i = 0; i < 8; i++) {
        long long qrCodeMasked = qrCode ^ (maskPatterns[i] << (n - 6));

        printf("QR code with mask pattern %d:\n", i);
        for (int j = n - 1; j >= 0; j--) {
            printf("%c", ((qrCodeMasked >> j) & 1) == 1 ? 'X' : '.');
            if (j % 8 == 0) {
                printf("\n");
            }
        }

        int penalty = 0;

        // Count penalty for rule 1
        for (int x = 0; x < n; x++) {
            int row = x / 8;
            int col = x % 8;

            if ((((qrCodeMasked >> x) & 1) == 1) == ((maskPatterns[i] >> row) & 1)) {
                penalty++;
            }

            if (col >= 1 && (((qrCodeMasked >> x) & 1) == ((qrCodeMasked >> (x - 1)) & 1))) {
                penalty++;
            }

            if (row >= 1 && col >= 1 && (((qrCodeMasked >> x) & 1) == ((qrCodeMasked >> (x - 8 - 1)) & 1))) {
                penalty++;
            }

            if (row >= 1 && (((qrCodeMasked >> x) & 1) == ((qrCodeMasked >> (x - 8)) & 1))) {
                penalty++;
            }
        }

        // Count penalty for rule 2
        int black = 0;
        int total = n / 8 * 8;

        for (int x = 0; x < total; x++) {
            if ((qrCodeMasked >> x) & 1) {
                black++;
            }
        }

        int ratio = 100 * black / total;
        penalty += abs((ratio / 5) - 10) * 10;

        // Count penalty for rule 3
        for (int x = 0; x < n - 10; x++) {
            if (((qrCodeMasked >> x) & 1) == 1 && ((qrCodeMasked >> (x + 1)) & 1) == 0 && ((qrCodeMasked >> (x + 2)) & 1) == 1 && ((qrCodeMasked >> (x + 3)) & 1) == 1 && ((qrCodeMasked >> (x + 4)) & 1) == 1 && ((qrCodeMasked >> (x + 5)) & 1) == 0 && ((qrCodeMasked >> (x + 6)) & 1) == 1 && ((qrCodeMasked >> (x + 7)) & 1) == 1 && ((qrCodeMasked >> (x + 8)) & 1) == 1 && ((qrCodeMasked >> (x + 9)) & 1) == 0 && ((qrCodeMasked >> (x + 10)) & 1) == 1 && ((maskPatterns[i] >> (x / 8)) & 1) == 1) {
                penalty += 40;
            }
        }

        for (int x = 0; x < n - 10; x++) {
            if (((qrCodeMasked >> x) & 1) == 0 && ((qrCodeMasked >> (x + 1)) & 1) == 1 && ((qrCodeMasked >> (x + 2)) & 1) == 1 && ((qrCodeMasked >> (x + 3)) & 1) == 1 && ((qrCodeMasked >> (x + 4)) & 1) == 1 && ((qrCodeMasked >> (x + 5)) & 1) == 0 && ((qrCodeMasked >> (x + 6)) & 1) == 1 && ((qrCodeMasked >> (x + 7)) & 1) == 1 && ((qrCodeMasked >> (x + 8)) & 1) == 1 && ((qrCodeMasked >> (x + 9)) & 1) == 0 && ((qrCodeMasked >> (x + 10)) & 1) == 1 && ((maskPatterns[i] >> (x / 8)) & 1) == 1) {
                penalty += 40;
            }
        }

        // Count penalty for rule 4
        int darkModules = 0;

        for (int x = 0; x < n; x++) {
            if ((qrCodeMasked >> x) & 1) {
                darkModules++;
            }
        }

        penalty += 10 * (abs((100 * darkModules / total) / 5 - 5));

        if (penalty < minPenalty) {
            minPenalty = penalty;
            mask = i;
        }
    }

    printf("Minimum penalty=%d, using mask pattern %d\n", minPenalty, mask);

    qrCode ^= (maskPatterns[mask] << (n - 6));

    printf("Final QR code:\n");

    for (int i = n - 1; i >= 0; i--) {
        printf("%c", ((qrCode >> i) & 1) == 1 ? 'X' : '.');
        if (i % 8 == 0) {
            printf("\n");
        }
    }
}

// Sample usage
int main() {
    generateQRCode("Hello World!");
    return 0;
}