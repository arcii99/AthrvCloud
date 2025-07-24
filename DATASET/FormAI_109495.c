//FormAI DATASET v1.0 Category: QR code generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define QR code version (1-40)
#define QR_VERSION 5

// Define bits per character
#define BITS_PER_CHAR 8

// Define polynomial for QR code generator
#define GENERATOR_POLY 0b10100110111LL

// Define alignment pattern coordinates for QR code version 5
const int ALIGN_PATTERN_COORD[6][2] = {{6, 26}, {18, 26}, {6, 18}, {18, 18}, {6, 10}, {18, 10}};

// Define function to add two polynomials
uint64_t poly_addition(uint64_t a, uint64_t b) {
    uint64_t result = a ^ b;
    return result;
}

// Define function to multiply two polynomials
uint64_t poly_multiplication(uint64_t a, uint64_t b) {
    uint64_t result = 0;

    while (b) {
        if (b & 1) {
            result ^= a;
        }

        a <<= 1;
        if (a & (1LL << BITS_PER_CHAR)) {
            a ^= GENERATOR_POLY;
        }
        b >>= 1;
    }

    return result;
}

// Define function to calculate the error correction code
void calculate_error_correction_code(uint8_t *data, int data_length, int ec_codewords, uint8_t *ec_codeword_buffer) {
    // Define generator polynomial
    uint64_t generator = 1;
    for (int i = 0; i < ec_codewords; i++) {
        generator = poly_multiplication(generator, 2);
    }

    // Initialize buffer for temporary calculation
    uint64_t buffer = 0;
    uint64_t poly = 0;

    // Loop over data to calculate error correction code
    for (int i = 0; i < data_length; i++) {
        buffer = (buffer << BITS_PER_CHAR) | data[i];
        if (buffer & (1LL << (BITS_PER_CHAR * ec_codewords))) {
            poly = generator ^ (buffer >> (BITS_PER_CHAR * ec_codewords));
        } else {
            poly = buffer;
        }
        int shift = BITS_PER_CHAR * ec_codewords;
        while (poly && shift >= 0) {
            uint8_t degree = __builtin_clzll(poly);
            poly ^= (1LL << (64 - degree - 1));
            shift -= degree;
            buffer ^= ((uint64_t) GENERATOR_POLY) << shift;
        }
    }

    // Fill buffer with error correction codewords
    for (int i = 0; i < ec_codewords; i++) {
        ec_codeword_buffer[i] = (buffer >> ((ec_codewords - i - 1) * BITS_PER_CHAR)) & 0xff;
    }
}

