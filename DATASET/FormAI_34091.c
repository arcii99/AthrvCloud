//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {

    // Declare the variables
    char input[1000];
    char output[1000] = "";
    char morseCode[36][6] = {
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."},
        {".----"}, {"..---"}, {"...--"}, {"....-"}, {"....."}, {"-...."}, {"--..."}, {"---.."}, {"----."}, {"-----"}
    };

    // Get the input from the user
    printf("Enter the text you want to convert to Morse code: ");
    fgets(input, 1000, stdin);

    // Loop through each character in the input
    for(int i = 0; i < strlen(input); i++) {

        // If the character is a space, add a slash to the output
        if(input[i] == ' ') {
            strcat(output, "/");
        }
        else {
            // Convert the character to Morse code and add it to the output
            int index = (int)toupper(input[i]) - 65;
            strcat(output, morseCode[index]);
            strcat(output, " ");
        }
          
    }

    // Print out the Morse code
    printf("\nThe Morse code for \"%s\" is:\n%s", input, output);

    return 0;
}