//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: shape shifting
#include <stdio.h>
#include <string.h>

// Declare the Morse code dictionary as a 2D array
const char *morse_dict[][2] = {
    {"A", ".-"}, {"B", "-..."}, {"C", "-.-."}, {"D", "-.."}, {"E", "."},
    {"F", "..-."}, {"G", "--."}, {"H", "...."}, {"I", ".."}, {"J", ".---"},
    {"K", "-.-"}, {"L", ".-.."}, {"M", "--"}, {"N", "-."}, {"O", "---"},
    {"P", ".--."}, {"Q", "--.-"}, {"R", ".-."}, {"S", "..."}, {"T", "-"},
    {"U", "..-"}, {"V", "...-"}, {"W", ".--"}, {"X", "-..-"}, {"Y", "-.--"},
    {"Z", "--.."}, {"0", "-----"}, {"1", ".----"}, {"2", "..---"}, {"3", "...--"},
    {"4", "....-"}, {"5", "....."}, {"6", "-...."}, {"7", "--..."}, {"8", "---.."},
    {"9", "----."}, {" ", " "}
};

// Function to convert a character to its Morse code equivalent
char *char_to_morse(char c) {
    c = toupper(c);
    for(int i = 0; i < 38; i++) {
        if(*morse_dict[i][0] == c) {
            return morse_dict[i][1];
        }
    }
    return "";
}

// Main function to convert text to Morse code
int main() {
    char input[100];
    printf("Enter text to convert to Morse code: ");
    fgets(input, 100, stdin);
    int input_len = strlen(input);
    char output[input_len * 5];
    output[0] = '\0'; // Initialize output to empty string
    for(int i = 0; i < input_len; i++) {
        char* morse_char = char_to_morse(input[i]);
        strcat(output, morse_char);
        strcat(output, " "); // Add space between each Morse code character
    }
    printf("Morse code equivalent: %s\n", output);
    return 0;
}