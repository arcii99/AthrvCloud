//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

//function to convert RGB to Hexadecimal Color Code
char* rgb_to_hex(int r, int g, int b){
    char *hex_code = malloc(sizeof(char)*7);   //allocate memory for hex code (RRGGBB)
    sprintf(hex_code, "#%02X%02X%02X", r, g, b);   //sprintf formats and stores string in the hex_code variable
    return hex_code;  //returns the hexadecimal code
}

//function to convert Hexadecimal Color Code to RGB
void hex_to_rgb(char* hex, int *r, int *g, int *b){
    sscanf(hex, "#%02x%02x%02x", r, g, b);  //sscanf reads hex and converts it into rgb values
}

//main function
int main(){

    int choice, r, g, b;
    char hex_code[7];

    //menu to select conversion type
    printf("Select Conversion Type:\n");
    printf("1. RGB to Hexadecimal\n");
    printf("2. Hexadecimal to RGB\n");
    scanf("%d", &choice);

    switch(choice){

        case 1:
            printf("Enter RGB values (0-255) for R, G, B respectively:\n"); //input RGB values
            scanf("%d %d %d", &r, &g, &b);

            //validate RGB values
            if(r<0 || r>255 || g<0 || g>255 || b<0 || b>255){
                printf("\nInvalid RGB values! \nExiting Program...");
                exit(0);
            }
            else{
                printf("\nRGB to Hexadecimal Conversion:\n");
                printf("RGB (%d,%d,%d) = %s", r, g, b, rgb_to_hex(r, g, b)); //calling rgb_to_hex function
            }
            break;

        case 2:
            printf("Enter Hexadecimal Color Code (RRGGBB):\n"); //input hex code
            scanf("%s", hex_code);

            //validate hex code
            if(hex_code[0] != '#' || strlen(hex_code) != 7){
                printf("\nInvalid Hexadecimal Code! \nExiting Program...");
                exit(0);
            }
            else{
                printf("\nHexadecimal to RGB Conversion:\n");
                hex_to_rgb(hex_code, &r, &g, &b); //calling hex_to_rgb function
                printf("Hex Code %s = RGB (%d,%d,%d)", hex_code, r, g, b);
            }
            break;

        default: 
            printf("\nInvalid Choice! \nExiting Program...");
            exit(0);
    }

    return 0;
}