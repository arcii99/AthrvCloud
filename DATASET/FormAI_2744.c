//FormAI DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include<stdio.h> //standard input/output library
#include<string.h> //string library to manipulate strings
#include<stdlib.h> //standard library for memory allocation
#include<ctype.h> //character handling library

int main(){
    char colorCode[8];
    printf("Enter the color code (RGB format): # ");
    scanf("%s", colorCode);
    int len = strlen(colorCode);
    if(len == 7){
        int i;
        for(i=1;i<len;i++){
            colorCode[i-1] = colorCode[i];
        }
        colorCode[i-1] = '\0';
    }  //gets the HEX code from the input

    int r,g,b;
    sscanf(colorCode,"%02x%02x%02x", &r, &g, &b); //sscanf function to convert HEX to RGB values using format specifiers
    printf("\nRGB values:\nR: %d\nG: %d\nB: %d\n", r,g,b);
    
    //Converting RGB to CMYK
    float red = (float)(r/255.0);
    float green = (float)(g/255.0);
    float blue = (float)(b/255.0);
    float k = 1 - fmaxf(fmaxf(red, green), blue); //formula to find K value for CMYK
    
    if(k == 1){ //exceptional case for black color
        printf("\nThis color is BLACK.");
        return 0;
    }
    
    float c = (1-red-k)/(1-k); //formula to find C value for CMYK
    float m = (1-green-k)/(1-k); //formula to find M value for CMYK
    float y = (1-blue-k)/(1-k); //formula to find Y value for CMYK

    printf("\nCMYK values:\nC: %.3f\nM: %.3f\nY: %.3f\nK: %.3f\n",c,m,y,k); //printing the CMYK values
    
    return 0;
}