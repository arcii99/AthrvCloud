//FormAI DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <string.h>

/* Defines a struct type to hold the configuration settings for the ebook reader */
typedef struct {
    char font_family[20];
    int font_size;
    int line_spacing;
    char background_color[20];
    char text_color[20];
} ConfigSettings;

/* Function to load the configuration settings from a file */
ConfigSettings loadConfigSettings(char* filename) {
    ConfigSettings config;

    FILE * file = fopen(filename, "r");
    if (file) {
        fscanf(file, "%s %d %d %s %s", config.font_family, &config.font_size, &config.line_spacing, config.background_color, config.text_color);
        fclose(file);
    }

    return config;
}

int main(int argc, char* argv[]) {
    char* filename = "config.txt";
    ConfigSettings config = loadConfigSettings(filename);

    printf("Font Family: %s\n", config.font_family);
    printf("Font Size: %d\n", config.font_size);
    printf("Line Spacing: %d\n", config.line_spacing);
    printf("Background Color: %s\n", config.background_color);
    printf("Text Color: %s\n", config.text_color);

    return 0;
}