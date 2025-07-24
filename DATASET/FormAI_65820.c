//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char *color_code) {
    if(strcmp(color_code, "Magenta") == 0) {
        printf("Magenta: #FF00FF\n");
    }
    else if(strcmp(color_code, "Turquoise") == 0) {
        printf("Turquoise: #40E0D0\n");
    }
    else if(strcmp(color_code, "Goldenrod") == 0) {
        printf("Goldenrod: #DAA520\n");
    }
    else if(strcmp(color_code, "Chartreuse") == 0) {
        printf("Chartreuse: #7FFF00\n");
    }
    else if(strcmp(color_code, "Lavender") == 0) {
        printf("Lavender: #E6E6FA\n");
    }
    else if(strcmp(color_code, "Periwinkle") == 0) {
        printf("Periwinkle: #CCCCFF\n");
    }
    else if(strcmp(color_code, "Cerulean") == 0) {
        printf("Cerulean: #007BA7\n");
    }
    else if(strcmp(color_code, "Aquamarine") == 0) {
        printf("Aquamarine: #7FFFD4\n");
    }
    else if(strcmp(color_code, "Fuchsia") == 0) {
        printf("Fuchsia: #FF00FF\n");
    }
    else if(strcmp(color_code, "Midnight Blue") == 0) {
        printf("Midnight Blue: #191970\n");
    }
    else {
        printf("That color is not recognized...are you sure this isn't a dream?\n");
    }
}

int main() {
    char color[50];
    printf("Welcome to the Surrealist Color Code Converter!\n");
    printf("Please enter a color: \n");
    scanf("%s", color);
    convert(color);
    return 0;
}