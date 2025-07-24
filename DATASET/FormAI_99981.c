//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void text_to_morse(char* text) {
    char alphabet[26][3] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    char numbers[10][6] = {
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
    };

    char* morse_code = (char*)malloc(sizeof(char)*200);
    int morse_code_index = 0;

    for(int i=0; i<strlen(text); i++) {
        if(text[i] == ' ') {
            morse_code[morse_code_index++] = ' '; // Single Space for Letter Separation
            continue;
        }

        if(text[i] >= 'a' && text[i] <= 'z') {
            strcat(morse_code, alphabet[text[i] - 'a']);
        } else if(text[i] >= 'A' && text[i] <= 'Z') {
            strcat(morse_code, alphabet[text[i] - 'A']);
        } else if(text[i] >= '0' && text[i] <= '9') {
            strcat(morse_code, numbers[text[i] - '0']);
        }
        strcat(morse_code, " "); // Double Space for Word Separation
    }

    puts("Morse Code: ");
    puts(morse_code);
}

int main() {
    char text[100];

    puts("Enter the text to convert into Morse Code: ");
    scanf("%[^\n]s", text);

    text_to_morse(text);
    return 0;
}