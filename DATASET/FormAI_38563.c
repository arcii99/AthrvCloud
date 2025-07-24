//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include <stdio.h>
#include <string.h>

// Function to embed the watermark into the original data
void embedWatermark(unsigned char *orig_data, unsigned char *watermark, int wm_size) {

    // Calculate the sizes of the original data and watermark
    int orig_size = strlen(orig_data);
    int total_size = orig_size + wm_size;

    // Create a new buffer to store the watermarked data
    unsigned char new_data[total_size];

    // Copy the original data into the new buffer
    memcpy(new_data, orig_data, orig_size);

    // Embed the watermark into the new buffer
    for (int i = orig_size, j = 0; i < total_size; i++, j++) {
        new_data[i] = watermark[j];
    }

    // Print the watermarked data
    printf("Watermarked Data: %s", new_data);
}

int main() {
    // Sample data to be watermarked
    unsigned char orig_data[] = "Hello World!";

    // Watermark to be embedded
    unsigned char watermark[] = "Test Watermark";

    // Size of the watermark
    int wm_size = strlen(watermark);

    // Embed the watermark into the original data
    embedWatermark(orig_data, watermark, wm_size);

    return 0;
}