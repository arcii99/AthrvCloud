//FormAI DATASET v1.0 Category: Data recovery tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54 // BMP header is 54 bytes long

// Function to read a 4-byte integer from a byte array
int get_int(unsigned char *arr) {
    return (int)(arr[0] | arr[1] << 8 | arr[2] << 16 | arr[3] << 24);
}

// Function to write a 4-byte integer to a byte array
void set_int(unsigned char *arr, int val) {
    arr[0] = (unsigned char)(val);
    arr[1] = (unsigned char)(val >> 8);
    arr[2] = (unsigned char)(val >> 16);
    arr[3] = (unsigned char)(val >> 24);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s file.bmp\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if(!file) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    // Read BMP header
    unsigned char header[HEADER_SIZE];
    if(fread(header, 1, HEADER_SIZE, file) != HEADER_SIZE) {
        printf("Error: Invalid BMP file format\n");
        fclose(file);
        return 1;
    }

    // Check if file format is BMP
    if(header[0] != 'B' || header[1] != 'M') {
        printf("Error: Invalid BMP file format\n");
        fclose(file);
        return 1;
    }

    // Get image size and offset of pixel data
    int img_offset = get_int(&header[10]);
    int img_width = get_int(&header[18]);
    int img_height = get_int(&header[22]);
    int img_size = get_int(&header[34]);

    // Check if pixel data is within file boundaries
    if(img_offset + img_size > fseek(file, 0, SEEK_END)) {
        printf("Error: Invalid BMP file format\n");
        fclose(file);
        return 1;
    }

    // Allocate memory for pixel data
    unsigned char* img_data = (unsigned char*)malloc(img_size);
    if(!img_data) {
        printf("Error: Not enough memory to load image\n");
        fclose(file);
        return 1;
    }

    // Read pixel data
    fseek(file, img_offset, SEEK_SET);
    if(fread(img_data, 1, img_size, file) != img_size) {
        printf("Error: Could not read pixel data\n");
        fclose(file);
        free(img_data);
        return 1;
    }

    fclose(file);

    // Copy pixel data to a new file
    char new_file_name[strlen(argv[1]) + 5];
    strcpy(new_file_name, argv[1]);
    strcat(new_file_name, ".new");

    FILE* new_file = fopen(new_file_name, "wb");
    if(!new_file) {
        printf("Error: Could not create new file\n");
        free(img_data);
        return 1;
    }

    fwrite(header, 1, HEADER_SIZE, new_file);
    fwrite(img_data, 1, img_size, new_file);

    fclose(new_file);

    printf("File recovered successfully\n");

    free(img_data);

    return 0;
}