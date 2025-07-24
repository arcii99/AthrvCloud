//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 1024

// Function to convert the pixel color to ASCII character
char get_ascii_char(int pixel_color) {
    if (pixel_color >= 0 && pixel_color < 64) {
        return '#';
    }
    else if (pixel_color >= 64 && pixel_color < 128) {
        return 'O';
    }
    else if (pixel_color >= 128 && pixel_color < 192) {
        return '%';
    }
    else if (pixel_color >= 192 && pixel_color < 256) {
        return '.';
    }
    else {
        return ' ';
    }
}

// Thread function to convert the image to ASCII art
void* convert_image_to_ascii(void* arg) {
    int* image = (int*)arg;
    char ascii_art[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            int pixel_color = *(image + i * MAX_SIZE + j);
            char ascii_char = get_ascii_char(pixel_color);
            ascii_art[i][j] = ascii_char;
        }
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
    pthread_exit(NULL);
}

int main() {
    int image[MAX_SIZE][MAX_SIZE];
    // TODO: Read the image from file

    // Create thread
    pthread_t thread;
    pthread_create(&thread, NULL, convert_image_to_ascii, (void*)image);

    // Wait for thread to finish
    pthread_join(thread, NULL);

    return 0;
}