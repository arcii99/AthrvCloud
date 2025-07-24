//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: safe
#include <stdio.h>
#include <string.h>

/* Function to convert text to Morse Code */
void text2morse(char text[], int length) {
    /* Morse Code mapping table */
    char *morse_codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};
    char *letters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "};

    for (int i = 0; i < length; i++) {
        char *current_char = &text[i];
        char *morse_code = NULL;

        /* Find the Morse Code for the current char */
        for (int j = 0; j < 27; j++) {
            if (strcmp(current_char, letters[j]) == 0) {
                morse_code = morse_codes[j];
                break;
            }
        }

        if (morse_code != NULL) {
            /* Print the Morse Code for the current char */
            printf("%s ", morse_code);
        }
    }
}

int main() {
    /* Input text */
    char text[100];

    printf("Enter the text to be converted to Morse Code: ");
    gets(text);

    /* Convert text to Morse Code */
    text2morse(text, strlen(text));

    return 0;
}