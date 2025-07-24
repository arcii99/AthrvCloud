//FormAI DATASET v1.0 Category: QR code generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s [input] [output]\n", argv[0]);
        return -1;
    }

    char *input = argv[1];
    char *output = argv[2];

    QRcode *code = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!code) {
        printf("Failed to encode input: %s\n", input);
        return -1;
    }

    FILE *fp = fopen(output, "w");
    if (!fp) {
        printf("Failed to open output file: %s\n", output);
        return -1;
    }

    int width = code->width;
    unsigned char *data = code->data;

    fprintf(fp, "P1\n");
    fprintf(fp, "%d %d\n", width, width);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < width; ++j) {
            int index = i * width + j;
            int bit = (data[index / 8] >> (7 - (index % 8))) & 1;
            fprintf(fp, "%d ", bit);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    QRcode_free(code);

    printf("QR code generated successfully: %s\n", output);
    return 0;
}