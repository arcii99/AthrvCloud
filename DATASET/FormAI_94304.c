//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Image {
    int width;
    int height;
    int** pixels;
} Image;

Image* createImage(int width, int height) {
    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(sizeof(int*)*height);
    for(int i=0;i<height;i++) {
        img->pixels[i] = malloc(sizeof(int)*width);
        memset(img->pixels[i], 0, width*sizeof(int));
    }
    return img;
}

void deleteImage(Image* img) {
    for(int i=0;i<img->height;i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

Image* loadImage(const char* filename) {
    FILE* f = fopen(filename, "r");
    if(f==NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }
    char buf[1024];
    fgets(buf, 1024, f);
    if(strcmp(buf, "P2\n")!=0) {
        printf("Error: Invalid file format (not P2)\n");
        fclose(f);
        return NULL;
    }
    int width=0, height=0;
    fgets(buf, 1024, f);
    sscanf(buf, "%d%d", &width, &height);
    Image* img = createImage(width, height);
    fscanf(f, "%d", &width);
    for(int i=0;i<height;i++) {
        for(int j=0;j<width;j++) {
            fscanf(f, "%d", &img->pixels[i][j]);
        }
    }
    fclose(f);
    return img;
}

int saveImage(const char* filename, Image* img) {
    FILE* f = fopen(filename, "w");
    if(f==NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }
    fprintf(f, "P2\n%d %d\n255\n", img->width, img->height);
    for(int i=0;i<img->height;i++) {
        for(int j=0;j<img->width;j++) {
            fprintf(f, "%d ", img->pixels[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    return 0;
}

void flipImage(Image* img) {
    for(int i=0;i<img->height;i++) {
        for(int j=0;j<img->width/2;j++) {
            int temp = img->pixels[i][j];
            img->pixels[i][j] = img->pixels[i][img->width-1-j];
            img->pixels[i][img->width-1-j] = temp;
        }
    }
}

void adjustBrightness(Image* img, int value) {
    for(int i=0;i<img->height;i++) {
        for(int j=0;j<img->width;j++) {
            img->pixels[i][j] += value;
            if(img->pixels[i][j]<0) img->pixels[i][j] = 0;
            if(img->pixels[i][j]>255) img->pixels[i][j] = 255;
        }
    }
}

void adjustContrast(Image* img, float value) {
    float factor = (259*(value+255))/(255*(259-value));
    for(int i=0;i<img->height;i++) {
        for(int j=0;j<img->width;j++) {
            int p = img->pixels[i][j];
            int np = factor*(p-128)+128;
            if(np<0) np = 0;
            if(np>255) np = 255;
            img->pixels[i][j] = np;
        }
    }
}

void artisticFilter(Image* img) {
    int kernel[3][3] = {{0, -2, 0}, {-2, 9, -2}, {0, -2, 0}};
    Image* temp = createImage(img->width, img->height);
    for(int i=1;i<img->height-1;i++) {
        for(int j=1;j<img->width-1;j++) {
            int sum = 0;
            for(int ki=0;ki<3;ki++) {
                for(int kj=0;kj<3;kj++) {
                    sum += img->pixels[i-1+ki][j-1+kj]*kernel[ki][kj];
                }
            }
            temp->pixels[i][j] = sum;
        }
    }
    for(int i=0;i<img->height;i++) {
        for(int j=0;j<img->width;j++) {
            img->pixels[i][j] = temp->pixels[i][j];
            if(img->pixels[i][j]<0) img->pixels[i][j] = 0;
            if(img->pixels[i][j]>255) img->pixels[i][j] = 255;
        }
    }
    deleteImage(temp);
}

int main() {
    Image* img = loadImage("input.pgm");
    if(img==NULL) {
        return 0;
    }

    flipImage(img);
    saveImage("output1.pgm", img);

    adjustBrightness(img, 50);
    saveImage("output2.pgm", img);

    adjustContrast(img, 50);
    saveImage("output3.pgm", img);

    artisticFilter(img);
    saveImage("output4.pgm", img);

    deleteImage(img);
    return 0;
}