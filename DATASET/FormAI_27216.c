//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
    printf("Welcome to Digital Watermarking Retro Edition..\n");
    printf("Enter the message to be watermarked: ");
    char message[1000];
    scanf("%[^\n]", message);

    int watermark[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9};
    int w_len = sizeof(watermark) / sizeof(watermark[0]);
    int m_len = strlen(message);
    int k = 0; // watermark index
    int sum = 0;
    
    for (int i = 0; i < m_len; i++) {
        int byte = message[i];
        int bit = 1 << 7; // Perform bit-by-bit watermarking
        while (bit) {
            if (k < w_len) {
                // Perform XOR operation to set the watermark
                byte ^= (watermark[k] & bit) ? bit : 0;
                k++;
            }
            // Calculate the sum of the bits in the message
            sum += byte & bit ? 1 : 0;
            bit >>= 1;
        }
        printf("%c", byte);
    }
    printf("\nSum of message bits: %d", sum);
    printf("\nWatermark used: ");
    for (int i = 0; i < w_len; i++) {
        printf("%d ", watermark[i]);
    }
    return 0;
}