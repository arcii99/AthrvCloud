//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include<stdio.h>
#include<stdlib.h>

#define MAX_WIDTH 60
#define MAX_HEIGHT 60
#define ASCII_SCALE 60

char ascii_arr[MAX_HEIGHT][MAX_WIDTH];

void initialize_ascii_arr(){
    int i, j;
    for(i=0;i<MAX_HEIGHT;i++){
        for(j=0;j<MAX_WIDTH;j++){
            ascii_arr[i][j] = ' '; //fill with spaces initially
        }
    }
}

void convert_to_ascii(int pixel_arr[MAX_HEIGHT][MAX_WIDTH], int width, int height){
    initialize_ascii_arr();
    int i,j;
    char ascii_chars[ASCII_SCALE] = {' ','.',',',':',';','+','*','?','%','S','#','@'};
    int intensity_scale = 256 / ASCII_SCALE;

    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            int intensity = pixel_arr[i][j]/intensity_scale;
            if(intensity > ASCII_SCALE - 1){
                intensity = ASCII_SCALE - 1;
            }
            ascii_arr[i][j] = ascii_chars[intensity];
        }
    }
}

void print_ascii(int width, int height){
    int i, j;
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            printf("%c", ascii_arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int pixel_arr[MAX_HEIGHT][MAX_WIDTH] = {{10, 20, 40, 50, 100},
                                             {120, 150, 180, 200, 220},
                                             {230, 240, 250, 255, 250},
                                             {200, 180, 150, 100, 50},
                                             {30, 20, 10, 5, 0}}; //fake pixel data

    convert_to_ascii(pixel_arr, MAX_WIDTH, MAX_HEIGHT);
    print_ascii(MAX_WIDTH, MAX_HEIGHT);

    return 0;
}