// Define function to encode data into QR code
void encode_data(const char *data, int data_length, uint8_t *buffer) {
    // Define bit buffer
    int bit_pos = 0;
    int bit_buffer = 0;

    // Append mode indicator (numeric mode)
    bit_buffer = (QR_VERSION >= 10) ? (0b100) : 0b1;
    bit_pos += (QR_VERSION >= 10) ? 4 : 1;

    // Append character count indicator
    for (int i = 0; i < 10; i++) {
        if (data_length < (1 << ((i + 1) * 3))) {
            bit_buffer |= data_length << bit_pos;
            bit_pos += (i + 1) * 3;
            break;
        }
    }

    // Process data in chunks of 3 digits
    for (int i = 0; i < data_length; i += 3) {
        // Check remaining length
        int remaining_length = data_length - i;

        // Encode 1 digit (4 bits)
        bit_buffer |= (data[i] - '0') << bit_pos;
        bit_pos += 4;

        // Encode 2 digits (7 bits)
        if (remaining_length > 1) {
            bit_buffer |= (data[i + 1] - '0') << bit_pos;
            bit_pos += 7;

            // Encode 3 digits (10 bits)
            if (remaining_length > 2) {
                bit_buffer |= (data[i + 2] - '0') << bit_pos;
                bit_pos += 10;
            }
        }
    }

    // Append terminator and padding
    int terminator_bits = (QR_VERSION >= 10) ? 12 : 4;
    bit_buffer |= (1 << bit_pos);
    bit_pos += terminator_bits;
    if (bit_pos % 8 != 0) {
        int padding_bits = 8 - bit_pos % 8;
        bit_buffer <<= padding_bits;
        bit_pos += padding_bits;
    }

    // Define number of blocks and bytes per block
    int num_blocks = (QR_VERSION >= 7) ? 2 : 1;
    int bytes_per_block = (QR_VERSION >= 7) ? 32 : 16;

    // Calculate total number of codewords (data + error correction)
    int total_codewords = num_blocks * bytes_per_block / BITS_PER_CHAR;
    int ec_codewords = (QR_VERSION >= 7) ? ((total_codewords - data_length / 3 - 1) / 2) : (total_codewords - data_length / 3 - 1);

    // Generate error correction code
    uint8_t *ec_codewords_buffer = malloc(ec_codewords);
    calculate_error_correction_code(buffer, data_length / 3 + (data_length % 3 != 0), ec_codewords, ec_codewords_buffer);

    // Append padding bytes
    int padding_bytes = total_codewords - data_length / 3 - ec_codewords - 1;
    memset(&buffer[data_length + (data_length % 3 != 0)], 0, padding_bytes);

    // Append terminator and padding codewords
    uint8_t terminator_codeword = (QR_VERSION >= 10) ? 0b0001 : 0b0;
    memset(&buffer[data_length + padding_bytes + (data_length % 3 != 0)], terminator_codeword, sizeof(uint8_t) * ec_codewords);
    memset(&buffer[data_length + padding_bytes + (data_length % 3 != 0) + ec_codewords], 0, sizeof(uint8_t) * (padding_bytes - ec_codewords));

    // Append error correction codewords
    memcpy(&buffer[data_length + padding_bytes + (data_length % 3 != 0) + padding_bytes - ec_codewords], ec_codewords_buffer, sizeof(uint8_t) * ec_codewords);

    // Free error correction code buffer
    free(ec_codewords_buffer);
}

