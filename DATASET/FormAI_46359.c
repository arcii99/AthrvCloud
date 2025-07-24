//FormAI DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>

// function to convert RGB to HEX
void RGBtoHEX(int r, int g, int b){
    printf("#%02X%02X%02X", r, g, b);
}

// function to convert HEX to RGB
void HEXtoRGB(char hex[]){
    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    printf("R = %d G = %d B = %d\n", r, g, b);
}

int main(){
    int choice;
    printf("COLOR CODE CONVERTER\n\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1){
        int r, g, b;
        printf("Enter RGB values (0-255):\n");
        printf("R = ");
        scanf("%d", &r);
        printf("G = ");
        scanf("%d", &g);
        printf("B = ");
        scanf("%d", &b);
        RGBtoHEX(r, g, b);
    }
    else if(choice == 2){
        char hex[7];
        printf("Enter HEX value (including # symbol): ");
        scanf("%s", hex);
        HEXtoRGB(hex);
    }
    else{
        printf("Invalid choice!");
    }
    return 0;
}