//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: standalone
#include <stdio.h>

// Function to generate ASCII art for given text
void generateAsciiArt(char text[]) {
    int i, j, index = 0;
    int asciiChar[7][7] = {
        {0, 0, 219, 219, 219, 0, 0},
        {0, 219, 0, 0, 0, 219, 0},
        {219, 0, 219, 0, 219, 0, 219},
        {219, 0, 0, 0, 0, 0, 219},
        {219, 0, 219, 219, 219, 0, 219},
        {219, 0, 0, 0, 0, 0, 219},
        {0, 219, 0, 0, 0, 219, 0}
    };
    for(i = 0; i < 7; i++) {
        for(j = 0; j < strlen(text); j++) {
            index = (int)text[j];
            if(index < 65 || index > 122)
                index = 63;
            else if(index >= 91 && index <= 96)
                index = 63;
            else
                index -= 65;
            int k;
            for(k = 0; k < 7; k++) {
                if(asciiChar[k][index] == 0)
                    printf(" ");
                else
                    printf("%c", (char)asciiChar[k][index]);
            }
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    char text[100];
    printf("Enter any text: ");
    scanf("%[^\n]", text);
    generateAsciiArt(text);
    return 0;
}