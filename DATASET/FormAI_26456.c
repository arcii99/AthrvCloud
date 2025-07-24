//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: lively
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

int main()
{
    char text[1000], watermark[50], coded[10000], decoded[10000];
    printf("Enter the text you want to watermark: ");
    fgets(text, 1000, stdin);
    printf("Enter the watermark you want to use: ");
    fgets(watermark, 50, stdin);

    // Encode the text with the watermark
    srand(time(NULL)); // Seed the random number generator
    int k = rand() % (strlen(text) - strlen(watermark)); // Choose a random starting index
    strncpy(coded, text, k); // Copy text up to the starting index
    strcat(coded, watermark); // Add the watermark
    strcat(coded, text + k); // Add the rest of the text after the starting index
    printf("Watermarked text: %s", coded);

    // Decode the text to recover the original text
    strcpy(decoded, coded); // Copy the coded text to decoded
    char* index = strstr(decoded, watermark); // Find the starting index of the watermark in decoded
    strncpy(decoded, decoded, index - decoded); // Copy up to the watermark
    strcat(decoded, decoded + (index - decoded) + strlen(watermark)); // Add the rest of the text after the watermark
    printf("\nDecoded text: %s", decoded);

    return 0;
}