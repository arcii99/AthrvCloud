//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Global variables
char map[15][15];
int rows = 15, cols = 15;
int pacman_x, pacman_y;
int total_coins = 0, coins_collected = 0;
int game_over = 0;

// Function to print the game map
void printMap() {
    printf("\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

// Function to move Pac-Man
void movePacman(int x, int y) {
    if(map[x][y] == '.') {
        coins_collected++;
        map[x][y] = ' ';
    } else if(map[x][y] == 'G') {
        game_over = 1;
    }
    map[pacman_x][pacman_y] = ' ';
    map[x][y] = 'P';
    pacman_x = x;
    pacman_y = y;
}

// Main function
int main() {
    // Initialize the map
    srand(time(NULL));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                map[i][j] = '#';
            } else if(rand() % 100 > 70) {
                map[i][j] = '.';
                total_coins++;
            } else {
                map[i][j] = ' ';
            }
        }
    }
    map[1][1] = 'P';
    pacman_x = 1;
    pacman_y = 1;
    map[rows - 2][cols - 2] = 'G';

    // Start the game loop
    while(!game_over) {
        system("clear");    // Clear the screen
        printMap();         // Print the map
        printf("\nCoins collected: %d/%d\n", coins_collected, total_coins);
        printf("Use arrow keys to move Pac-Man\n");

        // Get user input
        char input = getchar();
        while(input == '\n') {
            input = getchar();
        }

        // Move Pac-Man according to user input
        switch(input) {
            case 'w':
                if(map[pacman_x-1][pacman_y] != '#') {
                    movePacman(pacman_x-1, pacman_y);
                }
                break;
            case 's':
                if(map[pacman_x+1][pacman_y] != '#') {
                    movePacman(pacman_x+1, pacman_y);
                }
                break;
            case 'a':
                if(map[pacman_x][pacman_y-1] != '#') {
                    movePacman(pacman_x, pacman_y-1);
                }
                break;
            case 'd':
                if(map[pacman_x][pacman_y+1] != '#') {
                    movePacman(pacman_x, pacman_y+1);
                }
                break;
        }

        // Check if Pac-Man has collected all the coins
        if(coins_collected == total_coins) {
            printf("Congratulations! You have won the game!\n");
            game_over = 1;
        }
    }

    return 0;
}