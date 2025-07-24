//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>

/* This function converts the RGB values of a pixel to its corresponding grayscale value using the formula: 
   grayscale = 0.2989*red + 0.5870*green + 0.1140*blue */
int grayscale_value(int R, int G, int B){
    float grayscale = 0.2989*R + 0.5870*G + 0.1140*B;
    return (int) grayscale;
}

/* This function converts the grayscale value to the corresponding ASCII character using the following mapping:
   0-25: '#' (darkest shade)
   26-50: '&'
   51-75: '$'
   76-100: '*'
   101-125: '!'
   126-150: ':'
   151-175: ';'
   176-200: '-'
   201-225: '.'
   226-255: ' ' (lightest shade) */
char grayscale_to_ASCII(int grayscale){
    if(grayscale >= 0 && grayscale <= 25){
        return '#';
    }
    else if(grayscale >= 26 && grayscale <= 50){
        return '&';
    }
    else if(grayscale >= 51 && grayscale <= 75){
        return '$';
    }
    else if(grayscale >= 76 && grayscale <= 100){
        return '*';
    }
    else if(grayscale >= 101 && grayscale <= 125){
        return '!';
    }
    else if(grayscale >= 126 && grayscale <= 150){
        return ':';
    }
    else if(grayscale >= 151 && grayscale <= 175){
        return ';';
    }
    else if(grayscale >= 176 && grayscale <= 200){
        return '-';
    }
    else if(grayscale >= 201 && grayscale <= 225){
        return '.';
    }
    else{
        return ' ';
    }
}

/* This is the main function that reads in a ppm image file (in binary format), converts it to ASCII art, and prints the result to stdout */
int main(){
    // Open the ppm image file (replace "input.ppm" with the actual file name)
    FILE *input_file = fopen("input.ppm", "rb");
    if(!input_file){
        fprintf(stderr, "Error: Could not open input file.\n");
        return 1;
    }
    
    // Read the header of the ppm image file
    char header[3];
    fscanf(input_file, "%s\n", header);
    if(header[0] != 'P' && header[1] != '6'){
        fprintf(stderr, "Error: Invalid ppm image format.\n");
        return 1;
    }
    int width, height, max_val;
    fscanf(input_file, "%d %d\n%d\n", &width, &height, &max_val);
    
    // Allocate memory for an array of pixels (each pixel is represented by 3 bytes - R, G, B)
    unsigned char *pixels = (unsigned char*) malloc(width*height*3);
    if(!pixels){
        fprintf(stderr, "Error: Could not allocate memory for pixels.\n");
        return 1;
    }
    
    // Read in the pixels of the ppm image file
    int num_pixels_read = fread(pixels, sizeof(unsigned char), width*height*3, input_file);
    if(num_pixels_read != width*height*3){
        fprintf(stderr, "Error: Could not read pixels from input file.\n");
        return 1;
    }
    fclose(input_file);
    
    // Convert RGB pixels to ASCII characters
    char *ASCII_pixels = (char*) malloc(width*height);
    if(!ASCII_pixels){
        fprintf(stderr, "Error: Could not allocate memory for ASCII pixels.\n");
        return 1;
    }
    int index = 0;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            int R = pixels[index++];
            int G = pixels[index++];
            int B = pixels[index++];
            int grayscale = grayscale_value(R, G, B);
            ASCII_pixels[i*width+j] = grayscale_to_ASCII(grayscale);
        }
    }
    
    // Print the ASCII art to stdout
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%c", ASCII_pixels[i*width+j]);
        }
        printf("\n");
    }
    
    // Free allocated memory
    free(pixels);
    free(ASCII_pixels);
    
    return 0;
}