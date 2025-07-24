//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* recursive function to embed watermark in binary image data */
void embedWatermark(char *data, char *watermark, int dIndex, int wIndex, int wLength)
{
    /* terminate recursion if watermark has been fully embedded */
    if (wIndex == wLength) {
        return;
    }
    /* check if current bit of watermark is 1 */
    if (watermark[wIndex / 8] & (1 << (7 - wIndex % 8))) {
        /* set the least significant bit of data[dIndex] to 1 */
        data[dIndex] |= 1;
    }
    /* recursive call for next bit */
    embedWatermark(data, watermark, dIndex + 1, wIndex + 1, wLength);
}

/* recursive function to extract watermark from binary image data */
void extractWatermark(char *data, char *watermark, int dIndex, int wIndex, int wLength)
{
    /* terminate recursion if watermark has been fully extracted */
    if (wIndex == wLength) {
        return;
    }
    /* check if least significant bit of data[dIndex] is 1 */
    if (data[dIndex] & 1) {
        /* set the corresponding bit of watermark to 1 */
        watermark[wIndex / 8] |= (1 << (7 - wIndex % 8));
    }
    /* recursive call for next bit */
    extractWatermark(data, watermark, dIndex + 1, wIndex + 1, wLength);
}

int main()
{
    /* initialize binary image data and watermark */
    char data[1000] = "0101010101010101010101010101010101010101010101010101010101010101010101010101";
    char watermark[16] = "Hello, world!";
    int wLength = strlen(watermark) * 8;
    
    /* embed watermark in binary image data */
    embedWatermark(data, watermark, 0, 0, wLength);
    
    /* print embedded binary image data */
    printf("Embedded data: %s\n", data);
    
    /* extract watermark from binary image data */
    char extractedWatermark[16] = {0};
    extractWatermark(data, extractedWatermark, 0, 0, wLength);
    
    /* print extracted watermark */
    printf("Extracted watermark: %s\n", extractedWatermark);
    
    return 0;
}