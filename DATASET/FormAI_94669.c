//FormAI DATASET v1.0 Category: Color Code Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* color_converter(char* hex_color);

int main() {
    char hex_color[7];
    char* rgb_color;
    
    printf("Enter a hex color code: ");
    scanf("%s", hex_color);

    rgb_color = color_converter(hex_color);

    printf("The RGB color code is: %s\n", rgb_color);

    return 0;
}

char* color_converter(char* hex_color) {
    int r = 0, g = 0, b = 0;
    char* rgb_color = (char*)malloc(12);
    char* r_color = (char*)malloc(4);
    char* g_color = (char*)malloc(4);
    char* b_color = (char*)malloc(4);

    sscanf(hex_color, "%02x%02x%02x", &r, &g, &b);

    sprintf(r_color, "%d", r);
    sprintf(g_color, "%d", g);
    sprintf(b_color, "%d", b);

    strcpy(rgb_color, "(");
    strcat(rgb_color, r_color);
    strcat(rgb_color, ",");
    strcat(rgb_color, g_color);
    strcat(rgb_color, ",");
    strcat(rgb_color, b_color);
    strcat(rgb_color, ")");

    free(r_color);
    free(g_color);
    free(b_color);

    return rgb_color;
}