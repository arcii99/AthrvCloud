//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>

// Define game constants
#define MAX_ROW 10
#define MAX_COL 10
#define MAX_ENEMIES 10
#define MAX_HEALTH 100
#define MAX_ENEMY_HEALTH 50
#define MAX_ENEMY_ATTACK 20
#define MAX_PLAYER_ATTACK 30

// Initialize player and enemy coordinate structs
typedef struct {
    int x;
    int y;
} Coordinate;

// Player struct
typedef struct {
    Coordinate position;
    int health;
} Player;

// Enemy struct
typedef struct {
    Coordinate position;
    int health;
} Enemy;

// Global game variables
char gameBoard[MAX_ROW][MAX_COL];    // Used to store game board
Player player;                      // Player instance
Enemy enemyList[MAX_ENEMIES];       // List of enemy instances
int enemyCount;                     // Number of enemies on the board
bool gameOver = false;              // Game over flag

// Function declarations
void clearBoard();
void initializePlayer();
void initializeEnemies();
void updateBoard();
void printBoard();
void moveEnemies();
void attackPlayer();
void attackEnemy();

// Signal handling functions
void sigintHandler(int signal) {
    printf("\nInterrupt signal received. Exiting game...\n");
    gameOver = true;
}

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize game
    clearBoard();
    initializePlayer();
    initializeEnemies();
    printBoard();
    
    // Install signal handler
    signal(SIGINT, sigintHandler);
    
    // Game loop
    while (!gameOver) {
        // Move all enemy instances
        moveEnemies();
        
        // Print updated game board
        updateBoard();
        printBoard();
        
        // Check if player is attacked
        attackPlayer();
        
        // Check if enemy is attacked
        attackEnemy();
        
        // Sleep for a short time
        usleep(100000);
    }
    
    // Exit program
    return 0;
}

// Clear game board
void clearBoard() {
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++) {
            gameBoard[i][j] = '.';
        }
    }
}

// Initialize player
void initializePlayer() {
    player.position.x = rand() % MAX_ROW;
    player.position.y = rand() % MAX_COL;
    player.health = MAX_HEALTH;
    
    // Place player on board
    gameBoard[player.position.x][player.position.y] = '@';
}

// Initialize enemies
void initializeEnemies() {
    enemyCount = rand() % MAX_ENEMIES;
    int i;
    for (i = 0; i < enemyCount; i++) {
        enemyList[i].position.x = rand() % MAX_ROW;
        enemyList[i].position.y = rand() % MAX_COL;
        enemyList[i].health = MAX_ENEMY_HEALTH;
        
        // Place enemy on board
        gameBoard[enemyList[i].position.x][enemyList[i].position.y] = 'E';
    }
}

// Update game board
void updateBoard() {
    int i, j;
    clearBoard();
    
    // Place player on board
    gameBoard[player.position.x][player.position.y] = '@';
    
    // Place enemies on board
    for (i = 0; i < enemyCount; i++) {
        gameBoard[enemyList[i].position.x][enemyList[i].position.y] = 'E';
    }
}

// Print game board
void printBoard() {
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++) {
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
    printf("Player health: %d\n", player.health);
}

// Move enemies
void moveEnemies() {
    int i;
    for (i = 0; i < enemyCount; i++) {
        int direction = rand() % 4;    // Randomly select a direction to move in
        
        // Move enemy in selected direction
        if (direction == 0 && enemyList[i].position.x > 0) {
            enemyList[i].position.x--;
        } else if (direction == 1 && enemyList[i].position.y < MAX_COL - 1) {
            enemyList[i].position.y++;
        } else if (direction == 2 && enemyList[i].position.x < MAX_ROW - 1) {
            enemyList[i].position.x++;
        } else if (direction == 3 && enemyList[i].position.y > 0) {
            enemyList[i].position.y--;
        }
    }
}

// Attack player
void attackPlayer() {
    int i;
    for (i = 0; i < enemyCount; i++) {
        // Check if enemy and player are in the same location
        if (enemyList[i].position.x == player.position.x && enemyList[i].position.y == player.position.y) {
            int damage = rand() % MAX_ENEMY_ATTACK + 1;    // Calculate attack damage
            player.health -= damage;    // Reduce player health
            printf("Player is attacked by enemy %d for %d damage. ", i+1, damage);
            
            // Check if player is dead
            if (player.health <= 0) {
                printf("Player is dead. Game over!\n");
                gameOver = true;
            }
        }
    }
}

// Attack enemy
void attackEnemy() {
    int i;
    for (i = 0; i < enemyCount; i++) {
        // Check if player and enemy are in adjacent positions
        if ((enemyList[i].position.x == player.position.x - 1 && enemyList[i].position.y == player.position.y) ||
            (enemyList[i].position.x == player.position.x && enemyList[i].position.y == player.position.y + 1) ||
            (enemyList[i].position.x == player.position.x + 1 && enemyList[i].position.y == player.position.y) ||
            (enemyList[i].position.x == player.position.x && enemyList[i].position.y == player.position.y - 1)) {
            int damage = rand() % MAX_PLAYER_ATTACK + 1;    // Calculate attack damage
            enemyList[i].health -= damage;    // Reduce enemy health
            
            // Remove enemy from board if it is dead
            if (enemyList[i].health <= 0) {
                printf("Enemy %d is killed.\n", i+1);
                gameBoard[enemyList[i].position.x][enemyList[i].position.y] = '.';
                enemyList[i] = enemyList[enemyCount-1];
                enemyCount--;
            }
        }
    }
}