//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define maze size
#define ROWS 15
#define COLS 15

// Define number of pellets and power pellets
#define NUM_PELLETS 165
#define NUM_POWER_PELLETS 4

// Define character symbols
#define PACMAN_SYMBOL 'C'
#define GHOST_SYMBOL 'G'
#define WALL_SYMBOL '#'
#define PELLET_SYMBOL '.'
#define POWER_PELLET_SYMBOL 'O'
#define EMPTY_SYMBOL ' '

// Define game objects
struct Pacman {
    int x, y;           // Current position of Pac-Man
    int score;          // Current score of Pac-Man
    bool powered_up;    // Whether Pac-Man is powered up or not
    int power_up_timer; // Timer for power-up duration
};

struct Ghost {
    int x, y;       // Current position of ghost
    bool chasing;   // Whether ghost is chasing Pac-Man or not
};

// Define global variables
char maze[ROWS][COLS];
int pellets_left = NUM_PELLETS;
int power_pellets_left = NUM_POWER_PELLETS;
struct Pacman pacman;
struct Ghost ghosts[4];

// Function declarations
void setup_maze(char maze[ROWS][COLS]);
void place_pacman(char maze[ROWS][COLS], struct Pacman* pacman);
void place_ghosts(char maze[ROWS][COLS], struct Ghost* ghosts);
void place_pellets(char maze[ROWS][COLS]);
void print_maze(char maze[ROWS][COLS]);
void move_pacman(char maze[ROWS][COLS], struct Pacman* pacman);
void ai_ghosts(char maze[ROWS][COLS], struct Ghost* ghosts, struct Pacman* pacman);
bool is_collision(int x1, int y1, int x2, int y2);
void handle_collision(char maze[ROWS][COLS], struct Pacman* pacman);

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Setup maze and game objects
    setup_maze(maze);
    place_pacman(maze, &pacman);
    place_ghosts(maze, ghosts);
    place_pellets(maze);
    
    // Print initial maze
    print_maze(maze);

    // Game loop
    while (pellets_left > 0) {
        // Move Pac-Man and ghosts
        move_pacman(maze, &pacman);
        ai_ghosts(maze, ghosts, &pacman);
        
        // Handle collisions
        handle_collision(maze, &pacman);
        
        // Print updated maze
        print_maze(maze);
    }
    
    // Print final score
    printf("Game over! Final score: %d\n", pacman.score);
    
    return 0;
}

// Function definitions

void setup_maze(char maze[ROWS][COLS]) {
    // Set all cells to empty
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = EMPTY_SYMBOL;
        }
    }
    
    // Set border walls
    for (int i = 0; i < ROWS; i++) {
        maze[i][0] = WALL_SYMBOL;
        maze[i][COLS - 1] = WALL_SYMBOL;
    }
    for (int j = 0; j < COLS; j++) {
        maze[0][j] = WALL_SYMBOL;
        maze[ROWS - 1][j] = WALL_SYMBOL;
    }
}

void place_pacman(char maze[ROWS][COLS], struct Pacman* pacman) {
    // Place Pac-Man randomly
    do {
        pacman->x = rand() % (COLS - 2) + 1;
        pacman->y = rand() % (ROWS - 2) + 1;
    } while (maze[pacman->y][pacman->x] != EMPTY_SYMBOL);
    
    // Set initial score and power-up status
    pacman->score = 0;
    pacman->powered_up = false;
    pacman->power_up_timer = 0;
    
    // Place Pac-Man in maze
    maze[pacman->y][pacman->x] = PACMAN_SYMBOL;
}

void place_ghosts(char maze[ROWS][COLS], struct Ghost* ghosts) {
    // Place ghosts randomly
    for (int i = 0; i < 4; i++) {
        do {
            ghosts[i].x = rand() % (COLS - 2) + 1;
            ghosts[i].y = rand() % (ROWS - 2) + 1;
        } while (maze[ghosts[i].y][ghosts[i].x] != EMPTY_SYMBOL);
        
        // Set initial chasing status
        ghosts[i].chasing = false;
        
        // Place ghost in maze
        maze[ghosts[i].y][ghosts[i].x] = GHOST_SYMBOL;
    }
}

void place_pellets(char maze[ROWS][COLS]) {
    // Place pellets randomly
    for (int i = 0; i < NUM_PELLETS; i++) {
        int x, y;
        do {
            x = rand() % (COLS - 2) + 1;
            y = rand() % (ROWS - 2) + 1;
        } while (maze[y][x] != EMPTY_SYMBOL);
        maze[y][x] = PELLET_SYMBOL;
    }
    
    // Place power pellets randomly
    for (int i = 0; i < NUM_POWER_PELLETS; i++) {
        int x, y;
        do {
            x = rand() % (COLS - 2) + 1;
            y = rand() % (ROWS - 2) + 1;
        } while (maze[y][x] != EMPTY_SYMBOL);
        maze[y][x] = POWER_PELLET_SYMBOL;
    }
}

