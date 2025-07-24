//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: creative
#include<stdio.h>
#include<string.h>

// function to convert characters to Morse code
void char_to_morse(char message[], char morse_code[]) {
    int i, j;
    char morse[][6] = {{".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {"/"}};
    // convert each letter to corresponding Morse code and concatenate them to form a message in Morse code
    for(i=0; i<strlen(message); i++) {
        for(j=0; j<26; j++) {
            if(message[i] == ' ') {  // if space, add a slash for visual clarity
                strcat(morse_code, morse[26]);
                break;  // exit inner loop since space found
            }
            if(tolower(message[i]) == 'a'+j) {
                strcat(morse_code, morse[j]);
                strcat(morse_code, " ");  // add space between letters
                break;  // exit inner loop since letter found
            }
        }
    }
}

int main() {
    char message[100], morse_code[500] = "";
    printf("Enter a message: ");
    fgets(message, 100, stdin);
    // call function to convert message to Morse code
    char_to_morse(message, morse_code);
    // print the message in Morse code
    printf("Message in Morse code: %s\n", morse_code);
    return 0;
}