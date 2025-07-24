//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>

// function to get a single character from the user
char getch() {
    char c=0;
    struct termios term;
    if(tcgetattr(0, &term)) return -1;
    term.c_lflag &= ~ICANON;
    term.c_lflag &= ~ECHO;
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &term)) return -1;
    while(read(0,&c,1)<1);
    term.c_lflag |= ICANON;
    term.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &term)) return -1;
    return c;
}

// function to clear the terminal screen
void clearScreen() {
    printf("\033[2J\033[1;1H");
}

// function to print the Fibonacci sequence up to a certain term
void printFibonacci(int n) {
    long long int fib1 = 0;
    long long int fib2 = 1;
    long long int fib3 = 1;
    for(int i=0; i<n; i++) {
        printf("%lld ", fib3);
        fib1 = fib2;
        fib2 = fib3;
        fib3 = fib1 + fib2;
    }
}

// function to draw an ASCII art box
void drawBox(int width, int height, int x, int y) {
    printf("\033[%d;%dH+", y, x);
    for(int i=1; i<width; i++) printf("-");
    printf("+");
    for(int i=1; i<height; i++) {
        printf("\033[%d;%dH|", y+i, x);
        printf("\033[%d;%dH|", y+i, x+width);
    }
    printf("\033[%d;%dH+", y+height, x);
    for(int i=1; i<width; i++) printf("-");
    printf("+");
}

int main() {
    clearScreen();
    srand(time(NULL));
    int width = rand() % 50 + 10;
    int height = rand() % 10 + 5;
    int x = rand() % (80-width-1) + 1;
    int y = rand() % (24-height-1) + 1;
    drawBox(width, height, x, y);
    printf("\033[%d;%dHFibonacci Sequence:", y+1, x+1);
    int n = rand() % 10 + 10;
    printf("\033[%d;%dH", y+3, x+1);
    printFibonacci(n);
    printf("\033[%d;%dHPress any key to exit...", y+height+2, x+1);
    getch();
    clearScreen();
    return 0;
}