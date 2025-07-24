//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 500
#define MAX_HEIGHT 500

//Character array to store ASCII art characters
const char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

void convert_to_ascii(char* filename){
    FILE* fp = fopen(filename, "rb"); //open the file in binary mode
    if(fp == NULL){
        printf("Unable to open file\n");
        exit(EXIT_FAILURE);
    }
    unsigned char image[MAX_HEIGHT][MAX_WIDTH]; //2D array to store image data
    char ascii_image[MAX_HEIGHT][MAX_WIDTH]; //2D array to store ASCII image
    int height = 0, width = 0;
    fread(&image, sizeof(unsigned char), MAX_HEIGHT * MAX_WIDTH, fp); //read in the image data
    fclose(fp); //close the file
    //Find the height and width of the image
    for(int i=0 ; i<MAX_HEIGHT ; i++){
        for(int j=0 ; j<MAX_WIDTH ; j++){
            if(image[i][j] != 0){
                height = i;
                break;
            }
        }
    }
    for(int j=0 ; j<MAX_WIDTH ; j++){
        for(int i=0 ; i<MAX_HEIGHT ; i++){
            if(image[i][j] != 0){
                width = j;
                break;
            }
        }
    }
    //Normalize the image data
    for(int i=0 ; i<=height ; i++){
        for(int j=0 ; j<=width ; j++){
            int pixel_value = image[i][j] / 25;
            ascii_image[i][j] = ascii_chars[pixel_value]; //Map the pixel value to an ASCII character
        }
    }
    //Print the ASCII art to the console
    for(int i=0 ; i<=height ; i++){
        for(int j=0 ; j<=width ; j++){
            printf("%c", ascii_image[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv){
    if(argc != 2){
        printf("Usage: ./ascii <input-file>\n");
        exit(EXIT_FAILURE);
    }
    char* filename = argv[1];
    convert_to_ascii(filename);
    return 0;
}