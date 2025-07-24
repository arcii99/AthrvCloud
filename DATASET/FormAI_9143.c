//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining the playing board size
#define BOARD_WIDTH 50
#define BOARD_HEIGHT 20

// Defining the player starting position
#define PLAYER_START_X 25
#define PLAYER_START_Y 18

// Defining the enemy starting position
#define ENEMY_START_X 25
#define ENEMY_START_Y 5

// Defining the bullet speed
#define BULLET_SPEED 2

// Defining the enemy fire rate
#define ENEMY_FIRE_RATE 10

// Defining the player lives
#define PLAYER_LIVES 3

// Defining the maximum number of bullets
#define MAX_BULLETS 20

// Initializing the playing board and player variables
char board[BOARD_HEIGHT][BOARD_WIDTH];
int player_x = PLAYER_START_X;
int player_y = PLAYER_START_Y;
int enemy_x = ENEMY_START_X;
int enemy_y = ENEMY_START_Y;
int player_bullets[MAX_BULLETS][2];
int player_bullets_count = 0;
int player_lives = PLAYER_LIVES;
int enemy_fire_count = 0;
int score = 0;

// Function to draw the playing board
void draw_board() {
    for(int i = 0; i < BOARD_HEIGHT; i++) {
        for(int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the board and player variables
void initialize_board() {
    for(int i = 0; i < BOARD_HEIGHT; i++) {
        for(int j = 0; j < BOARD_WIDTH; j++) {
            if(i == 0 || i == BOARD_HEIGHT - 1) {
                board[i][j] = '-';
            } else if(j == 0 || j == BOARD_WIDTH - 1) {
                board[i][j] = '|';
            } else {
                board[i][j] = ' ';
            }
        }
    }
    board[player_y][player_x] = '^';
    board[enemy_y][enemy_x] = 'V';
}

// Function to move the player left
void move_player_left() {
    if(player_x > 1) {
        board[player_y][player_x] = ' ';
        player_x--;
        board[player_y][player_x] = '^';
    }
}

// Function to move the player right
void move_player_right() {
    if(player_x < BOARD_WIDTH - 2) {
        board[player_y][player_x] = ' ';
        player_x++;
        board[player_y][player_x] = '^';
    }
}

// Function to fire player bullets
void fire_player_bullet() {
    if(player_bullets_count < MAX_BULLETS) {
        player_bullets[player_bullets_count][0] = player_x;
        player_bullets[player_bullets_count][1] = player_y - 1;
        player_bullets_count++;
    }
}

// Function to move the player bullets
void move_player_bullets() {
    for(int i = 0; i < player_bullets_count; i++) {
        board[player_bullets[i][1]][player_bullets[i][0]] = ' ';
        player_bullets[i][1] -= BULLET_SPEED;
        if(player_bullets[i][1] < 1) {
            player_bullets_count--;
            player_bullets[i][0] = player_bullets[player_bullets_count][0];
            player_bullets[i][1] = player_bullets[player_bullets_count][1];
        } else {
            board[player_bullets[i][1]][player_bullets[i][0]] = '|';
        }
    }
}

// Function for the enemy to fire bullets
void enemy_fire_bullet() {
    if(enemy_fire_count >= ENEMY_FIRE_RATE) {
        int bullet_x = enemy_x;
        int bullet_y = enemy_y + 1;
        while(bullet_y < BOARD_HEIGHT - 1) {
            if(board[bullet_y][bullet_x] == '|') {
                board[bullet_y][bullet_x] = ' ';
                break;
            } else if(bullet_x == player_x && bullet_y == player_y) {
                board[bullet_y][bullet_x] = ' ';
                player_lives--;
                break;
            } else {
                board[bullet_y][bullet_x] = '*';
                bullet_y++;
            }
        }
        enemy_fire_count = 0;
    } else {
        enemy_fire_count++;
    }
}

// Function to move the enemy left and right
void move_enemy() {
    if((enemy_x == BOARD_WIDTH - 2) || (enemy_x == 1)) {
        enemy_y++;
    } else {
        if((rand() % 2) == 0) {
            enemy_x++;
        } else {
            enemy_x--;
        }
    }
}

// Function to check for collisions between the player bullets and the enemy
void check_for_collisions() {
    for(int i = 0; i < player_bullets_count; i++) {
        if(player_bullets[i][0] == enemy_x && player_bullets[i][1] == enemy_y) {
            board[player_bullets[i][1]][player_bullets[i][0]] = ' ';
            player_bullets[i][0] = player_bullets[player_bullets_count - 1][0];
            player_bullets[i][1] = player_bullets[player_bullets_count - 1][1];
            player_bullets_count--;
            enemy_x = ENEMY_START_X;
            enemy_y = ENEMY_START_Y;
            score += 10;
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    initialize_board();
    int game_over = 0;
    while(!game_over) {
        system("clear");
        draw_board();
        printf("Score: %d\tLives: %d\n\n", score, player_lives);
        char input;
        scanf(" %c", &input);
        switch(input) {
            case 'a': move_player_left(); break;
            case 'd': move_player_right(); break;
            case ' ': fire_player_bullet(); break;
        }
        move_player_bullets();
        enemy_fire_bullet();
        move_enemy();
        check_for_collisions();
        if(player_lives <= 0) {
            game_over = 1;
            printf("\nGame Over! Your Score: %d\n", score);
        } else if(score == 100) {
            game_over = 1;
            printf("\nYou Win! Your Score: %d\n", score);
        }
    }
    return 0;
}