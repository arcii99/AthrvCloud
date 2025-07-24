//FormAI DATASET v1.0 Category: Color Code Converter ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
    char input_color[10], output_color[10];
    printf("Enter the input color code: ");
    scanf("%s", input_color);
    printf("\n");

    if (strcmp(input_color, "00FF00") == 0) {
        strcpy(output_color, "008000");
    } else if (strcmp(input_color, "FF0000") == 0) {
        strcpy(output_color, "800000");
    } else if (strcmp(input_color, "0000FF") == 0) {
        strcpy(output_color, "000080");
    } else if (strcmp(input_color, "FFFF00") == 0) {
        strcpy(output_color, "808000");
    } else if (strcmp(input_color, "FF00FF") == 0) {
        strcpy(output_color, "800080");
    } else if (strcmp(input_color, "00FFFF") == 0) {
        strcpy(output_color, "008080");
    } else {
        printf("Invalid input color code.\n");
        return 0;
    }

    printf("The output color code is: %s\n", output_color);

    return 0;
}