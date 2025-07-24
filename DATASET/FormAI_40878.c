//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: enthusiastic
/* Welcome to my C Space Invaders Game Clone! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the game board size */
#define BOARD_SIZE_X 20
#define BOARD_SIZE_Y 10

/* Define the game board boundary */
#define BOARD_LEFT_BOUNDARY 0
#define BOARD_RIGHT_BOUNDARY BOARD_SIZE_X - 1
#define BOARD_TOP_BOUNDARY 0
#define BOARD_BOTTOM_BOUNDARY BOARD_SIZE_Y - 1

/* Define the player's initial position */
#define PLAYER_INIT_POS_X BOARD_SIZE_X / 2
#define PLAYER_INIT_POS_Y BOARD_SIZE_Y - 1

/* Define the enemy's initial position */
int enemy_pos_x = BOARD_SIZE_X / 2;
int enemy_pos_y = BOARD_TOP_BOUNDARY;

/* Define the player's initial health */
#define PLAYER_INIT_HEALTH 3

/* Define the player's and enemy's bullet speed */
#define BULLET_SPEED 1

/* Define the player's bullet damage */
#define BULLET_DAMAGE 1

/* Define the enemy's bullet damage */
#define ENEMY_BULLET_DAMAGE 1

/* Define the player's score */
int score = 0;

/* Define the player's health */
int player_health = PLAYER_INIT_HEALTH;

/* Define the player's position */
int player_pos_x = PLAYER_INIT_POS_X;
int player_pos_y = PLAYER_INIT_POS_Y;

/* Define the player's bullet */
int player_bullet_pos_x = 0;
int player_bullet_pos_y = 0;
int player_bullet_exists = 0;

/* Define the enemy's bullet */
int enemy_bullet_pos_x = 0;
int enemy_bullet_pos_y = 0;
int enemy_bullet_exists = 0;

/* Define the game board */
char game_board[BOARD_SIZE_Y][BOARD_SIZE_X];

/* Print the game board */
void print_board() {
    int i, j;

    printf("Score: %d\n", score);
    printf("Health: %d\n", player_health);

    for(i = 0; i < BOARD_SIZE_Y; i++) {
        for(j = 0; j < BOARD_SIZE_X; j++) {
            printf("%c ", game_board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

/* Update the player's bullet position */
void update_player_bullet_pos() {
    player_bullet_pos_y--;
    if(player_bullet_pos_y == BOARD_TOP_BOUNDARY) {
        player_bullet_exists = 0;
    }
}

/* Update the enemy's bullet position */
void update_enemy_bullet_pos() {
    enemy_bullet_pos_y++;
    if(enemy_bullet_pos_y == BOARD_BOTTOM_BOUNDARY) {
        enemy_bullet_exists = 0;
    }
}

/* Move the player left */
void move_player_left() {
    if(player_pos_x > BOARD_LEFT_BOUNDARY) {
        player_pos_x--;
    }
}

/* Move the player right */
void move_player_right() {
    if(player_pos_x < BOARD_RIGHT_BOUNDARY) {
        player_pos_x++;
    }
}

/* Fire the player's bullet */
void fire_player_bullet() {
    if(!player_bullet_exists) {
        player_bullet_pos_x = player_pos_x;
        player_bullet_pos_y = player_pos_y - 1;
        player_bullet_exists = 1;
    }
}

/* Fire the enemy's bullet */
void fire_enemy_bullet() {
    if(!enemy_bullet_exists) {
        enemy_bullet_pos_x = enemy_pos_x;
        enemy_bullet_pos_y = enemy_pos_y + 1;
        enemy_bullet_exists = 1;
    }
}

/* Check if the player's bullet has hit the enemy */
void check_player_bullet_hit_enemy() {
    if(player_bullet_pos_x == enemy_pos_x && player_bullet_pos_y == enemy_pos_y) {
        score++;
        enemy_pos_x = rand() % BOARD_SIZE_X;
        enemy_pos_y = BOARD_TOP_BOUNDARY;
        player_bullet_exists = 0;
    }
}

/* Check if the enemy's bullet has hit the player */
void check_enemy_bullet_hit_player() {
    if(enemy_bullet_pos_x == player_pos_x && enemy_bullet_pos_y == player_pos_y) {
        player_health--;
        enemy_bullet_exists = 0;
    }
}

/* Initialize the game board */
void init_board() {
    int i, j;

    for(i = 0; i < BOARD_SIZE_Y; i++) {
        for(j = 0; j < BOARD_SIZE_X; j++) {
            game_board[i][j] = ' ';
        }
    }

    game_board[player_pos_y][player_pos_x] = 'P';
    game_board[enemy_pos_y][enemy_pos_x] = 'E';
}

/* Update the game board */
void update_board() {
    int i, j;

    init_board();

    if(player_bullet_exists) {
        game_board[player_bullet_pos_y][player_bullet_pos_x] = '|';
    }

    if(enemy_bullet_exists) {
        game_board[enemy_bullet_pos_y][enemy_bullet_pos_x] = '|';
    }

    if(player_health > 0) {
        game_board[player_pos_y][player_pos_x] = 'P';
    }

    if(player_health <= 0) {
        printf("Game Over!\n");
        exit(0);
    }

    for(i = BOARD_BOTTOM_BOUNDARY; i >= BOARD_TOP_BOUNDARY; i--) {
        if(game_board[i][enemy_pos_x] == 'P') {
            player_health -= ENEMY_BULLET_DAMAGE;
            enemy_bullet_exists = 0;
        }
    }

    if(enemy_pos_y < BOARD_BOTTOM_BOUNDARY) {
        enemy_pos_y++;
    } else {
        enemy_pos_x = rand() % BOARD_SIZE_X;
        enemy_pos_y = BOARD_TOP_BOUNDARY;
        score -= 2;
    }

    check_player_bullet_hit_enemy();
    check_enemy_bullet_hit_player();
}

/* Main function */
int main() {
    char input_char;

    /* Seed random number generator */
    srand(time(NULL));

    /* Initialize game board */
    init_board();

    while(1) {
        /* Clear screen and print game board */
        system("clear");
        print_board();

        /* Process player input */
        scanf("%c", &input_char);

        if(input_char == 'a') {
            move_player_left();
        } else if(input_char == 'd') {
            move_player_right();
        } else if(input_char == 'w') {
            fire_player_bullet();
        }

        /* Update game board */
        update_board();

        /* Fire enemy bullet */
        if(rand() % 10 == 0) {
            fire_enemy_bullet();
        }

        /* Update bullet positions */
        if(player_bullet_exists) {
            update_player_bullet_pos();
        }

        if(enemy_bullet_exists) {
            update_enemy_bullet_pos();
        }
    }

    return 0;
}