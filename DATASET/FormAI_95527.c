//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 40
#define PORTAL_NUM 4
#define GHOST_NUM 4
#define PELLET_NUM 240
#define POWERUP_NUM 4

int gameBoard[ROWS][COLS];
int playerX, playerY;
int portalX[PORTAL_NUM], portalY[PORTAL_NUM];
int ghostX[GHOST_NUM], ghostY[GHOST_NUM];
int pelletX[PELLET_NUM], pelletY[PELLET_NUM];
int powerupX[POWERUP_NUM], powerupY[POWERUP_NUM];
int score = 0;
int lives = 3;
int level = 1;

void generatePortals() {
    portalX[0] = 0;
    portalY[0] = 11;
    portalX[1] = 0;
    portalY[1] = 28;
    portalX[2] = 24;
    portalY[2] = 11;
    portalX[3] = 24;
    portalY[3] = 28;
}

void generatePellets() {
    int pelletCount = 0;
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(gameBoard[i][j] != 1 && gameBoard[i][j] != -1) {
                pelletX[pelletCount] = i;
                pelletY[pelletCount] = j;
                pelletCount++;
            }
        }
    }
}

void generatePowerUps() {
    int powerupCount = 0;
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(gameBoard[i][j] != 1 && gameBoard[i][j] != -1) {
                int r = rand()%10000;
                if(r < 5) {
                    powerupX[powerupCount] = i;
                    powerupY[powerupCount] = j;
                    powerupCount++;
                }
            }
        }
    }
}

void generateGhosts() {
    for(int i=0; i<GHOST_NUM; i++) {
        int r = rand()%4;
        if(r == 0) {
            ghostX[i] = 12;
            ghostY[i] = 18;
        } else if(r == 1) {
            ghostX[i] = 11;
            ghostY[i] = 18;
        } else if(r == 2) {
            ghostX[i] = 12;
            ghostY[i] = 19;
        } else {
            ghostX[i] = 11;
            ghostY[i] = 19;
        }
    }
}

