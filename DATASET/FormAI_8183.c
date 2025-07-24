//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main(void) {
    char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char morse[27][7] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
                         ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
                         ".--", "-..-", "-.--", "--..", " "};
    char input[MAX_LENGTH];
    int i, j, k;
    
    printf("Enter a string to convert to Morse code: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    
    printf("Morse code translation: \n");
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            printf(" ");
        } else {
            for (j = 0; j < 26; j++) {
                if (toupper(input[i]) == alphabet[j]) {
                    for (k = 0; k < strlen(morse[j]); k++) {
                        printf("%c", morse[j][k]);
                    }
                    printf(" ");
                    break;
                }
            }
        }
    }
    printf("\n");
    return 0;
}