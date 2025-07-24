//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

void print_ascii_art(Image img);

int main() {
    // create example image
    unsigned char data[12] = { 
        0, 0, 0, 255, 255, 255, 
        0, 255, 0, 255, 255, 255 
    };
    Image img = { 2, 2, data };

    // print ascii art
    print_ascii_art(img);

    return 0;
}

void print_ascii_art(Image img) {
    // iterate over image data
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            // calculate average value of pixel
            int sum = 0;
            for (int k = 0; k < 3; k++) {
                sum += img.data[(i * img.width + j) * 3 + k];
            }
            int avg = sum / 3;

            // map average value to ascii character
            char c = '\0';
            if (avg < 64) {
                c = ' ';
            } else if (avg < 128) {
                c = '.';
            } else if (avg < 192) {
                c = '*';
            } else {
                c = '#';
            }

            // print ascii character
            printf("%c", c);
        }
        printf("\n");
    }
}