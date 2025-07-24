//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define ROWS 18
#define COLS 20
#define WALL 'X'
#define PATH ' '
#define GHOST 'G'
#define PACMAN 'P'
#define FOOD '*'

int score = 0;

char maze[ROWS][COLS] = {
    "XXXXXXXXXXXXXXXXXXXX",
    "X*****X********X****",
    "X*XXX*X*X*XXXXX*X*XX",
    "X*XXX*X*X*XXXXX*X*XX",
    "X*XXX*X*X*XXXXX*X*XX",
    "X      X X      X  X",
    "X*XXX*X*X*XX*XXX*X*XX",
    "X*XXX*X*X*XX*XXX*X*XX",
    "X*****X***XX*****X**",
    "XXXXXX*X*X*XXXXX*X*X",
    "XXXXXX*X*X*XXXXX*X*X",
    "XXXXXX*XGX*XXXXX*XGX",
    "XXXXXX*X*X*XXXXX*X*X",
    "XXXXXX*X*X*XXXXX*X*X",
    "X*****X***XX*****XX",
    "X*XXX*X*X*XXXXX*X*XX",
    "X*XXX*X*X*XXXXX*X*XX",
    "X*XXX*X*X*XXXXX*X*XX",
    "XXXXXXXXXXXXXXXXXXXX",
};

struct Position {
    int x;
    int y;
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Ghost {
    struct Position pos;
    enum Direction dir;
};

enum State {
    CHASE,
    SCATTER
};

struct GhostAI {
    struct Ghost ghost;
    enum State state;

    int chaseCounter;
    int scatterCounter;

