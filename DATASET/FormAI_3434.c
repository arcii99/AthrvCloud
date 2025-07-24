//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>

// Function to convert decimal to binary
long int decimalToBinary(long int n)
{
    int remainder;
    long int binary = 0, i = 1;

    while(n != 0)
    {
        remainder = n % 2;
        n = n / 2;
        binary += remainder * i;
        i *= 10;
    }

    return binary;
}

int main()
{
    long int originalData, watermarkData;
    int key = 42; // Key for watermarking

    printf("Enter the original data: ");
    scanf("%ld", &originalData);

    printf("Enter the watermark data: ");
    scanf("%ld", &watermarkData);

    // Generate the watermarked data
    long int watermarkedData = originalData ^ (watermarkData << key);

    printf("Watermarked data: %ld\n", watermarkedData);

    // Extract the watermark
    long int extractedWatermark = (watermarkedData >> key) & ((1 << 32) - 1);

    printf("Extracted watermark: %ld\n", extractedWatermark);
    printf("Extracted watermark in binary: %ld\n", decimalToBinary(extractedWatermark));

    return 0;
}