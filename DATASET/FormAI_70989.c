//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
char key = 'K';     // Watermark key
char str[256];      // String to be watermarked

// Function for watermarking
void watermark(char *str, int len) {
    int i, j;
    for (i = 0, j = len-1; i < j; i++, j--) {
        // XOR characters at both ends
        char temp = str[i] ^ str[j];
        // XOR result with watermark key
        str[i] ^= key;
        str[j] ^= key;
        // Print watermarked character
        printf("%02X ", temp);
    }
}

// Function for checking watermark
void checkwatermark(char *str, int len) {
    int i, j;
    for (i = 0, j = len-1; i < j; i++, j--) {
        // XOR characters at both ends with watermark key
        str[i] ^= key;
        str[j] ^= key;
        // Print original character
        printf("%c", str[i]);
        if (i != j) printf("%c", str[j]);
    }
}

int main() {
    // Retro-style ASCII art header
    printf("______________________________________________________________\n");
    printf("<----------------- C Digital Watermarking -------------------->\n");
    printf("--------------------------------------------------------------\n\n");

    printf("Enter a string to watermark (max 255 characters): ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') str[len-1] = '\0';   // Remove newline character

    // Display original string
    printf("\nOriginal String: %s\n", str);
    printf("Original String (Hex): ");
    for (int i = 0; i < len; i++) printf("%02X ", str[i]);
    printf("\n\n");

    // Watermark the string
    printf("Watermarked String (Hex): ");
    watermark(str, len);

    // Display watermarked string
    printf("\n\n");

    // Check watermark for correctness
    printf("Checking Watermark...\n\n");
    printf("Original String (Hex): ");
    checkwatermark(str, len);

    return 0;
}