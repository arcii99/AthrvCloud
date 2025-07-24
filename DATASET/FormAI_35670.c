//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* hexToRgb(char*);
char* rgbToHex(char*);

int main() {
    char input[10];
    printf("Enter HEX or RGB color code: ");
    scanf("%s", input);

    char* result;
    if (input[0] == '#') {
        result = hexToRgb(input);
        printf("RGB code: %s", result);
    } else {
        result = rgbToHex(input);
        printf("HEX code: %s", result);
    }

    free(result);
    return 0;
}

char* hexToRgb(char* input) {
    char* output = malloc(sizeof(char) * 15);
    char hex[7];
    strncpy(hex, input + 1, 6);
    hex[6] = '\0';

    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    sprintf(output, "%d,%d,%d", r, g, b);
    return output;
}

char* rgbToHex(char* input) {
    char* output = malloc(sizeof(char) * 8);
    int r, g, b;
    sscanf(input, "%d,%d,%d", &r, &g, &b);
    sprintf(output, "#%02x%02x%02x", r, g, b);
    return output;
}