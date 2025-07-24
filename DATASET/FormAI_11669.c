//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scientific
#include <stdio.h>
#include <string.h>

void morseCodeConverter(char* morseCode[], char* text) {
    // Morse code table for alphabets and numbers
    char* morseTable[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                          ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                          ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
                          "-----", ".----", "..---", "...--", "....-", ".....", "-....", 
                          "--...", "---..", "----." };
	
    int len = strlen(text);
    int i, j, index;
    char ch;

    for (i = 0; i < len; i++) {
        index = -1;
        ch = text[i];

        // Morse code for alphabets
        if (ch >= 'A' && ch <= 'Z') {
            index = ch - 'A';
        }

        // Morse code for numbers
        if (ch >= '0' && ch <= '9') {
            index = ch - '0' + 26;
        }

        // If character is a space
        if (ch == ' ') {
            printf("    ");
        }

        // If character is valid
        if (index != -1) {
            printf("%s ", morseTable[index]);
        }
    }
}

int main() {
    char* morseCode[100] = { '\0' };
    char* text = "HELLO WORLD";
    
    printf("Text : %s\n", text);
    printf("Morse Code : ");
    morseCodeConverter(morseCode, text);
    
    return 0;
}