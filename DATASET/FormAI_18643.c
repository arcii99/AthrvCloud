//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: future-proof
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 1000
#define MORSE_TABLE_SIZE 36

const char* morse_code_table[MORSE_TABLE_SIZE] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----" 
};

void convert_text_to_morse(const char* input, char* output) {
    size_t i, j, k;
    size_t len = strlen(input);
    for (i = 0, k = 0; i < len; ++i) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            j = c - 'a';
        } else if (c >= 'A' && c <= 'Z') {
            j = c - 'A';
        } else if (c >= '0' && c <= '9') {
            j = c - '0' + 26;
        } else {
            continue;
        }
        const char* morse = morse_code_table[j];
        while (*morse) {
            output[k++] = *morse++;
        }
        output[k++] = ' ';
    }
    output[k] = '\0';
}

int main() {
    char input[MAX_STR_LEN], output[MAX_STR_LEN * 5];
    
    printf("Enter a string to convert to Morse code:\n");
    fgets(input, MAX_STR_LEN, stdin);
    input[strcspn(input, "\n")] = 0;
    
    convert_text_to_morse(input, output);
    
    printf("Morse code: %s\n", output);
    
    return 0;
}