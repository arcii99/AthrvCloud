//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: secure
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], watermark[20] = "my watermark"; // set the watermark to "my watermark"
    int i, j;

    printf("Enter text to watermark: ");
    gets(input);

    for(i=0; i<strlen(input); i++)
    {
        if(i%2 == 0)
        {
            input[i] = (input[i] + 2) % 256; // add 2 to the even-indexed characters
        }
        else
        {
            input[i] = (input[i] + 3) % 256; // add 3 to the odd-indexed characters
        }
    }

    for(i=0; i<strlen(watermark); i++)
    {
        watermark[i] = (watermark[i] + 4) % 256; // add 4 to each character in the watermark
    }

    // insert the watermark into the text every 5 characters
    for(i=0, j=0; i<strlen(input); i++, j++)
    {
        if(j == 5)
        {
            strcat(input, watermark); // insert the watermark
            j = 0; // reset j
        }
    }

    printf("Watermarked text: %s\n", input);

    return 0;
}