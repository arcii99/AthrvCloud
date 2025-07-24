//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include <stdio.h>

int main() {
    char message[] = "This is a sample message.";
    char watermark[] = "MyWatermark123";
    int i, j = 0, k = 0;

    for(i = 0; message[i] != '\0'; i++) {
        // embed the watermark into the message
        if(k < strlen(watermark)) {
            message[i] = watermark[k++];
        }
        // add some noise to the message
        else {
            message[i] += 3;
            message[i] ^= 7;
        }
    }

    printf("The watermarked message is: %s\n", message);
    printf("Extracting watermark...\n");

    // extract the watermark from the watermarked message
    for(i = 0; message[i] != '\0'; i++) {
        if(j < strlen(watermark) && message[i] == watermark[j]) {
            j++;
        }
        else if(j == strlen(watermark)) {
            printf("Watermark found!\n");
            break;
        }
    }

    if(j < strlen(watermark)) {
        printf("Watermark not found.\n");
    }

    return 0;
}