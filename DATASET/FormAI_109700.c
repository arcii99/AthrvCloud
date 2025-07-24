//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char morse_code[36][8] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                          ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                          ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", 
                          "--..", ".----", "..---", "...--", "....-", ".....", 
                          "-....", "--...", "---..", "----.", "-----"};
                          
char *text_to_morse(char *text);
/*The function text_to_morse() takes a string as input and returns the Morse code equivalent of the string.*/

char *get_morse(char c);
/*The function get_morse() takes a character as input and returns its Morse code equivalent.*/

int main() {
    char text[100];
    printf("Enter Text (A-Z, 0-9): ");
    fgets(text, 100, stdin);
    printf("Morse Code:\n");
    printf("%s", text_to_morse(text));
    return 0;
}

char *text_to_morse(char *text) {
    int i, j;
    static char result[200];
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char c = toupper(text[i]);
            char *code = get_morse(c);
            strcat(result, code);
            strcat(result, " ");
        }
        else if (isdigit(text[i])) {
            char *code = get_morse(text[i]);
            strcat(result, code);
            strcat(result, " ");
        }
        else if (text[i] == ' ') {
            strcat(result, "/ ");
        }
    }
    return result;
}

char *get_morse(char c) {
    if(isdigit(c)){
        return morse_code[c - '0' + 26];
    }
    if(isalpha(c)){
        return morse_code[c - 'A'];
    }
    return "";
}