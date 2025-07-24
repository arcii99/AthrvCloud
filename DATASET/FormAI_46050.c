//FormAI DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to hold image info */
typedef struct Image {
    unsigned char *data;
    int width, height;
    int channels;
} Image;

/* Function to read image data from file */
Image *readImage(char *filename)
{
    FILE *fp;
    Image *img;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    /* Get file size */
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    /* Allocate memory for image */
    img = (Image *) malloc(sizeof(Image));
    if (img == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    /* Read image header */
    char header[54];
    if (fread(header, sizeof(char), 54, fp) != 54) {
        perror("Error reading image header");
        fclose(fp);
        free(img);
        return NULL;
    }

    /* Get dimensions */
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int channels = *(int*)&header[28];

    /* Validate dimensions and channels */
    if (width <= 0 || height <= 0 || channels != 3) {
        perror("Invalid image dimensions or channel count");
        fclose(fp);
        free(img);
        return NULL;
    }

    /* Allocate memory for image data */
    int imageSize = width * height * channels;
    img->data = (unsigned char *) malloc(imageSize);
    if (img->data == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        free(img);
        return NULL;
    }

    /* Read image data */
    if (fread(img->data, sizeof(unsigned char), imageSize, fp) != imageSize) {
        perror("Error reading image data");
        fclose(fp);
        free(img->data);
        free(img);
        return NULL;
    }

    /* Set image properties */
    img->width = width;
    img->height = height;
    img->channels = channels;

    /* Close file */
    fclose(fp);

    return img;
}

/* Function to write image data to file */
void writeImage(char *filename, Image *img)
{
    FILE *fp;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    /* Write header */
    char header[54] = {
        0x42, 0x4D,             /* BMP file signature */
        0x36, 0x00, 0x0C, 0x00, /* File size (bytes) = header size (54) + image data size */
        0x00, 0x00,             /* Reserved */
        0x00, 0x00,             /* Reserved */
        0x36, 0x00, 0x00, 0x00, /* Offset to image data */
        0x28, 0x00, 0x00, 0x00, /* Image header size */
        0x00, 0x00, 0x00, 0x02, /* Image width (pixels) */
        0x00, 0x00, 0x00, 0x02, /* Image height (pixels) */
        0x01, 0x00,             /* Number of color planes */
        0x18, 0x00,             /* Bits per pixel */
        0x00, 0x00, 0x00, 0x00, /* Compression method */
        0x10, 0x00, 0x00, 0x00, /* Image data size (bytes) */
        0x13, 0x0B, 0x00, 0x00, /* Horizontal resolution (pixels/meter) */
        0x13, 0x0B, 0x00, 0x00, /* Vertical resolution (pixels/meter) */
        0x00, 0x00, 0x00, 0x00, /* Number of colors in palette */
        0x00, 0x00, 0x00, 0x00, /* Number of important colors */
    };
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;
    *(int*)&header[28] = img->channels;
    int imageSize = img->width * img->height * img->channels;
    *(int*)&header[2] = 54 + imageSize;
    fwrite(header, sizeof(char), 54, fp);

    /* Write image data */
    fwrite(img->data, sizeof(unsigned char), imageSize, fp);

    /* Close file */
    fclose(fp);
}

/* Function to invert image colors */
void invertColors(Image *img)
{
    int imageSize = img->width * img->height * img->channels;
    for (int i = 0; i < imageSize; i++) {
        img->data[i] = 255 - img->data[i];
    }
}

/* Main function */
int main(int argc, char *argv[])
{
    char *filename;
    Image *img;

    /* Check for filename argument */
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    } else {
        filename = argv[1];
    }

    /* Read image from file */
    img = readImage(filename);
    if (img == NULL) {
        printf("Error reading image from file: %s\n", filename);
        return -1;
    }

    /* Invert image colors */
    invertColors(img);

    /* Write image to file */
    char *outFilename = "out.bmp";
    writeImage(outFilename, img);
    printf("Image saved to file: %s\n", outFilename);

    /* Free memory */
    free(img->data);
    free(img);

    return 0;
}