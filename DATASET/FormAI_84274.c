//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include<stdio.h>

int main(){
    char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    char* file_name = "image.jpg";
    FILE* image_file = fopen(file_name,"rb");
    if(image_file == NULL){
        printf("Failed to open image file.");
        return 1;
    }
    fseek(image_file,0,SEEK_END);
    int file_size = ftell(image_file);
    rewind(image_file);
    unsigned char* image_data = (unsigned char*)malloc(file_size*sizeof(unsigned char));
    fread(image_data,sizeof(unsigned char),file_size,image_file);
    fclose(image_file);

    //Assuming image file is a 128x128 grayscale JPG, containing one byte per pixel
    int width = 128;
    int height = 128;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            unsigned char pixel = image_data[(i*width)+j];
            int ascii_index = (pixel*10)/255;
            printf("%c",ascii_chars[ascii_index]);
        }
        printf("\n");
    }

    free(image_data);
    return 0;
}