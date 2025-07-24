//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1000
#define ASCII_IMAGE_WIDTH 50
#define ASCII_IMAGE_HEIGHT 25

char ASCII_CHARS[] = { ' ', '.', '\'', '`', '^', '"', ',', ':', ';', 'I', 'l', '!', 'i', '>', '<', '~', '+', '_', '-', '?', ']', '[', '}', '{', '1', ')', '(', '|', '\\', '/', 't', 'f', 'j', 'r', 'x', 'n', 'u', 'v', 'c', 'z', 'X', 'Y', 'U', 'J', 'C', 'L', 'Q', '0', 'O', 'Z', 'm', 'w', 'q', 'p', 'd', 'b', 'k', 'h', 'a', 'o', '*', '#', 'M', 'W', '&', '8', '%', 'B', '@', '$' };

int getWidth(), getHeight();
void checkInputSize(int size);
void printImage(char image[][ASCII_IMAGE_WIDTH + 1], int height);
void convertToASCII(char image[][getWidth()], int width, int height, char ASCII_IMAGE[][ASCII_IMAGE_WIDTH+1]);
int getASCII(char image[], int size);

int main(){
    char image[MAX_INPUT_SIZE];
    int width, height;

    printf("Enter the image to be converted to ASCII art:\n");
    fgets(image, MAX_INPUT_SIZE, stdin);

    printf("Enter the width of the image:\n");
    scanf("%d", &width);

    printf("Enter the height of the image:\n");
    scanf("%d", &height);

    checkInputSize(width * height);

    char ASCII_IMAGE[ASCII_IMAGE_HEIGHT][ASCII_IMAGE_WIDTH + 1];
    convertToASCII(image, width, height, ASCII_IMAGE);
    printImage(ASCII_IMAGE, ASCII_IMAGE_HEIGHT);

    return 0;
}

int getWidth(){
    return ASCII_IMAGE_WIDTH;
}

int getHeight(){
    return ASCII_IMAGE_HEIGHT;
}

void checkInputSize(int size){
    if(size > MAX_INPUT_SIZE){
        printf("ERROR: Input size exceeds maximum allowed");
        exit(1);
    }
}

void printImage(char image[][ASCII_IMAGE_WIDTH + 1], int height){
    for(int i = 0; i < height; i++){
        printf("%s\n", image[i]);
    }
}

void convertToASCII(char image[][getWidth()], int width, int height, char ASCII_IMAGE[][ASCII_IMAGE_WIDTH+1]){
    int x = 0;
    int y = 0;

    for(int i = 0; i < (width * height); i++){
        if(x == getWidth()){
            x = 0;
            y++;
        }

        int start = i * 3;
        char rgb[3] = {image[start], image[start + 1], image[start + 2]};
        int grayscaleValue = getASCII(rgb, 3);
        ASCII_IMAGE[y][x] = ASCII_CHARS[grayscaleValue];
        x++;
    }

    for(int i = y + 1; i < getHeight(); i++){
        for(int j = 0; j < getWidth(); j++){
            ASCII_IMAGE[i][j] = ' ';
        }
    }
}

int getASCII(char rgb[], int size){
    int val = 0;
    for(int i = 0; i < size; i++){
        val += rgb[i];
    }

    return (int)(((float)val / 255.0) * 65.0);
}