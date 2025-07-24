//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Defining the dimensions of the pixel art
#define WIDTH 20
#define HEIGHT 10

int main(){
    srand(time(0));
    //Defining the color codes
    const char* colors[8] = {"\x1b[31m","\x1b[32m","\x1b[33m","\x1b[34m","\x1b[35m","\x1b[36m","\x1b[37m","\x1b[0m"};
    //Defining the pixel art grid
    char pixelArt[HEIGHT][WIDTH];

    //Creating the pixel art
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            int index = rand()%8; //Choosing a random color
            pixelArt[i][j] = index; //Assigning the color code to the pixel
            printf("%s@\x1b[0m",colors[index]); //Printing the colored character '@'
        }
        printf("\n");
    }

    return 0;
}