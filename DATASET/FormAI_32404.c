//FormAI DATASET v1.0 Category: Color Code Converter ; Style: modular
#include<stdio.h>

//Function prototype for RGB to Hex conversion
char* RGB2Hex(int r, int g, int b);

//Function prototype for Hex to RGB conversion
void Hex2RGB(char *hex, int *r, int *g, int *b);

int main(){

    //RGB to Hex conversion demonstration
    int r = 255, g = 165, b = 0;
    char *hex = RGB2Hex(r, g, b);
    printf("RGB color (%d,%d,%d) is %s in Hexadecimal format.\n", r, g, b, hex);

    //Hex to RGB conversion demonstration
    char *hexcode = "FFA500";
    int red, green, blue;
    Hex2RGB(hexcode, &red, &green, &blue);
    printf("Hexadecimal color %s is (%d,%d,%d) in RGB format.\n", hexcode, red, green, blue);

    return 0;
}

//RGB to Hex conversion function body
char* RGB2Hex(int r, int g, int b){

    static char hex[7];
    sprintf(hex, "#%02X%02X%02X", r, g, b);

    return hex;
}

//Hex to RGB conversion function body
void Hex2RGB(char *hex, int *r, int *g, int *b){

    sscanf(hex, "%02X%02X%02X", r, g, b);
}