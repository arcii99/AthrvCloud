//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 500
#define MAX_HEIGHT 500

char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

void convert_to_ascii(char* filename){
    FILE* file = fopen(filename, "rb");
    if(file == NULL){
        printf("Error: could not open file %s.\n", filename);
        exit(1);
    }
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;
    fscanf(file, "%d %d", &width, &height);
    for(int i = 0; i < height; i++){
        fread(image[i], sizeof(unsigned char), width, file);
    }
    fclose(file);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int index = (int)((image[i][j]/255.0)*(sizeof(ascii_chars)/sizeof(char)));
            printf("%c", ascii_chars[index]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv){
    if(argc != 2){
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }
    convert_to_ascii(argv[1]);
    return 0;
}