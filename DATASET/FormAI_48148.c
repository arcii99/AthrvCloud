//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 21

int pacman_x, pacman_y;
int ghost1_x, ghost1_y;
int ghost2_x, ghost2_y;
int ghost3_x, ghost3_y;
int score = 0;
char maze[ROWS][COLS] = {
"#####################",
"#............##.....#",
"#.#.####.###.##.###.#",
"#.#.#....#...#.....#",
"#...###.#.#.###.####",
"####....#.#.#.#.....#",
"#..###.#.###.#.#####",
"#....#.#.#...#.....#",
"######.#.#.#.#.#.#.#",
"#.......#.#.#.#.#.#.#",
"####.###.#.#.#.#.#.#",
"#.......#...#.#.#.#.#",
"######.#.#.#.#.#.###",
"#......#.#...#.....#",
"#.######.#.#.#.#.#.#",
"#.................#",
"###################"
};

/* Function to display the current state of the game board */
void display() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == pacman_x && j == pacman_y) {
                printf("C"); /* Pacman position */
            } else if (i == ghost1_x && j == ghost1_y) {
                printf("G"); /* Ghost 1 position */
            } else if (i == ghost2_x && j == ghost2_y) {
                printf("G"); /* Ghost 2 position */
            } else if (i == ghost3_x && j == ghost3_y) {
                printf("G"); /* Ghost 3 position */
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score); /* Display current score */
}

/* Function to move Pacman */
void move_pacman(char direction) {
    int new_x, new_y;
    /* Determine new position based on direction */
    if (direction == 'w') {
        new_x = pacman_x - 1;
        new_y = pacman_y;
    } else if (direction == 's') {
        new_x = pacman_x + 1;
        new_y = pacman_y;
    } else if (direction == 'a') {
        new_x = pacman_x;
        new_y = pacman_y - 1;
    } else if (direction == 'd') {
        new_x = pacman_x;
        new_y = pacman_y + 1;
    }
    /* Check if new position is valid */
    if (maze[new_x][new_y] == '#' || maze[new_x][new_y] == '.') {
        /* Wall or dot, do not move */
        return;
    } else if (maze[new_x][new_y] == 'G') {
        /* Pacman collided with a ghost, game over */
        printf("Game Over!\n");
        exit(0);
    } else {
        /* Valid move */
        pacman_x = new_x;
        pacman_y = new_y;
        if (maze[pacman_x][pacman_y] == '.') {
            score += 10; /* Picked up a dot, increase score */
            maze[pacman_x][pacman_y] = ' '; /* Remove dot */
        }
    }
}

/* Function to move Ghosts */
void move_ghosts() {
    /* Randomly determine ghost direction */
    int direction1 = rand() % 4;
    int direction2 = rand() % 4;
    int direction3 = rand() % 4;
    /* Determine new ghost position based on direction */
    if (direction1 == 0) {
        ghost1_x--;
    } else if (direction1 == 1) {
        ghost1_x++;
    } else if (direction1 == 2) {
        ghost1_y--;
    } else {
        ghost1_y++;
    }
    if (direction2 == 0) {
        ghost2_x--;
    } else if (direction2 == 1) {
        ghost2_x++;
    } else if (direction2 == 2) {
        ghost2_y--;
    } else {
        ghost2_y++;
    }
    if (direction3 == 0) {
        ghost3_x--;
    } else if (direction3 == 1) {
        ghost3_x++;
    } else if (direction3 == 2) {
        ghost3_y--;
    } else {
        ghost3_y++;
    }
    /* Check if ghosts collided with Pacman */
    if (ghost1_x == pacman_x && ghost1_y == pacman_y || ghost2_x == pacman_x && ghost2_y == pacman_y || ghost3_x == pacman_x && ghost3_y == pacman_y) {
        printf("Game Over!\n");
        exit(0);
    }
}

int main() {
    /* Initialize game board */
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 'C') {
                pacman_x = i;
                pacman_y = j;
            } else if (maze[i][j] == 'G') {
                if (ghost1_x == 0 && ghost1_y == 0) {
                    ghost1_x = i;
                    ghost1_y = j;
                } else if (ghost2_x == 0 && ghost2_y == 0) {
                    ghost2_x = i;
                    ghost2_y = j;
                } else {
                    ghost3_x = i;
                    ghost3_y = j;
                }
            }
        }
    }
    /* Set random seed */
    srand(time(NULL));
    /* Game loop */
    while (1) {
        system("clear");
        display();
        char input;
        printf("Enter move: ");
        scanf(" %c", &input);
        move_pacman(input);
        move_ghosts();
    }
    return 0;
}