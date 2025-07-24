//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

typedef struct {
    int x;
    int y;
} Point;

void delay(int);
void printBorder();
void printPoint(Point);
void printSpaces(int);
void initializeGrid(char [ROWS][COLS]);
void printGrid(char [ROWS][COLS]);
void clearGrid(char [ROWS][COLS]);
void generateAsteroids(char [ROWS][COLS]);
void moveAsteroids(char [ROWS][COLS]);

int main() {
    srand(time(NULL));
    char grid[ROWS][COLS];
    Point spaceship = {COLS/2, ROWS-2};
    int score = 0;

    initializeGrid(grid);
    clearGrid(grid);

    while(1) {
        printf("\033[0;0H"); // Positions cursor to top left of screen
        printBorder();
        printGrid(grid);
        printBorder();
        printf("\nScore: %d\n", score);

        // Move spaceship
        int input = getchar();
        if(input == 'a' && spaceship.x > 1) {
            spaceship.x--;
        }
        else if(input == 'd' && spaceship.x < COLS-2) {
            spaceship.x++;
        }

        // Generate asteroids
        generateAsteroids(grid);

        // Move asteroids
        moveAsteroids(grid);

        // Check for collision with spaceship
        if(grid[spaceship.y][spaceship.x] == '*') {
            printf("\nGame Over! Final Score: %d\n", score);
            break;
        }

        score++;
        delay(100);
    }

    return 0;
}

void delay(int milliseconds) {
    clock_t start = clock();
    while((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}

void printBorder() {
    printf("+");
    for(int i = 0; i < COLS; i++) {
        printf("-");
    }
    printf("+\n");
}

void printPoint(Point p) {
    printf("(%d,%d)", p.x, p.y);
}

void printSpaces(int numSpaces) {
    for(int i = 0; i < numSpaces; i++) {
        printf(" ");
    }
}

void initializeGrid(char grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
    }
}

void printGrid(char grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        printf("|");
        for(int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("|\n");
    }
}

void clearGrid(char grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
    }
}

void generateAsteroids(char grid[ROWS][COLS]) {
    int numAsteroids = rand() % 5;
    for(int i = 0; i < numAsteroids; i++) {
        int x = rand() % COLS;
        int y = 1;
        grid[y][x] = '*';
    }
}

void moveAsteroids(char grid[ROWS][COLS]) {
    for(int i = ROWS-1; i >= 0; i--) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == '*') {
                grid[i][j] = ' ';
                if(i != ROWS-1) {
                    grid[i+1][j] = '*';
                }
            }
        }
    }
}