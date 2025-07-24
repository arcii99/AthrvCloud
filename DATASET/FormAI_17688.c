//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000
#define ASCII_WIDTH 80

void print_ascii_art(char* text){
    // Define the ascii art characters
    char ascii_char[] = {'@', 'B', '%', '+', '-', '.', ' '};
    int length = strlen(text);
    int ascii_height = 7;

    // Initialize the ascii art buffer
    char ascii_buffer[MAX_LEN];
    memset(ascii_buffer, ' ', MAX_LEN * sizeof(char));

    // Fill up the ascii buffer
    for(int i = 0; i < length; i++){
        // Get the ascii index
        int ascii_index = text[i] % 7;

        // Calculate the starting index of the ascii character in the buffer
        int start_index = (i * ASCII_WIDTH * ascii_height) + (i * 2);

        // Set the ascii character in the buffer
        for(int j = 0; j < ascii_height; j++){
            ascii_buffer[start_index + (j * ASCII_WIDTH) + j] = ascii_char[ascii_index];
            ascii_buffer[start_index + (j * ASCII_WIDTH) + j + 1] = ascii_char[ascii_index];
        }
    }

    // Print the ascii art
    for(int i = 0; i < ascii_height; i++){
        for(int j = 0; j < length * (ASCII_WIDTH + 2); j++){
            printf("%c", ascii_buffer[(i * length * (ASCII_WIDTH + 2)) + j]);
        }
        printf("\n");
    }
}

int main(){
    char* text = "Hello World!";
    print_ascii_art(text);
    return 0;
}