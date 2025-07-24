//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert text to morse code
void textToMorse(char* text) {
    char morseCode[36][10] = { {".-"   }, {"-..."}, {"-.-."}, {"-.." }, {"."   }, {"..-."}, {"--." }, {"...."}, {".."  }, {".---"},
                               {"-.-"  }, {".-.."}, {"--"  }, {"-."  }, {"---" }, {".--."}, {"--.-"}, {".-." }, {"..." }, {"-"   },
                               {"..-"  }, {"...-"}, {".--" }, {"-..-"}, {"-.--"}, {"--.."},{".----"}, {"..---"}, {"...--"}, {"....-"},
                               {"....."},{"-...."},{"--..."},{"---.."},{"----."},{".-.-.-"},{"--..--"} };
    char letters[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', ','};

    int len = strlen(text);
    for(int i = 0; i < len; i++) {
        char letter = toupper(text[i]);
        for(int j = 0; j < 36; j++) {
            if(letter == letters[j]) {
                printf("%s ", morseCode[j]);
                break;
            }
        }
    }
    printf("\n");
}

// Function to read input asynchronously
void readInput() {
    char buffer[100];
    printf("Enter text to convert: ");
    while(fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if(buffer[0] == '\n') {
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        textToMorse(buffer);
        printf("Enter text to convert: ");
    }
}

// Main function
int main() {
    printf("Text to Morse Code Converter\n");
    printf("============================\n");
    readInput();
    return 0;
}