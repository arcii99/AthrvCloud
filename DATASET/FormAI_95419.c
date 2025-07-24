//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of moves the player can make
#define MAX_MOVES 10

// Define a struct for the player s information
typedef struct {
    char name[20];
    int health;
    int fuel;
    int score;
} Player;

// Define a struct for the alien
typedef struct {
    int row;
    int col;
} Alien;

// Define the function for generating a random number between min and max
int generateRandom(int min, int max) {
    int randNum = (rand() % (max - min + 1)) + min;
    return randNum;
}

// Define the function for printing the game board
void printBoard(char board[][10], int playerRow, int playerCol, int alienRow, int alienCol) {
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf(" %d ", i);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("___");
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("|");
        for (int j = 0; j < 10; j++) {
            if (i == playerRow && j == playerCol) {
                printf("P|");
            } else if (i == alienRow && j == alienCol) {
                printf("A|");
            } else {
                printf("%c|", board[i][j]);
            }
        }
        printf(" %d", i);
        printf("\n");
        for (int k = 0; k < 10; k++) {
            printf("___");
        }
        printf("\n");
    }
}

// Define a function for determining if the player is dead
int isPlayerDead(Player *player) {
    if (player->health <= 0 || player->fuel <= 0) {
        return 1;
    } else {
        return 0;
    }
}

// Define a function for determining if the player has won
int hasPlayerWon(Player *player) {
    if (player->score >= 100) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL)); // Seed the random generator

    // Initialize the game board with empty cells
    char board[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = ' ';
        }
    }

    // Initialize the player
    Player player;
    printf("Enter your name: ");
    scanf("%s", player.name);
    player.health = 100;
    player.fuel = 100;
    player.score = 0;
    int playerRow = generateRandom(0, 9);
    int playerCol = generateRandom(0, 9);
    board[playerRow][playerCol] = 'P';

    // Initialize the alien
    Alien alien;
    alien.row = generateRandom(0, 9);
    alien.col = generateRandom(0, 9);
    board[alien.row][alien.col] = 'A';

    // Print the initial game board
    printBoard(board, playerRow, playerCol, alien.row, alien.col);

    // Start the game loop
    int movesLeft = MAX_MOVES;
    int gameOver = 0;
    while (!gameOver) {
        // Get the player's move
        printf("Moves left: %d\n", movesLeft);
        printf("Enter your move (w - up, s - down, a - left, d - right): ");
        char move;
        scanf(" %c", &move);

        // Update the player's position
        int newRow = playerRow;
        int newCol = playerCol;
        if (move == 'w' && playerRow > 0) {
            newRow--;
        } else if (move == 's' && playerRow < 9) {
            newRow++;
        } else if (move == 'a' && playerCol > 0) {
            newCol--;
        } else if (move == 'd' && playerCol < 9) {
            newCol++;
        }
        if (newRow != playerRow || newCol != playerCol) {
            movesLeft--;
            if (board[newRow][newCol] == ' ') {
                board[playerRow][playerCol] = ' ';
                playerRow = newRow;
                playerCol = newCol;
                board[playerRow][playerCol] = 'P';
            } else if (board[newRow][newCol] == 'A') {
                player.score += 10;
                board[playerRow][playerCol] = ' ';
                playerRow = newRow;
                playerCol = newCol;
                board[playerRow][playerCol] = 'P';
                alien.row = generateRandom(0, 9);
                alien.col = generateRandom(0, 9);
                board[alien.row][alien.col] = 'A';
            }
        }

        // Update the player's health and fuel
        if (playerRow == alien.row && playerCol == alien.col) {
            player.health -= 20;
            player.fuel -= 10;
        } else {
            player.fuel--;
        }

        // Check if the game is over
        if (isPlayerDead(&player)) {
            printf("Game over! You died!\n");
            gameOver = 1;
        } else if (hasPlayerWon(&player)) {
            printf("Congratulations! You won!\n");
            gameOver = 1;
        } else if (movesLeft == 0) {
            printf("Game over! You ran out of moves!\n");
            gameOver = 1;
        }

        // Print the game board after each move
        printBoard(board, playerRow, playerCol, alien.row, alien.col);
    }

    return 0;
}