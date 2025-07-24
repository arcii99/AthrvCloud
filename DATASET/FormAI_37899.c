//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 400
#define MAX_HEIGHT 300

char asciiArt[MAX_HEIGHT][MAX_WIDTH];

void convertImageToAscii(char inputImage[], float scale) {

    FILE *fp;
    unsigned char imageBuffer[MAX_WIDTH*MAX_HEIGHT*3];
    char asciiSet[] = " .:-=+*#%@";
    int asciiSetLength = strlen(asciiSet);

    fp = fopen(inputImage, "rb");
    fread(imageBuffer, 1, MAX_WIDTH*MAX_HEIGHT*3, fp);
    fclose(fp);

    for(int i = 0, k = 0; i < MAX_HEIGHT; i++, k += 3*MAX_WIDTH) {
        for(int j = 0; j < MAX_WIDTH; j++) {
            int r = imageBuffer[k+3*j];
            int g = imageBuffer[k+3*j+1];
            int b = imageBuffer[k+3*j+2];
            float grayScale = 0.21*r + 0.72*g + 0.07*b;
            int asciiIndex = ((int) (grayScale / (255.0 / asciiSetLength)))-1;
            asciiIndex = (asciiIndex >= 0 && asciiIndex < asciiSetLength) ? asciiIndex : asciiSetLength-1;
            asciiArt[i][j] = asciiSet[asciiIndex];
        }
    }

    int scaledWidth = MAX_WIDTH * scale;
    int scaledHeight = MAX_HEIGHT * scale;
    for(int i = 0; i < scaledHeight; i++) {
        for(int j = 0; j < scaledWidth; j++) {
            int originalY = (int) (i / scale);
            int originalX = (int) (j / scale);
            printf("%c", asciiArt[originalY][originalX]);
        }
        printf("\n");
    }
}

int main() {
    convertImageToAscii("input_image.jpg", 0.5);
    return 0;
}