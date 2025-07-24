//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: expert-level
#include <stdio.h>

// function to check if the given integer is prime or not
int checkPrime(int num)
{
    int i;
    for(i=2; i<=num/2; i++)
    {
        if(num%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

// function to generate a watermark for the given integer
int generateWatermark(int num)
{
    int i, product = 1;
    for(i=2; i<=num; i++)
    {
        if(num%i == 0 && checkPrime(i))
        {
            product *= i;
        }
    }
    return product;
}

// function to embed the watermark into the given integer
int embedWatermark(int num, int watermark)
{
    // shift the watermark to left by 6 bits
    watermark <<= 6;
    // clear the last 6 bits of the number
    num &= ~63;
    // embed the watermark into the number
    num |= watermark;
    return num;
}

// function to extract the watermark from the given integer
int extractWatermark(int num)
{
    // get the last 6 bits of the number
    int watermark = num & 63;
    // shift the watermark back to its original position
    watermark >>= 6;
    return watermark;
}

int main()
{
    int num = 17853;
    int watermark = generateWatermark(num);
    int watermarkedNum = embedWatermark(num, watermark);
    printf("Original Number : %d\n", num);
    printf("Watermark : %d\n", watermark);
    printf("Watermarked Number : %d\n", watermarkedNum);
    int extractedWatermark = extractWatermark(watermarkedNum);
    printf("Extracted Watermark : %d\n", extractedWatermark);
    if(extractedWatermark == watermark)
    {
        printf("Watermarking Successful!\n");
    }
    else
    {
        printf("Watermarking Failed!\n");
    }
    return 0;
}