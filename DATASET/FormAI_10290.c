//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

char ascii_char[]=" .:-=+*#%@";

void convert_image_to_ascii(char *filename, int width, int height, int style)
{
    FILE *fp=NULL;
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    char ascii_image[MAX_HEIGHT][MAX_WIDTH];
    int i,j;
    double pixel_to_ascii_ratio;
    
    //open the image file
    fp=fopen(filename,"rb");
    if(fp == NULL)
    {
        printf("Error: Unable to open file!");
        exit(1);
    }
    
    //read the image data
    fread(image, sizeof(unsigned char), width*height, fp);
    
    //close the file
    fclose(fp);
    
    //calculate the pixel to ascii ratio
    pixel_to_ascii_ratio=255.0/strlen(ascii_char);
    
    //convert the image to ascii
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            ascii_image[i][j]=ascii_char[(int)(image[i][j]/pixel_to_ascii_ratio)];
        }
    }
    
    //print the ascii image to console
    switch(style)
    {
        case 1:
            for(i=0;i<height;i++)
            {
                for(j=0;j<width;j++)
                {
                    printf("%c",ascii_image[i][j]);
                }
                printf("\n");
            }
            break;
            
        case 2:
            for(i=height-1;i>=0;i--)
            {
                for(j=width-1;j>=0;j--)
                {
                    printf("%c",ascii_image[i][j]);
                }
                printf("\n");
            }
            break;
            
        case 3:
            for(j=0;j<width;j++)
            {
                for(i=0;i<height;i++)
                {
                    printf("%c",ascii_image[i][j]);
                }
                printf("\n");
            }
            break;
            
        case 4:
            for(j=width-1;j>=0;j--)
            {
                for(i=height-1;i>=0;i--)
                {
                    printf("%c",ascii_image[i][j]);
                }
                printf("\n");
            }
            break;
            
        default:
            printf("Invalid style selected!");
            break;
    }
}

int main()
{
    int width=16;
    int height=10;
    int style=1;
    char filename[]="sample_image.dat";
    
    convert_image_to_ascii(filename, width, height, style);
    return 0;
}