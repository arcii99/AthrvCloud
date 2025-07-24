//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define WIDTH 64
#define HEIGHT 32
#define MAX_PLAYERS 4

char board[WIDTH][HEIGHT];
int playerX[MAX_PLAYERS], playerY[MAX_PLAYERS];
int numPlayers = 0;
char playerIcons[MAX_PLAYERS] = {'1', '2', '3', '4'};

// Function to print the game board
void print_board() {
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random pixel art
void generate_art() {
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            board[i][j] = rand() % 2 == 0 ? '.' : '*';
        }
    }
}

// Function to add a new player
void add_player() {
    if(numPlayers < MAX_PLAYERS) {
        playerX[numPlayers] = rand() % WIDTH;
        playerY[numPlayers] = rand() % HEIGHT;
        board[playerX[numPlayers]][playerY[numPlayers]] = playerIcons[numPlayers];
        numPlayers++;
    }
}

// Function to move a player
void move_player(int i, int direction) {
    int newX = playerX[i];
    int newY = playerY[i];

    switch(direction) {
        case 1: // UP
            if(newY > 0)
                newY--;
            break;
        case 2: // DOWN
            if(newY < HEIGHT-1)
                newY++;
            break;
        case 3: // LEFT
            if(newX > 0)
                newX--;
            break;
        case 4: // RIGHT
            if(newX < WIDTH-1)
                newX++;
            break;
    }

    // Check if the new position is already occupied by another player
    for(int j=0; j<numPlayers; j++) {
        if(j != i && playerX[j] == newX && playerY[j] == newY) {
            return;
        }
    }

    // Move the player to the new position
    board[playerX[i]][playerY[i]] = '.';
    playerX[i] = newX;
    playerY[i] = newY;
    board[playerX[i]][playerY[i]] = playerIcons[i];
}

int main() {
    srand(time(NULL));
    generate_art();
    print_board();
    add_player();
    add_player();
    add_player();
    add_player();

    while(1) {
        printf("Player 1, please enter direction (1=UP, 2=DOWN, 3=LEFT, 4=RIGHT): ");
        int direction;
        scanf("%d", &direction);
        move_player(0, direction);
        print_board();

        printf("Player 2, please enter direction (1=UP, 2=DOWN, 3=LEFT, 4=RIGHT): ");
        scanf("%d", &direction);
        move_player(1, direction);
        print_board();

        printf("Player 3, please enter direction (1=UP, 2=DOWN, 3=LEFT, 4=RIGHT): ");
        scanf("%d", &direction);
        move_player(2, direction);
        print_board();

        printf("Player 4, please enter direction (1=UP, 2=DOWN, 3=LEFT, 4=RIGHT): ");
        scanf("%d", &direction);
        move_player(3, direction);
        print_board();
    }

    return 0;
}