//FormAI DATASET v1.0 Category: Color Code Converter ; Style: active
#include<stdio.h>

int main(){
    int option;
    float red, green, blue;
    printf("Welcome to the C Color Code Converter!\n");
    printf("Please select an option:\n");
    printf("1. RGB to HEX\n2. HEX to RGB\n");
    scanf("%d", &option);

    switch(option){
        case 1:
            printf("Enter the RGB values:\n");
            scanf("%f %f %f", &red, &green, &blue);
            printf("The HEX code is: #%02X%02X%02X\n", (int)red, (int)green, (int)blue);
            break;
        
        case 2:
            printf("Enter the HEX code:\n");
            char hex[7];
            scanf("%s", hex);
            int r = (int)strtol(hex, NULL, 16) >> 16;
            int g = (int)strtol(hex+2, NULL, 16) >> 8;
            int b = (int)strtol(hex+4, NULL, 16);
            printf("The RGB values are: %d %d %d\n", r, g, b);
            break;
        
        default:
            printf("Invalid option selected.\n");
    }

    return 0;
}