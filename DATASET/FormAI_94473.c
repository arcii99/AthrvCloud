//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {
    char text[50];
    printf("Enter the text to be converted to ASCII art: ");
    fgets(text, sizeof(text), stdin);
    // remove newline character from the end of the input string
    text[strlen(text)-1] = '\0';

    int i, j, k;

    for(i = 0; i < strlen(text); i++) {
        printf("  ");
        for(j = 0; j < 4; j++) {
            for(k = 0; k < 8; k++) {
                if(text[i] >= 'A' && text[i] <= 'Z') {
                    printf("%c ", (text[i] - 'A' + 65) & (1 << (k+j*8)) ? 'X' : ' ');
                }
                else if(text[i] >= 'a' && text[i] <= 'z') {
                    printf("%c ", (text[i] - 'a' + 97) & (1 << (k+j*8)) ? 'X' : ' ');
                }
                else if(text[i] >= '0' && text[i] <= '9') {
                    printf("%c ", (text[i] - '0') & (1 << (k+j*8)) ? 'X' : ' ');
                }
                else {
                    printf("  ");
                }
            }
            printf("\n  ");
        }
        printf("\n");
    }

    return 0;
}