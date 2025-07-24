//FormAI DATASET v1.0 Category: QR code generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_DIM 21

// Helper function to print out the QR code
void print_qr(int qr[QR_DIM][QR_DIM]) {
    int i, j;
    for (i = 0; i < QR_DIM; i++) {
        for (j = 0; j < QR_DIM; j++) {
            if (qr[i][j] == 1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}

// Helper function to calculate the BCH code
int bch(int data, int poly) {
    int i, msb_pos, t;
    // Step 1: Calculate the position of the most significant bit in the data
    for (i = 0; i < 31; i++) {
        if ((data >> i) == 0)
            break;
    }
    msb_pos = i - 1;
    // Step 2: XOR the top bits of the polynomial with the data
    t = poly ^ (data >> msb_pos);
    // Step 3: Repeat until the degree of t is less than the degree of the
    // polynomial
    while (msb_pos >= 0 && (t >> msb_pos) > 0) {
        t ^= poly << (msb_pos - (int)log2(poly));
        // Recalculate the position of the most significant bit of t
        for (i = 0; i < 31; i++) {
            if ((t >> i) == 0)
                break;
        }
        msb_pos = i - 1;
    }
    // Step 4: Return the remainder
    return t;
}

// Main function to generate QR code
int main(int argc, char *argv[]) {
    int i, j, k, l, data_len, bc_len, total_len, ecc_len, data_bits, ecc_bits, version, mask, poly;
    char *data_str;
    int qr[QR_DIM][QR_DIM] = {0};
    int ecc_a[15] = {  // Ecc coefficients for version 1
        0x537, 0x559, 0x5D5, 0x5F3, 0x62B, 0x673, 0x6B7, 0x703, 0x7c3, 0x84B,
        0x8EC, 0x97F, 0x9E7, 0xA75, 0xAF5
    };
    int ecc_b[15] = {  // Ecc coefficients for version 2
        0x1AB, 0x1D7, 0x223, 0x253, 0x2B7, 0x2E1, 0x30F, 0x33B, 0x397, 0x3E5,
        0x43F, 0x4C9, 0x4FA, 0x53B, 0x571
    };
    // Step 1: Parse the input data
    if (argc < 2) {
        printf("Usage: ./qr <data string>\n");
        return 1;
    }
    data_str = argv[1];
    data_len = strlen(data_str);
    // Step 2: Get the version number based on the length of the input data
    if (data_len <= 17)
        version = 1;
    else if (data_len <= 32)
        version = 2;
    else
        version = 0;  // Data too long
    if (version == 0) {
        printf("Input data too long (%d characters)\n", data_len);
        return 1;
    }
    // Step 3: Calculate the number of bits in the data and the error correction
    // code
    bc_len = version == 1 ? 10 : 13;
    total_len = version == 1 ? 19 : 32;
    ecc_len = version == 1 ? 7 : 10;
    data_bits = (total_len - bc_len - ecc_len) * 8;
    ecc_bits = ecc_len * 8;
    // Step 4: Generate the BCH code
    poly = version == 1 ? 0x537 : 0x187;
    for (i = 0; i < data_len; i += bc_len) {
        int data_chunk = 0;
        // Convert the data chunk to an int
        for (j = 0; j < bc_len && i + j < data_len; j++) {
            data_chunk <<= 8;
            data_chunk |= data_str[i + j];
        }
        // Add the BCH code to the data chunk
        for (j = ecc_bits - 1; j >= 0; j--) {
            int bit = (bch(data_chunk, poly) >> j) & 1;
            data_chunk <<= 1;
            data_chunk |= bit;
        }
        // Append the data chunk to the input string
        for (j = 0; j < total_len - ecc_len && (i / bc_len) * (total_len - ecc_len) + j < data_bits; j++) {
            int bit = (data_chunk >> (data_bits - j - 1)) & 1;
            qr[j / QR_DIM][j % QR_DIM] = bit;
        }
        // Generate the error correction code
        if (version == 1) {
            int ecc_chunk = 0;
            for (j = 0; j < 10; j++) {
                ecc_chunk <<= 8;
                for (k = 0; k < QR_DIM; k++) {
                    int bit = qr[k][j + total_len - ecc_len];
                    ecc_chunk |= bit << (7 - (k / 3) * 3 - (k % 3));
                }
            }
            for (j = ecc_bits - 1; j >= 0; j--) {
                int bit = (bch(ecc_chunk, ecc_a[j]) >> (QR_DIM - j - 1)) & 1;
                ecc_chunk <<= 1;
                ecc_chunk |= bit;
            }
            for (j = 0; j < ecc_len; j++) {
                for (k = 0; k < 3; k++) {
                    for (l = 0; l < 3; l++) {
                        int bit = (ecc_chunk >> ((2 - l) * 3 + k)) & 1;
                        qr[(11 + j) * 3 + k][(total_len - ecc_len + 10) * 3 + l] = bit;
                    }
                }
            }
        } else {
            int ecc_chunk1 = 0, ecc_chunk2 = 0;
            for (j = 0; j < 13; j++) {
                ecc_chunk1 <<= 8;
                ecc_chunk2 <<= 8;
                for (k = 0; k < QR_DIM; k++) {
                    int bit = qr[k][j + total_len - ecc_len];
                    ecc_chunk1 |= bit << (7 - (k / 3) * 3 - (k % 3));
                    ecc_chunk2 |= bit << (14 - (k % 2) * 3 - (k / 2));
                }
            }
            for (j = ecc_bits - 1; j >= 0; j--) {
                int bit1 = (bch(ecc_chunk1, ecc_a[j]) >> (QR_DIM - j - 1)) & 1;
                int bit2 = (bch(ecc_chunk2, ecc_b[j]) >> (14 - j - 1)) & 1;
                ecc_chunk1 <<= 1;
                ecc_chunk1 |= bit1;
                ecc_chunk2 <<= 1;
                ecc_chunk2 |= bit2;
            }
            for (j = 0; j < ecc_len; j++) {
                for (k = 0; k < 2; k++) {
                    for (l = 0; l < 6; l++) {
                        int bit = (ecc_chunk1 >> ((2 - k) * 3 + l)) & 1;
                        qr[(9 + j / 2) * 3 + k][(total_len - ecc_len + 12) * 3 + l] = bit;
                    }
                }
                for (k = 0; k < 3; k++) {
                    for (l = 0; l < 2; l++) {
                        int bit = (ecc_chunk2 >> ((2 - l) * 3 + k)) & 1;
                        qr[(total_len - ecc_len + 10) * 3 + k][(9 + j / 2) * 3 + l] = bit;
                    }
                }
            }
        }
    }
    // Step 5: Choose a mask and apply it to the QR code
    mask = 0;
    for (i = 0; i < QR_DIM; i++) {
        for (j = 0; j < QR_DIM; j++) {
            // Choose a mask based on the least significant bits of i and j
            if ((i + j) % 2 == 0)
                mask = 0;
            else if (i % 2 == 0)
                mask = 1;
            else
                mask = 2;
            if ((i + j) % 3 == 0)
                mask = (mask + 3) % 8;
            // Apply the mask
            if (mask == 0)
                qr[i][j] ^= ((i + j) % 2 == 0) ? 1 : 0;
            else if (mask == 1)
                qr[i][j] ^= (i % 2 == 0) ? 1 : 0;
            else if (mask == 2)
                qr[i][j] ^= (j % 3 == 0) ? 1 : 0;
            else if (mask == 3)
                qr[i][j] ^= ((i + j) % 3 == 0) ? 1 : 0;
            else if (mask == 4)
                qr[i][j] ^= ((i / 2 + j / 3) % 2 == 0) ? 1 : 0;
            else if (mask == 5)
                qr[i][j] ^= ((i * j) % 2 + (i * j) % 3 == 0) ? 1 : 0;
            else if (mask == 6)
                qr[i][j] ^= (((i * j) % 2 + (i * j) % 3) % 2 == 0) ? 1 : 0;
            else
                qr[i][j] ^= (((i + j) % 2 + (i * j) % 3) % 2 == 0) ? 1 : 0;
        }
    }
    // Step 6: Print out the QR code
    print_qr(qr);
    return 0;
}