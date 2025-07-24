//FormAI DATASET v1.0 Category: Browser Plugin ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

/* The following code generates a custom browser plugin with a unique graphical design */

int main() {
    // Initializing variables
    char name[20], color[10], shape[10];
    int num_sides, length;

    // Getting user input
    printf("Enter plugin name (up to 20 characters): ");
    scanf("%s", name);
    printf("Enter color (red, green, blue, yellow, purple, or orange): ");
    scanf("%s", color);
    printf("Enter number of sides (3-10): ");
    scanf("%d", &num_sides);
    printf("Enter length of each side (in pixels): ");
    scanf("%d", &length);

    // Generating plugin code
    printf("<object width=\"100\" height=\"100\" type=\"application/x-%s-plugin\">\n", name);
    printf("<param name=\"color\" value=\"%s\">\n", color);
    printf("<param name=\"num_sides\" value=\"%d\">\n", num_sides);
    printf("<param name=\"length\" value=\"%d\">\n", length);
    printf("</object>");

    // Displaying graphical representation
    printf("\n\n");
    for (int i = 0; i < num_sides; i++) {
        printf(" ");
        for (int j = 0; j < length; j++) {
            printf("%s", color);
        }
        printf("\n");
    }

    // Ending program
    return 0;
}