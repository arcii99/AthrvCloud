//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include <stdio.h>

void convert_image_to_ascii(char* filename) {
    FILE* file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: File not found or unable to open.\n");
    }
    else {
        unsigned char buffer[4096];
        int index = 0;
        while (fread(buffer, sizeof(buffer), 1, file)) {
            for (int i = 0; i < sizeof(buffer); i++) {
                if (i % 8 == 0) {
                    printf("\n");
                }
                if (buffer[i] < 64) {
                    printf(" ");
                }
                else if (buffer[i] < 128) {
                    printf(".");
                }
                else if (buffer[i] < 192) {
                    printf("o");
                }
                else {
                    printf("*");
                }
            }
            index++;
        }
        fclose(file);
    }
}

int main() {
    convert_image_to_ascii("image.jpg");
    return 0;
}