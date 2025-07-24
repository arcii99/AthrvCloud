//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <string.h>

void embed_watermark(char* data, char* watermark) {
    int i, j;

    // get watermark length
    int watermark_len = strlen(watermark);

    // loop through data and embed watermark
    for (i = 0, j = 0; i < strlen(data); i++, j++) {
        // if j reaches end of watermark, reset j to 0
        if (j == watermark_len) {
            j = 0;
        }

        // embed watermark
        data[i] = data[i] ^ watermark[j];
    }
}

int check_watermark(char* data, char* watermark) {
    int i, j;

    // get watermark length
    int watermark_len = strlen(watermark);

    // loop through data and check watermark
    for (i = 0, j = 0; i < strlen(data); i++, j++) {
        // if j reaches end of watermark, reset j to 0
        if (j == watermark_len) {
            j = 0;
        }

        // check watermark
        if ((data[i] ^ watermark[j]) != data[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char data[] = "Hello World!";
    char watermark[] = "Digital Watermarking";

    printf("Original Data: %s\n", data);

    // embed watermark
    embed_watermark(data, watermark);

    printf("Watermarked Data: %s\n", data);

    // check watermark
    int result = check_watermark(data, watermark);

    if (result) {
        printf("Watermark is present.\n");
    } else {
        printf("Watermark is not present.\n");
    }

    return 0;
}