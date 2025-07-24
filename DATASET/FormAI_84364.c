//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: funny
#include <stdio.h>

int main() {
    char message[100] = "I am a secret message!";
    char watermark[] = "Haha, you can't even see me!";
    int len = sizeof(watermark) / sizeof(watermark[0]);
    int pos = 7;
    int i, j;

    for (i = 0; i < len; i++) {
        if (i == pos) {
            message[i] = watermark[i];
        }
    }

    printf("Original Message: %s\n", message);

    for (j = 0; j < len; j++) {
        if (message[j] != watermark[j]) {
            printf("Haha, not a valid watermark!\n");
            break;
        } else {
            printf("Wow, you found the hidden message!\n");
            break;
        }
    }

    return 0;
}