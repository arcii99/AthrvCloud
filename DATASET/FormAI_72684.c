//FormAI DATASET v1.0 Category: Image compression ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

//Data structure to store pixel values
typedef struct Pixel
{
    int red;
    int green;
    int blue;
}Pixel;

//Struct to store frequency and its corresponding pixel
typedef struct Freq_Pixel
{
    int freq;
    Pixel pixel;
}Freq_Pixel;

//Function to compare the frequency of two pixels
int compare(const void* a, const void* b)
{
    Freq_Pixel* f1 = (Freq_Pixel*)a;
    Freq_Pixel* f2 = (Freq_Pixel*)b;
    return f2->freq - f1->freq;
}

//Function to compress the image
void compress_image(char* input_file, char* output_file)
{
    //Open the input file
    FILE* fp = fopen(input_file, "rb");
    if(fp == NULL)
    {
        printf("Error opening input file!\n");
        return;
    }

    //Get the height and width of the image
    int height, width;
    fseek(fp, 18, SEEK_SET); // Move pointer to 18th byte for height and width
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Calculate the total number of pixels
    int total_pixels = height * width;

    //Allocate memory to store the pixels
    Pixel* pixels = malloc(sizeof(Pixel) * total_pixels);

    //Read the pixel values
    fseek(fp, 54, SEEK_SET); // Move pointer to pixel data
    for(int i=0; i<total_pixels; i++)
    {
        fread(&pixels[i].blue, 1, 1, fp);
        fread(&pixels[i].green, 1, 1, fp);
        fread(&pixels[i].red, 1, 1, fp);
    }

    //Close the input file
    fclose(fp);

    //Create an array to store frequency of each pixel
    Freq_Pixel* freq_pixels = malloc(sizeof(Freq_Pixel) * total_pixels);

    //Initialize the frequencies to zero
    for(int i=0; i<total_pixels; i++)
    {
        freq_pixels[i].freq = 0;
        freq_pixels[i].pixel = pixels[i];
    }

    //Count the frequency of each pixel
    for(int i=0; i<total_pixels; i++)
    {
        freq_pixels[i].freq = 1;
        for(int j=i+1; j<total_pixels; j++)
        {
            if(freq_pixels[i].pixel.red == pixels[j].red && freq_pixels[i].pixel.green == pixels[j].green && freq_pixels[i].pixel.blue == pixels[j].blue)
            {
                freq_pixels[i].freq++;
                //Set the frequency of this pixel to zero, so that it is not counted again
                pixels[j].red = 0;
                pixels[j].green = 0;
                pixels[j].blue = 0;
            }
        }
    }

    //Sort the array in decreasing order of frequency
    qsort(freq_pixels, total_pixels, sizeof(Freq_Pixel), compare);

    //Create an array to store the compressed pixel values
    Pixel* compressed_pixels = malloc(sizeof(Pixel) * total_pixels);

    //Store the most frequent pixels first
    for(int i=0; i<total_pixels; i++)
    {
        compressed_pixels[i] = freq_pixels[i].pixel;
    }

    //Open the output file
    fp = fopen(output_file, "wb");
    if(fp == NULL)
    {
        printf("Error opening output file!\n");
        return;
    }

    //Write the header of the BMP file
    fseek(fp, 0, SEEK_SET);
    unsigned char header[54] = {0x42, 0x4D, 36 + 3*total_pixels, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 54, 0x0, 0x0, 0x0, 40, 0x0, 0x0, 0x0, width, width >> 8, width >> 16, width >> 24, height, height >> 8, height >> 16, height >> 24, 0x01, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 12, 0x0, 0x13, 0x0, 0x0, 0x0, 0x13, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    fwrite(header, sizeof(unsigned char), 54, fp);

    //Write the compressed pixel values
    fseek(fp, 54, SEEK_SET);
    for(int i=0; i<total_pixels; i++)
    {
        fwrite(&compressed_pixels[i].blue, 1, 1, fp);
        fwrite(&compressed_pixels[i].green, 1, 1, fp);
        fwrite(&compressed_pixels[i].red, 1, 1, fp);
    }

    //Close the output file
    fclose(fp);

    //Free memory
    free(pixels);
    free(freq_pixels);
    free(compressed_pixels);

    printf("Image compressed successfully!\n");
}

int main()
{
    char* input_file = "input.bmp";
    char* output_file = "output.bmp";

    compress_image(input_file, output_file);

    return 0;
}