void displayBoard() {
    system("clear");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(gameBoard[i][j] == 1) {
                printf("#");
            } else if(gameBoard[i][j] == -1) {
                printf(" ");
            } else if(i == playerX && j == playerY) {
                printf("O");
            } else {
                int isGhost = 0;
                for(int k=0; k<GHOST_NUM; k++) {
                    if(i == ghostX[k] && j == ghostY[k]) {
                        printf("X");
                        isGhost = 1;
                        break;
                    }
                }
                if(!isGhost) {
                    int isPellet = 0;
                    for(int k=0; k<PELLET_NUM; k++) {
                        if(i == pelletX[k] && j == pelletY[k]) {
                            printf(".");
                            isPellet = 1;
                            break;
                        }
                    }
                    if(!isPellet) {
                        int isPowerUp = 0;
                        for(int k=0; k<POWERUP_NUM; k++) {
                            if(i == powerupX[k] && j == powerupY[k]) {
                                printf("P");
                                isPowerUp = 1;
                                break;
                            }
                        }
                        if(!isPowerUp) {
                            int isPortal = 0;
                            for(int k=0; k<PORTAL_NUM; k++) {
                                if(i == portalX[k] && j == portalY[k]) {
                                    printf(" ");
                                    isPortal = 1;
                                    break;
                                }
                            }
                            if(!isPortal) {
                                printf(" ");
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
    }
}

void movePlayer(char input) {
    if(input == 'w' && gameBoard[playerX-1][playerY] != 1) {
        playerX--;
    }
    if(input == 'a' && gameBoard[playerX][playerY-1] != 1) {
        playerY--;
    }
    if(input == 's' && gameBoard[playerX+1][playerY] != 1) {
        playerX++;
    }
    if(input == 'd' && gameBoard[playerX][playerY+1] != 1) {
        playerY++;
    }
    if(gameBoard[playerX][playerY] == 0) {
        score++;
    } else if(gameBoard[playerX][playerY] == 2) {
        score+=10;
        for(int i=0; i<GHOST_NUM; i++) {
            ghostX[i] = 12;
            ghostY[i] = 18;
        }
    }
    gameBoard[playerX][playerY] = -1;
}

void moveGhosts() {
    for(int i=0; i<GHOST_NUM; i++) {
        int r = rand()%4;
        if(r == 0 && gameBoard[ghostX[i]-1][ghostY[i]] != 1) {
            ghostX[i]--;
        }
        if(r == 1 && gameBoard[ghostX[i]][ghostY[i]-1] != 1) {
            ghostY[i]--;
        }
        if(r == 2 && gameBoard[ghostX[i]+1][ghostY[i]] != 1) {
            ghostX[i]++;
        }
        if(r == 3 && gameBoard[ghostX[i]][ghostY[i]+1] != 1) {
            ghostY[i]++;
        }
        if(ghostX[i] == playerX && ghostY[i] == playerY) {
            lives--;
            playerX = 12;
            playerY = 19;
            for(int i=0; i<GHOST_NUM; i++) {
                ghostX[i] = 12;
                ghostY[i] = 18;
            }
            if(lives == 0) {
                printf("GG WE LOST\n");
                exit(0);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    
    // Initialize board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(i==0 || i==ROWS-1 || j==0 || j==COLS-1) {
                gameBoard[i][j] = 1;
            } else {
                gameBoard[i][j] = 0;
            }
        }
    }
    
    // Generate objects
    generatePortals();
    for(int i=0; i<PORTAL_NUM; i++) {
        gameBoard[portalX[i]][portalY[i]] = -1;
    }
    for(int i=0; i<3; i++) {
        int r = rand()%2;
        if(r == 0) {
            gameBoard[12][i+14] = 1;
        } else {
            gameBoard[12][i+25] = 1;
        }
    }
    gameBoard[12][21] = 1;
    gameBoard[11][18] = 1;
    gameBoard[11][19] = 1;
    gameBoard[12][18] = 1;
    gameBoard[12][19] = 1;
    for(int i=0; i<POWERUP_NUM; i++) {
        powerupX[i] = -1;
        powerupY[i] = -1;
    }
    for(int i=0; i<1; i++) {
        powerupX[i] = 6;
        powerupY[i] = 26;
        gameBoard[powerupX[i]][powerupY[i]] = 2;
    }
    
    // Generate other objects randomly
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int r = rand()%10000;
            if(gameBoard[i][j] == 0 && r<2000) {
                gameBoard[i][j] = 1;
            }
        }
    }
    for(int i=0; i<1; i++) {
        for(int j=0; j<ROWS; j++) {
            for(int k=0; k<COLS; k++) {
                if(gameBoard[j][k] == 0) {
                    int r = rand()%10000;
                    if(r < 5) {
                        ghostX[i] = j;
                        ghostY[i] = k;
                        gameBoard[j][k] = -1;
                    }
                }
            }
        }
    }
    generatePellets();
    generatePowerUps();
    
    // Start game
    playerX = 12;
    playerY = 19;
    while(1) {
        displayBoard();
        char input;
        scanf(" %c", &input);
        movePlayer(input);
        moveGhosts();
        if(score == PELLET_NUM) {
            printf("Congratulations, you have completed Level %d\n", level);
            level++;
            score = 0;
            for(int i=0; i<ROWS; i++) {
                for(int j=0; j<COLS; j++) {
                    if(i==0 || i==ROWS-1 || j==0 || j==COLS-1) {
                        gameBoard[i][j] = 1;
                    } else {
                        gameBoard[i][j] = 0;
                    }
                }
            }
            generatePortals();
            for(int i=0; i<PORTAL_NUM; i++) {
                gameBoard[portalX[i]][portalY[i]] = -1;
            }
            for(int i=0; i<3; i++) {
                int r = rand()%2;
                if(r == 0) {
                    gameBoard[12][i+14] = 1;
                } else {
                    gameBoard[12][i+25] = 1;
                }
            }
            gameBoard[12][21] = 1;
            gameBoard[11][18] = 1;
            gameBoard[11][19] = 1;
            gameBoard[12][18] = 1;
            gameBoard[12][19] = 1;
            for(int i=0; i<POWERUP_NUM; i++) {
                powerupX[i] = -1;
                powerupY[i] = -1;
            }
            for(int i=0; i<1; i++) {
                powerupX[i] = 6;
                powerupY[i] = 26;
                gameBoard[powerupX[i]][powerupY[i]] = 2;
            }
            for(int i=0; i<ROWS; i++) {
                for(int j=0; j<COLS; j++) {
                    int r = rand()%10000;
                    if(gameBoard[i][j] == 0 && r<2000) {
                        gameBoard[i][j] = 1;
                    }
                }
            }
            for(int i=0; i<1; i++) {
                for(int j=0; j<ROWS; j++) {
                    for(int k=0; k<COLS; k++) {
                        if(gameBoard[j][k] == 0) {
                            int r = rand()%10000;
                            if(r < 5) {
                                ghostX[i] = j;
                                ghostY[i] = k;
                                gameBoard[j][k] = -1;
                            }
                        }
                    }
                }
            }
            generatePellets();
            generatePowerUps();
            playerX = 12;
            playerY = 19;
        }
    }
    return 0;
}