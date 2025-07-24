//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

typedef struct {
    int r;
    int g;
    int b;
} RGB;

int main() {
    char message[] = "This is a secret message";
    char key[] = "Cyb3RpUNK";
    int len_message = strlen(message);
    int len_key = strlen(key);
    RGB image[100][100];
    
    // Set all pixels to black
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            image[i][j].r = 0;
            image[i][j].g = 0;
            image[i][j].b = 0;
        }
    }
    
    // Generate watermark
    int watermark[len_message];
    for (int i=0; i<len_message; i++) {
        watermark[i] = message[i] ^ key[i % len_key];
    }
    
    // Embed watermark into image
    int k = 0;
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (k < len_message) {
                image[i][j].r = watermark[k];
                k++;
            }
        }
    }
    
    // Extract watermark from image
    k = 0;
    char extracted[len_message+1];
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (k < len_message) {
                extracted[k] = image[i][j].r ^ key[k % len_key];
                k++;
            }
        }
    }
    extracted[len_message] = '\0';
    
    printf("Original message: %s\n", message);
    printf("Extracted message: %s\n", extracted);
    
    return 0;
}