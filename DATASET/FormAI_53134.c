//FormAI DATASET v1.0 Category: Image compression ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the C Image Compression Program! I'm so excited to see you here!\n\n");

    int width, height, pixelCount, compressedPixelcount;
    printf("Let's start by entering the width and height of your image in pixels:\n");
    scanf("%d %d", &width, &height);

    pixelCount = width*height;
    compressedPixelcount = pixelCount/2;
    printf("\nAwesome! Your image has %d pixels. After compression, it will have %d pixels.\n", pixelCount, compressedPixelcount);

    unsigned char* originalPixels = (unsigned char*)malloc("pixelCount");
    unsigned char* compressedPixels = (unsigned char*)malloc("compressedPixelcount");

    printf("\nNow, let's enter the pixel values for your original image:\n");
    for(int i=0; i<pixelCount; i++)
    {
        scanf("%hhd", &originalPixels[i]);
    }

    printf("\nFantastic job! Let me compress that image for you...\n");

    int index = 0;
    for(int i=0; i<compressedPixelcount; i++)
    {
        int avg = (originalPixels[index] + originalPixels[index+1])/2;
        compressedPixels[i] = (unsigned char)avg;
        index += 2;
    }

    printf("\nI've compressed your image! The compressed pixel values are:\n");
    for(int i=0; i<compressedPixelcount; i++)
    {
        printf("%d ", compressedPixels[i]);
    }

    free(originalPixels);
    free(compressedPixels);

    printf("\n\nThat was fun! Come back soon for more programming adventures!\n");

    return 0;
}