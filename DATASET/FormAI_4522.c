//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLS 30

int score = 0;
char board[ROWS][COLS] = {0};

typedef struct {
    int x;
    int y;
} Location;

Location pacman = {0};
Location ghosts[4] = {{0},{0},{0},{0}};
Location prevLocation = {0};

void clearScreen() {
    system("clear"); //Change to "cls" if using Windows
}

Location getLocationFromString(char* locationString) {
    Location l;
    sscanf(locationString, "%d,%d", &l.x, &l.y);
    return l;
}

void displayScore() {
    printf("Score: %d\n", score);
}

void displayBoard() {
    char obstacles[] = {'#', '-'};
    clearScreen();
    displayScore();
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (i == pacman.x && j == pacman.y) {
                printf("P");
            } else {
                bool isGhost = false;
                for (int g=0; g<4; g++) {
                    if (i == ghosts[g].x && j == ghosts[g].y) {
                        printf("G");
                        isGhost = true;
                        break;
                    }
                }
                if (!isGhost) {
                    if (board[i][j] == 0) {
                        printf(".");
                    } else {
                        bool isObstacle = false;
                        for (int o=0; o<2; o++) {
                            if (board[i][j] == obstacles[o]) {
                                printf("%c", obstacles[o]);
                                isObstacle = true;
                                break;
                            }
                        }
                        if (!isObstacle) {
                            printf(" ");
                        }
                    }
                }
            }
        }
        printf("\n");
    }
}

void loadBoard() {
    FILE* file = fopen("board.txt", "r");
    if (file) {
        char line[COLS+2];
        for (int i=0; i<ROWS; i++) {
            fgets(line, COLS+2, file);
            for (int j=0; j<COLS; j++) {
                board[i][j] = line[j];
                if (line[j] == 'P') {
                    pacman.x = i;
                    pacman.y = j;
                }
            }
        }
        fclose(file);
    }
}

bool canMoveTo(Location location) {
    if (board[location.x][location.y] == '#' || board[location.x][location.y] == '-') {
        return false;
    }
    for (int g=0; g<4; g++) {
        if (location.x == ghosts[g].x && location.y == ghosts[g].y) {
            return false;
        }
    }
    return true;
}

Location findRandomLocation() {
    bool validLocation = false;
    Location randomLocation;
    while (!validLocation) {
        randomLocation.x = rand() % ROWS;
        randomLocation.y = rand() % COLS;
        validLocation = canMoveTo(randomLocation);
    }
    return randomLocation;
}

void moveGhost(int g) {
    Location location;
    int rowDiff = rand() % 3 - 1;
    int colDiff = rand() % 3 - 1;
    location.x = ghosts[g].x + rowDiff;
    location.y = ghosts[g].y + colDiff;
    if (canMoveTo(location)) {
        ghosts[g] = location;
    }
}

void moveGhosts() {
    for (int g=0; g<4; g++) {
        moveGhost(g);
    }
}

void checkGhostCollisions() {
    for (int g=0; g<4; g++) {
        if (pacman.x == ghosts[g].x && pacman.y == ghosts[g].y) {
            gameOver();
        }
    }
}

void checkForDotEating() {
    if (board[pacman.x][pacman.y] == '.') {
        score++;
        board[pacman.x][pacman.y] = ' ';
    }
}

void checkForGameOver() {
    bool hasDot = false;
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (board[i][j] == '.') {
                hasDot = true;
                break;
            }
        }
        if (hasDot) {
            break;
        }
    }
    if (!hasDot) {
        printf("\nYOU WON!\n");
        exit(0);
    }
}

void gameOver() {
    printf("\nGAME OVER!\n");
    exit(0);
}

void setup() {
    srand(time(0));
    loadBoard();
    ghosts[0] = findRandomLocation();
    ghosts[1] = findRandomLocation();
    ghosts[2] = findRandomLocation();
    ghosts[3] = findRandomLocation();
}

void getInput() {
    char input[10];
    printf("Enter move (up, down, left, right): ");
    fgets(input, 10, stdin);
    prevLocation = pacman;
    if (strcmp(input, "up\n") == 0) {
        pacman.x--;
    } else if (strcmp(input, "down\n") == 0) {
        pacman.x++;
    } else if (strcmp(input, "left\n") == 0) {
        pacman.y--;
    } else if (strcmp(input, "right\n") == 0) {
        pacman.y++;
    }
}

int main() {
    setup();
    while (true) {
        displayBoard();
        getInput();
        if (!canMoveTo(pacman)) {
            pacman = prevLocation;
        }
        moveGhosts();
        checkGhostCollisions();
        checkForDotEating();
        checkForGameOver();
    }
    return 0;
}