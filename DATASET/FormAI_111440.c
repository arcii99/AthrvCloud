//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BMP_HEADER_SIZE 54
#define BMP_COLOR_TABLE_SIZE 1024

#pragma pack(push, 1)

typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
    uint32_t header_size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t image_size;
    int32_t x_px_per_meter;
    int32_t y_px_per_meter;
    uint32_t colors_used;
    uint32_t colors_important;
} bmp_header;

#pragma pack(pop)

uint8_t* load_bmp(char* path, bmp_header* header) {
    FILE* file = fopen(path, "rb");
    if (!file) {
        printf("Failed to open file: %s\n", path);
        return NULL;
    }

    if (fread(header, sizeof(bmp_header), 1, file) != 1) {
        printf("Error reading header from bmp file: %s\n", path);
        fclose(file);
        return NULL;
    }

    if (header->type != 0x4D42) {
        printf("Invalid BMP file: %s\n", path);
        fclose(file);
        return NULL;
    }

    if (header->bits_per_pixel != 24) {
        printf("Unsupported BMP format. Only 24-bit RGB files are supported: %s\n", path);
        fclose(file);
        return NULL;
    }

    uint32_t size = BMP_HEADER_SIZE + header->image_size + BMP_COLOR_TABLE_SIZE;
    uint8_t* data = (uint8_t*) malloc(size);

    fseek(file, 0, SEEK_SET);
    if (fread(data, size, 1, file) != 1) {
        printf("Error reading bmp file: %s\n", path);
        fclose(file);
        free(data);
        return NULL;
    }

    fclose(file);
    return data;
}

void flip_image(bmp_header* header, uint8_t* data) {
    uint32_t row_size = ((header->bits_per_pixel * header->width + 31) / 32) * 4;
    uint8_t* row = (uint8_t*) malloc(row_size);
    uint32_t half_height = header->height / 2;

    for (uint32_t i = 0; i < half_height; i++) {
        uint32_t upper_offset = BMP_HEADER_SIZE + (i * row_size);
        uint32_t lower_offset = BMP_HEADER_SIZE + ((header->height - i - 1) * row_size);

        memcpy(row, &data[upper_offset], row_size);
        memcpy(&data[upper_offset], &data[lower_offset], row_size);
        memcpy(&data[lower_offset], row, row_size);
    }

    free(row);
}

void change_brightness_contrast(bmp_header* header, uint8_t* data, int32_t brightness, float contrast) {
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    uint32_t row_size = ((header->bits_per_pixel * header->width + 31) / 32) * 4;

    for (int32_t y = 0; y < header->height; y++) {
        uint8_t* row = &data[BMP_HEADER_SIZE + y * row_size];

        for (int32_t x = 0; x < header->width; x++) {
            uint32_t offset = x * 3;
            int32_t b = row[offset];
            int32_t g = row[offset + 1];
            int32_t r = row[offset + 2];

            int32_t new_r = factor * (r - 128) + 128 + brightness;
            int32_t new_g = factor * (g - 128) + 128 + brightness;
            int32_t new_b = factor * (b - 128) + 128 + brightness;

            if (new_r < 0) new_r = 0;
            if (new_g < 0) new_g = 0;
            if (new_b < 0) new_b = 0;
            if (new_r > 255) new_r = 255;
            if (new_g > 255) new_g = 255;
            if (new_b > 255) new_b = 255;

            row[offset] = (uint8_t) new_b;
            row[offset + 1] = (uint8_t) new_g;
            row[offset + 2] = (uint8_t) new_r;
        }
    }
}

int main() {
    bmp_header header;
    uint8_t* data = load_bmp("input.bmp", &header);
    if (!data) return -1;

    flip_image(&header, data);
    change_brightness_contrast(&header, data, 20, 1.5f);

    FILE* file = fopen("output.bmp", "wb");
    if (!file) {
        printf("Failed to create output file\n");
        free(data);
        return -1;
    }

    fwrite(data, BMP_HEADER_SIZE + header.image_size, 1, file);
    fclose(file);
    free(data);

    return 0;
}