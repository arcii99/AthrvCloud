//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100

char ascii_chars[] = {' ', '.', '-', ':', '+', '*', '=', 'X', '#', '%', '@'};

char medieval_chars[] = {' ', '.', '-', ':', '+', '*', '=', '>', '}', 'O', '0', '@'};

void convert_image_to_ascii(char* image_path) {
    FILE* image = fopen(image_path, "r");
    if (!image) {
        printf("Error opening image file.\n");
        return;
    }
    char buffer[MAX_WIDTH];
    int width, height;
    fscanf(image, "%d %d\n", &width, &height);
    char current_char;
    for (int y = 0; y < height; y++) {
        fgets(buffer, MAX_WIDTH, image);
        for (int x = 0; x < width; x++) {
            current_char = buffer[x];
            int index = ((int) (current_char * 11) / 256);
            printf("%c", medieval_chars[index]);
        }
        printf("\n");
    }
    fclose(image);
}

int main() {
    char* image_path = "medieval_castle.pgm";
    convert_image_to_ascii(image_path);
    return 0;
}