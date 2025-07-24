//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The following pages represent the digital content to be watermarked
char page1[1024], page2[1024];

// The watermark to be inserted into the digital content
char watermark[] = "MyWatermark001";

// Function to insert the watermark into the digital content
void insertWatermark(char *content, int contentSize, char *watermark, int watermarkSize)
{
    // Watermark will be inserted at the end of the content
    int startIndex = contentSize;

    // Copy the watermark to the content
    for (int i = 0; i < watermarkSize; i++)
    {
        content[startIndex + i] = watermark[i];
    }
}

int main()
{
    printf("Welcome to the Digital Watermarking program.\n");

    // Load the digital content to be watermarked
    printf("Enter page 1 contents: ");
    fgets(page1, sizeof(page1), stdin);
    printf("Enter page 2 contents: ");
    fgets(page2, sizeof(page2), stdin);

    // Insert the watermark into the digital content
    insertWatermark(page1, strlen(page1), watermark, strlen(watermark));
    insertWatermark(page2, strlen(page2), watermark, strlen(watermark));

    // Display the watermarked digital content
    printf("\nThe watermarked digital content is:\n");
    printf("Page 1: %s\n", page1);
    printf("Page 2: %s\n", page2);

    return 0;
}