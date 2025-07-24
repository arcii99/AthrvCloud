//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: paranoid
#include <stdio.h>
#include <string.h>

int main() {
    char input[100], output[500];
    int i, j, k;
    char morse[27][6] = { {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {"\0"} };
    char alphabet[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    printf("Enter text to be converted to Morse code: ");
    scanf("%[^\n]s", input);

    for(i = 0; i < strlen(input); i++) {
        for(j = 0; j < 26; j++) {
            if(input[i] == alphabet[j]) {
                for(k = 0; k < strlen(morse[j]); k++) {
                    strcat(output, morse[j][k]);
                    strcat(output, " ");
                }
                strcat(output, " ");
            }
        }
    }

    printf("Morse code of the entered text: %s", output);

    return 0;
}