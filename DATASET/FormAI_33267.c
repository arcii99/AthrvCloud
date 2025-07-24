//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main() {
    char tx[1000];
    printf("Enter text to convert to ASCII art: ");
    scanf("%[^\n]", tx);
    for(int i = 0; i < strlen(tx); i++) {
        if(tx[i] == ' ') { // space
            printf("\n\n\n"); // leave 3 blank lines
            continue;
        }
        if(tx[i] >= 'a' && tx[i] <= 'z') { // lowercase alphabet
            for(int j = 0; j < tx[i]-'a'+1; j++) {
                printf("#"); // print '#' for each letter
            }
            printf("\n\n"); // leave 2 blank lines
        }
        else if(tx[i] >= 'A' && tx[i] <= 'Z') { // uppercase alphabet
            for(int j = 0; j < tx[i]-'A'+1; j++) {
                printf("#"); // print '#' for each letter
            }
            printf("\n\n"); // leave 2 blank lines
        }
        else if(tx[i] >= '0' && tx[i] <= '9') { // digits
            for(int j = 0; j < tx[i]-'0'+1; j++) {
                printf("*"); // print '*' for each digit
            }
            printf("\n\n"); // leave 2 blank lines
        }
        else { // other characters
            printf("\n\n\n"); // leave 3 blank lines
        }
    }
    return 0;
}