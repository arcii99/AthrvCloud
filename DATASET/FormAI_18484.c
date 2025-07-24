//FormAI DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 10000

int get_image_size(FILE *fptr) {
    int size = -1;
    fseek(fptr, 0, SEEK_END);
    size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    return size;
}

void hide_text_in_image(char *text, int text_size, char *image_filename) {
    FILE *fptr = fopen(image_filename, "r+");
    if (fptr == NULL) {
        printf("File not found!\n");
        return;
    }

    int image_size = get_image_size(fptr);
    char image_data[MAX_IMAGE_SIZE];

    fread(image_data, sizeof(char), image_size, fptr);

    int text_index = 0;
    for (int i = 0; i < image_size; i += 3) {
        if (text_index >= text_size) {
            break;
        }
        image_data[i] = text[text_index];
        text_index++;
    }

    fseek(fptr, 0, SEEK_SET);
    fwrite(image_data, sizeof(char), image_size, fptr);
    fclose(fptr);
    printf("Text successfully hidden in image!\n");
}

void extract_text_from_image(char *image_filename) {
    FILE *fptr = fopen(image_filename, "r");
    if (fptr == NULL) {
        printf("File not found!\n");
        return;
    }

    int image_size = get_image_size(fptr);
    char image_data[MAX_IMAGE_SIZE];
    fread(image_data, sizeof(char), image_size, fptr);

    int text_size = 0;
    char text[MAX_IMAGE_SIZE];

    for (int i = 0; i < image_size; i += 3) {
        if (image_data[i] == '\0') {
            break;
        }
        text[text_size] = image_data[i];
        text_size++;
    }

    printf("Text extracted from image:\n%s\n", text);
    fclose(fptr);
}

int main() {
    char text[] = "This is a test message to be hidden in an image.";
    char image_filename[] = "image.jpg";

    hide_text_in_image(text, sizeof(text), image_filename);
    extract_text_from_image(image_filename);
    
    return 0;
}