//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize ASCII characters
    char* ascii_chars = " .`-^\",:;Il!i><~+_-?][}{1)(/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    int num_chars = strlen(ascii_chars);
    
    // Set the dimensions of the ASCII art
    int width = 50, height = 25;
    
    // Allocate memory for the ASCII art array
    char** ascii_art = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        ascii_art[i] = malloc(width * sizeof(char));
    }
    
    // Read in user input
    char input[256];
    printf("Enter some text: ");
    fgets(input, 256, stdin);
    
    // Convert user input to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Calculate the ASCII character index
            int char_index = (int)(input[(i * width + j) % strlen(input)]) % num_chars;
            
            // Set the corresponding ASCII character in the array
            ascii_art[i][j] = ascii_chars[char_index];
        }
    }
    
    // Print out the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
    
    // Deallocate memory for the ASCII art array
    for (int i = 0; i < height; i++) {
        free(ascii_art[i]);
    }
    free(ascii_art);
    
    return 0;
}