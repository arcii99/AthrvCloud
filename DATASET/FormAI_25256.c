//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to pass arguments to the threads
typedef struct {
    float red;
    float green;
    float blue;
} Color;

// Function to convert RGB color code to CMYK color code
void rgb_to_cmyk(float r, float g, float b, float *c, float *m, float *y, float *k) {
    float r_norm = r/255;
    float g_norm = g/255;
    float b_norm = b/255;
    float max_val = r_norm;
    if (g_norm > max_val) {
        max_val = g_norm;
    }
    if (b_norm > max_val) {
        max_val = b_norm;
    }
    float white = 1.0 - max_val;
    *k = white;
    if (white == 1.0) {
        *c = 0;
        *m = 0;
        *y = 0;
    } else {
        *c = (1.0 - r_norm - white) / (1.0 - white);
        *m = (1.0 - g_norm - white) / (1.0 - white);
        *y = (1.0 - b_norm - white) / (1.0 - white);
    }
}

// Thread function to print RGB and CMYK color codes
void *print_color_codes(void *arg) {
    Color *color = (Color *) arg;
    printf("RGB color code - (%.2f, %.2f, %.2f)\n", color->red, color->green, color->blue);
    float c, m, y, k;
    rgb_to_cmyk(color->red, color->green, color->blue, &c, &m, &y, &k);
    printf("CMYK color code - (%.2f, %.2f, %.2f, %.2f)\n", c, m, y, k);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    Color colors[5] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 0}, {0, 255, 255}};
    for (int i=0; i<5; i++) {
        pthread_create(&threads[i], NULL, print_color_codes, (void *)&colors[i]);
    }
    for (int i=0; i<5; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}