//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include<stdio.h>

int main(){

    FILE *input, *output;
    char ch, pixel;

    //Open the input and output files
    input = fopen("image.bmp", "rb");
    output = fopen("ascii-art.txt", "w");

    //Error handling if files not opened properly
    if(input == NULL || output == NULL){
        printf("Error opening files...");
        return 0;
    }

    //skip header of bmp file
    fseek(input, 54, SEEK_SET);

    int row, column, gray, ascii;
    for(row = 0; row < 480; row++){
        for(column = 0; column < 640; column++){
            pixel = fgetc(input);
            gray = (int)pixel;

            //Convert pixel value to ASCII
            if(gray < 51) ascii = 35; //darkest
            else if(gray < 102) ascii = 111;
            else if(gray < 153) ascii = 45;
            else if(gray < 204) ascii = 46;
            else if(gray < 255) ascii = 32; //lightest

            //Write the ASCII character to file
            fputc(ascii, output);
        }
        fputc('\n', output); //end of row
    }

    //Close the files
    fclose(input);
    fclose(output);

    return 0;
}