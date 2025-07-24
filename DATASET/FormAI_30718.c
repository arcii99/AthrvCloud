//FormAI DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* hexToRgb(char* hex);

int main() {
    char input[8];
    printf("Enter a 6 digit hexadecimal color code:\n");
    scanf("%s", input);

    char* rgb = hexToRgb(input);
    printf("The RGB color code is: %s\n", rgb);

    free(rgb);
    return 0;
}

char* hexToRgb(char* hex) {
    char* rgb = malloc(sizeof(char) * 11);
    if (strlen(hex) != 6) {
        strcpy(rgb, "Invalid");
        return rgb;
    }

    int r, g, b;
    sscanf(hex, "%2x%2x%2x", &r, &g, &b);

    sprintf(rgb, "%d, %d, %d", r, g, b);
    return rgb;
}