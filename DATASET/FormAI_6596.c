//FormAI DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include<stdio.h>
#include<math.h>

// Function to convert RGB to Hexadecimal color code
char* rgbToHex(int r, int g, int b){
    char* hexCode = (char*)malloc(sizeof(char)*7);
    sprintf(hexCode, "#%02x%02x%02x", r, g, b);
    return hexCode;
}

// Function to convert Hexadecimal color code to RGB
int* hexToRgb(char* hexCode){
    int* rgbValues = (int*)malloc(sizeof(int)*3);
    sscanf(hexCode, "#%02x%02x%02x", &rgbValues[0], &rgbValues[1], &rgbValues[2]);
    return rgbValues;
}

int main(){

    // RGB to Hexadecimal Color Code Conversion Example
    int red, green, blue;
    printf("Enter the RGB values (0 to 255) separated by space: ");
    scanf("%d %d %d", &red, &green, &blue);
    char* hexCode = rgbToHex(red, green, blue);
    printf("The Hexadecimal Color Code is: %s\n", hexCode);

    // Hexadecimal Color Code to RGB Conversion Example
    char hex[7];
    printf("Enter the Hexadecimal Color Code: ");
    scanf("%s", &hex);
    int* rgbValues = hexToRgb(hex);
    printf("The RGB values are: %d %d %d\n", rgbValues[0], rgbValues[1], rgbValues[2]);

    return 0;
}