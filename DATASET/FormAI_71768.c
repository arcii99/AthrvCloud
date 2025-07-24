//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shape shifting
#include <stdio.h>

void fractal(int n, int x, int y, int size);
void changeColors();
void draw(int x, int y, int size);

int main() {
    fractal(5, 250, 250, 200);
    return 0;
}

void fractal(int n, int x, int y, int size) {
    if (n == 0) {
        draw(x, y, size);
    } else {
        changeColors();
        fractal(n-1, x, y, size/2);
        fractal(n-1, x+size/2, y, size/2);
        fractal(n-1, x, y+size/2, size/2);
        fractal(n-1, x+size/2, y+size/2, size/2);
    }
}

void changeColors() {
    static int color = 0;
    switch (color) {
        case 0: 
            printf("\033[31;47m"); // Red on white
            break;
        case 1: 
            printf("\033[32;40m"); // Green on black
            break;
        case 2: 
            printf("\033[33;44m"); // Yellow on blue
            break;
        case 3: 
            printf("\033[34;41m"); // Blue on red
            break;
        case 4: 
            printf("\033[35;42m"); // Magenta on green
            break;
        case 5: 
            printf("\033[36;43m"); // Cyan on yellow
            break;
    }
    color = (color + 1) % 6;
}

void draw(int x, int y, int size) {
    printf("\033[%d;%dH*", y, x); // Set cursor position and print star
    fflush(stdout); // Flush output stream
    usleep(50000); // Pause for 50 milliseconds
}