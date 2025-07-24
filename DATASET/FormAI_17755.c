//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constants */
#define ROWS 5
#define COLUMNS 10
#define ALIEN_ROW_HEIGHT 2
#define PLAYER_ROW ROWS - 1
#define PLAYER_INITIAL_COLUMN COLUMNS / 2
#define SHOOTER_ODDS 3
#define BOMB_DROP_ODDS 5
#define PLAYER_LIVES 3

/* Enumerations */
enum Entity { EMPTY, ALIEN, PLAYER, SHOT, BOMB };

/* Function declarations */
void initBoard(int board[ROWS][COLUMNS]);
void drawBoard(int board[ROWS][COLUMNS], int score, int lives);
int movePlayer(int board[ROWS][COLUMNS], int column);
void moveAliens(int board[ROWS][COLUMNS]);
void moveShot(int board[ROWS][COLUMNS], int* shotRow, int* shotColumn);
void moveBomb(int board[ROWS][COLUMNS], int* bombRow, int* bombColumn);
int fireShot(int board[ROWS][COLUMNS], int playerColumn, int* shotRow, int* shotColumn);
int dropBomb(int board[ROWS][COLUMNS], int* bombRow, int* bombColumn);
int checkCollisions(int board[ROWS][COLUMNS], int* score);
int playGame();

/* Main function */
int main() {
    srand(time(0));
    int playAgain = 1;
    while (playAgain) {
        playGame();
        printf("Do you want to play again? (y/n) ");
        char answer;
        scanf("%c", &answer);
        playAgain = (answer == 'y' || answer == 'Y');
    }
    return 0;
}

/* Initialize the board */
void initBoard(int board[ROWS][COLUMNS]) {
    /* Initialize all cells to EMPTY */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = EMPTY;
        }
    }
    /* Place the player in the middle of the bottom row */
    board[PLAYER_ROW][PLAYER_INITIAL_COLUMN] = PLAYER;
    /* Place the aliens in the top two rows */
    for (int i = 0; i < ALIEN_ROW_HEIGHT * 2; i += 2) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = ALIEN;
        }
    }
}

/* Draw the board */
void drawBoard(int board[ROWS][COLUMNS], int score, int lives) {
    printf("Score: %d\tLives: %d\n", score, lives);
    printf(" ");
    for (int j = 0; j < COLUMNS; j++) {
        printf("__");
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLUMNS; j++) {
            switch (board[i][j]) {
            case EMPTY:
                printf("  ");
                break;
            case ALIEN:
                printf("<>");
                break;
            case PLAYER:
                printf("^^");
                break;
            case SHOT:
                printf("oo");
                break;
            case BOMB:
                printf("**");
                break;
            }
        }
        printf("|\n");
    }
    printf("|");
    for (int j = 0; j < COLUMNS; j++) {
        printf("__");
    }
    printf("|\n");
}

/* Move the player, return 1 if alive, 0 if dead */
int movePlayer(int board[ROWS][COLUMNS], int column) {
    /* Check if the move is legal */
    if (column < 0 || column >= COLUMNS) {
        return 1;
    }
    /* Find the player's current location */
    int oldRow = -1;
    int oldColumn = -1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == PLAYER) {
                oldRow = i;
                oldColumn = j;
                break;
            }
        }
        if (oldRow != -1) {
            break;
        }
    }
    /* Update the board */
    board[oldRow][oldColumn] = EMPTY;
    board[PLAYER_ROW][column] = PLAYER;
    return 1;
}

/* Move the aliens */
void moveAliens(int board[ROWS][COLUMNS]) {
    for (int i = ROWS - 2; i >= 0; i -= 2) {
        /* Check if the row is empty */
        int rowEmpty = 1;
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == ALIEN) {
                rowEmpty = 0;
                break;
            }
        }
        if (rowEmpty) {
            continue;
        }
        /* Determine the direction of movement */
        int moveRight = 1;
        if (board[i][COLUMNS - 1] == ALIEN) {
            moveRight = 0;
        }
        /* Move the row */
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == ALIEN) {
                /* Update the board */
                board[i][j] = EMPTY;
                if (moveRight) {
                    board[i][j + 1] = ALIEN;
                }
                else {
                    board[i][j - 1] = ALIEN;
                }
            }
        }
    }
}

/* Move the shot, return 1 if it is still on the board, 0 if it has gone off */
void moveShot(int board[ROWS][COLUMNS], int* shotRow, int* shotColumn) {
    /* Check if the shot is still on the board */
    if (*shotRow == -1 || *shotColumn == -1) {
        return;
    }
    /* Update the board */
    board[*shotRow][*shotColumn] = EMPTY;
    /* Move the shot */
    (*shotRow)--;
    /* Check if the shot has gone off the board */
    if (*shotRow < 0) {
        return;
    }
    /* Check if the shot has hit an alien */
    if (board[*shotRow][*shotColumn] == ALIEN) {
        board[*shotRow][*shotColumn] = EMPTY;
        *shotRow = -1;
        *shotColumn = -1;
    }
    /* Update the board */
    board[*shotRow][*shotColumn] = SHOT;
}

