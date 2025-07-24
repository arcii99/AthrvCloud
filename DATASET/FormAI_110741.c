//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WATERMARK_BIT_SIZE 16

typedef struct {
    int bit_Watermark[WATERMARK_BIT_SIZE];
} watermark;

int main()
{
    char input[100];
    printf("Enter text to be watermarked: ");
    fgets(input, sizeof(input), stdin);

    // Generate watermark
    watermark bitwatermark;
    int i;
    for (i = 0; i < WATERMARK_BIT_SIZE; i++) {
        bitwatermark.bit_Watermark[i] = rand() % 2;
    }

    // Print generated watermark
    printf("Generated Watermark: ");
    for (i = 0; i < WATERMARK_BIT_SIZE; i++) {
        printf("%d", bitwatermark.bit_Watermark[i]);
    }
    printf("\n");

    // Convert input text to binary
    char binary[8000] = "";
    char temp[9] = "";
    for (i = 0; i < strlen(input); i++) {
        sprintf(temp, "%d", input[i]);
        strcat(binary, temp);
    }

    // Embed watermark in first 16 bits
    for (i = 0; i < WATERMARK_BIT_SIZE; i++) {
        binary[i] = bitwatermark.bit_Watermark[i] + '0';
    }

    // Convert binary back to ASCII
    char output[100] = "";
    for (i = 0; i < strlen(binary); i += 8) {
        char tempstr[9] = "";
        strncpy(tempstr, binary + i, 8);
        int charval = strtol(tempstr, NULL, 2);
        sprintf(tempstr, "%c", charval);
        strcat(output, tempstr);
    }

    // Print watermarked text
    printf("Watermarked Text: %s", output);

    return 0;
}