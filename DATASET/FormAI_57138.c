//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

char ASCII_CHARS[] = {' ','.','\'',':','o','&','8','#','@'};
int NUM_CHARS = 9;

void image_to_ascii(char *img_path){

    FILE *fp;
    char buffer[MAX_WIDTH];
    int image[MAX_HEIGHT][MAX_WIDTH];

    fp = fopen(img_path, "r");
    if(fp == NULL){
        printf("Invalid file path.\n");
        exit(1);
    }

    // Read the image
    int row_count = 0;
    int col_count = 0;

    while(fgets(buffer, MAX_WIDTH, fp) != NULL){

        col_count = 0;
        for(int i = 0; i < strlen(buffer); i++){
            if(buffer[i] == '1'){
                image[row_count][col_count] = 1;
            }else if(buffer[i] == '0'){
                image[row_count][col_count] = 0;
            }
            col_count++;
        }

        row_count++;

    }
    fclose(fp);

    // Resize the image
    int width = col_count;
    int height = row_count;
    int new_width = width / 2;
    int new_height = height / 2;

    int new_image[new_height][new_width];

    for(int i = 0; i < new_height; i++){
        for(int j = 0; j < new_width; j++){
            int pixel_sum = 0;
            for(int y = i*2; y < i*2+2; y++){
                for(int x = j*2; x < j*2+2; x++){
                    pixel_sum += image[y][x];
                }
            }
            int avg_pixel = (int) pixel_sum / 4;
            new_image[i][j] = avg_pixel;
        }
    }

    // Convert image to ASCII art
    for(int i = 0; i < new_height; i++){
        for(int j = 0; j < new_width; j++){
            int index = (int) (((float) new_image[i][j] / 255) * (NUM_CHARS - 1));
            printf("%c", ASCII_CHARS[index]);
        }
        printf("\n");
    }

}

int main(){

    char *img_path = "image.txt";
    image_to_ascii(img_path);

    return 0;
}