/* Move the bomb, return 1 if it is still on the board, 0 if it has gone off */
void moveBomb(int board[ROWS][COLUMNS], int* bombRow, int* bombColumn) {
    /* Check if the bomb is still on the board */
    if (*bombRow == -1 || *bombColumn == -1) {
        return;
    }
    /* Update the board */
    board[*bombRow][*bombColumn] = EMPTY;
    /* Move the bomb */
    (*bombRow)++;
    /* Check if the bomb has gone off the board */
    if (*bombRow >= ROWS) {
        return;
    }
    /* Check if the bomb has hit the player */
    if (board[*bombRow][*bombColumn] == PLAYER) {
        *bombRow = -1;
        *bombColumn = -1;
        return;
    }
    /* Update the board */
    board[*bombRow][*bombColumn] = BOMB;
}

/* Fire the player's shot, return 1 if a shot was fired, 0 otherwise */
int fireShot(int board[ROWS][COLUMNS], int playerColumn, int* shotRow, int* shotColumn) {
    /* Generate a random number to determine if the shooter fires */
    int randNum = rand() % SHOOTER_ODDS;
    if (randNum != 0) {
        return 0;
    }
    /* Check if there is already a shot in progress */
    if (*shotRow != -1 || *shotColumn != -1) {
        return 0;
    }
    /* Find the row of the shooter */
    int shooterRow = -1;
    for (int i = 0; i < ROWS; i++) {
        if (board[i][playerColumn] == ALIEN) {
            shooterRow = i;
        }
    }
    /* Check if there is a shooter in the same column as the player */
    if (shooterRow == -1) {
        return 0;
    }
    /* Fire the shot */
    *shotRow = shooterRow;
    *shotColumn = playerColumn;
    board[shooterRow][playerColumn] = SHOT;
    return 1;
}

/* Drop a bomb from one of the aliens, return 1 if a bomb was dropped, 0 otherwise */
int dropBomb(int board[ROWS][COLUMNS], int* bombRow, int* bombColumn) {
    /* Generate a random number to determine if a bomb is dropped */
    int randNum = rand() % BOMB_DROP_ODDS;
    if (randNum != 0) {
        return 0;
    }
    /* Check if there is already a bomb in progress */
    if (*bombRow != -1 || *bombColumn != -1) {
        return 0;
    }
    /* Find a random alien to drop the bomb from */
    int alienRow;
    int alienColumn;
    do {
        alienRow = rand() % (ROWS - (ALIEN_ROW_HEIGHT * 2));
        alienRow += ALIEN_ROW_HEIGHT;
        alienColumn = rand() % COLUMNS;
    } while (board[alienRow][alienColumn] != ALIEN);
    /* Drop the bomb */
    *bombRow = alienRow;
    *bombColumn = alienColumn;
    board[alienRow][alienColumn] = BOMB;
    return 1;
}

/* Check for collisions, return 1 if the game continues, 0 if it is over or won */
int checkCollisions(int board[ROWS][COLUMNS], int* score) {
    /* Check if the player has been hit by a bomb */
    for (int i = 0; i < COLUMNS; i++) {
        if (board[PLAYER_ROW][i] == BOMB) {
            (*score)--;
            return (*score >= 0);
        }
    }
    /* Check if the player has hit an alien */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == SHOT && i == PLAYER_ROW - 1) {
                (*score)++;
                return 1;
            }
        }
    }
    /* Check if there are any aliens left */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == ALIEN) {
                return 1;
            }
        }
    }
    /* The player has won! */
    return 0;
}

/* Play one game */
int playGame() {
    int board[ROWS][COLUMNS];
    int playerColumn = PLAYER_INITIAL_COLUMN;
    int shotRow = -1;
    int shotColumn = -1;
    int bombRow = -1;
    int bombColumn = -1;
    int lives = PLAYER_LIVES;
    int score = 0;
    initBoard(board);
    while (1) {
        drawBoard(board, score, lives);
        /* Move the player */
        int ch = getchar();
        if (ch == 'q' || ch == 'Q') {
            break;
        }
        else if (ch == 'a' || ch == 'A') {
            playerColumn--;
        }
        else if (ch == 'd' || ch == 'D') {
            playerColumn++;
        }
        if (!movePlayer(board, playerColumn)) {
            /* Player is dead */
            lives--;
            if (lives <= 0) {
                printf("You lose!\n");
                break;
            }
            else {
                /* Reset the player and the board */
                initBoard(board);
                playerColumn = PLAYER_INITIAL_COLUMN;
                shotRow = -1;
                shotColumn = -1;
                bombRow = -1;
                bombColumn = -1;
            }
        }
        /* Move the aliens */
        moveAliens(board);
        /* Fire the alien shooter */
        fireShot(board, playerColumn, &shotRow, &shotColumn);
        /* Drop a bomb */
        dropBomb(board, &bombRow, &bombColumn);
        /* Move the shot */
        moveShot(board, &shotRow, &shotColumn);
        /* Move the bomb */
        moveBomb(board, &bombRow, &bombColumn);
        /* Check for collisions */
        if (!checkCollisions(board, &score)) {
            printf("You win!\n");
            break;
        }
    }
    return 0;
}