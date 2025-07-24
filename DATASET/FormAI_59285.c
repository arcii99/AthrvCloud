//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_WIDTH 30
#define BOARD_HEIGHT 20

typedef struct {
    int x;
    int y;
    bool is_alive;
} Alien;

typedef struct {
    int x;
    int y;
    bool is_alive;
} Player;

typedef struct {
    int x;
    int y;
    bool is_alive;
} Bullet;

void initialize_board(char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    // Fill with empty spaces
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }

    // Add player
    board[BOARD_HEIGHT-1][BOARD_WIDTH/2] = 'P';
}

void print_board(char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_aliens(Alien aliens[3][10])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            aliens[i][j].x = j*3 + 1;
            aliens[i][j].y = i*2 + 1;
            aliens[i][j].is_alive = true;
        }
    }
}

void print_aliens(Alien aliens[3][10], char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (aliens[i][j].is_alive) {
                board[aliens[i][j].y][aliens[i][j].x] = 'A';
            }
        }
    }
}

void initialize_player(Player *player)
{
    player->x = BOARD_WIDTH/2;
    player->y = BOARD_HEIGHT-1;
    player->is_alive = true;
}

void print_player(Player *player, char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    board[player->y][player->x] = 'P';
}

void initialize_bullet(Bullet *bullet)
{
    bullet->is_alive = false;
}

void print_bullet(Bullet *bullet, char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    if (bullet->is_alive) {
        board[bullet->y][bullet->x] = '|';
    }
}

void move_player(Player *player, char direction)
{
    if (direction == 'l' && player->x > 0) {
        player->x--;
    } else if (direction == 'r' && player->x < BOARD_WIDTH-1) {
        player->x++;
    }
}

void move_bullet(Bullet *bullet)
{
    if (bullet->is_alive) {
        bullet->y--;
        if (bullet->y < 0) {
            bullet->is_alive = false;
        }
    }
}

void move_aliens(Alien aliens[3][10], char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    // Check if any aliens have hit the wall
    bool hit_wall = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (aliens[i][j].is_alive && aliens[i][j].y == BOARD_HEIGHT-1) {
                hit_wall = true;
                break;
            }
        }
    }

    // If any aliens hit the wall, game over
    if (hit_wall) {
        printf("\nGAME OVER\n");
        exit(EXIT_SUCCESS);
    }

    // Generate random number to determine if aliens should move left, right, or down
    srand(time(NULL));
    int direction = rand() % 3;

    // Move aliens left
    if (direction == 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10; j++) {
                if (aliens[i][j].is_alive) {
                    aliens[i][j].x--;
                    if (aliens[i][j].x < 0) {
                        aliens[i][j].x = 0;
                    }
                }
            }
        }
    }

    // Move aliens right
    else if (direction == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 9; j >= 0; j--) {
                if (aliens[i][j].is_alive) {
                    aliens[i][j].x++;
                    if (aliens[i][j].x > BOARD_WIDTH-1) {
                        aliens[i][j].x = BOARD_WIDTH-1;
                    }
                }
            }
        }
    }

    // Move aliens down
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10; j++) {
                if (aliens[i][j].is_alive) {
                    aliens[i][j].y++;
                }
            }
        }
    }
}

void shoot_bullet(Player *player, Bullet *bullet)
{
    if (!bullet->is_alive) {
        bullet->x = player->x;
        bullet->y = player->y-1;
        bullet->is_alive = true;
    }
}

void check_collisions(Player *player, Bullet *bullet, Alien aliens[3][10])
{
    // Check if bullet has hit an alien
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (aliens[i][j].is_alive && bullet->is_alive && bullet->x == aliens[i][j].x && bullet->y == aliens[i][j].y) {
                aliens[i][j].is_alive = false;
                bullet->is_alive = false;
            }
        }
    }

    // Check if an alien has hit the player
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (aliens[i][j].is_alive && player->x == aliens[i][j].x && player->y == aliens[i][j].y) {
                printf("\nGAME OVER\n");
                exit(EXIT_SUCCESS);
            }
        }
    }
}

int main(void)
{
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    initialize_board(board);

    Alien aliens[3][10];
    initialize_aliens(aliens);

    Player player;
    initialize_player(&player);

    Bullet bullet;
    initialize_bullet(&bullet);

    char input;

    do {
        system("clear");
        print_board(board);
        print_aliens(aliens, board);
        print_player(&player, board);
        print_bullet(&bullet, board);

        input = getchar();
        getchar();  // Consume newline character

        // Move player
        if (input == 'a') {
            move_player(&player, 'l');
        } else if (input == 'd') {
            move_player(&player, 'r');
        }

        // Shoot bullet
        else if (input == ' ') {
            shoot_bullet(&player, &bullet);
        }

        move_bullet(&bullet);
        move_aliens(aliens, board);
        check_collisions(&player, &bullet, aliens);
    } while (1);

    return 0;
}