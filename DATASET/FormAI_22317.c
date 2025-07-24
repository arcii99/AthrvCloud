//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//function to set the bit of a byte
void setBit(unsigned char *byte, int bitNum) {
    *byte |= 1 << bitNum; //OR-ing with 1 to set bitNum-th bit
}

//function to clear the bit of a byte
void clearBit(unsigned char *byte, int bitNum) {
    *byte &= ~(1 << bitNum); //AND-ing with 0 to clear bitNum-th bit
}

//function to get the value of a bit in a byte
int getBit(unsigned char byte, int bitNum) {
    return (byte >> bitNum) & 1; //shifting and AND-ing with 1 to get the bitNum-th bit
}

//function to print binary representation of a byte
void printByte(unsigned char byte) {
    for(int i=7;i>=0;i--) {
        printf("%d", getBit(byte, i));
    }
}

int main() {
    unsigned char data[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'}; //input data
    int dataLen = strlen(data); //length of input data
    unsigned char watermark[] = {'W', 'A', 'T', 'E', 'R', 'M', 'A', 'R', 'K', '\0'}; //watermark to be embedded
    int watermarkLen = strlen(watermark); //length of the watermark

    //embed the watermark
    for(int i=0;i<watermarkLen;i++) {
        int watermarkBit = getBit(watermark[i], 0); //get the least significant bit of the watermark char
        int dataBit = getBit(data[i], 0); //get the least significant bit of the corresponding data char
        if(watermarkBit != dataBit) { //if the two bits are different, change the data bit to embed the watermark bit
            if(watermarkBit == 1) {
                setBit(&data[i], 0);
            }
            else {
                clearBit(&data[i], 0);
            }
        }
    }

    //print the embedded data
    printf("Embedded Watermarked Data (ASCII representation): %s\n", data);

    //print the embedded data in binary representation
    printf("Embedded Watermarked Data (Binary representation):\n");
    for(int i=0;i<dataLen;i++) {
        printByte(data[i]);
        printf(" ");
    }
    printf("\n");

    //extract the watermark
    char extractedWatermark[watermarkLen+1];
    extractedWatermark[watermarkLen] = '\0'; //null terminate the extracted watermark string
    for(int i=0;i<watermarkLen;i++) {
        int watermarkBit = getBit(data[i], 0); //get the least significant bit of the corresponding data char
        if(watermarkBit == 1) {
            setBit(&extractedWatermark[i], 0); //embed the bit in the extracted watermark char
        }
        else {
            clearBit(&extractedWatermark[i], 0);
        }
    }

    //print the extracted watermark
    printf("Extracted Watermark: %s\n", extractedWatermark);

    return 0;
}