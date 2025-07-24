//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

char asciiArt[MAX_HEIGHT][MAX_WIDTH];

void convertToAscii(char *imagePath, int resizeFactor) {
    FILE *imageFile = fopen(imagePath, "rb");
    if(imageFile == NULL) {
        printf("Error Opening File: %s", imagePath);
        return;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    int padding = 0;
    while((width * 3 + padding) % 4 != 0) {
        padding++;
    }

    unsigned char pixelData[height][width][3];
    fseek(imageFile, sizeof(header), SEEK_SET);

    for(int i = height - 1; i >= 0; i--) {
        for(int j = 0; j < width; j++) {
            fread(pixelData[i][j], 3, 1, imageFile);
        }
        fseek(imageFile, padding, SEEK_CUR);
    }

    fclose(imageFile);

    int newWidth = width / resizeFactor;
    int newHeight = height / resizeFactor;

    for(int i = 0; i < newHeight; i++) {
        for(int j = 0; j < newWidth; j++) {
            int red = 0;
            int green = 0;
            int blue = 0;
            for(int k = 0; k < resizeFactor; k++) {
                for(int l = 0; l < resizeFactor; l++) {
                    red += pixelData[i * resizeFactor + k][j * resizeFactor + l][0];
                    green += pixelData[i * resizeFactor + k][j * resizeFactor + l][1];
                    blue += pixelData[i * resizeFactor + k][j * resizeFactor + l][2];
                }
            }

            red /= resizeFactor * resizeFactor;
            green /= resizeFactor * resizeFactor;
            blue /= resizeFactor * resizeFactor;

            int brightness = (red + green + blue) / 3;
            static char asciiChars[] = {'@', '#', 'S', '%', '?', '*', '+', ':', ',', '.', ' '};
            int textSize = sizeof(asciiChars) - 1;
            int index = brightness * textSize / 255;

            if(index < 0) {
                index = 0;
            }

            if(index > textSize - 1) {
                index = textSize - 1;
            }

            asciiArt[i][j] = asciiChars[index];
        }
    }
}

int main() {
    memset(asciiArt, 0, sizeof(asciiArt));
    char imagePath[] = "path_to_your_image.bmp";

    int resizeFactor = 5;
    convertToAscii(imagePath, resizeFactor);

    for(int i = 0; i < MAX_HEIGHT && asciiArt[i][0] != '\0'; i++) {
        printf("%s\n", asciiArt[i]);
    }

    return 0;
}