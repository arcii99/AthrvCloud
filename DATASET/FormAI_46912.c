//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_WIDTH 512
#define MAX_HEIGHT 512
#define MAX_ASCII 255
#define WATERMARK "example"
#define WM_LENGTH 7

//Function prototypes
void insert_watermark(char* image_file, char* output_file);
int read_image_file(char* filename, unsigned char** image, int *height, int *width);
int write_image_file(char* filename, unsigned char* image, int height, int width);

int main(int argc, char* argv[])
{
    if(argc != 3) //There should be exactly two arguments
    {
        printf("Usage: %s <input image file> <output image file>\n", argv[0]);
        exit(1);
    }

    insert_watermark(argv[1], argv[2]); //Insert the watermark into the image file
    printf("Digital watermarking completed!\n");

    return 0;
}

//Function to insert watermark into an image file
void insert_watermark(char* image_file, char* output_file)
{
    unsigned char* image_data = NULL;
    int height = 0;
    int width = 0;
    int i, j, k;
    int ascii_sum = 0;
    int bit_counter = 0;
    int wm_index = 0;

    //Read the image file into a buffer
    if(!read_image_file(image_file, &image_data, &height, &width))
    {
        printf("Could not read image file: %s\n", image_file);
        exit(1);
    }

    //Calculate the sum of ASCII values in the watermark
    for(i = 0; i < WM_LENGTH; i++)
    {
        ascii_sum += WATERMARK[i];
    }

    //Insert the watermark into the least significant bit of each byte of the image data
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            for(k = 0; k < 3; k++)
            {
                if(bit_counter < 8 * WM_LENGTH)
                {
                    if(wm_index < WM_LENGTH)
                    {
                        int ascii_val = WATERMARK[wm_index];
                        int bit_val = (ascii_val >> bit_counter) & 1;
                        image_data[(i * width * 3) + (j * 3) + k] = (image_data[(i * width * 3) + (j * 3) + k] & 0xFE) | bit_val;
                        bit_counter++;
                        if(bit_counter == 8)
                        {
                            bit_counter = 0;
                            wm_index++;
                        }
                    }
                    else
                    {
                        image_data[(i * width * 3) + (j * 3) + k] = image_data[(i * width * 3) + (j * 3) + k] & 0xFE;
                    }
                }
                else
                {
                    break;
                }
            }
            if(bit_counter >= 8 * WM_LENGTH)
            {
                break;
            }
        }
        if(bit_counter >= 8 * WM_LENGTH)
        {
            break;
        }
    }

    //Write the new image data to the output file
    if(!write_image_file(output_file, image_data, height, width))
    {
        printf("Could not write image file: %s\n", output_file);
        exit(1);
    }

    //Free the memory allocated for image_data
    free(image_data);
}

//Function to read an image file into a buffer
int read_image_file(char* filename, unsigned char** image, int* height, int* width)
{
    FILE* fp = fopen(filename, "rb"); //Open the image file for binary read
    if(!fp)
    {
        return 0;
    }

    //Read the image header
    char header[54];
    fread(header, 1, 54, fp);
    *width = (*(int*)&header[18]);
    *height = (*(int*)&header[22]);

    //Allocate memory for the image data buffer
    *image = (unsigned char*)malloc((*width) * (*height) * 3 * sizeof(unsigned char));
    if(!(*image))
    {
        fclose(fp);
        return 0;
    }

    //Read the image data into the buffer
    fread(*image, 1, (*width) * (*height) * 3, fp);
    fclose(fp);

    return 1;
}

//Function to write image data to a file
int write_image_file(char* filename, unsigned char* image, int height, int width)
{
    FILE* fp = fopen(filename, "wb"); //Open the output file for binary write
    if(!fp)
    {
        return 0;
    }

    //Write the image header
    char header[54] = {
        0x42, 0x4D, 0x36, 0x00, 0x0C, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x06, 0x00, 0x0C, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00
    };
    (*(int*)&header[2]) = 54 + width * height * 3;
    (*(int*)&header[18]) = width;
    (*(int*)&header[22]) = height;
    fwrite(header, 1, 54, fp);

    //Write the image data to the file
    fwrite(image, 1, width * height * 3, fp);
    fclose(fp);

    return 1;
}