//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int length, i, j;
    char *morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
                        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char output[1000];

    printf("Enter text to convert to Morse code: ");
    fgets(input, 100, stdin);
    length = strlen(input);

    for(i = 0; i < length; i++) {
        if(input[i] == ' ') {
            strcat(output, "/ ");
        } else if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
            if(input[i] >= 'a' && input[i] <= 'z') {
                input[i] -= 32;
            }

            strcat(output, morse[input[i] - 'A']);
            strcat(output, " ");
        }
    }

    printf("Morse code: %s\n", output);

    return 0;
}