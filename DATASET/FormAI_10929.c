//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

void print_ASCII_art(char str[MAX_SIZE], int height, int width) {
    int len = strlen(str);
    int index = 0;
    int row, col, i;

    for(row = 0; row < height; row++) {
        for(col = 0; col < width && index < len; col++) {
            printf("%c", str[index]);
            index++;
        }
        printf("\n");
    }
}

int main() {
    char text[MAX_SIZE];
    int height, width;

    printf("Enter your text: ");
    scanf("%[^\n]s", text);

    printf("\nEnter height of ASCII art: ");
    scanf("%d", &height);

    printf("\nEnter width of ASCII art: ");
    scanf("%d", &width);

    printf("\nGenerated ASCII art:\n\n");
    print_ASCII_art(text, height, width);

    return 0;
}