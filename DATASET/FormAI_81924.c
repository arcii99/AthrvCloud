//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include <stdio.h>

void embed(char *input_img, char *output_img, char *message) {
    FILE *fp_input, *fp_output;
    char ch, bit;
    int i, j, len;

    fp_input = fopen(input_img, "rb");
    fp_output = fopen(output_img, "wb");

    // Embed message length in the first 32 bits
    len = strlen(message);
    fwrite(&len, sizeof(len), 1, fp_output);

    for (i = 0; i < len; i++) {
        ch = message[i];

        for (j = 0; j < 8; j++) {
            fread(&bit, sizeof(bit), 1, fp_input);
            bit = (ch >> j) & 1;
            fwrite(&bit, sizeof(bit), 1, fp_output);
        }
    }

    // Copy remaining bits from input image to output image
    while (fread(&bit, sizeof(bit), 1, fp_input))
        fwrite(&bit, sizeof(bit), 1, fp_output);

    fclose(fp_input);
    fclose(fp_output);
}

void extract(char *input_img, char *message) {
    FILE *fp_input;
    char ch, bit;
    int i, j, len;

    fp_input = fopen(input_img, "rb");

    // Extract message length from the first 32 bits
    fread(&len, sizeof(len), 1, fp_input);

    for (i = 0; i < len; i++) {
        ch = 0;

        for (j = 0; j < 8; j++) {
            fread(&bit, sizeof(bit), 1, fp_input);
            ch |= bit << j;
        }

        message[i] = ch;
    }

    message[i] = '\0';

    fclose(fp_input);
}

int main() {
    char input_img[] = "input_image.bmp";
    char output_img[] = "output_image.bmp";
    char message[] = "Hello, world!";
    char extracted_message[100];

    embed(input_img, output_img, message);
    extract(output_img, extracted_message);

    printf("Extracted message: %s\n", extracted_message);

    return 0;
}