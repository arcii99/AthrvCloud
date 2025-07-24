//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Morse Code Lookup Table
char *morse_lookup(int index) {
    char *morse_table[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
        "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
        ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
    };
    return morse_table[index];
}

// Morse Code Conversion
char* convert_morse(char *str) {
    int i, j;
    char *morse_code = "";
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            morse_code = strcat(morse_code, "/");
            continue;
        }
        char ch = tolower(str[i]);
        if (ch < 97 || ch > 122) {
            continue;
        }
        j = (int)ch - 97;
        morse_code = strcat(morse_code, morse_lookup(j));
        morse_code = strcat(morse_code, " ");
    }
    strcat(morse_code, "\0");
    return morse_code;
}

int main() {
    char input[100];
    printf("Enter Text to Convert to Morse Code:\n");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character from input
    printf("\nText: %s", input);
    printf("Morse Code: %s", convert_morse(input));
    return 0;
}