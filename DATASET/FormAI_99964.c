//FormAI DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void hex_to_rgb(char hex[], int *red, int *green, int *blue) {
    // Convert hexadecimal string to RGB values
    sscanf(hex, "%02x%02x%02x", red, green, blue);
}

void rgb_to_hex(int red, int green, int blue, char hex[]) {
    // Convert RGB values to hexadecimal string
    sprintf(hex, "%02x%02x%02x", red, green, blue);
}

int main() {
    // Initialize variables
    char color_code[8];
    int red, green, blue;
    char convert_option;

    // Print welcome message
    printf("Welcome to the Color Code Converter!\n");

    // Loop to allow user to convert multiple color codes
    while (1) {
        // Prompt user for conversion option
        printf("\nEnter 'h' to convert a hexadecimal color code to RGB,\nEnter 'r' to convert RGB values to a hexadecimal color code, or\nEnter 'q' to quit the program: ");
        scanf(" %c", &convert_option);

        // Check if user wants to quit the program
        if (convert_option == 'q') {
            printf("Thank you for using the Color Code Converter. Goodbye!\n");
            break;
        } else if (convert_option == 'h') {
            // User selected option to convert hexadecimal color code to RGB
            printf("\nEnter a hexadecimal color code (e.g. FF00AA): #");
            scanf("%s", color_code);

            // Call function to convert hexadecimal color code to RGB
            hex_to_rgb(color_code, &red, &green, &blue);

            // Print RGB values to user
            printf("\nThe RGB values for color code #%s are: %d, %d, %d\n", color_code, red, green, blue);
        } else if (convert_option == 'r') {
            // User selected option to convert RGB values to hexadecimal color code
            printf("\nEnter the red value (0-255): ");
            scanf("%d", &red);
            printf("Enter the green value (0-255): ");
            scanf("%d", &green);
            printf("Enter the blue value (0-255): ");
            scanf("%d", &blue);

            // Call function to convert RGB values to hexadecimal color code
            char hex[7];
            rgb_to_hex(red, green, blue, hex);

            // Print hexadecimal color code to user
            printf("\nThe hexadecimal color code for RGB values %d, %d, %d is: #%s\n", red, green, blue, hex);
        } else {
            // Invalid conversion option selected
            printf("\nInvalid conversion option. Please try again.\n");
        }
    }

    return 0;
}