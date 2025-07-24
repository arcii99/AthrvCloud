//FormAI DATASET v1.0 Category: Color Code Converter ; Style: ultraprecise
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* convert_to_hexadecimal(char color[]);
char* convert_to_RGB(char color[]);

int main(void) {
    char color[8];
    printf("Enter the color code: ");
    scanf("%s", color);

    if(strlen(color) != 6) {
        printf("Invalid color code!");
        exit(0);
    }

    char* hex_code = convert_to_hexadecimal(color);
    printf("Hexadecimal code: #%s\n", hex_code);
    free(hex_code);
    
    char* RGB_code = convert_to_RGB(color);
    printf("RGB code: %s\n", RGB_code);
    free(RGB_code);

    return 0;
}

char* convert_to_hexadecimal(char color[]) {
    int hex_value;
    char* hex_code = (char*)malloc(6*sizeof(char));

    for(int i=0; i<3; i++) {
        sscanf(color+2*i, "%2x", &hex_value);
        sprintf(hex_code+2*i, "%02X", hex_value); 
    }

    return hex_code;
}

char* convert_to_RGB(char color[]) {
    int r, g, b;
    char* RGB_code = (char*)malloc(12*sizeof(char));

    sscanf(color, "%2x%2x%2x", &r, &g, &b);
    sprintf(RGB_code, "%d, %d, %d", r, g, b);

    return RGB_code;
}