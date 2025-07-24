//FormAI DATASET v1.0 Category: Image Editor ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    unsigned char r, g, b; //red, green, blue values
} Pixel;

typedef struct {
    int width, height; // image width and height
    Pixel data[MAX_WIDTH][MAX_HEIGHT]; // 2D array for storing pixel data
} Image;

//function to read an image file and store its data in Image structure
void read_image(char *filename, Image *img) {
    FILE *f = fopen(filename, "rb");
    char header[54];
    fread(header, sizeof(char), 54, f); //read header

    //extract width and height information from header
    img->width = *(int*)&header[18];
    img->height = *(int*)&header[22];

    int row_padded = (img->width*3 + 3) & (~3); //calculate row padding
    unsigned char data[row_padded];

    //read pixel data row by row and store it in Image structure
    for(int i=0; i<img->height; i++) {
        fread(data, sizeof(unsigned char), row_padded, f);
        for(int j=0; j<img->width; j++) {
            int index = j*3;
            img->data[i][j].b = data[index];
            img->data[i][j].g = data[index+1];
            img->data[i][j].r = data[index+2];
        }
    }
    fclose(f);
}

//function to write an image file using data stored in Image structure
void write_image(char *filename, Image *img) {
    FILE *f = fopen(filename, "wb");

    //write header
    unsigned char header[54] = {
        'B','M',
        0,0,0,0,
        0,0,0,0,
        54,0,0,0,
        40,0,0,0,
        0,0,0,0,
        0,0,0,0,
        1,0,24,0
    };

    int row_padded = (img->width*3 + 3) & (~3);
    int size_file = row_padded*img->height + 54; //calculate file size
    *(int*)&header[2] = size_file;
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;

    fwrite(header, sizeof(unsigned char), 54, f); //write header

    unsigned char data[row_padded];
    memset(data, 0, row_padded); //initialize pixel data to 0

    //write pixel data row by row
    for(int i=0; i<img->height; i++) {
        for(int j=0; j<img->width; j++) {
            int index = j*3;
            data[index] = img->data[i][j].b;
            data[index+1] = img->data[i][j].g;
            data[index+2] = img->data[i][j].r;
        }
        fwrite(data, sizeof(unsigned char), row_padded, f);
    }
    fclose(f);
}

//function to invert colors of an image
void invert_colors(Image *img) {
    for(int i=0; i<img->height; i++) {
        for(int j=0; j<img->width; j++) {
            img->data[i][j].r = 255 - img->data[i][j].r;
            img->data[i][j].g = 255 - img->data[i][j].g;
            img->data[i][j].b = 255 - img->data[i][j].b;
        }
    }
}

int main() {
    Image img;
    read_image("example.bmp", &img);

    //invert colors of image
    invert_colors(&img);

    write_image("output.bmp", &img);
    printf("Image processing complete!\n");

    return 0;
}