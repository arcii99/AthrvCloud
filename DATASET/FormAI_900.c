//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel* pixels;
} Image;

void flip_horizontally(Image* img) {
    Pixel temp;
    for(int row=0; row < img->height; row++) {
        for(int col=0; col < img->width/2; col++) {
            temp = img->pixels[row*img->width+col];
            img->pixels[row*img->width+col] = img->pixels[(row+1)*img->width-col-1];
            img->pixels[(row+1)*img->width-col-1] = temp;
        }
    }
}

void adjust_brightness(Image* img, int scale) {
    for(int i=0; i<img->width*img->height; i++) {
        img->pixels[i].red += scale;
        img->pixels[i].green += scale;
        img->pixels[i].blue += scale;
    }
}

void adjust_contrast(Image* img, int scale) {
    double factor = (259.0 * (scale + 255.0)) / (255.0 * (259.0 - scale));
    for(int i=0; i<img->width*img->height; i++) {
        img->pixels[i].red = (int)(factor * (img->pixels[i].red - 128) + 128);
        img->pixels[i].green = (int)(factor * (img->pixels[i].green - 128) + 128);
        img->pixels[i].blue = (int)(factor * (img->pixels[i].blue - 128) + 128);
    }
}

Image* read_image_from_file(char* file_name) {
    FILE* fp = fopen(file_name, "rb");
    if(fp == NULL)
        return NULL;

    Image* img = (Image*)malloc(sizeof(Image));
    if(img == NULL)
        return NULL;

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    img->width = *(int*)&header[18];
    img->height = *(int*)&header[22];

    int padding_size = 4 - (img->width * sizeof(Pixel) % 4);
    if(padding_size == 4)
        padding_size = 0;

    img->pixels = (Pixel*)malloc(sizeof(Pixel)*img->height*img->width);
    if(img->pixels == NULL)
        return NULL;

    unsigned char buffer[img->width*sizeof(Pixel)];
    for(int row=0; row < img->height; row++) {
        fread(buffer, sizeof(unsigned char), img->width*sizeof(Pixel), fp);
        for(int col=0; col < img->width; col++) {
            img->pixels[row*img->width+col].blue = buffer[col*3];
            img->pixels[row*img->width+col].green = buffer[col*3+1];
            img->pixels[row*img->width+col].red = buffer[col*3+2];
        }
        fseek(fp, padding_size, SEEK_CUR);
    }
    fclose(fp);
    return img;
}

void write_image_to_file(Image* img, char* file_name) {
    FILE* fp = fopen(file_name, "wb");
    if(fp == NULL)
        return;

    unsigned char header[54] = {
        'B','M',          // signature
        0,0,0,0,          // file size
        0,0,0,0,          // reserved
        54,0,0,0,         // image offset
        40,0,0,0,         // header size
        0,0,0,0,          // width
        0,0,0,0,          // height
        1,0,              // color planes
        24,0,             // bits per pixel
        0,0,0,0,          // compression
        0,0,0,0,          // image size
        0,0,0,0,          // horizontal resolution
        0,0,0,0,          // vertical resolution
        0,0,0,0,          // colors in color table
        0,0,0,0           // important color count
    };
    *(int*)&header[2] = 54 + img->width*img->height*sizeof(Pixel);
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;
    fwrite(header, sizeof(unsigned char), 54, fp);

    int padding_size = 4 - (img->width * sizeof(Pixel) % 4);
    if(padding_size == 4)
        padding_size = 0;

    unsigned char padding[3] = {0, 0, 0};
    for(int row=0; row < img->height; row++) {
        for(int col=0; col < img->width; col++) {
            fwrite(&img->pixels[row*img->width+col].blue, sizeof(unsigned char), 1, fp);
            fwrite(&img->pixels[row*img->width+col].green, sizeof(unsigned char), 1, fp);
            fwrite(&img->pixels[row*img->width+col].red, sizeof(unsigned char), 1, fp);
        }
        fwrite(padding, sizeof(unsigned char), padding_size, fp);
    }
    fclose(fp);
}

int main() {
    char file_name[] = "image.bmp";
    Image* img = read_image_from_file(file_name);
    if(img == NULL) {
        printf("Error reading image file\n");
        return 1;
    }

    // Flip image horizontally
    flip_horizontally(img);

    // Increase brightness
    adjust_brightness(img, 30);

    // Increase contrast
    adjust_contrast(img, 100);

    // Save the modified image
    write_image_to_file(img, "modified_image.bmp");

    // Free memory
    free(img->pixels);
    free(img);
    return 0;
}