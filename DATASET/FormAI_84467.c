//FormAI DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS_PER_BYTE 8

void write_byte(FILE *out_file, unsigned char byte) {
    fwrite(&byte, 1, sizeof(unsigned char), out_file);
}

void hide_message(FILE *out_file, unsigned int bits, const char *message) {
    // Write the number of bits to be stored
    write_byte(out_file, bits);

    // Write message length to the output file
    unsigned int message_len = strlen(message);
    for (int i = sizeof(unsigned int) - 1; i >= 0; --i) {
        write_byte(out_file, ((unsigned char*)&message_len)[i]);
    }

    // Write each character
    unsigned char mask = 0x01;
    unsigned char curr_byte = 0x00;
    int curr_bit_index = 0;
    for (int i = 0; i < message_len; ++i) {
        for (int j = 0; j < BITS_PER_BYTE; ++j) {
            if (message[i] & (1 << j)) {
                curr_byte |= mask;
            }
            ++curr_bit_index;
            mask <<= 1;
            if (curr_bit_index == bits) {
                // Store the current byte and reset the state
                write_byte(out_file, curr_byte);
                curr_byte = 0x00;
                curr_bit_index = 0;
                mask = 0x01;
            }
        }
    }

    // Write the last byte if necessary
    if (curr_bit_index > 0) {
        write_byte(out_file, curr_byte);
    }
}

void seek_next_byte(FILE *in_file) {
    fseek(in_file, (long int)(ftell(in_file)/BITS_PER_BYTE+1)*BITS_PER_BYTE, SEEK_SET);
}

void decode_message(FILE *in_file, char *message) {
    unsigned int bits = fgetc(in_file);
    if (bits == EOF) {
        return;
    }

    // Read the message length
    unsigned int message_len = 0;
    for (size_t i = 0; i < sizeof(unsigned int); ++i) {
        unsigned int byte = fgetc(in_file);
        message_len |= byte << (BITS_PER_BYTE * i);
    }

    // Read each character
    unsigned char mask = 0x01;
    int curr_bit_index = 0;
    for (unsigned int i = 0; i < message_len; ++i) {
        char curr_char = 0x00;
        for (int j = 0; j < BITS_PER_BYTE; ++j) {
            int bit = fgetc(in_file) & mask;
            curr_char |= (bit << j);
            ++curr_bit_index;
            if (curr_bit_index == bits) {
                curr_bit_index = 0;
                mask = 0x01;
                message[i] = curr_char;
                break;
            }
            mask <<= 1;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s infile messagefile outfile\n", argv[0]);
        return 1;
    }

    FILE *in_file = fopen(argv[1], "rb");
    if (in_file == NULL) {
        printf("Failed to open %s for reading\n", argv[1]);
        return 1;
    }

    FILE *message_file = fopen(argv[2], "r");
    if (message_file == NULL) {
        printf("Failed to open %s for reading\n", argv[2]);
        fclose(in_file);
        return 1;
    }

    FILE *out_file = fopen(argv[3], "wb");
    if (out_file == NULL) {
        printf("Failed to open %s for writing\n", argv[3]);
        fclose(in_file);
        fclose(message_file);
        return 1;
    }

    // Hide the message from the input file in the output file
    char message[1024];
    fgets(message, sizeof(message), message_file);
    hide_message(out_file, 1, message);

    // Copy any remaining data from the input file to the output file
    int c;
    while ((c = fgetc(in_file)) != EOF) {
        fputc(c, out_file);
    }

    fclose(in_file);
    fclose(message_file);
    fclose(out_file);

    // Decode the message from the output file
    in_file = fopen(argv[3], "rb");
    if (in_file == NULL) {
        printf("Failed to open %s for reading\n", argv[3]);
        return 1;
    }

    decode_message(in_file, message);
    printf("Message: %s", message);

    fclose(in_file);
    return 0;
}