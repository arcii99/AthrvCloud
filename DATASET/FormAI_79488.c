//FormAI DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>
#include <string.h>

void convert_color_code(char* code);

int main() {
    char color_code[10];
    printf("Enter a color code (#RRGGBB): ");
    scanf("%s", color_code);
    convert_color_code(color_code);
    return 0;
}

void convert_color_code(char* code) {
    char red[3], green[3], blue[3];
    strncpy(red, code+1, 2);
    strncpy(green, code+3, 2);
    strncpy(blue, code+5, 2);
    red[2] = '\0';
    green[2] = '\0';
    blue[2] = '\0';
    printf("RGB color code: (%d, %d, %d)\n", 
            (int) strtol(red, NULL, 16), 
            (int) strtol(green, NULL, 16), 
            (int) strtol(blue, NULL, 16));
}