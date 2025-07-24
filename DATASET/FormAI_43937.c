//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 24
#define COLS 80

typedef enum {
    WALL = '#',
    PACMAN = 'C',
    FRUIT = '*',
    GHOST = 'G'
} EntityType;

const EntityType ENTITIES[] = {WALL, PACMAN, FRUIT, GHOST};

typedef struct {
    int x;
    int y;
} Position;

Position pacman;
Position ghosts[4];
Position fruits[5];

char screen[ROWS][COLS];

int score;

void init_game() {
    // initialize pacman's position
    pacman.x = COLS / 2;
    pacman.y = ROWS / 2;
    
    // initialize ghost positions
    for (int i = 0; i < 4; i++) {
        ghosts[i].x = rand() % COLS;
        ghosts[i].y = rand() % ROWS;
    }
    
    // initialize fruit positions
    for (int i = 0; i < 5; i++) {
        fruits[i].x = rand() % COLS;
        fruits[i].y = rand() % ROWS;
    }
    
    // initialize the screen
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            screen[i][j] = ' ';
        }
    }
    
    // add the entities to the screen
    for (int i = 0; i < 4; i++) {
        screen[ghosts[i].y][ghosts[i].x] = GHOST;
    }
    
    for (int i = 0; i < 5; i++) {
        screen[fruits[i].y][fruits[i].x] = FRUIT;
    }
    
    screen[pacman.y][pacman.x] = PACMAN;
}

void move_pacman(char direction) {
    Position new_pos;
    
    if (direction == 'w' && pacman.y > 0) {
        new_pos.x = pacman.x;
        new_pos.y = pacman.y - 1;
    } else if (direction == 's' && pacman.y < ROWS - 1) {
        new_pos.x = pacman.x;
        new_pos.y = pacman.y + 1;
    } else if (direction == 'a' && pacman.x > 0) {
        new_pos.x = pacman.x - 1;
        new_pos.y = pacman.y;
    } else if (direction == 'd' && pacman.x < COLS - 1) {
        new_pos.x = pacman.x + 1;
        new_pos.y = pacman.y;
    } else {
        return;
    }
    
    // update the score and remove entities from screen
    if (screen[new_pos.y][new_pos.x] == FRUIT) {
        score++;
    } else if (screen[new_pos.y][new_pos.x] == GHOST) {
        score -= 5;
    }
    
    screen[pacman.y][pacman.x] = ' ';
    screen[new_pos.y][new_pos.x] = PACMAN;
    
    pacman = new_pos;
}

void move_ghosts() {
    for (int i = 0; i < 4; i++) {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        
        int new_x = ghosts[i].x + dx;
        int new_y = ghosts[i].y + dy;
        
        if (new_x < 0 || new_x >= COLS || new_y < 0 || new_y >= ROWS) {
            continue;
        }
        
        if (screen[new_y][new_x] == WALL) {
            continue;
        }
        
        screen[ghosts[i].y][ghosts[i].x] = ' ';
        ghosts[i].x = new_x;
        ghosts[i].y = new_y;
        screen[ghosts[i].y][ghosts[i].x] = GHOST;
    }
}

void display_screen() {
    system("cls");
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
    
    printf("Score: %d\n", score);
}

int main() {
    srand(time(NULL));
    
    init_game();
    
    while (1) {
        display_screen();
        
        char input = getchar();
        move_pacman(input);
        move_ghosts();
    }
    
    return 0;
}