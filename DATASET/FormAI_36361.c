//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* toMorse(char c) {
    const char* alpha[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
    const char* numeric[] = { "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." };
    if (isalpha(c)) return alpha[toupper(c) - 'A'];
    if (isdigit(c)) return numeric[c - '0'];
    switch (c) {
        case ' ': return "/";
        case '.': return ".-.-.-";
        case ',': return "--..--";
        case '?': return "..--..";
        case '\'': return ".----.";
        case '!': return "-.-.--";
        case '/': return "-..-.";
        case '(': return "-.--.";
        case ')': return "-.--.-";
        case '&': return ".-...";
        case ':': return "---...";
        case ';': return "-.-.-.";
        case '=': return "-...-";
        case '+': return ".-.-.";
        case '-': return "-....-";
        case '_': return "..--.-";
        case '\"': return ".-..-.";
        case '$': return "...-..-";
        case '@': return ".--.-.";
        default: return "";
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s {string to convert}\n", argv[0]);
        return 1;
    }

    char* text = argv[1];
    int len = strlen(text);
    for (int i = 0; i < len; ++i) {
        char* morse = toMorse(text[i]);
        printf("%s ", morse);
    }
    printf("\n");
    return 0;
}