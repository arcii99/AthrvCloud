//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
#include <stdio.h>
#include <string.h>

void convertTextToMorse(char* text) {
    char *morseCodeList[27] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "
    };

    char morseCode[65535] = "";
    int textLength = strlen(text);

    for (int i = 0; i < textLength; i++) {
        int alphabetIndex = text[i] - 'a';
        if (alphabetIndex < 0) {
            strcat(morseCode, "   ");
        } else {
            strcat(morseCode, morseCodeList[alphabetIndex]);
            strcat(morseCode, " ");
        }
    }

    printf("%s\n", morseCode);
}

int main() {
    char text[65535];
    printf("Enter some text (in lowercase alphabets only):\n");
    scanf("%[^\n]%*c", text);

    convertTextToMorse(text);

    return 0;
}