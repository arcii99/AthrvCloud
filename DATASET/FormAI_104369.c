//FormAI DATASET v1.0 Category: Image Steganography ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54
#define MAX_SECRET_MSG_SIZE 10000

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} BitmapImage;

// function to read bitmap image from file
BitmapImage *readBitmapImage(char *fileName) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error: Could not open file for reading\n");
        return NULL;
    }

    // read bitmap file header
    unsigned char header[HEADER_SIZE];
    if (fread(header, 1, HEADER_SIZE, file) != HEADER_SIZE) {
        printf("Error: Could not read file header\n");
        fclose(file);
        return NULL;
    }

    // verify that file is a 24-bit uncompressed bitmap image
    if (header[0] != 'B' || header[1] != 'M' || *(int*)&(header[0x1E]) != 0 || *(int*)&(header[0x1C]) != 24) {
        printf("Error: File is not a 24-bit uncompressed bmp image\n");
        fclose(file);
        return NULL;
    }

    // read image dimensions
    int width = *(int*)&(header[0x12]);
    int height = *(int*)&(header[0x16]);

    // allocate memory for bitmap image
    BitmapImage *image = (BitmapImage*) malloc(sizeof(BitmapImage));
    image->width = width;
    image->height = height;
    image->pixels = (Pixel*) malloc(width * height * sizeof(Pixel));

    // read pixel data
    int padding = (4 - (width * sizeof(Pixel)) % 4) % 4;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Pixel *pixel = &(image->pixels[i * width + j]);
            if (fread(pixel, sizeof(Pixel), 1, file) != 1) {
                printf("Error: Could not read pixel data\n");
                fclose(file);
                free(image);
                return NULL;
            }
        }
        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);
    return image;
}

// function to write bitmap image to file
int writeBitmapImage(char *fileName, BitmapImage *image) {
    FILE *file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Error: Could not open file for writing\n");
        return 0;
    }

    // write bitmap file header
    unsigned char header[HEADER_SIZE];
    memset(header, 0, HEADER_SIZE);
    header[0] = 'B'; header[1] = 'M';
    *(int*)&(header[0x1C]) = 24;
    *(int*)&(header[0x12]) = image->width;
    *(int*)&(header[0x16]) = image->height;
    int bmpFileSize = HEADER_SIZE + (image->width * sizeof(Pixel) + ((4 - (image->width * sizeof(Pixel)) % 4) % 4)) * image->height;
    *(int*)&(header[0x02]) = bmpFileSize;
    if (fwrite(header, 1, HEADER_SIZE, file) != HEADER_SIZE) {
        printf("Error: Could not write file header\n");
        fclose(file);
        return 0;
    }

    // write pixel data
    int padding = (4 - (image->width * sizeof(Pixel)) % 4) % 4;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel *pixel = &(image->pixels[i * image->width + j]);
            if (fwrite(pixel, sizeof(Pixel), 1, file) != 1) {
                printf("Error: Could not write pixel data\n");
                fclose(file);
                return 0;
            }
        }
        unsigned char paddingByte = 0;
        fwrite(&paddingByte, 1, padding, file);
    }

    fclose(file);
    return 1;
}

// function to hide secret message in bitmap image
int hideSecretMessage(char *fileName, char *secretMsg) {
    BitmapImage *image = readBitmapImage(fileName);
    if (image == NULL) {
        return 0;
    }

    int secretMsgSize = strlen(secretMsg);
    if (secretMsgSize > MAX_SECRET_MSG_SIZE) {
        printf("Error: Secret message size exceeds maximum allowed limit\n");
        free(image->pixels);
        free(image);
        return 0;
    }

    int noOfBytesToHide = secretMsgSize * 8;
    if (noOfBytesToHide > (image->width * image->height * 3)) {
        printf("Error: Image is too small to hide secret message of given size\n");
        free(image->pixels);
        free(image);
        return 0;
    }

    // convert secret message to binary form
    unsigned char binarySecretMsg[MAX_SECRET_MSG_SIZE * 8] = {0};
    for (int i = 0; i < secretMsgSize; i++) {
        unsigned char c = secretMsg[i];
        for (int j = 0; j < 8; j++) {
            binarySecretMsg[i * 8 + j] = (c & (1 << j)) ? 1 : 0;
        }
    }

    // hide binary message in image
    int k = 0;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel *pixel = &(image->pixels[i * image->width + j]);
            if (k >= noOfBytesToHide) {
                break;
            }
            pixel->r = (pixel->r & 0xFE) | binarySecretMsg[k];
            k++;
            if (k >= noOfBytesToHide) {
                break;
            }
            pixel->g = (pixel->g & 0xFE) | binarySecretMsg[k];
            k++;
            if (k >= noOfBytesToHide) {
                break;
            }
            pixel->b = (pixel->b & 0xFE) | binarySecretMsg[k];
            k++;
        }
        if (k >= noOfBytesToHide) {
            break;
        }
    }

    // save image with secret message
    if (!writeBitmapImage("hiddenMsgImage.bmp", image)) {
        free(image->pixels);
        free(image);
        return 0;
    }

    free(image->pixels);
    free(image);
    return 1;
}

// function to extract hidden secret message from bitmap image
int extractSecretMessage(char *fileName) {
    BitmapImage *image = readBitmapImage(fileName);
    if (image == NULL) {
        return 0;
    }

    int noOfBytesToExtract = image->width * image->height * 3;
    unsigned char *binarySecretMsg = (unsigned char*) malloc(noOfBytesToExtract * sizeof(unsigned char));
    int k = 0;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel *pixel = &(image->pixels[i * image->width + j]);
            binarySecretMsg[k++] = pixel->r & 1;
            binarySecretMsg[k++] = pixel->g & 1;
            binarySecretMsg[k++] = pixel->b & 1;
        }
    }

    // convert binary message to text form
    unsigned char secretMsg[MAX_SECRET_MSG_SIZE] = {0};
    int msgSize = 0;
    for (int i = 0; i < noOfBytesToExtract / 8; i++) {
        unsigned char c = 0;
        for (int j = 0; j < 8; j++) {
            c |= (binarySecretMsg[i * 8 + j] << j);
        }
        secretMsg[i] = c;
        if (secretMsg[i] == '\0') {
            break;
        }
        msgSize++;
    }

    printf("Secret Message: %s\n", secretMsg);

    free(binarySecretMsg);
    free(image->pixels);
    free(image);
    return 1;
}

int main() {
    char *fileName = "sample.bmp";
    char *secretMsg = "Hello, World! How are you?";
    printf("The original message is: %s\n", secretMsg);

    printf("Hiding secret message in image...\n");
    if (!hideSecretMessage(fileName, secretMsg)) {
        printf("Failed to hide secret message!\n");
        return 1;
    }
    printf("Secret message hidden successfully in image\n");

    printf("Extracting secret message from image...\n");
    if (!extractSecretMessage("hiddenMsgImage.bmp")) {
        printf("Failed to extract secret message!\n");
        return 1;
    }
    printf("Secret message extracted successfully from image\n");

    return 0;
}