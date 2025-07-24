//FormAI DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 1000

char* binaryBuffer(int x){
    char* bin = (char*)malloc(9 * sizeof(char));
    int i;
    for(i = 7; i >= 0; --i){
        bin[i] = (char)((x % 2) + '0');
        x = x / 2;
    }
    bin[8] = '\0';
    return bin;
}

void encode(char* message, int* pixels, int width, int height){
    if(strlen(message) * 8 > (width * height)){
        printf("Error: Message too large to encode in image!\n");
        return;
    }
    int pixelIndex = 0;
    int bitIndex = 0;
    while(*message){
        char* c_bin = binaryBuffer(*message);
        message++;
        int i;
        for(i = 0; i < 8; ++i){
            char bit = c_bin[i];
            int mask = 1 << (bitIndex % 3);
            int clearMask = ~(1 << (bitIndex % 3));
            int pixel = pixels[pixelIndex];
            int red = (pixel >> 16) & 0xff;
            int green = (pixel >> 8) & 0xff;
            int blue = pixel & 0xff;
            switch(bitIndex % 3){
                case 0:
                    red = (red & clearMask) | ((bit - '0') << (7 - bitIndex));
                    break;
                case 1:
                    green = (green & clearMask) | ((bit - '0') << (7 - bitIndex));
                    break;
                case 2:
                    blue = (blue & clearMask) | ((bit - '0') << (7 - bitIndex));
                    break;
                default:
                    printf("Error: This should never run!\n");
                    break;
            }
            pixel = 0xff000000 | (red << 16) | (green << 8) | (blue);
            pixels[pixelIndex] = pixel;
            bitIndex += 1;
            if(bitIndex % 3 == 0){
                pixelIndex += 1;
            }
        }
        free(c_bin);
    }
    return;
}

void decode(int* pixels, int width, int height){
    char message[MAX_PIXELS];
    int pixelIndex = 0;
    int bitIndex = 0;
    while(1){
        int pixel = pixels[pixelIndex];
        int red = (pixel >> 16) & 0xff;
        int green = (pixel >> 8) & 0xff;
        int blue = pixel & 0xff;
        int bit;
        switch(bitIndex % 3){
            case 0:
                bit = red & 1;
                break;
            case 1:
                bit = green & 1;
                break;
            case 2:
                bit = blue & 1;
                break;
            default:
                printf("Error: This should never run!\n");
                break;
        }
        message[bitIndex / 8] = (message[bitIndex / 8] << 1) | bit;
        bitIndex += 1;
        if(bitIndex % 8 == 0){
            if(message[(bitIndex / 8) - 1] == '\0'){
                printf("Decoded message: %s\n", message);
                return;
            }
        }
        pixelIndex += 1;
    }
}

int main(int argc, char const *argv[]){
    char* message = "This is a secret message hidden inside an image!";
    int pixels[MAX_PIXELS] = {0xff000000, 0x00000000, 0xffffffff, 0x12abcdef};
    int width = 2;
    int height = 2;
    encode(message, pixels, width, height);
    decode(pixels, width, height);
    return 0;
}