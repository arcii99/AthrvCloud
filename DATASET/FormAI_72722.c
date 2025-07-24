//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: realistic
#include <stdio.h>

int main() {
    
    printf("Enter the text to convert to ASCII art: ");
    char text[50];
    fgets(text, 50, stdin);
    
    int i, j, k;
    for(i=0; i<9; i++) {
        for(j=0; text[j]!='\0'; j++) {
            char c = text[j];
            if(c >= 'A' && c <= 'Z') {
                c += 32;
            }
            if(c >= 'a' && c <= 'z') {
                for(k=0; k<9; k++) {
                    printf("%c ", 2+i*9+k);
                }
            } else if(c == ' ') {
                printf("   ");
            } else {
                printf("???");
            }
        }
        printf("\n");
    }

    return 0;
}