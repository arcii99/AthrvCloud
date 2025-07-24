//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: visionary
#include <stdio.h>
#include <string.h>

// Define Morse Code table using arrays
char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
char *alpha[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

void textToMorse(char *text)
{
    int i, j;
    char c;
    for (i = 0; i < strlen(text); i++) {
        // Convert to uppercase
        c = toupper(text[i]);
        // Match character to Morse Code table
        for (j = 0; j < 36; j++) {
            if (c == alpha[j][0]) {
                printf("%s ", morseCode[j]);
                break;
            }
        }
        // If character not in Morse Code table, ignore
    }
    printf("\n");
}

int main()
{
    char text[100];
    printf("Enter Text: ");
    scanf("%[^\n]s", text);
    printf("Morse Code: ");
    textToMorse(text);
    return 0;
}