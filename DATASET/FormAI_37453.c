//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: statistical
#include <stdio.h>
#include <string.h>

#define MAX_HEIGHT 10
#define MAX_WIDTH 10

char chars[MAX_HEIGHT][MAX_WIDTH];

void clearChars() {
    for(int i = 0; i < MAX_HEIGHT; i++) {
        for(int j = 0; j < MAX_WIDTH; j++) {
            chars[i][j] = ' ';
        }
    }
}

void printChars() {
    for(int i = 0; i < MAX_HEIGHT; i++) {
        for(int j = 0; j < MAX_WIDTH; j++) {
            printf("%c", chars[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char text[100];
    printf("Enter text to convert to ASCII art:\n");
    scanf("%s", text);
    int text_length = strlen(text);
    
    clearChars();
    
    int char_index = 0;
    for(int i = 0; i < MAX_HEIGHT; i++) {
        for(int j = 0; j < MAX_WIDTH; j++) {
            if(char_index < text_length) {
                chars[i][j] = text[char_index];
                char_index++;
            }
        }
    }
    
    printChars();
    
    return 0;
}