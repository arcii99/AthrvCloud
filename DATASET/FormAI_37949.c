//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};
char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

char* morse_conversion(char ch) {
    int i;
    for (i = 0; toupper(ch) != letters[i]; i++) {
        if (i == 26) { // if the letter is not present in letters[], return invalid
            return "?";
        }
    }
    return morse_code[i];
}

int main(void) {
    char input[256];
    printf("Enter a string: ");
    scanf("%[^\n]", input);
    getchar(); // consume the newline character
    
    int size = strlen(input);
    printf("\nMorse code conversion:\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", morse_conversion(input[i]));
    }
    printf("\n");
    
    return 0;
}