//FormAI DATASET v1.0 Category: Color Code Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

char* convert_color_to_code(char* color) {
    char* code = malloc(sizeof(char) * 7);
    if (color == "red") {
        strncpy(code, "#FF0000", 7);
    } else if (color == "green") {
        strncpy(code, "#00FF00", 7);
    } else if (color == "blue") {
        strncpy(code, "#0000FF", 7);
    } else {
        printf("Invalid color!\n");
        return "";
    }
    return code;
}

int main() {
    char color[10];
    printf("Please enter a color (red, green, or blue): ");
    scanf("%s", color);
    char* code = convert_color_to_code(color);
    if (code) {
        printf("%s\n", code);
        free(code);
    }
    return 0;
}