//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
#include<stdio.h>
#include<math.h>

void insertWatermark(int *dataPointer, int *watermarkPointer) {
    int x, i, bit, newData, watermark;
    watermark = *watermarkPointer;
    for(i=0 ; i<32 ; i++) {
        x = *dataPointer;
        bit = (watermark>>i) & 1;
        //insert bit into least significant bit of x
        newData = (x & ~1) | bit;
        *dataPointer = newData;
        //update pointers
        watermark = watermark>>1;
        dataPointer++;
    }
}

void extractWatermark(int *dataPointer, int *watermarkPointer) {
    int x, i, bit, extracted = 0;
    for(i=0 ; i<32 ; i++) {
        x = *dataPointer;
        bit = x & 1;
        //insert bit into least significant bit of extracted
        extracted = (extracted<<1) | bit;
        //update pointers
        dataPointer++;
    }
    *watermarkPointer = extracted;
}

int main() {
    int data = 0x1234abcd;
    int watermark = 0x4321;
    printf("Original data: 0x%08x\n", data);
    printf("Watermark: 0x%04x\n", watermark);

    //insert watermark
    insertWatermark(&data, &watermark);
    printf("Watermark inserted data: 0x%08x\n", data);

    //extract watermark
    extractWatermark(&data, &watermark);
    printf("Extracted watermark: 0x%04x\n", watermark);

    return 0;
}