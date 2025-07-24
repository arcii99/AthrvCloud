//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Watermark encoding function
void encode_watermark(char* input_file, char* output_file, char* watermark) {

    FILE* fin = fopen(input_file, "rb");
    FILE* fout = fopen(output_file, "wb");

    int watermark_length = strlen(watermark);
    int bytes_per_channel = sizeof(uint8_t);
    uint8_t buffer;

    // Embed watermark length into image header
    fseek(fin, 0, SEEK_SET);
    fwrite(&watermark_length, sizeof(watermark_length), 1, fout);

    // Embed watermark into image data
    for (int i = 0; i < watermark_length; i++) {
        char c = watermark[i];
        for (int j = 0; j < 8; j++) {
            fread(&buffer, bytes_per_channel, 1, fin);
            buffer = (buffer & 0xFE) | ((c >> (7-j)) & 0x01);
            fwrite(&buffer, bytes_per_channel, 1, fout);
        }
    }

    // Copy remaining image data
    while (fread(&buffer, bytes_per_channel, 1, fin) == 1) {
        fwrite(&buffer, bytes_per_channel, 1, fout);
    }

    fclose(fin);
    fclose(fout);
}

// Watermark decoding function
void decode_watermark(char* input_file, char* watermark) {

    FILE* fin = fopen(input_file, "rb");

    int watermark_length;
    uint8_t buffer;

    // Extract watermark length from image header
    fread(&watermark_length, sizeof(watermark_length), 1, fin);

    // Extract watermark from image data
    for (int i = 0; i < watermark_length; i++) {
        char c = 0;
        for (int j = 0; j < 8; j++) {
            fread(&buffer, sizeof(buffer), 1, fin);
            c |= ((buffer & 0x01) << (7-j));
        }
        watermark[i] = c;
    }

    watermark[watermark_length] = '\0';

    fclose(fin);
}

int main() {

    char* input_file = "example.bmp";
    char* output_file = "encoded.bmp";
    char* watermark = "Hello world!";

    encode_watermark(input_file, output_file, watermark);

    char decoded[100];

    decode_watermark(output_file, decoded);

    printf("Decoded Watermark: %s\n", decoded);

    return 0;
}