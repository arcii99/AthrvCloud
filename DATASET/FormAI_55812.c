//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the digital watermark
void calculate_digital_watermark(char *input_string, char *watermark_string, char *output_string) {
    strcat(output_string, watermark_string);
    strcat(output_string, input_string);
    strcat(output_string, watermark_string);
}

// Main function to run the program
int main() {
    // User inputs
    char input_string[100];
    char watermark_string[20];

    printf("Enter a string of 100 characters or less: ");
    fgets(input_string, 100, stdin);

    printf("Enter a watermark string of 20 characters or less: ");
    fgets(watermark_string, 20, stdin);

    // Remove the newline character at the end of the strings
    input_string[strcspn(input_string, "\n")] = 0;
    watermark_string[strcspn(watermark_string, "\n")] = 0;

    // Calculate the digital watermark
    char output_string[140] = {0};
    calculate_digital_watermark(input_string, watermark_string, output_string);

    // Print the output string
    printf("Digital Watermarked String: %s\n", output_string);

    return 0;
}