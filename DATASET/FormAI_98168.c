//FormAI DATASET v1.0 Category: Color Code Converter ; Style: excited
#include<stdio.h>
#include<string.h>

int main(){
    char colorCode[8];
    int r, g, b;
    
    printf("Welcome to the Color Code Converter!\n");
    printf("Enter a 6 digit hexadecimal color code (e.g. FF00FF): ");
    scanf("%s", colorCode);
    
    if(strlen(colorCode) != 6){
        printf("Invalid color code entered.\n");
        return 0;
    }
    
    r = (int)strtol(colorCode, NULL, 16) >> 16 & 0xFF; //Extracting red component
    g = (int)strtol(colorCode, NULL, 16) >> 8 & 0xFF; //Extracting green component
    b = (int)strtol(colorCode, NULL, 16) & 0xFF; // Extracting blue component
    
    printf("RGB Components for color code %s:\n", colorCode);
    printf("Red: %d\n", r);
    printf("Green: %d\n", g);
    printf("Blue: %d\n", b);
    
    printf("We have successfully converted the color code to RGB format. Hurray!\n");
    
    return 0;
}