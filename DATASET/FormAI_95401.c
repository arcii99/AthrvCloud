//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <string.h>

char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " ", "/", NULL};
char *alphabet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " ", "/", NULL};

int main() {
    char input[1000];
    int i, j, k;
    printf("Welcome to the Morse Code converter program! \n");
    printf("Please enter the text you would like to convert to Morse Code: \n");
    fgets(input, 1000, stdin);

    printf("\nYour text in Morse Code is: \n");

    for(i = 0; input[i] != '\0'; i++) {
        for(j = 0; alphabet[j] != NULL; j++) {
            if(input[i] == *alphabet[j]) {
                for(k = 0; morse_code[j][k] != '\0'; k++) {
                    printf("%c", morse_code[j][k]);
                }
                printf(" ");
            }
        }
    }
    printf("\nThank you for using the Morse Code converter program!\n");
    return 0;
}