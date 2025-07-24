//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main()
{
    // Welcome message
    printf("Welcome to the C Color Code Converter!\n\n");

    // Initialize variables
    char color[7]; // Stores the hex color code entered by user
    char r[3], g[3], b[3]; // Stores the rgb values after conversion
    int r_int, g_int, b_int; // Stores the integer value of rgb

    // Loop until user enters valid hex color code
    do {
        // Prompt user to enter hex color code
        printf("Please enter a hex color code (eg: #FFA500): ");
        scanf("%s", color);

        // Check if hex color code is valid
        if (color[0] != '#' || strlen(color) != 7) {
            printf("Invalid hex color code. Please try again.\n");
        }
    } while (color[0] != '#' || strlen(color) != 7);

    // Convert hex color code to rgb values
    sscanf(color, "#%2hhx%2hhx%2hhx", &r_int, &g_int, &b_int);

    // Convert integer values to string
    sprintf(r, "%d", r_int);
    sprintf(g, "%d", g_int);
    sprintf(b, "%d", b_int);

    // Print the converted rgb values
    printf("\nRGB values: %s, %s, %s\n", r, g, b);

    return 0;
}