//FormAI DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() {
    char hex[7]; //declare a char array to store hexadecimal color code
    printf("Enter a hexadecimal color code in the format RRGGBB (e.g. FF0000 for red):\n");
    scanf("%s", hex); //take user input and store it in hex array

    int r = strtol(hex, NULL, 16) >> 16; //convert the first two hex digits to decimal for red component
    int g = strtol(hex+2, NULL, 16) >> 8; //convert the next two hex digits to decimal for green component
    int b = strtol(hex+4, NULL, 16); //convert the last two hex digits to decimal for blue component

    printf("The RGB color code is: %d,%d,%d\n", r,g,b); //print the RGB color code
    
    return 0; //exit the program
}