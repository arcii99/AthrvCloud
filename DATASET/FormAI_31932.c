//FormAI DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* hex_to_rgb(char* hex) {
    char* rgb = malloc(7);
    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    sprintf(rgb, "%d %d %d", r, g, b);
    return rgb;
}

char* rgb_to_hex(char* rgb) {
    char* hex = malloc(7);
    int r, g, b;
    sscanf(rgb, "%d %d %d", &r, &g, &b);
    sprintf(hex, "%02x%02x%02x", r, g, b);
    return hex;
}

int main() {
    char option[10];
    char input[10];
    printf("Welcome to the Color Code Converter!\n");
    printf("Choose an option: \n");
    printf("1. Convert from HEX to RGB\n");
    printf("2. Convert from RGB to HEX\n");
    printf("Option: ");
    fgets(option, 10, stdin);
    option[strlen(option) - 1] = '\0';
    if (strcmp(option, "1") == 0) {
        printf("Enter a HEX code: ");
        fgets(input, 10, stdin);
        input[strlen(input) - 1] = '\0';
        char* rgb = hex_to_rgb(input);
        printf("RGB code: %s\n", rgb);
        free(rgb);
    } else if (strcmp(option, "2") == 0) {
        printf("Enter a RGB code (ex: 255 255 255): ");
        fgets(input, 10, stdin);
        input[strlen(input) - 1] = '\0';
        char* hex = rgb_to_hex(input);
        printf("Hex code: %s\n", hex);
        free(hex);
    } else {
        printf("Invalid option. Exiting...\n");
    }
    return 0;
}