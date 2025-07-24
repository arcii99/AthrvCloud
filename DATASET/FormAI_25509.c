//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char message[100], morse[100], code[26][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int i, j;

    printf("Enter your message to be translated to Morse code: ");
    scanf("%[^\n]%*c", message);

    for (i = 0; i < strlen(message); i++) {
        if (message[i] == ' ') {
            strcat(morse, "   ");
        } else {
            for (j = 0; j < 26; j++) {
                if (message[i] == 'A' + j || message[i] == 'a' + j) {
                    strcat(morse, code[j]);
                }
            }
            strcat(morse, " ");
        }
    }

    printf("\nYour message in Morse code is:\n%s\n", morse);

    return 0;
}