//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* text = "Hello World!"; // The text we want to watermark
char* watermark = "0123456789"; // The watermark we want to use, in this case a series of numbers

int main() {
    int text_len = strlen(text); // Get the length of the text
    int watermark_len = strlen(watermark); // Get the length of the watermark
    int result_len = text_len + watermark_len; // Calculate the length of the result string

    char* result = calloc(result_len + 1, sizeof(char)); // Allocate memory for the result string
    int i, j;

    for(i = 0, j = 0; i < text_len && j < watermark_len; i++, j++) {
        // Shift each character of the text by the corresponding character of the watermark
        int shift = (int)watermark[j] - '0'; // Convert the character to an integer
        result[i] = text[i] + shift;
        // If the character goes beyond the range of printable ASCII characters, wrap around
        if(result[i] > 126) {
            result[i] = result[i] - 95;
        }
    }

    // If the watermark is longer than the text, append the remaining characters of the watermark to the result
    if(j < watermark_len) {
        strcat(result, &watermark[j]);
    }

    printf("Original text: %s\n", text);
    printf("Watermark: %s\n", watermark);
    printf("Watermarked text: %s\n", result);

    free(result); // Free the memory allocated for the result string
    return 0;
}