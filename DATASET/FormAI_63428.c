//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define HEIGHT 25
#define WIDTH 80

int map[HEIGHT][WIDTH];
int playerX, playerY;

// Function to generate the map
void generateMap() {
    srand(time(NULL));
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(i == 0 || i == HEIGHT-1 || j == 0 || j == WIDTH-1) map[i][j] = 1; // Surround the map with walls
            else map[i][j] = rand() % 2;
        }
    }
}

// Function to print the map
void printMap() {
    putchar('\n');
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(i == playerY && j == playerX) putchar('@'); // Print the player
            else if(map[i][j] == 1) putchar('#'); // Print walls
            else putchar('.'); // Print floor
        }
        putchar('\n');
    }
}

int main() {
    generateMap();
    playerX = WIDTH/2;
    playerY = HEIGHT/2;
    
    char input = '\0';
    while(input != 'q') {
        printMap();
        scanf(" %c", &input);
        switch(input) {
            case 'w':
                if(map[playerY-1][playerX] == 0) playerY--;
                break;
            case 'a':
                if(map[playerY][playerX-1] == 0) playerX--;
                break;
            case 's':
                if(map[playerY+1][playerX] == 0) playerY++;
                break;
            case 'd':
                if(map[playerY][playerX+1] == 0) playerX++;
                break;
            default:
                break;
        }
    }
    return 0;
}