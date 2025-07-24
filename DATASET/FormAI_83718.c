//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char morse[36][10] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
    "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    "...-", ".--", "-..-", "-.--", "--..", "-----",
    ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----."
};

const char alphabet[36] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

void convert_to_morse(char* message, char* morse_code) {
    int j = 0;
    for(int i=0; message[i] != '\0'; i++) {
        if(message[i] == ' ') {
            strcat(morse_code, " ");
            j++;
        } else {
            int index;
            if(message[i] >= 'a' && message[i] <= 'z') {
                index = message[i] - 'a';
            } else if (message[i] >= '0' && message[i] <= '9') {
                index = message[i] - '0' + 26;
            } else {
                continue;
            }
            strcat(morse_code, morse[index]);
            j++;
        }
    }
}

int main() {

    char message[100], morse_code[400];
    morse_code[0] = '\0';

    printf("Enter your message to convert to Morse code: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0;

    convert_to_morse(message, morse_code);

    printf("Your Morse code message is: ");
    for(int i = 0; morse_code[i] != '\0'; i++) {
        if(morse_code[i] == '.') {
            printf(".");
            usleep(200000);
        } else if (morse_code[i] == '-') {
            printf("-");
            usleep(600000);
        } else {
            printf(" ");
            usleep(400000);
        }
    }

    return 0;
}