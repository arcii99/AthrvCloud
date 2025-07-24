//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256

void main() {
    char message[MAX_SIZE];
    char watermark[MAX_SIZE];
    char result[MAX_SIZE];
    int i, j = 0, k;
    int msg_length, wm_length;
    int bit_count = 0;

    printf("Enter your message: ");
    fgets(message, MAX_SIZE, stdin);
    printf("Enter your watermark: ");
    fgets(watermark, MAX_SIZE, stdin);

    msg_length = strlen(message);
    wm_length = strlen(watermark);

    for (i = 0; i < msg_length; i++) {
        if (bit_count < wm_length * 8) {
            for (k = 0; k < 8; k++) {
                if (bit_count < wm_length * 8) {
                    result[j] = (message[i] & (1 << k)) ? watermark[bit_count / 8] | (1 << (bit_count % 8)) : watermark[bit_count / 8] & ~(1 << (bit_count % 8));
                    bit_count++;
                    j++;
                } else {
                    break;
                }
            }
        }
        result[j] = message[i];
        j++;
    }

    printf("Resulting message with watermark:\n%s\n", result);
}