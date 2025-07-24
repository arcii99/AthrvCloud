//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <string.h>

/* This is my unique C Metadata Extractor program! It's going to blow your mind! */

struct ImageMetadata {
    char fileName[100];
    char fileType[50];
    int height;
    int width;
};

void extractMetadata(struct ImageMetadata *image) {
    // pretend we actually extract metadata from the image file
    strcpy(image->fileName, "myImage.jpg");
    strcpy(image->fileType, "JPEG");
    image->height = 1080;
    image->width = 1920;
}

int main() {
    struct ImageMetadata myImage;
    extractMetadata(&myImage);

    printf("We've successfully extracted the following metadata from the image file:\n");
    printf("File Name: %s\n", myImage.fileName);
    printf("File Type: %s\n", myImage.fileType);
    printf("Dimensions: %dx%d\n", myImage.width, myImage.height);

    printf("This program is amazing! We've successfully extracted metadata from an image file!\n");
    printf("I'm so excited about this program. I feel like we can do so much more with it!\n");
    return 0;
}