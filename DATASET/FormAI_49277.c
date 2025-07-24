//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define GRID_ROW    21
#define GRID_COL    21

#define GRID_EMPTY  "   "
#define GRID_PACMAN " P "
#define GRID_WALL   "###"
#define GRID_DOT    " . "
#define GRID_ENERGIZER " O "

#define MAX_DOTS    186
#define MAX_THREADS 4

typedef struct {
    int row;
    int col;
} point_t;

typedef struct {
    int pid;
    int dots_eaten;
    point_t loc;
    point_t last_loc;
    char icon[3]; /* Can only be GRID_PACMAN or GRID_ENERGIZER */
} player_t;

/* Shared variables between threads */
char grid[GRID_ROW][GRID_COL][3] = { {0} };
int dots_remaining = MAX_DOTS;
int is_energized = 0;
int winner_pid = -1;
int game_over = 0;

/* Player variables */
player_t players[MAX_THREADS];
pthread_mutex_t player_lock;

/* Function declarations */
void draw_grid(void);
void move_player(int pid, int row_offset, int col_offset);
void *player_thread(void *args);

/* Main function */
int main(void) {
    pthread_t threads[MAX_THREADS];
    int i;
    void *status;

    /* Initialize the grid */
    for (i = 0; i < GRID_ROW; i++) {
        int j;
        for (j = 0; j < GRID_COL; j++) {
            if (i == 0 || i == GRID_ROW-1 || j == 0 || j == GRID_COL-1 || ((i == 9 || i == 11) && (j < 3 || j > 17))) {
                sprintf(grid[i][j], "%s", GRID_WALL);
            } else if ((i == 1 || i == GRID_ROW-2) && (j % 2 == 0)) {
                sprintf(grid[i][j], "%s", GRID_WALL);
            } else if ((i == 1 && j == 1) || (i == 1 && j == GRID_COL-2) || (i == GRID_ROW-2 && j == 1) || (i == GRID_ROW-2 &&j == GRID_COL-2)) {
                sprintf(grid[i][j], "%s", GRID_ENERGIZER);
            } else {
                sprintf(grid[i][j], "%s", GRID_DOT);
            }
        }
    }

    /* Initialize players */
    pthread_mutex_init(&player_lock, NULL);
    for (i = 0; i < MAX_THREADS; i++) {
        players[i].pid = i+1;
        players[i].dots_eaten = 0;
        if (i == 0) {
            sprintf(players[i].icon, "%s", GRID_PACMAN);
            players[i].loc = (point_t) {1, 10};
        } else if (i == 1) {
            sprintf(players[i].icon, "%s", GRID_ENERGIZER);
            players[i].loc = (point_t) {19, 10};
        } else if (i == 2) {
            sprintf(players[i].icon, "%s", GRID_ENERGIZER);
            players[i].loc = (point_t) {10, 1};
        } else if (i == 3) {
            sprintf(players[i].icon, "%s", GRID_ENERGIZER);
            players[i].loc = (point_t) {10, 19};
        }
        players[i].last_loc = players[i].loc;
        pthread_create(&threads[i], NULL, player_thread, (void *)&players[i]);
    }

    /* Main game loop */
    while (!game_over) {
        draw_grid();
        sleep(1);
    }

    /* Join player threads */
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], &status);
    }

    printf("Game over! Player %d won with %d dots eaten!\n", winner_pid, players[winner_pid-1].dots_eaten);

    return 0;
}

/* Function to redraw the grid */
void draw_grid(void) {
    int i, j;

    /* Clear the screen */
    printf("\033c");

    /* Draw the grid */
    for (i = 0; i < GRID_ROW; i++) {
        for (j = 0; j < GRID_COL; j++) {
            printf("%s", grid[i][j]);
        }
        printf("\n");
    }
    printf("Dots remaining: %d\n", dots_remaining);
}

/* Function to move a player, called by player_thread() */
void move_player(int pid, int row_offset, int col_offset) {
    point_t new_loc = (point_t) {players[pid-1].loc.row+row_offset, players[pid-1].loc.col+col_offset};

    /* Check if the new location is a dot */
    if (strcmp(grid[new_loc.row][new_loc.col], GRID_DOT) == 0 || strcmp(grid[new_loc.row][new_loc.col], GRID_ENERGIZER) == 0) {
        pthread_mutex_lock(&player_lock);
        sprintf(grid[new_loc.row][new_loc.col], "%s", GRID_EMPTY);
        dots_remaining--;
        players[pid-1].dots_eaten++;
        pthread_mutex_unlock(&player_lock);
        if (dots_remaining == 0) {
            winner_pid = pid;
            game_over = 1;
        }
        if (strcmp(grid[new_loc.row][new_loc.col], GRID_ENERGIZER) == 0) {
            is_energized = 1;
        }
    }

    /* Move the player to the new location, if possible */
    if (strcmp(grid[new_loc.row][new_loc.col], GRID_WALL) != 0) {
        pthread_mutex_lock(&player_lock);
        if (is_energized) {
            sprintf(grid[players[pid-1].loc.row][players[pid-1].loc.col], "%s", GRID_EMPTY);
            sprintf(grid[new_loc.row][new_loc.col], "%s", players[pid-1].icon);
            players[pid-1].last_loc = players[pid-1].loc;
            players[pid-1].loc = new_loc;
        } else if (players[pid-1].last_loc.row == new_loc.row && players[pid-1].last_loc.col == new_loc.col) {
	    /* Player is trying to move back to the previous location, do not move */
	    /* This is to prevent the player from "stuttering" when the user spams the arrow keys */
            return;
	} else {
            sprintf(grid[players[pid-1].last_loc.row][players[pid-1].last_loc.col], "%s", GRID_EMPTY);
            sprintf(grid[new_loc.row][new_loc.col], "%s", players[pid-1].icon);
            players[pid-1].last_loc = players[pid-1].loc;
            players[pid-1].loc = new_loc;
        }
        pthread_mutex_unlock(&player_lock);
    }
}

/* Function to move a player in a random direction */
void random_move_player(int pid) {
    int direction;
    point_t offset;

    /* Choose a random direction */
    direction = rand() % 4;

    /* Calculate the offset based on the direction */
    if (direction == 0) {
        offset = (point_t) {-1, 0}; /* up */
    } else if (direction == 1) {
        offset = (point_t) {0, 1}; /* right */
    } else if (direction == 2) {
        offset = (point_t) {1, 0}; /* down */
    } else {
        offset = (point_t) {0, -1}; /* left */
    }

    move_player(pid, offset.row, offset.col);
}

/* Thread function for players */
void *player_thread(void *args) {
    player_t *player = (player_t *)args;

    printf("Player %d spawned at (%d, %d)!\n", player->pid, player->loc.row, player->loc.col);

    while (!game_over) {
        random_move_player(player->pid);
        sleep(1);
    }

    printf("Player %d exiting with %d dots eaten.\n", player->pid, player->dots_eaten);

    pthread_exit(NULL);
}