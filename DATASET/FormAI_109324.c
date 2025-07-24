//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_SIZE 1000 // Set the image size
#define KEY 1234 // Set the key for encryption/decryption

int main()
{
    // Create an example image
    int image[IMAGE_SIZE][IMAGE_SIZE];
    for(int i=0; i<IMAGE_SIZE; i++) {
        for(int j=0; j<IMAGE_SIZE; j++) {
            image[i][j] = (i*j) % 256;
        }
    }
    
    // Create the watermark
    int watermark[5] = {10, 20, 30, 40, 50};
    
    // Embed the watermark into the image
    for(int i=0; i<5; i++) {
        int x = i*200;
        int y = i*200;
        image[x][y] += watermark[i];
    }
    
    // Encrypt the watermark
    for(int i=0; i<5; i++) {
        watermark[i] = watermark[i] ^ KEY;
    }
    
    // Extract the watermark from the image
    int extracted[5];
    for(int i=0; i<5; i++) {
        int x = i*200;
        int y = i*200;
        extracted[i] = image[x][y] - watermark[i];
    }
    
    // Decrypt the extracted watermark
    for(int i=0; i<5; i++) {
        extracted[i] = extracted[i] ^ KEY;
    }
    
    // Compare the extracted watermark with the original watermark
    int match = 1;
    for(int i=0; i<5; i++) {
        if(extracted[i] != watermark[i]) {
            match = 0;
            break;
        }
    }
    
    // Print the result
    if(match) {
        printf("Watermark is successfully embedded and extracted from the image.\n");
    } else {
        printf("Watermark is not extracted properly.\n");
    }
    
    return 0;
}