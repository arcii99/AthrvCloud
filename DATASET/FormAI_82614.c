//FormAI DATASET v1.0 Category: Color Code Converter ; Style: thoughtful
#include <stdio.h>

// function to convert RGB value to hex code string
void rgbToHex(int R, int G, int B){
    char hex[7]; // hex code string to hold output
    sprintf(hex, "#%02X%02X%02X", R, G, B); // format output as hex code
    printf("Hex Code: %s\n", hex); // print the hex code
}

// function to convert hex code string to RGB values
void hexToRgb(char hex[]){
    int R, G, B; // RGB values to hold output
    sscanf(hex, "#%02X%02X%02X", &R, &G, &B); // scan and convert hex input
    printf("R: %d G: %d B: %d\n", R, G, B); // print the RGB values
}

// main function
int main(){
    int choice;
    printf("Choose an option:\n");
    printf("1. Convert RGB to Hex\n");
    printf("2. Convert Hex to RGB\n");
    scanf("%d", &choice); // read user choice

    int R, G, B;
    char hex[7];
    switch(choice){
        case 1:
            printf("Enter RGB values (separated by spaces): ");
            scanf("%d %d %d", &R, &G, &B);
            rgbToHex(R, G, B);
            break;
        case 2:
            printf("Enter Hex code (without #): ");
            scanf("%s", hex);
            hexToRgb(hex);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}