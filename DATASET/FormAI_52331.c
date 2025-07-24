//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_char(char c, int n) {
    for(int i = 0; i < n; i++) {
        putchar(c);
    }
}

void print_art(char* str) {
    const int char_width = 6;
    const int line_height = 4;
    const int padding = 3;
    const int max_width = 80;
    const int max_height = 60;

    int len = strlen(str);
    int art_width = len * (char_width + padding) - padding;
    if(art_width > max_width) {
        printf("Art too wide\n");
        return;
    }

    int lines = (max_height - line_height) / 2;
    for(int i = 0; i < lines; i++) {
        printf("\n");
    }

    int char_index;
    for(int row = 0; row < line_height; row++) {
        for(int i = 0; i < padding; i++) {
            print_char(' ', padding);
        }
        for(int col = 0; col < len; col++) {
            char_index = row * 6 + col * 7;
            if(char_index >= strlen(str)) {
                break;
            }
            for(int i = 0; i < char_width; i++) {
                putchar(str[char_index + i]);
            }
            print_char(' ', padding);
        }
        printf("\n");
    }

    for(int i = 0; i < lines; i++) {
        printf("\n");
    }
}

int main() {
    char str[] = ".########...#######..########..########........##....##..#######...######.....##.....##.########.##.....##.##.......##.....##.##.....##.########..########.";
    print_art(str);

    return 0;
}