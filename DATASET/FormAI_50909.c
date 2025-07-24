//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char *alphabets[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

char *numbers[] = {
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

char *char_to_morse(char ch) {
    int char_num = (int) ch;
    if (char_num >= 65 && char_num <= 90) {
        return alphabets[char_num - 65];
    }
    else if (char_num >= 97 && char_num <= 122) {
        return alphabets[char_num - 97];
    }
    else if (char_num >= 48 && char_num <= 57) {
        return numbers[char_num - 48];
    }
    else {
        return "";
    }
}

void convert_to_morse(char *text, char *morse) {
    int length = strlen(text);
    int i, j;
    for (i = 0, j = 0; i < length; i++, j++) {
        if (text[i] == ' ') {
            morse[j] = '/';
            j++;
        }
        else {
            char *morse_char = char_to_morse(text[i]);
            if (strlen(morse_char) > 0) {
                strcpy(&morse[j], morse_char);
                j += strlen(morse_char);
            }
        }
    }
    morse[j] = '\0';
}

int main() {
    char text[MAX_LENGTH];
    char morse[MAX_LENGTH];

    printf("Text: ");
    fgets(text, MAX_LENGTH, stdin);

    convert_to_morse(text, morse);
    printf("Morse code: %s\n", morse);

    return 0;
}