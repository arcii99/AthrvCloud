//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

int get_bit(unsigned int num, int bit_pos) {
    return (num >> bit_pos) & 1;
}

void set_bit(unsigned int *num, int bit_pos, int bit_val) {
    unsigned int mask = 1 << bit_pos;
    if (bit_val == 0) {
        mask = ~mask;
        *num = *num & mask;
    }
    else {
        *num = *num | mask;
    }
}

int main() {
    unsigned int original_message = 0;
    int watermark[MAX_LEN];
    char message[MAX_LEN];

    // Read user input
    printf("Enter message: ");
    scanf("%[^\n]%*c", message);
    printf("Enter watermark (binary format): ");
    for (int i = 0; i < strlen(message); i++) {
        if (i >= MAX_LEN*8) {
            break;
        }

        scanf("%1d", &watermark[i]);
        set_bit(&original_message, i, message[i] & 1);
        set_bit(&original_message, i+1, watermark[i]);
    }

    // Output watermarked message
    printf("Watermarked message: ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%c", '0' + get_bit(original_message, i));
    }
    printf("\n");

    // Extract watermark
    printf("Extracted watermark: ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%d", get_bit(original_message, i+1));
    }
    printf("\n");
    
    return 0;
}