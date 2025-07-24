//FormAI DATASET v1.0 Category: Image Steganography ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <InputImage> <OutputImage>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "rb");
    FILE *outp = fopen(argv[2], "wb");

    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    if (outp == NULL) {
        printf("Error creating file %s\n", argv[2]);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long int len = ftell(fp);
    rewind(fp);

    BYTE *buf = (BYTE*) malloc(sizeof(BYTE) * len);

    fread(buf, sizeof(BYTE), len, fp);

    // Hide data here
    buf[0] = 255;
    buf[1] = 250;
    buf[2] = 240;

    fwrite(buf, sizeof(BYTE), len, outp);

    fclose(fp);
    fclose(outp);

    return 0;
}