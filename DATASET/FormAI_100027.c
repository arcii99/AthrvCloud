//FormAI DATASET v1.0 Category: Image Editor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 150
#define HEIGHT 150

void grayscale(unsigned char* img)
{
    int i;
    for(i = 0; i < WIDTH * HEIGHT; i++) {
        unsigned char r, g, b, gray;
        r = *(img + i * 3);
        g = *(img + i * 3 + 1);
        b = *(img + i * 3 + 2);
        gray = (r + g + b) / 3;
        *(img + i * 3) = gray;
        *(img + i * 3 + 1) = gray;
        *(img + i * 3 + 2) = gray;
    }
}

void flipHorizontally(unsigned char* img)
{
    int x, y;
    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH / 2; x++) {
            unsigned char* pixel1 = img + (y * WIDTH + x) * 3;
            unsigned char* pixel2 = img + (y * WIDTH + (WIDTH - x - 1)) * 3;
            unsigned char tempR = *pixel1, tempG = *(pixel1 + 1), tempB = *(pixel1 + 2);
            *pixel1 = *pixel2;
            *(pixel1 + 1) = *(pixel2 + 1);
            *(pixel1 + 2) = *(pixel2 + 2);
            *pixel2 = tempR;
            *(pixel2 + 1) = tempG;
            *(pixel2 + 2) = tempB;
        }
    }
}

void flipVertically(unsigned char* img)
{
    int x, y;
    for(y = 0; y < HEIGHT / 2; y++) {
        for(x = 0; x < WIDTH; x++) {
            unsigned char* pixel1 = img + (y * WIDTH + x) * 3;
            unsigned char* pixel2 = img + ((HEIGHT - y - 1) * WIDTH + x) * 3;
            unsigned char tempR = *pixel1, tempG = *(pixel1 + 1), tempB = *(pixel1 + 2);
            *pixel1 = *pixel2;
            *(pixel1 + 1) = *(pixel2 + 1);
            *(pixel1 + 2) = *(pixel2 + 2);
            *pixel2 = tempR;
            *(pixel2 + 1) = tempG;
            *(pixel2 + 2) = tempB;
        }
    }
}

int main()
{
    FILE *inFile, *outFile;
    unsigned char buffer[WIDTH * HEIGHT * 3];
    
    // Read the input file
    inFile = fopen("input.img", "rb");
    if(inFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    fread(buffer, sizeof(unsigned char), WIDTH * HEIGHT * 3, inFile);
    fclose(inFile);
    
    // Apply the transformations
    grayscale(buffer);
    flipHorizontally(buffer);
    flipVertically(buffer);
    
    // Write the output file
    outFile = fopen("output.img", "wb");
    if(outFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    fwrite(buffer, sizeof(unsigned char), WIDTH * HEIGHT * 3, outFile);
    fclose(outFile);
    
    printf("Image processing complete.\n");
    return 0;
}