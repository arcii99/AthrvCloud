//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: secure
#include <stdio.h>
#include <string.h>

// A function to convert text to morse code
void toMorseCode(char input[]) {
    int i, j;
    char morseCode[36][6] = { // contains morse code for alphabets and digits
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, // A to G
        {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, // H to N
        {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, // O to U
        {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {"-----"}, {".----"}, // V to 1
        {"..---"}, {"...--"}, {"....-"}, {"....."}, {"-...."}, {"--..."} // 2 to 7
    };
    
    printf("Morse code of \"%s\" is:\n", input);
    
    for(i=0; i<strlen(input); i++) {
        if (isalpha(input[i])) { // check if the input is an alphabet
            printf("%s ", morseCode[toupper(input[i]) - 65]);
        }
        else if (isdigit(input[i])) { // check if the input is a digit
            printf("%s ", morseCode[input[i] - 22]);
        }
        else if (input[i] == ' ') { // print space
            printf("/ ");
        }
    }
}

int main() {
    char input[100];
    printf("Enter some text to convert to Morse code:\n");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // remove trailing newline character
    toMorseCode(input);
    return 0;
}