//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Cryptic
#include<stdio.h>
#include<string.h>

// Converts color codes in the form of RRGGBBAA to RGBA
int main(){
    char hex[8];
    int hex_values[4];

    printf("Enter a hex color code (RRGGBBAA): ");
    scanf("%s", hex);

    // Converting hex code to RGB values
    for(int i = 0; i < 8; i += 2){
        // Converting hex values to decimal
        if(hex[i] >= '0' && hex[i] <= '9') 
            hex_values[i/2] = hex[i] - '0';
        else if(hex[i] >= 'A' && hex[i] <= 'F')
            hex_values[i/2] = hex[i] - 'A' + 10;
        else if(hex[i] >= 'a' && hex[i] <= 'f')
            hex_values[i/2] = hex[i] - 'a' + 10;
    }

    // Outputting RGBA values
    printf("RGBA values: (%d,%d,%d,%d)\n", hex_values[0], hex_values[1], hex_values[2], hex_values[3]);

    return 0;
}