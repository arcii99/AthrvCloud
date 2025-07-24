//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Shannon entropy formula
double shannon_entropy(uint8_t *data, size_t len) {
    double freq[256] = {0};
    for (size_t i = 0; i < len; i++) {
        freq[data[i]]++;
    }
    double entropy = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i]) {
            double p = freq[i] / len;
            entropy -= p * log2(p);
        }
    }
    return entropy;
}

// Image to ASCII art conversion
void image_to_ascii(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file\n");
        return;
    }
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    uint8_t *data = malloc(fsize);
    if (!data) {
        printf("Error allocating memory\n");
        fclose(fp);
        return;
    }
    fread(data, fsize, 1, fp);
    fclose(fp);
    char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    size_t num_chars = sizeof(ascii_chars) / sizeof(ascii_chars[0]);
    for (size_t i = 0, j = 0; i < fsize; i += 3, j++) {
        uint8_t r = data[i];
        uint8_t g = data[i+1];
        uint8_t b = data[i+2];
        double brightness = (0.2126*r + 0.7152*g + 0.0722*b) / 255;
        int index = (int)(brightness * (num_chars - 1));
        printf("%c", ascii_chars[index]);
        // Check for end of row
        if (j && j % 50 == 0) {
            printf("\n");
        }
    }
    free(data);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./img2ascii [filename]\n");
        return 1;
    }
    char *filename = argv[1];
    image_to_ascii(filename);
    double entropy = shannon_entropy((uint8_t *)filename, sizeof(filename));
    printf("\nShannon entropy: %f\n", entropy);
    return 0;
}