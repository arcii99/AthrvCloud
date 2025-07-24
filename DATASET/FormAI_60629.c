//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {

    char text[100];
    char morse[100][10] = {
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, 
        {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, 
        {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, 
        {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, 
        {"-.--"}, {"--.."}, {" "}
    };
    char letters[] = "abcdefghijklmnopqrstuvwxyz ";

    printf("My love, please tell me your message:\n");
    fgets(text, 100, stdin);
    strtok(text, "\n"); // Removes new line character from input

    printf("\nThou speakest in Morse Code:\n");

    for (int i = 0; i < strlen(text); i++) {
        char letter = tolower(text[i]);
        for (int j = 0; j < strlen(letters); j++) {
            if (letter == letters[j]) {
                printf("%s ", morse[j]);
                break;
            }
        }
    }
    printf("\nFarewell, my love!\n");

    return 0;
}