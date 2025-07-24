//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define WIDTH 80
#define HEIGHT 24

char chars[] = {' ', '.', '*', ':', 'o', '&', '8', '#', '@'};

void draw(char *text) {
    int i, j, k, c;
    int l = strlen(text);
    int lines = l / WIDTH + 1;
    char art[HEIGHT][WIDTH];
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            art[i][j] = ' ';
        }
    }
    k = 0;
    for(i = 0; i < lines; i++) {
        for(j = 0; j < WIDTH; j++) {
            if(k == l) {
                break;
            }
            if(isprint(text[k])) {
                art[i][j] = text[k];
            } else {
                art[i][j] = ' ';
            }
            k++;
        }
        if(k == l) {
            break;
        }
    }
    printf("\n\n");
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            c = art[i][j] % 9;
            printf("\033[1;33m%c\033[0m", chars[c]);
        }
        printf("\n");
    }
}

int main() {
    char text[1000];
    printf("Enter some text:\n");
    fgets(text, 1000, stdin);
    draw(text);
    return 0;
}