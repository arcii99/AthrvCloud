//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scientific
#include <stdio.h>
#include <string.h>

int main() {
    char input[100], output[1000];
    int i, j;
    
    printf("Enter text to convert to Morse code: ");
    fgets(input, sizeof(input), stdin);
    
    char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "/", ".-.-.-", "--..--", "..--..", "-.-.--"};
    char *letters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", " ", ".", ",", "?"};
    
    for(i=0; i<strlen(input); i++) {
        for(j=0; j<sizeof(letters)/sizeof(letters[0]); j++) {
            if(input[i] == letters[j][0]) {
                strcat(output, morse_code[j]);
                strcat(output, " ");
                break;
            }
        }
    }
    
    printf("Morse code: %s\n", output);
    
    return 0;
}