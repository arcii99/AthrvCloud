//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
#include <stdio.h>
#include <string.h>

char *MORSE_TABLE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

char *ALPHA_TABLE[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
    "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
};

char *morse_code(char message[]) {
    char *result = "";
    int i, j;

    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] == ' ') {
            result = strcat(result, "   ");
        } else {
            for(j = 0; j < 26; j++) {
                if(message[i] == ALPHA_TABLE[j][0]) {
                    result = strcat(result, MORSE_TABLE[j]);
                    result = strcat(result, " ");
                    break;
                }
            }
        }
    }

    return result;
}

int main() {
    char input[100];
    printf("Enter message to convert to Morse Code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    printf("%s", morse_code(input));

    return 0;
}