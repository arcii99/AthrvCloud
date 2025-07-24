//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200 // Maximum width of the image
#define MAX_HEIGHT 200 // Maximum height of the image
#define MAX_FILENAME_LENGTH 50 // Maximum length of the file name

void readFile(FILE *fp, char asciiArt[MAX_HEIGHT][MAX_WIDTH], int *width, int *height) {
    char buffer[MAX_WIDTH+1];
    int lineCount = 0;

    while (lineCount < MAX_HEIGHT && fgets(buffer, MAX_WIDTH+2, fp)) {
        int len = strlen(buffer);
        if (len > *width) *width = len;
        strncpy(asciiArt[lineCount], buffer, len-1);
        asciiArt[lineCount][len-1] = '\0';
        lineCount++;
    }
    *height = lineCount;
}

void convertToAscii(char ASCIIChars[70], unsigned char grayScaleValue, char *asciiChar) {
    int index = grayScaleValue *69/255;
    *asciiChar = ASCIIChars[index];
}

void convertImageToAscii(char asciiArt[MAX_HEIGHT][MAX_WIDTH], int width, int height, char *asciiImage) {
    char ASCIIChars[] = " .:-=+*#%@";
    int index = 0;
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            char asciiChar = ' ';
            if (asciiArt[i][j] != '\0') {
                unsigned char grayscaleValue = (unsigned char)asciiArt[i][j];
                convertToAscii(ASCIIChars, grayscaleValue, &asciiChar);
            }
            asciiImage[index++] = asciiChar;
        }
        asciiImage[index++] = '\n';
    }
    asciiImage[index] = '\0';
}

int main() {
    char asciiArt[MAX_HEIGHT][MAX_WIDTH] = {{0}};
    char asciiImage[MAX_HEIGHT*MAX_WIDTH+MAX_HEIGHT+1] = {0};
    char filename[MAX_FILENAME_LENGTH];
    FILE *fp;

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Unable to open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    int width = 0, height = 0;

    readFile(fp, asciiArt, &width, &height);

    if (width > MAX_WIDTH) {
        printf("Error: Maximum width exceeded.\n");
        exit(EXIT_FAILURE);
    }

    if (height > MAX_HEIGHT) {
        printf("Error: Maximum height exceeded.\n");
        exit(EXIT_FAILURE);
    }

    convertImageToAscii(asciiArt, width, height, asciiImage);

    printf("%s", asciiImage);

    return 0;
}