//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ROWS 512
#define COLS 512

// define a prototype for digital watermarking function
void digitalWatermark(char* img_file, char* msg_file, char* watermarked_img_file);

int main()
{
    char img_file[] = "input_img.bmp";
    char msg_file[] = "hidden_msg.txt";
    char watermarked_img_file[] = "watermarked_img.bmp";

    // call the digital watermarking function to embed message in image
    digitalWatermark(img_file, msg_file, watermarked_img_file);

    return 0;
}

// Function to embed a hidden message in an image using digital watermarking technique
void digitalWatermark(char* img_file, char* msg_file, char* watermarked_img_file)
{
    FILE *img_fp, *msg_fp, *watermarked_img_fp;
    unsigned char img_data[ROWS][COLS], secret_msg[100], copy_img_data[ROWS][COLS];
    int i, j, k, len, bit, count = 0;

    // open the image file in read mode
    img_fp = fopen(img_file,"rb");

    // check if file exists or not
    if(img_fp == NULL)
    {
        printf("Error: Unable to open image file\n");
        exit(0);
    }

    // read the image data from file
    for(i = 0; i<ROWS; i++)
    {
        for(j = 0; j<COLS; j++)
        {
            img_data[i][j] = getc(img_fp);
        }
    }

    // close the image file
    fclose(img_fp);

    // open the message file in read mode
    msg_fp = fopen(msg_file,"r");

    // check if file exists or not
    if(msg_fp == NULL)
    {
        printf("Error: Unable to open message file\n");
        exit(0);
    }

    // read the message from file and store in secret_msg array
    fgets(secret_msg, 100, msg_fp);

    // store the length of the message
    len = strlen(secret_msg);

    // close the message file
    fclose(msg_fp);

    // loop through each bit of the message
    for(i = 0; i<len*8; i++)
    {
        // get the bit from the message
        bit = (secret_msg[i/8] >> (7 - (i % 8))) & 1;

        // embed the bit in the image
        copy_img_data[count / COLS][count % COLS] = img_data[count / COLS][count % COLS] & 0xFE | bit;

        // increment the counter
        count++;
    }

    // copy the remaining image data to the copy_img_data
    for(k = count; k<ROWS*COLS; k++)
    {
        copy_img_data[k / COLS][k % COLS] = img_data[k / COLS][k % COLS];
    }

    // create a new image file to store the watermarked image
    watermarked_img_fp = fopen(watermarked_img_file, "wb");

    // check if file is created or not
    if(watermarked_img_fp == NULL)
    {
        printf("Error: Unable to create watermarked image file\n");
        exit(0);
    }

    // write the header information to the new image file
    for(i = 0; i<54; i++)
    {
        putc(getc(img_fp), watermarked_img_fp);
    }

    // write the watermarked image data to the new image file
    for(i = 0; i<ROWS; i++)
    {
        for(j = 0; j<COLS; j++)
        {
            putc(copy_img_data[i][j], watermarked_img_fp);
        }
    }

    // close the watermarked image file
    fclose(watermarked_img_fp);

    // print the success message
    printf("Success: Digital Watermarking done successfully!!\n");
}