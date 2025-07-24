//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: futuristic
/*
Futuristic Digital Watermarking Program
Author: Chatbot-X
Date: 2050
*/

#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], watermark[50];
    int i, j, k, len_text, len_wm, pos;

    // Get input text from user
    printf("Enter text to watermark: ");
    fgets(text, sizeof(text), stdin);

    // Get watermark to use
    printf("Enter watermark: ");
    fgets(watermark, sizeof(watermark), stdin);

    // Calculate lengths of text and watermark
    len_text = strlen(text) - 1; // exclude newline character
    len_wm = strlen(watermark) - 1; // exclude newline character

    // Check if length of watermark is too long
    if (len_wm > (len_text / 4)) {
        printf("Watermark is too long for given text.");
        return 1;
    }

    // Generate random position for watermark insertion
    pos = rand() % (len_text - len_wm);

    // Iterate over text and insert watermark
    for (i = 0, j = 0, k = pos; i < len_text; i++) {
        if (i == k) {
            printf("%c", watermark[j]);
            j++;
            if (j == len_wm) {
                k = len_text; // exit loop
            }
        }
        printf("%c", text[i]);
    }

    return 0;
}