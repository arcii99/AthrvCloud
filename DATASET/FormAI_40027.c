//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <string.h>

void convertToMorse(char code[26][5], char message[]) {     // function to convert text to Morse code
    int i, j;
    printf("Morse Code: ");
    for(i=0; message[i]!='\0'; i++) {           // loop through the message character by character
        if(message[i] >= 'a' && message[i] <= 'z') {  // check if character is a alphabet
            j = message[i] - 'a';               // get the position of this alphabet in the code array
            printf("%s ", code[j]);             // print the Morse code for this alphabet
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') { // check if character is a capital alphabet
            j = message[i] - 'A';               // get the position of this capital alphabet in the code array
            printf("%s ", code[j]);             // print the Morse code for this capital alphabet
        }
        else if(message[i] == ' ') {            // print Morse code for space
            printf(" ");
        }
        else {
            printf("\nInvalid Character '%c' in message!\n", message[i]); // print error message for invalid characters
            return;
        }
    }
    printf("\n");
}

int main() {
    char code[26][5] = {                          // 2D array to store Morse code for each alphabet
        {".-"}, {"-..."}, {"-.-."}, {"-.."},
        {"."}, {"..-."}, {"--."}, {"...."},
        {".."}, {".---"}, {"-.-"}, {".-.."},
        {"--"}, {"-."}, {"---"}, {".--."},
        {"--.-"}, {".-."}, {"..."}, {"-"},
        {"..-"}, {"...-"}, {".--"}, {"-..-"},
        {"-.--"}, {"--.."}
    };
    char message[100];

    printf("Enter message to convert to Morse Code:\n");
    scanf("%[^\n]", message);                // read message from user

    printf("Text: %s\n", message);
    convertToMorse(code, message);           // call function to convert text to Morse code

    return 0;
}