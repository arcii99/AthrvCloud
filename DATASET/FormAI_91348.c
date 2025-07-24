//FormAI DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 50

typedef struct ImageData {
    unsigned char** pixelData;
    unsigned int width;
    unsigned int height;
} ImageData;

void loadImage(char* fileName, ImageData* imageData) {
    FILE* file = fopen(fileName, "rb");
    if(file == NULL) {
        printf("Failed to open file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    char format[3];
    fgets(format, 3, file);

    if(strcmp(format, "P6") == 0) {
        char ch = getc(file);
        while(ch == '#') {
            while(getc(file) != '\n');
            ch = getc(file);
        }
        
        ungetc(ch, file);
        fscanf(file, "%d %d %*d", &imageData->width, &imageData->height);

        imageData->pixelData = malloc(imageData->height * sizeof(unsigned char*));
        for(int i = 0; i < imageData->height; i++) {
            imageData->pixelData[i] = malloc(imageData->width * 3 * sizeof(unsigned char));
            fread(imageData->pixelData[i], 3 * sizeof(unsigned char), imageData->width, file);
        }
    }

    fclose(file);
}

void saveImage(char* fileName, ImageData* imageData) {
    FILE* file = fopen(fileName, "wb");
    if(file == NULL) {
        printf("Failed to open file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P6\n%d %d\n255\n", imageData->width, imageData->height);

    for(int i = 0; i < imageData->height; i++) {
        fwrite(imageData->pixelData[i], 3 * sizeof(unsigned char), imageData->width, file);
    }

    fclose(file);
}

void grayscale(ImageData* imageData) {
    for(int i = 0; i < imageData->height; i++) {
        for(int j = 0; j < imageData->width; j++) {
            unsigned int grayValue = ((imageData->pixelData[i][j*3] + imageData->pixelData[i][j*3+1] + imageData->pixelData[i][j*3+2]) / 3);
            imageData->pixelData[i][j*3] = imageData->pixelData[i][j*3+1] = imageData->pixelData[i][j*3+2] = grayValue;
        }
    }
}

void invertColors(ImageData* imageData) {
    for(int i = 0; i < imageData->height; i++) {
        for(int j = 0; j < imageData->width; j++) {
            imageData->pixelData[i][j*3] = 255 - imageData->pixelData[i][j*3];
            imageData->pixelData[i][j*3+1] = 255 - imageData->pixelData[i][j*3+1];
            imageData->pixelData[i][j*3+2] = 255 - imageData->pixelData[i][j*3+2];
        }
    }
}

void drawBorder(ImageData* imageData, unsigned int borderWidth, unsigned char* borderColor) {
    for(int i = 0; i < imageData->height; i++) {
        for(int j = 0; j < imageData->width; j++) {
            if(i < borderWidth || i >= imageData->height - borderWidth || j < borderWidth || j >= imageData->width - borderWidth) {
                imageData->pixelData[i][j*3] = borderColor[0];
                imageData->pixelData[i][j*3+1] = borderColor[1];
                imageData->pixelData[i][j*3+2] = borderColor[2];
            }
        }
    }
}

int main() {
    char fileName[MAX_FILE_NAME];
    printf("Enter the file name: ");
    scanf("%s", fileName);

    ImageData imageData;
    loadImage(fileName, &imageData);

    unsigned int option;
    printf("\nMenu:\n1. Convert to grayscale\n2. Invert colors\n3. Draw border\n4. Save image\n5. Exit\n");
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                grayscale(&imageData);
                printf("\nImage converted to grayscale.\n");
                break;
            case 2:
                invertColors(&imageData);
                printf("\nImage colors inverted.\n");
                break;
            case 3:
                unsigned int borderWidth;
                printf("\nEnter border width: ");
                scanf("%d", &borderWidth);

                unsigned char borderColor[3];
                printf("\nEnter border color (RGB values between 0-255): ");
                scanf("%hhu %hhu %hhu", &borderColor[0], &borderColor[1], &borderColor[2]);

                drawBorder(&imageData, borderWidth, borderColor);
                printf("\nBorder drawn.\n");
                break;
            case 4:
                char newFileName[MAX_FILE_NAME];
                printf("\nEnter the new file name: ");
                scanf("%s", newFileName);

                saveImage(newFileName, &imageData);
                printf("\nImage saved.\n");
                break;
            case 5:
                printf("\nExiting.\n");
                break;
            default:
                printf("\nInvalid option.\n");
                break;
        }
    } while(option != 5);

    for(int i = 0; i < imageData.height; i++) {
        free(imageData.pixelData[i]);
    }
    free(imageData.pixelData);

    return 0;
}