// Define function to generate QR code with math shapes
void generate_qr_code(uint8_t *buffer) {
    // Define pattern sizes
    int finder_size = 7;
    int separator_size = 1;
    int alignment_size = 5;
    int timing_size = QR_VERSION * 2 + 1;
    int version_size = 0;
    int format_size = 15;

    // Calculate total code size
    int code_size = (finder_size * 3 + separator_size * 2 + alignment_size * 6 + timing_size * 2 + version_size + format_size) * 2 - separator_size;

    // Initialize code with white pixels
    uint8_t code[QR_VERSION][QR_VERSION];
    memset(code, 0xff, sizeof(code));

    // Draw finder patterns
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Set position of finder pattern
            int x = i == 0 ? 0 : (i == 1 ? QR_VERSION - finder_size : finder_size);
            int y = j == 0 ? 0 : (j == 1 ? QR_VERSION - finder_size : finder_size);

            // Draw border
            for (int k = 0; k < finder_size; k++) {
                for (int l = 0; l < finder_size; l++) {
                    code[y + k][x + l] = 0x0;
                }
            }

            // Draw inner shape
            for (int k = 2; k < finder_size - 2; k++) {
                for (int l = 2; l < finder_size - 2; l++) {
                    code[y + k][x + l] = 0x1;
                }
            }
        }
    }

    // Draw separator
    int separator_pos = finder_size * 3;
    for (int i = 0; i < separator_size; i++) {
        for (int j = 0; j < QR_VERSION; j++) {
            code[j][separator_pos + i] = 0x0;
            code[separator_pos + i][j] = 0x0;
        }
    }

    // Draw alignment patterns
    for (int i = 0; i < 6; i++) {
        // Set position of alignment pattern
        int x = ALIGN_PATTERN_COORD[i][0] - alignment_size / 2;
        int y = ALIGN_PATTERN_COORD[i][1] - alignment_size / 2;

        // Draw outer border
        for (int k = 0; k < alignment_size; k++) {
            for (int l = 0; l < alignment_size; l++) {
                code[y + k][x + l] = 0x0;
            }
        }

        // Draw inner shape
        for (int k = 2; k < alignment_size - 2; k++) {
            for (int l = 2; l < alignment_size - 2; l++) {
                code[y + k][x + l] = 0x1;
            }
        }
    }

    // Draw timing patterns
    for (int i = 0; i < timing_size; i++) {
        code[6][7 + i] = i % 2 == 0 ? 0x1 : 0x0;
        code[7 + i][6] = i % 2 == 0 ? 0x1 : 0x0;
    }

    // Draw version information
    if (QR_VERSION >= 7) {
        // Define position of version pattern
        int x = QR_VERSION - 11;
        int y = 0;

        // Calculate version information
        uint16_t version_info = QR_VERSION << 12;

        // Generate version information data
        for (int i = 0; i < 6; i++) {
            if (version_info & (1 << (i + 9))) {
                code[y + 5 - i][x] = 0x1;
            } else {
                code[y + 5 - i][x] = 0x0;
            }
        }
        for (int i = 0; i < 6; i++) {
            if (version_info & (1 << i)) {
                code[y][x + i] = 0x1;
            } else {
                code[y][x + i] = 0x0;
            }
        }
    }

    // Draw format information
    {
        // Define position of format pattern
        int x = separator_pos - format_size / 2;
        int y = separator_pos - format_size / 2;

        // Calculate format information
        uint16_t format_info = 0b000000000011110;

        // Generate format information data
        for (int i = 0; i < 6; i++) {
            if (format_info & (1 << (i + 9))) {
                code[y + i][x] = 0x1;
            } else {
                code[y + i][x] = 0x0;
            }
        }
        for (int i = 0; i < 6; i++) {
            if (format_info & (1 << i)) {
                code[y][x + format_size - 1 - i] = 0x1;
            } else {
                code[y][x + format_size - 1 - i] = 0x0;
            }
        }
        for (int i = 0; i < 8; i++) {
            if (format_info & (1 << (i + 14))) {
                code[y + format_size - 1][x + i] = 0x1;
            } else {
                code[y + format_size - 1][x + i] = 0x0;
            }
        }
        for (int i = 0; i < 8; i++) {
            if (format_info & (1 << (i + 6))) {
                code[y + format_size - 1 - i][x + format_size - 1] = 0x1;
            } else {
                code[y + format_size - 1 - i][x + format_size - 1] = 0x0;
            }
        }
    }

    // Set module values from bit buffer
    for (int i = 0; i < QR_VERSION; i++) {
        for (int j = 0; j < QR_VERSION; j++) {
            buffer[i * QR_VERSION + j] = code[i][j];
        }
    }
}

// Define function to print QR code to console
void print_qr_code(const uint8_t *buffer) {
    for (int i = 0; i < QR_VERSION; i++) {
        for (int j = 0; j < QR_VERSION; j++) {
            printf("%c", buffer[i * QR_VERSION + j] ? 'X' : ' ');
        }
        printf("\n");
    }
}

// Main function
int main(void) {
    // Define data to encode
    const char *data = "Hello, world!";

    // Generate bit buffer from data
    uint8_t buffer[1000];
    encode_data(data, strlen(data), buffer);

    // Generate QR code from bit buffer
    uint8_t qr_code[QR_VERSION * QR_VERSION];
    generate_qr_code(qr_code);

    // Overlay bit buffer on QR code
    for (int i = 0; i < QR_VERSION * QR_VERSION; i++) {
        if (qr_code[i] == 1) {
            qr_code[i] = buffer[i / 8] & (1 << (7 - i % 8));
        }
    }

    // Print QR code to console
    print_qr_code(qr_code);

    return EXIT_SUCCESS;
}