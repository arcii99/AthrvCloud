//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main(){
    char asciiChars[] = {'#', '&', '@', '%', '*', '+', '-', ';', ':', ',', '.', ' '};
    int numChars = sizeof(asciiChars);
    char blankChar = asciiChars[numChars - 1];

    FILE *imgFile;
    imgFile = fopen("image.ppm", "r");

    if(imgFile){
        int width, height, maxColor;
        char format[3];

        fscanf(imgFile, "%s %d %d %d", format, &width, &height, &maxColor);

        int pixelCount = width * height;
        int asciiCount = pixelCount / 3;
        int remainder = pixelCount % 3;
        if(remainder > 0) asciiCount++;

        unsigned char pixel[3];
        int pixelVal;
        char asciiChar;
        int count = 0;

        while(count < asciiCount){
            fread(pixel, 1, 3, imgFile);
            pixelVal = ((pixel[0] + pixel[1] + pixel[2]) / 3) * (numChars - 1) / maxColor;
            asciiChar = asciiChars[pixelVal];
            printf("%c", asciiChar);
            if((count + 1) % width == 0) printf("\n");
            count++;
        }

        fclose(imgFile);
    }
    else{
        printf("Cannot open image file.");
        return 1;
    }

    return 0;
}