void print_maze(char maze[ROWS][COLS]) {
    // Clear screen
    system("clear");
    
    // Print maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void move_pacman(char maze[ROWS][COLS], struct Pacman* pacman) {
    // Move Pac-Man based on user input
    char input = getchar();
    if (input == 'w' && maze[pacman->y - 1][pacman->x] != WALL_SYMBOL) {
        maze[pacman->y][pacman->x] = EMPTY_SYMBOL;
        pacman->y--;
    } else if (input == 'a' && maze[pacman->y][pacman->x - 1] != WALL_SYMBOL) {
        maze[pacman->y][pacman->x] = EMPTY_SYMBOL;
        pacman->x--;
    } else if (input == 's' && maze[pacman->y + 1][pacman->x] != WALL_SYMBOL) {
        maze[pacman->y][pacman->x] = EMPTY_SYMBOL;
        pacman->y++;
    } else if (input == 'd' && maze[pacman->y][pacman->x + 1] != WALL_SYMBOL) {
        maze[pacman->y][pacman->x] = EMPTY_SYMBOL;
        pacman->x++;
    }
    
    // Check if Pac-Man ate a pellet
    if (maze[pacman->y][pacman->x] == PELLET_SYMBOL) {
        pacman->score += 10;
        pellets_left--;
    } else if (maze[pacman->y][pacman->x] == POWER_PELLET_SYMBOL) {
        pacman->powered_up = true;
        pacman->power_up_timer = 10;
        pacman->score += 50;
        power_pellets_left--;
        pellets_left--;
    }
    
    // Place Pac-Man in maze
    maze[pacman->y][pacman->x] = PACMAN_SYMBOL;
}

void ai_ghosts(char maze[ROWS][COLS], struct Ghost* ghosts, struct Pacman* pacman) {
    // Move ghosts towards or away from Pac-Man depending on their current chasing status
    for (int i = 0; i < 4; i++) {
        if (ghosts[i].chasing) {
            if (pacman->powered_up) {
                // Move away from Pac-Man if he is powered up
                if (pacman->y < ghosts[i].y && maze[ghosts[i].y - 1][ghosts[i].x] != WALL_SYMBOL) {
                    maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                    ghosts[i].y--;
                } else if (pacman->x < ghosts[i].x && maze[ghosts[i].y][ghosts[i].x - 1] != WALL_SYMBOL) {
                    maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                    ghosts[i].x--;
                } else if (pacman->y > ghosts[i].y && maze[ghosts[i].y + 1][ghosts[i].x] != WALL_SYMBOL) {
                    maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                    ghosts[i].y++;
                } else if (pacman->x > ghosts[i].x && maze[ghosts[i].y][ghosts[i].x + 1] != WALL_SYMBOL) {
                    maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                    ghosts[i].x++;
                }
            } else {
                // Move towards Pac-Man if he is not powered up
                if (pacman->y < ghosts[i].y && maze[ghosts[i].y - 1][ghosts[i].x] != WALL_SYMBOL) {
                    maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                    ghosts[i].y--;
                } else if (pacman->x < ghosts[i].x && maze[ghosts[i].y][ghosts[i].x - 1] != WALL_SYMBOL) {
                    maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                    ghosts[i].x--;
                } else if (pacman->y > ghosts[i].y && maze[ghosts[i].y + 1][ghosts[i].x] != WALL_SYMBOL) {
                    maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                    ghosts[i].y++;
                } else if (pacman->x > ghosts[i].x && maze[ghosts[i].y][ghosts[i].x + 1] != WALL_SYMBOL) {
                    maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                    ghosts[i].x++;
                }
            }
        } else {
            // Move randomly if not chasing Pac-Man
            int move = rand() % 4;
            switch (move) {
                case 0: // Move up
                    if (maze[ghosts[i].y - 1][ghosts[i].x] != WALL_SYMBOL) {
                        maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                        ghosts[i].y--;
                    }
                    break;
                case 1: // Move left
                    if (maze[ghosts[i].y][ghosts[i].x - 1] != WALL_SYMBOL) {
                        maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                        ghosts[i].x--;
                    }
                    break;
                case 2: // Move down
                    if (maze[ghosts[i].y + 1][ghosts[i].x] != WALL_SYMBOL) {
                        maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                        ghosts[i].y++;
                    }
                    break;
                case 3: // Move right
                    if (maze[ghosts[i].y][ghosts[i].x + 1] != WALL_SYMBOL) {
                        maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                        ghosts[i].x++;
                    }
                    break;
            }
        }
        
        // Place ghosts in maze
        maze[ghosts[i].y][ghosts[i].x] = GHOST_SYMBOL;
    }
}

bool is_collision(int x1, int y1, int x2, int y2) {
    // Check if two objects are in the same position
    return (x1 == x2 && y1 == y2);
}

void handle_collision(char maze[ROWS][COLS], struct Pacman* pacman) {
    // Check if Pac-Man collides with power pellet timer
    if (pacman->powered_up) {
        pacman->power_up_timer--;
        if (pacman->power_up_timer == 0) {
            pacman->powered_up = false;
        }
    }
    
    // Check if Pac-Man collides with a ghost
    for (int i = 0; i < 4; i++) {
        if (is_collision(pacman->x, pacman->y, ghosts[i].x, ghosts[i].y)) {
            if (pacman->powered_up) {
                // Ghost is eaten and respawns
                pacman->score += 100;
                maze[ghosts[i].y][ghosts[i].x] = EMPTY_SYMBOL;
                do {
                    ghosts[i].x = rand() % (COLS - 2) + 1;
                    ghosts[i].y = rand() % (ROWS - 2) + 1;
                } while (maze[ghosts[i].y][ghosts[i].x] != EMPTY_SYMBOL);
                maze[ghosts[i].y][ghosts[i].x] = GHOST_SYMBOL;
                ghosts[i].chasing = false;
            } else {
                // Pac-Man is eaten and game ends
                printf("Game over! Final score: %d\n", pacman->score);
                exit(0);
            }
        }
    }
}