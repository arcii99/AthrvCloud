//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// Constants
#define MAP_WIDTH 20
#define MAP_HEIGHT 20
#define MAX_GHOSTS 4
#define PACMAN 'C'
#define GHOST 'G'
#define WALL '#'
#define DOT '.'
#define BLANK ' '

// Structs
typedef struct {
    int x;
    int y;
} Point;

// Globals
char map[MAP_HEIGHT][MAP_WIDTH];
bool gameOver;
Point pacman;
Point ghosts[MAX_GHOSTS];
int score;
struct termios orig_termios;

// Function prototypes
void init();
void play();
void end();
void drawMap();
void movePacman(char);
void moveGhosts();
Point getGhostTarget(int);
void updatePosition(Point *, int, int);
void getInput(char *);
void setNonCanonicalMode();
void resetCanonicalMode();
void clearScreen();
void die();
void printScore();

// Main function
int main() {
    init();
    play();
    end();
    return 0;
}

// Function definitions
void init() {
    // Initialize the map
    for(int i=0; i<MAP_HEIGHT; i++) {
        for(int j=0; j<MAP_WIDTH; j++) {
            if(i==0 || i==MAP_HEIGHT-1 || j==0 || j==MAP_WIDTH-1) {
                map[i][j] = WALL;
            } else {
                map[i][j] = DOT;
            }
        }
    }

    // Place pacman
    pacman.x = MAP_WIDTH/2;
    pacman.y = MAP_HEIGHT/2;
    map[pacman.y][pacman.x] = PACMAN;

    // Place ghosts
    for(int i=0; i<MAX_GHOSTS; i++) {
        ghosts[i].x = rand()%(MAP_WIDTH-2)+1;
        ghosts[i].y = rand()%(MAP_HEIGHT-2)+1;
        map[ghosts[i].y][ghosts[i].x] = GHOST;
    }

    // Set initial score and game over state
    score = 0;
    gameOver = false;

    // Set noncanonical mode for user input
    setNonCanonicalMode();
}

void play() {
    // Game loop
    while(!gameOver) {
        clearScreen();
        printScore();
        drawMap();
        char input;
        getInput(&input);
        movePacman(input);
        moveGhosts();
        usleep(100000);
    }
    die();
}

void end() {
    // Reset canonical mode for terminal
    resetCanonicalMode();
}

void drawMap() {
    printf("+");
    for(int i=0; i<MAP_WIDTH; i++) {
        printf("-");
    }
    printf("+\n");

    for(int i=0; i<MAP_HEIGHT; i++) {
        printf("|");
        for(int j=0; j<MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("|\n");
    }

    printf("+");
    for(int i=0; i<MAP_WIDTH; i++) {
        printf("-");
    }
    printf("+\n");
}

void movePacman(char dir) {
    // Update the map and pacman's position based on input direction
    int dx = 0;
    int dy = 0;
    switch(dir) {
        case 'w': dy = -1; break;
        case 'a': dx = -1; break;
        case 's': dy = 1; break;
        case 'd': dx = 1; break;
    }
    updatePosition(&pacman, dx, dy);
    if(map[pacman.y][pacman.x] == DOT) {
        score += 10;
    } else if(map[pacman.y][pacman.x] == GHOST) {
        gameOver = true;
    }
    map[pacman.y][pacman.x] = PACMAN;
}

void moveGhosts() {
    // Update the ghosts' positions based on their target positions
    for(int i=0; i<MAX_GHOSTS; i++) {
        Point target = getGhostTarget(i);
        int dx = 0;
        int dy = 0;
        if(ghosts[i].x < target.x) {
            dx = 1;
        } else if(ghosts[i].x > target.x) {
            dx = -1;
        }
        if(ghosts[i].y < target.y) {
            dy = 1;
        } else if(ghosts[i].y > target.y) {
            dy = -1;
        }
        updatePosition(&ghosts[i], dx, dy);
        if(map[ghosts[i].y][ghosts[i].x] == PACMAN) {
            gameOver = true;
        }
        map[ghosts[i].y][ghosts[i].x] = GHOST;
    }
}

Point getGhostTarget(int ghostIndex) {
    // Return pacman's position as the target for the ghost that is closest to pacman
    Point target = pacman;
    int minDist = abs(pacman.x - ghosts[ghostIndex].x) + abs(pacman.y - ghosts[ghostIndex].y);

    for(int i=0; i<MAX_GHOSTS; i++) {
        if(i == ghostIndex) continue;
        int dist = abs(pacman.x - ghosts[i].x) + abs(pacman.y - ghosts[i].y);
        if(dist < minDist) {
            target = pacman;
            minDist = dist;
        }
    }

    return target;
}

void updatePosition(Point *p, int dx, int dy) {
    // Check if the new position is a valid position (not a wall or outside of the map) and update the position
    int newX = p->x + dx;
    int newY = p->y + dy;
    if(map[newY][newX] != WALL) {
        map[p->y][p->x] = BLANK;
        p->x = newX;
        p->y = newY;
    }
}

void getInput(char *input) {
    // Get user input (one character) without waiting for return key
    char c;
    read(STDIN_FILENO, &c, 1);
    if(c != '\n') {
        *input = c;
    }
}

void setNonCanonicalMode() {
    // Set noncanonical mode for the terminal to allow for input without waiting for return key
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    new_termios.c_cc[VMIN] = 0;
    new_termios.c_cc[VTIME] = 1;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

void resetCanonicalMode() {
    // Reset the terminal to its original canonical mode
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

void clearScreen() {
    // Print ANSI escape sequence for clearing the terminal
    printf("\033[2J\033[H");
}

void die() {
    // Print game over message and final score
    clearScreen();
    printf("GAME OVER\n");
    printScore();
}

void printScore() {
    // Print current score to the terminal
    printf("SCORE: %d\n", score);
}