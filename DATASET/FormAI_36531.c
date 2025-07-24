//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Define the height and width of the generated ASCII art
#define ART_WIDTH 60
#define ART_HEIGHT 20

// Define the Cyberpunk-inspired character set
const char* CHAR_SET = "  .`'+*|vxt/-_)(}{][%$#@";

// Define the color codes for the Cyberpunk style
#define COLOR_CYAN "\033[36m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_RESET "\033[0m"

// Function to generate ASCII art from a given string
void generate_art(char* text) {
    int length = strlen(text);
    int char_set_size = strlen(CHAR_SET);

    // Calculate the number of columns for the art
    int cols = ART_WIDTH / (length + 1);
    if (cols <= 0) {
        cols = 1;
    }

    // Calculate the number of rows for the art
    int rows = ART_HEIGHT / (cols * 2);
    int actual_cols = (length > cols) ? cols : length;
    int remainder = (cols - actual_cols) / 2;
    
    // Generate the ASCII art
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < actual_cols; c++) {
            int index = (c + remainder) + (r * actual_cols);
            char ch = (index < length) ? text[index] : ' ';
            int color = (index % 4) == 0 ? 1 : 0;
            int char_value = (int)ch % char_set_size;

            printf("%s%c%s", (color == 0) ? COLOR_CYAN : COLOR_YELLOW, CHAR_SET[char_value], COLOR_RESET);
        }
        printf("\n");

        // Print a blank line after every other row
        if ((r % 2) == 1) {
            printf("\n");
        }
    }
}

int main() {
    char text[] = "Cyberpunk ASCII Art Generator";
    generate_art(text);
    return 0;
}