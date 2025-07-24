//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 512

struct watermark {
    char msg[MAX_SIZE];
    int x;
    int y;
};

int main() {
    // Load input image
    char input[MAX_SIZE];
    printf("Enter input file name: ");
    scanf("%s", input);
    FILE* fp1 = fopen(input, "rb");
    if (!fp1) {
        printf("Error: Could not open input file '%s'!\n", input);
        return 1;
    }
    fseek(fp1, 0, SEEK_END);
    long int size = ftell(fp1);
    fseek(fp1, 0, SEEK_SET);
    unsigned char* img = (unsigned char*) malloc(size);
    fread(img, sizeof(unsigned char), size, fp1);
    fclose(fp1);
    printf("Loaded input image '%s' of size %ld bytes.\n", input, size);

    // Load watermark message
    char message[MAX_SIZE];
    printf("Enter watermark message: ");
    scanf("%s", message);
    struct watermark wm;
    strcpy(wm.msg, message);
    printf("Watermark message: %s\n", wm.msg);

    // Embed watermark message
    srand(1234); // Set seed for pseudo-random number generator
    int x = rand() % (MAX_SIZE/2);
    int y = rand() % (MAX_SIZE/2);
    wm.x = x;
    wm.y = y;
    int offset = y * MAX_SIZE + x;
    for (int i = 0; i < strlen(wm.msg); i++) {
        char c = wm.msg[i];
        unsigned char p = img[offset + i];
        p &= ~(1 << 0); // Clear least significant bit
        int bit;
        for (int j = 0; j < 8; j++) {
            bit = (c >> j) & 1;
            p |= (bit << j);
        }
        img[offset + i] = p;
    }
    printf("Embedded watermark message at pixel (%d, %d).\n", x, y);

    // Save output image
    char output[MAX_SIZE];
    printf("Enter output file name: ");
    scanf("%s", output);
    FILE* fp2 = fopen(output, "wb");
    fwrite(img, sizeof(unsigned char), size, fp2);
    fclose(fp2);
    printf("Saved output image '%s' of size %ld bytes.\n", output, size);

    // Extract watermark message
    struct watermark wm2;
    x = wm.x;
    y = wm.y;
    offset = y * MAX_SIZE + x;
    for (int i = 0; i < strlen(wm2.msg); i++) {
        char c = 0;
        unsigned char p = img[offset + i];
        for (int j = 0; j < 8; j++) {
            if (p & (1 << j)) {
                c |= (1 << j);
            }
        }
        wm2.msg[i] = c;
    }
    printf("Extracted watermark message: %s\n", wm2.msg);

    // Compute PSNR
    double mse = 0;
    for (int i = 0; i < size; i++) {
        mse += pow((double)img[i] - (double)img[i+size], 2);
    }
    mse /= size;
    double psnr = 20 * log10(255.0 / sqrt(mse));
    printf("PSNR: %f dB\n", psnr);

    free(img);
    return 0;
}