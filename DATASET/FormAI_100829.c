//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAX_FILE_NAME 100
#define MAX_PIXEL_VALUE 255
#define HEADER_SIZE 54

// Function to read in the BMP image
int readImage(char *filename, unsigned char **header, unsigned char **imgData) {
    FILE *fp;
    int imgSize, i;

    fp = fopen(filename,"rb");
    if(fp==NULL) {
        printf("Error in opening the file!\n");
        return -1;
    }

    // Reading the header information from the BMP file
    *header=(unsigned char *) calloc(HEADER_SIZE,sizeof(unsigned char));
    fread(*header,sizeof(unsigned char),HEADER_SIZE,fp);

    int width = *(int*)&(*header)[18];
    int height = *(int*)&(*header)[22];
    int bpp = *(int*)&(*header)[28];

    // Calculating the image size
    imgSize = width * height * bpp/8;
    *imgData=(unsigned char *) calloc(imgSize,sizeof(unsigned char));

    // Reading the image data
    fseek(fp,HEADER_SIZE,SEEK_SET);
    fread(*imgData,sizeof(unsigned char),imgSize,fp);

    fclose(fp);
    return imgSize;
}

// Function to write the BMP image
void writeImage(char * filename,unsigned char *data, unsigned char *header,int imgSize) {
    FILE *f;
    f=fopen(filename,"wb");
    fwrite(header,sizeof(unsigned char),HEADER_SIZE,f);
    fwrite(data,sizeof(unsigned char),imgSize,f);
    fclose(f);
}

// Function to flip the image horizontally
void flipHorizontal(unsigned char *imgData, int width, int height, int bpp) {
    // Swapping the pixels row-wise
    for(int i=0;i<height;i++) {
        for(int j=0;j<width/2;j++) {
            for(int k=0;k<bpp/8;k++) {
                int temp=imgData[i*width*bpp/8+j*bpp/8+k];
                imgData[i*width*bpp/8+j*bpp/8+k]=imgData[i*width*bpp/8+(width-j-1)*bpp/8+k];
                imgData[i*width*bpp/8+(width-j-1)*bpp/8+k]=temp;
            }
        }
    }
}

// Function to adjust the brightness and contrast levels of the image
void adjustBrightnessContrast(unsigned char *imgData, int width, int height, int bpp, int brightnessLevel, int contrastLevel) {
    // Setting the minimum and maximum pixel value according to the bpp
    int minPixelValue=0;
    int maxPixelValue=0;

    if(bpp==8){
        minPixelValue=0;
        maxPixelValue=255;
    }
    else if(bpp==24){
        minPixelValue=0;
        maxPixelValue=255*255*255;
    }

    // Adjusting the pixel values using the formula I_new = (I_old - m) * c + m
    float m = brightnessLevel/100.0 * (maxPixelValue-minPixelValue) + minPixelValue;
    float c = contrastLevel/100.0 * (maxPixelValue-minPixelValue) / (maxPixelValue+minPixelValue);

    for(int i=0;i<height;i++) {
        for(int j=0;j<width;j++) {
            for(int k=0;k<bpp/8;k++) {
                int index = i*width*bpp/8+j*bpp/8+k;
                int pixelValue = imgData[index];
                imgData[index] = (unsigned char)((pixelValue - m) * c + m);
            }
        }
    }
}

int main() {
    char filename[MAX_FILE_NAME];
    printf("Enter the filename: ");
    scanf("%s",filename);

    unsigned char *header, *imgData;
    int imgSize = readImage(filename, &header, &imgData);
    if(imgSize==-1)
        exit(-1);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bpp = *(int*)&header[28];

    int choice;
    printf("\nMenu:\n1. Flip the image horizontally\n2. Adjust brightness/contrast levels\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice) {
        case 1:
            flipHorizontal(imgData, width, height, bpp);
            printf("Image flipped horizontally successfully!");
            break;
        case 2:
            int brightnessLevel, contrastLevel;
            printf("Enter the brightness level (-100 to 100): ");
            scanf("%d",&brightnessLevel);
            printf("Enter the contrast level (-100 to 100): ");
            scanf("%d",&contrastLevel);
            adjustBrightnessContrast(imgData, width, height, bpp, brightnessLevel, contrastLevel);
            printf("Image brightness/contrast levels adjusted successfully!");
            break;
        default:
            printf("Invalid choice!");
            break;
    }

    writeImage("output.bmp",imgData,header,imgSize);

    return 0;
}