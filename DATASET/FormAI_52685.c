//FormAI DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *read_image(char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Error: failed to open file %s\n", filename);
        return NULL;
    }
    // Read the file header
    unsigned char header[54];
    if (fread(header, 1, 54, f) != 54) {
        fprintf(stderr, "Error: invalid file format %s\n", filename);
        fclose(f);
        return NULL;
    }
    // Check if the file is a BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: unsupported image format %s\n", filename);
        fclose(f);
        return NULL;
    }
    // Read the image size
    int width = *(int*)(header + 18);
    int height = *(int*)(header + 22);
    // Read the image data
    unsigned char *data = (unsigned char*)malloc(width * height * 3);
    if (!data) {
        fprintf(stderr, "Error: failed to allocate memory for image %s\n", filename);
        fclose(f);
        return NULL;
    }
    if (fseek(f, *(int*)(header + 10), SEEK_SET) != 0) {
        fprintf(stderr, "Error: failed to read image data %s\n", filename);
        free(data);
        fclose(f);
        return NULL;
    }
    int bytes_per_row = width * 3;
    for (int i = 0; i < height; i++) {
        if (fread(data + i * bytes_per_row, 1, bytes_per_row, f) != bytes_per_row) {
            fprintf(stderr, "Error: failed to read image data %s\n", filename);
            free(data);
            fclose(f);
            return NULL;
        }
    }
    fclose(f);
    // Create the image object
    Image *image = (Image*)malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: failed to allocate memory for image %s\n", filename);
        free(data);
        return NULL;
    }
    image->width = width;
    image->height = height;
    image->data = data;
    return image;
}

void write_image(Image *image, char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        fprintf(stderr, "Error: failed to open file %s for writing\n", filename);
        return;
    }
    // Write the file header
    unsigned char header[54] = {
        'B', 'M', // Signature
        0, 0, 0, 0, // File size - to be filled in later
        0, 0, 0, 0, // Reserved
        54, 0, 0, 0, // Offset to image data
        40, 0, 0, 0, // BITMAPINFOHEADER size
        0, 0, 0, 0, // Image width - to be filled in later
        0, 0, 0, 0, // Image height - to be filled in later
        1, 0, // Planes
        24, 0, // Bits per pixel
        0, 0, 0, 0, // Compression - no compression
        0, 0, 0, 0, // Image size - can be set to 0 for no compression
        0x13, 0x0B, 0, 0, // Pixels per meter - default 72 DPI x 39.3701 inches/meter = 2834.65
        0x13, 0x0B, 0, 0, // Pixels per meter
        0, 0, 0, 0, // Colors in the color table - we don't use a color table
        0, 0, 0, 0 // Important color count - all colors are important
    };
    int file_size = 54 + image->width * image->height * 3;
    *(int*)(header + 2) = file_size;
    *(int*)(header + 18) = image->width;
    *(int*)(header + 22) = image->height;
    fwrite(header, 1, 54, f);
    // Write the image data
    int bytes_per_row = image->width * 3;
    for (int i = 0; i < image->height; i++) {
        fwrite(image->data + i * bytes_per_row, 1, bytes_per_row, f);
    }
    fclose(f);
}

void embed_message(Image *image, char *message) {
    int len = strlen(message);
    if (len * 8 > image->width * image->height * 3) {
        fprintf(stderr, "Error: message too long to embed in image\n");
        return;
    }
    unsigned char *p = image->data;
    for (int i = 0; i < len; i++) {
        unsigned char c = message[i];
        for (int j = 0; j < 8; j++) {
            if (c & (1 << j)) {
                *p = (*p & 0xFE) | 1;
            } else {
                *p = (*p & 0xFE) | 0;
            }
            p++;
        }
    }
}

char *extract_message(Image *image) {
    int i = 0;
    int len = 0;
    unsigned char *p = image->data;
    while (i < image->width * image->height * 3) {
        unsigned char c = 0;
        for (int j = 0; j < 8; j++) {
            c |= (*p & 1) << j;
            p++;
        }
        if (!c) {
            break;
        }
        len++;
    }
    if (len == 0) {
        fprintf(stderr, "Error: no message found in image\n");
        return NULL;
    }
    char *message = (char*)malloc(len + 1);
    if (!message) {
        fprintf(stderr, "Error: failed to allocate memory for message\n");
        return NULL;
    }
    i = 0;
    p = image->data;
    while (i < len) {
        unsigned char c = 0;
        for (int j = 0; j < 8; j++) {
            c |= (*p & 1) << j;
            p++;
        }
        message[i] = c;
        i++;
    }
    message[len] = '\0';
    return message;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }
    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }
    char *message = argv[3];
    embed_message(image, message);
    write_image(image, argv[2]);
    printf("Embedded message:\n%s\n", message);
    free(image->data);
    free(image);
    return 0;
}