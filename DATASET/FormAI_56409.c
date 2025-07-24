//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void text_to_morse(char [], char []);

int main() {
    char text[MAX_SIZE];
    char morse[MAX_SIZE];

    printf("Enter text to convert to Morse code:\n");
    fgets(text, MAX_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0'; // remove trailing newline character

    text_to_morse(text, morse);
    
    printf("\nMorse code: %s\n", morse);
    return 0;
}

void text_to_morse(char text[], char morse[]) {
    const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                                "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                                "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                                "-.--", "--..", "/", ".----", "..---", "...--", "....-",
                                ".....", "-....", "--...", "---..", "----.", "-----"};

    for(int i = 0, j = 0; i < strlen(text); i++) {
        if(isalpha(text[i])) {
            char c = tolower(text[i]);
            morse[j++] = morse_code[c-'a'][0];
            morse[j++] = morse_code[c-'a'][1];
            morse[j++] = morse_code[c-'a'][2];
        } else if(isdigit(text[i])) {
            morse[j++] = morse_code[text[i]-'0'+25][0];
            morse[j++] = morse_code[text[i]-'0'+25][1];
            morse[j++] = morse_code[text[i]-'0'+25][2];
        } else if(text[i] == ' ') {
            morse[j++] = '/';
        }
    }
    morse[strlen(morse)] = '\0';
}