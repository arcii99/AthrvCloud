//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t* read_bmp(char* filename, int* row_size, int* img_size) {
    FILE* f = fopen(filename, "rb");
    if (!f) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // read bitmap headers
    uint16_t sig;
    fread(&sig, sizeof(uint16_t), 1, f);
    if (sig != 0x4D42) { // BM signature
        printf("File is not a BMP!\n");
        return NULL;
    }

    uint32_t file_size;
    fread(&file_size, sizeof(uint32_t), 1, f);
    fseek(f, 4, SEEK_CUR); // skip reserved area
    uint32_t offset;
    fread(&offset, sizeof(uint32_t), 1, f);

    uint32_t header_size;
    fread(&header_size, sizeof(uint32_t), 1, f);
    if (header_size != 40) {
        printf("Unsupported BMP format!\n");
        return NULL;
    }

    uint32_t width, height;
    fread(&width, sizeof(uint32_t), 1, f);
    fread(&height, sizeof(uint32_t), 1, f);

    *img_size = height * ((3 * width + 3) & (~3));
    *row_size = (*img_size) / height; // row size, aligned to 4 bytes
    uint16_t planes;
    fread(&planes, sizeof(uint16_t), 1, f);
    if (planes != 1) {
        printf("Unsupported BMP format!\n");
        return NULL;
    }

    uint16_t bpp;
    fread(&bpp, sizeof(uint16_t), 1, f);
    if (bpp != 24) {
        printf("Unsupported BMP format!\n");
        return NULL;
    }

    fseek(f, offset, SEEK_SET);
    uint8_t* img_data = (uint8_t*)malloc(*img_size);
    if (!img_data) {
        printf("Error allocating memory!\n");
        return NULL;
    }
    fread(img_data, 1, *img_size, f);
    fclose(f);
    return img_data;
}

void write_bmp(char* filename, uint8_t* img_data, int row_size, int width, int height) {
    FILE* f = fopen(filename, "wb");
    if (!f) {
        printf("Error opening file %s\n", filename);
        return;
    }

    uint32_t img_size = height * row_size;
    uint32_t file_size = img_size + 54;
    fwrite("BM", 1, 2, f);
    fwrite(&file_size, sizeof(uint32_t), 1, f);
    uint32_t reserved = 0;
    fwrite(&reserved, sizeof(uint32_t), 1, f);
    uint32_t offset = 54;
    fwrite(&offset, sizeof(uint32_t), 1, f);
    uint32_t header_size = 40;
    fwrite(&header_size, sizeof(uint32_t), 1, f);
    fwrite(&width, sizeof(uint32_t), 1, f);
    fwrite(&height, sizeof(uint32_t), 1, f);
    uint16_t planes = 1;
    fwrite(&planes, sizeof(uint16_t), 1, f);
    uint16_t bpp = 24;
    fwrite(&bpp, sizeof(uint16_t), 1, f);
    uint32_t compression = 0;
    fwrite(&compression, sizeof(uint32_t), 1, f);
    uint32_t size = img_size;
    fwrite(&size, sizeof(uint32_t), 1, f);
    uint32_t hres = 0;
    uint32_t vres = 0;
    fwrite(&hres, sizeof(uint32_t), 1, f);
    fwrite(&vres, sizeof(uint32_t), 1, f);
    uint32_t palette = 0;
    fwrite(&palette, sizeof(uint32_t), 1, f);
    uint32_t important = 0;
    fwrite(&important, sizeof(uint32_t), 1, f);
    fwrite(img_data, 1, img_size, f);
    fclose(f);
}

void flip_horizontally(uint8_t* img_data, int row_size, int height) {
    uint8_t* temp = (uint8_t*)malloc(row_size);
    if (!temp) {
        printf("Error allocating memory!\n");
        return;
    }

    int half_height = height / 2;
    for (int i = 0; i < half_height; i++) {
        int j = height - i - 1;
        uint8_t* row1 = img_data + i * row_size;
        uint8_t* row2 = img_data + j * row_size;
        memcpy(temp, row1, row_size);
        memcpy(row1, row2, row_size);
        memcpy(row2, temp, row_size);
    }

    free(temp);
}

void adjust_contrast(uint8_t* img_data, int row_size, int height, float factor) {
    uint8_t* row = img_data;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < row_size; x += 3) {
            int r = *(row + x + 2);
            int g = *(row + x + 1);
            int b = *(row + x);
            r = (int)((r - 128) * factor + 128);
            g = (int)((g - 128) * factor + 128);
            b = (int)((b - 128) * factor + 128);
            if (r < 0) r = 0;
            if (g < 0) g = 0;
            if (b < 0) b = 0;
            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b > 255) b = 255;
            *(row + x + 2) = (uint8_t)r;
            *(row + x + 1) = (uint8_t)g;
            *(row + x) = (uint8_t)b;
        }
        row += row_size;
    }
}

int main() {
    int row_size, img_size;
    uint8_t* img_data = read_bmp("input.bmp", &row_size, &img_size);
    if (!img_data) {
        return 1;
    }

    flip_horizontally(img_data, row_size, img_size / row_size);
    adjust_contrast(img_data, row_size, img_size / row_size, 1.5);
    write_bmp("output.bmp", img_data, row_size, row_size / 3, img_size / row_size);

    free(img_data);
    return 0;
}