//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

int player_x;
int player_y;
int player_lives = 3;
int alien_speed = 2;
int score = 0;

char game_board[HEIGHT][WIDTH];

void init_game_board()
{
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            game_board[i][j] = '.';
        }
    }
}

void draw_game_board()
{
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", game_board[i][j]);
        }
        printf("\n");
    }
}

void move_player(int direction)
{
    if (direction == -1 && player_x > 0) {
        game_board[player_y][player_x] = '.';
        player_x--;
    } else if (direction == 1 && player_x < WIDTH - 1) {
        game_board[player_y][player_x] = '.';
        player_x++;
    }

    game_board[player_y][player_x] = 'X';
}

void move_aliens()
{
    int i, j;

    for (i = HEIGHT - 1; i >= 0; i--) {
        for (j = 0; j < WIDTH; j++) {
            if (game_board[i][j] == 'O') {
                game_board[i][j] = '.';
                game_board[i + alien_speed][j] = 'O';
            }
        }
    }
}

void create_aliens()
{
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++) {
            game_board[4 + i][10 + j * 3] = 'O';
        }
    }
}

void fire_bullet()
{
    int i;

    for (i = player_y - 1; i >= 0; i--) {
        if (game_board[i][player_x] == 'O') {
            game_board[i][player_x] = '.';
            score += 10;
            printf("Alien killed! Current score: %d\n", score);
            return;
        } else if (game_board[i][player_x] == 'X') {
            return;
        }
    }

    game_board[i][player_x] = '|';
}

int game_over()
{
    int i, j;
    for (i = HEIGHT - 1; i >= 0; i--) {
        for (j = 0; j < WIDTH; j++) {
            if (game_board[i][j] == 'O' && i == HEIGHT - 1) {
                return 1;
            } else if (game_board[i][j] == 'X' && i == HEIGHT - 1) {
                player_lives--;
                game_board[player_y][player_x] = '.';
                player_x = WIDTH / 2;
                game_board[player_y][player_x] = 'X';
                printf("Player Lives: %d\n", player_lives);
                return 0;
            }
        }
    }

    return 0;
}

int main()
{
    srand(time(NULL));

    init_game_board();
    create_aliens();
    player_x = WIDTH / 2;
    player_y = HEIGHT - 1;
    game_board[player_y][player_x] = 'X';

    while (player_lives > 0 && !game_over()) {
        draw_game_board();

        char input;
        printf("Score: %d\n", score);
        printf("Enter command (a/d/s/l): ");
        scanf(" %c", &input);

        switch (input) {
            case 'a':
                move_player(-1);
                break;
            case 'd':
                move_player(1);
                break;
            case 's':
                move_aliens();
                break;
            case 'l':
                fire_bullet();
                break;
            default:
                printf("Invalid command.\n");
        }
    }

    if (player_lives <= 0) {
        printf("Game Over! You Lose!\n");
    } else {
        printf("Game Over! You Win!\n");
    }

    return 0;
}