//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: realistic
#include <stdio.h>
#include <string.h>

// Function to convert text to Morse code
void text_to_morse(char text[])
{
    int i, j;
    char morse[37][10] = {
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"},
        {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"},
        {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {"-----"}, {".----"}, {"..---"},
        {"...--"}, {"....-"}, {"....."}, {"-...."}, {"--..."}, {"---.."}, {"----."}
    };
    // Morse code equivalent of space character
    char space[] = "/";

    // Loop through the characters in the text
    for (i = 0; i < strlen(text); i++) {
        // If the character is a space, append a space to the output string
        if (text[i] == ' ') {
            printf("%s ", space);
        }
        else {
            // Otherwise, loop through the Morse code array to find the equivalent
            for (j = 0; j < 37; j++) {
                if (text[i] == j + 'A' || text[i] == j + 'a') {
                    printf("%s ", morse[j]);
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    char input[100];

    printf("Enter a message: ");
    fgets(input, 100, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    printf("Morse code equivalent: ");
    text_to_morse(input);

    return 0;
}