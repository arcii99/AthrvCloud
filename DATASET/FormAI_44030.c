//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define ROWS 25
#define COLS 40
#define PELLETS 500 //Number of pellets in the game
#define ENEMIES 4 //Number of ghosts in the game

//Structs for positions and objects
typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    Position pos;
    bool eaten;
} Pellet;

typedef struct {
    Position pos;
    int direction;
    int speed;
} Enemy;

//Global variables
char board[ROWS][COLS];
Position player;
Pellet pellets[PELLETS];
Enemy enemies[ENEMIES];
int score = 0;
bool game_over = false;

//Function prototypes
void init_board();
void init_player();
void init_pellets();
void init_enemies();
void *enemy_thread(void *arg);
bool check_collision(Position pos);
void draw_board();
void draw_player();
void draw_pellets();
void draw_enemies();
void move_player(int keycode);
void move_enemies();
void check_pellet_collisions();
void check_enemy_collisions();
void game_loop();

int main() {
    srand(time(NULL)); //Seed the random number generator
    init_board();
    init_player();
    init_pellets();
    init_enemies();
    pthread_t thread_id[ENEMIES];

    //Create a thread for each enemy
    for(int i = 0; i < ENEMIES; i++) {
        pthread_create(&thread_id[i], NULL, enemy_thread, (void *)&enemies[i]);
    }

    game_loop();

    //Join each thread
    for(int i = 0; i < ENEMIES; i++) {
        pthread_join(thread_id[i], NULL);
    }

    printf("Game Over! Final score: %d\n", score);
    return 0;
}

/* Initialize the game board with walls and empty spaces */
void init_board() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                board[i][j] = '#';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

/* Initialize the player's starting position */
void init_player() {
    player.row = ROWS / 2;
    player.col = COLS / 2;
    board[player.row][player.col] = 'P';
}

/* Initialize the pellets at random locations */
void init_pellets() {
    int count = 0;
    while(count < PELLETS) {
        int row = rand() % (ROWS - 2) + 1;
        int col = rand() % (COLS - 2) + 1;
        if(board[row][col] == ' ') {
            pellets[count].pos.row = row;
            pellets[count].pos.col = col;
            pellets[count].eaten = false;
            board[row][col] = '.';
            count++;
        }
    }
}

/* Initialize the enemies at random locations */
void init_enemies() {
    for(int i = 0; i < ENEMIES; i++) {
        int row = rand() % (ROWS - 2) + 1;
        int col = rand() % (COLS - 2) + 1;
        enemies[i].pos.row = row;
        enemies[i].pos.col = col;
        enemies[i].direction = rand()%4;
        enemies[i].speed = 10000;
        board[row][col] = 'G';
    }
}

/* Enemy thread function to move a ghost */
void *enemy_thread(void *arg) {
    Enemy *enemy = (Enemy *)arg;
    while(!game_over) {
        usleep(enemy->speed);
        //Check if the enemy can move in its current direction
        Position next_pos;
        switch(enemy->direction) {
            case 0: //Up
                next_pos.row = enemy->pos.row - 1;
                next_pos.col = enemy->pos.col;
                break;
            case 1: //Right
                next_pos.row = enemy->pos.row;
                next_pos.col = enemy->pos.col + 1;
                break;
            case 2: //Down
                next_pos.row = enemy->pos.row + 1;
                next_pos.col = enemy->pos.col;
                break;
            case 3: //Left
                next_pos.row = enemy->pos.row;
                next_pos.col = enemy->pos.col - 1;
                break;
        }
        if(check_collision(next_pos)) {
            enemy->pos = next_pos;
        } else {
            enemy->direction = rand()%4; //Choose a new random direction
        }
    }
    return NULL;
}

/* Check if a collision will occur at the given position */
bool check_collision(Position pos) {
    if(board[pos.row][pos.col] == ' ') {
        return true; //No collision
    } else if(board[pos.row][pos.col] == '#' || board[pos.row][pos.col] == 'G') {
        return false; //Collision with wall or enemy
    } else if(board[pos.row][pos.col] == '.') {
        return true; //Pellet collision
    } else {
        game_over = true; //Player collision
        return false;
    }
}

/* Draw the game board */
void draw_board() {
    system("clear"); //Clear the console
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

/* Draw the player at its current position */
void draw_player() {
    board[player.row][player.col] = 'P';
}

/* Draw the pellets that haven't been eaten yet */
void draw_pellets() {
    for(int i = 0; i < PELLETS; i++) {
        if(!pellets[i].eaten) {
            board[pellets[i].pos.row][pellets[i].pos.col] = '.';
        }
    }
}

/* Draw the enemies at their current positions */
void draw_enemies() {
    for(int i = 0; i < ENEMIES; i++) {
        board[enemies[i].pos.row][enemies[i].pos.col] = 'G';
    }
}

/* Move the player in the given direction */
void move_player(int keycode) {
    switch(keycode) {
        case 65: //UP
            if(check_collision((Position){player.row - 1, player.col})) {
                board[player.row][player.col] = ' ';
                player.row--;
                score++;
            }
            break;
        case 66: //DOWN
            if(check_collision((Position){player.row + 1, player.col})) {
                board[player.row][player.col] = ' ';
                player.row++;
                score++;
            }
            break;
        case 67: //RIGHT
            if(check_collision((Position){player.row, player.col + 1})) {
                board[player.row][player.col] = ' ';
                player.col++;
                score++;
            }
            break;
        case 68: //LEFT
            if(check_collision((Position){player.row, player.col - 1})) {
                board[player.row][player.col] = ' ';
                player.col--;
                score++;
            }
            break;
    }
}

/* Move the enemies in random directions */
void move_enemies() {
    for(int i = 0; i < ENEMIES; i++) {
        //Check if the enemy can move in its current direction
        Position next_pos;
        switch(enemies[i].direction) {
            case 0: //Up
                next_pos.row = enemies[i].pos.row - 1;
                next_pos.col = enemies[i].pos.col;
                break;
            case 1: //Right
                next_pos.row = enemies[i].pos.row;
                next_pos.col = enemies[i].pos.col + 1;
                break;
            case 2: //Down
                next_pos.row = enemies[i].pos.row + 1;
                next_pos.col = enemies[i].pos.col;
                break;
            case 3: //Left
                next_pos.row = enemies[i].pos.row;
                next_pos.col = enemies[i].pos.col - 1;
                break;
        }
        if(check_collision(next_pos)) {
            board[enemies[i].pos.row][enemies[i].pos.col] = ' ';
            enemies[i].pos = next_pos;
        } else {
            enemies[i].direction = rand()%4; //Choose a new random direction
        }
    }
}

/* Check for collisions between the player and pellets */
void check_pellet_collisions() {
    for(int i = 0; i < PELLETS; i++) {
        if(!pellets[i].eaten && player.row == pellets[i].pos.row && player.col == pellets[i].pos.col) {
            pellets[i].eaten = true;
            score += 10;
        }
    }
}

/* Check for collisions between the player and enemies */
void check_enemy_collisions() {
    for(int i = 0; i < ENEMIES; i++) {
        if(player.row == enemies[i].pos.row && player.col == enemies[i].pos.col) {
            game_over = true;
        }
    }
}

/* Main game loop */
void game_loop() {
    while(!game_over) {
        draw_board();
        draw_player();
        draw_pellets();
        draw_enemies();
        int keycode = getchar();
        if(keycode == 27) { //Check for arrow key input
            getchar(); //Consume the [
            keycode = getchar();
            move_player(keycode);
        }
        move_enemies();
        check_pellet_collisions();
        check_enemy_collisions();
    }
}