    int chaseDuration;
    int scatterDuration;
};

struct Pacman {
    struct Position pos;
    enum Direction dir;
    int numLives;
    int allowedDirections[3];
};

static struct termios old, new;

/* Set new keyboard input settings */
void initTermios(int echo) {
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ~ICANON;
    new.c_lflag &= echo ? ECHO : ~ECHO;
    tcsetattr(0, TCSANOW, &new);
}

/* Restore old keyboard input settings */
void resetTermios(void) {
    tcsetattr(0, TCSANOW, &old);
}

/* Wait for keypress and return key code */
char getch_(int echo) {
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* Macro to call getch_ without echoing */
#define getch() getch_(0)

int randint(int a, int b) { return rand() % (b - a + 1) + a; }

void clear_screen() {
    printf("\x1b[H\x1b[2J");
}

void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == WALL) {
                printf("#");
            } else if (maze[i][j] == PATH) {
                printf(" ");
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
}

void print_score() {
    printf("\nScore: %d\n", score);
}

void print_lives(int numLives) {
    printf("\nLives: %d\n", numLives);
}

void print_game_information(int numLives) {
    print_score();
    print_lives(numLives);
}

void draw_character(int x, int y, char character) {
    printf("\x1b[%d;%dH%c", x, y, character);
    fflush(stdout);
}

void remove_character(int x, int y) {
    printf("\x1b[%d;%dH%c", x, y, ' ');
    fflush(stdout);
}

void move_character(int oldX, int oldY, int newX, int newY, char character) {
    remove_character(oldX, oldY);
    draw_character(newX, newY, character);
}

void set_ghost_direction(struct Ghost *ghost) {
    // Only set new direction if there is a path ahead
    int x = ghost->pos.x, y = ghost->pos.y;

    int possibleDirections[4] = { UP, DOWN, LEFT, RIGHT };
    int j, temp, n = 4;

    // Shuffle directions
    while (n > 1) {
        j = randint(0, n - 1);
        temp = possibleDirections[j];
        possibleDirections[j] = possibleDirections[n - 1];
        possibleDirections[n - 1] = temp;
        n--;
    }

    int newX, newY;
    for (int i = 0; i < 4; i++) {
        if (possibleDirections[i] == UP) {
            newX = x - 1;
            newY = y;
        } else if (possibleDirections[i] == DOWN) {
            newX = x + 1;
            newY = y;
        } else if (possibleDirections[i] == LEFT) {
            newX = x;
            newY = y - 1;
        } else {
            newX = x;
            newY = y + 1;
        }

        if (maze[newX][newY] != WALL) {
            ghost->pos.x = newX;
            ghost->pos.y = newY;
            ghost->dir = possibleDirections[i];
            break;
        }
    }
}

void set_ghost_to_box(struct Ghost *ghost) {
    ghost->pos.x = 11;
    ghost->pos.y = 9;
}

void move_ghost(struct GhostAI *ghostAI, struct Pacman *pacman) {
    int x = ghostAI->ghost.pos.x, y = ghostAI->ghost.pos.y;
    int newX, newY;

    // Move in direction unless there is a wall ahead
    if (ghostAI->ghost.dir == UP) {
        newX = x - 1;
        newY = y;
    } else if (ghostAI->ghost.dir == DOWN) {
        newX = x + 1;
        newY = y;
    } else if (ghostAI->ghost.dir == LEFT) {
        newX = x;
        newY = y - 1;
    } else {
        newX = x;
        newY = y + 1;
    }

    if (maze[newX][newY] != WALL) {
        move_character(x, y, newX, newY, GHOST);
        ghostAI->ghost.pos.x = newX;
        ghostAI->ghost.pos.y = newY;
    } else {
        set_ghost_direction(&ghostAI->ghost);
    }
}

void move_pacman(struct Pacman *pacman, int direction) {
    // Move in direction unless there is a wall ahead
    int x = pacman->pos.x, y = pacman->pos.y;
    int newX, newY;

    if (direction == UP) {
        newX = x - 1;
        newY = y;
    } else if (direction == DOWN) {
        newX = x + 1;
        newY = y;
    } else if (direction == LEFT) {
        newX = x;
        newY = y - 1;
    } else {
        newX = x;
        newY = y + 1;
    }

    if (maze[newX][newY] != WALL) {
        move_character(x, y, newX, newY, PACMAN);
        pacman->pos.x = newX;
        pacman->pos.y = newY;
    }
}

void reset_pacman_directions(struct Pacman *pacman) {
    pacman->allowedDirections[0] = UP;
    pacman->allowedDirections[1] = DOWN;
    pacman->allowedDirections[2] = LEFT;
    pacman->allowedDirections[3] = RIGHT;
}

int check_ghost_collision(struct GhostAI *ghostAI, struct Pacman *pacman, int numLives) {
    int gx = ghostAI->ghost.pos.x, gy = ghostAI->ghost.pos.y;
    int px = pacman->pos.x, py = pacman->pos.y;

    if (gx == px && gy == py) {
        numLives--;
        score -= 100;
        if (numLives > 0) {
            // Reset positions of pacman and ghosts
            pacman->pos.x = 8;
            pacman->pos.y = 9;
            ghostAI->ghost.pos.x = 11;
            ghostAI->ghost.pos.y = 9;
            reset_pacman_directions(pacman);
        }
    }

    return numLives;
}

void set_ghost_state(struct GhostAI *ghostAI) {
    if (ghostAI->state == CHASE) {
        ghostAI->chaseCounter--;
        if (ghostAI->chaseCounter == 0) {
            ghostAI->state = SCATTER;
            ghostAI->scatterCounter = ghostAI->scatterDuration;
        }
    } else {
        ghostAI->scatterCounter--;
        if (ghostAI->scatterCounter == 0) {
            ghostAI->state = CHASE;
            ghostAI->chaseCounter = ghostAI->chaseDuration;
        }
    }
}

void set_pacman_directions(struct Pacman *pacman) {
    int x = pacman->pos.x, y = pacman->pos.y;

    if (maze[x - 1][y] != WALL) {
        pacman->allowedDirections[0] = UP;
    } else {
        pacman->allowedDirections[0] = -1;
    }

    if (maze[x + 1][y] != WALL) {
        pacman->allowedDirections[1] = DOWN;
    } else {
        pacman->allowedDirections[1] = -1;
    }

    if (maze[x][y - 1] != WALL) {
        pacman->allowedDirections[2] = LEFT;
    } else {
        pacman->allowedDirections[2] = -1;
    }

    if (maze[x][y + 1] != WALL) {
        pacman->allowedDirections[3] = RIGHT;
    } else {
        pacman->allowedDirections[3] = -1;
    }
}

void update_score(struct Pacman *pacman) {
    int x = pacman->pos.x, y = pacman->pos.y;
    if (maze[x][y] == FOOD) {
        score += 10;
        maze[x][y] = PATH;
    }
}

void place_powerup() {
    int top = 4, bottom = ROWS - 5;
    int left = 5, right = COLS - 6;

    int x = randint(top, bottom), y = randint(left, right);

    if (maze[x][y] == PATH) {
        maze[x][y] = FOOD;
    } else {
        place_powerup();
    }
}

void run_game() {
    struct Pacman pacman = {
        .pos = { 8, 9 },
        .numLives = 3
    };

    struct GhostAI ghostAI = {
        .ghost = { .pos = { 11, 9 } },
        .state = SCATTER,
        .chaseCounter = 10,
        .scatterCounter = 5,
        .chaseDuration = 10,
        .scatterDuration = 5
    };

    // Place powerups randomly
    place_powerup();
    place_powerup();

    while (pacman.numLives > 0) {
        print_game_information(pacman.numLives);
        print_maze();

        char key = getch();
        if (key == 'w') {
            if (pacman.allowedDirections[0] != -1) {
                pacman.dir = pacman.allowedDirections[0];
            }
        } else if (key == 's') {
            if (pacman.allowedDirections[1] != -1) {
                pacman.dir = pacman.allowedDirections[1];
            }
        } else if (key == 'a') {
            if (pacman.allowedDirections[2] != -1) {
                pacman.dir = pacman.allowedDirections[2];
            }
        } else if (key == 'd') {
            if (pacman.allowedDirections[3] != -1) {
                pacman.dir = pacman.allowedDirections[3];
            }
        }

        set_pacman_directions(&pacman);
        update_score(&pacman);
        move_pacman(&pacman, pacman.dir);
        pacman.numLives = check_ghost_collision(&ghostAI, &pacman, pacman.numLives);

        if (ghostAI.state == CHASE) {
            move_ghost(&ghostAI, &pacman);
        } else {
            set_ghost_direction(&ghostAI.ghost);
            move_ghost(&ghostAI, &pacman);
        }

        set_ghost_state(&ghostAI);
    }

    clear_screen();
    printf("Game over! Your final score is %d\n", score);
}

void main() {
    srand(time(NULL));
    run_game();
}