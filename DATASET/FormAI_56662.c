//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define ROWS 5
#define COLUMNS 10
#define ENEMIES_COUNT 20
#define FRAME_RATE 100000
#define BULLET_SPEED 1

int score = 0;

struct Bullet {
  int x, y;
  int speed;
};

struct Enemy {
  int x, y;
  bool alive;
};

struct GameState {
  int playerX, playerY;
  bool gameOver;
  bool win;
  struct Bullet bullet;
  struct Enemy enemies[ENEMIES_COUNT];
};

struct termios orig_termios;

/* Disable terminal buffer */
void disable_raw_mode() 
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

/* Enable terminal buffer */
void enable_raw_mode() 
{
    struct termios raw = orig_termios;
    tcgetattr(STDIN_FILENO, &raw);
    atexit(disable_raw_mode);

    cfmakeraw(&raw);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

/* Get a character from terminal */
char read_key() 
{
    char c = '\0';
    if (read(STDIN_FILENO, &c, 1) == -1) 
        exit(1);
    return c;
}

/* Check if a key is pressed */
bool is_key_pressed()
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDOUT_FILENO+1, &fds, NULL, NULL, &tv);
}

/* Initialize game state */
struct GameState init_game_state()
{
    struct GameState game;
    game.playerX = 5;
    game.playerY = ROWS - 1;
    game.gameOver = false;
    game.win = false;

    game.bullet.speed = BULLET_SPEED;
    game.bullet.x = -1;
    game.bullet.y = -1;

    /* Initialize enemies */
    int enemyIndex = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (enemyIndex < ENEMIES_COUNT) {
                struct Enemy enemy;
                enemy.x = j * 2;
                enemy.y = i * 2;
                enemy.alive = true;
                game.enemies[enemyIndex] = enemy;
                enemyIndex++;
            }
        }
    }
    return game;
}

/* Draw game */
void draw(struct GameState game)
{
    /* Clear screen */
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);

    /* Draw enemies */
    for (int i = 0; i < ENEMIES_COUNT; i++) {
        if (game.enemies[i].alive) {
            printf("\033[%d;%dH", game.enemies[i].y, game.enemies[i].x);
            printf("X");
        }
    }

    /* Draw player */
    printf("\033[%d;%dH", game.playerY, game.playerX);
    printf("*");

    /* Draw bullet */
    if (game.bullet.y > -1) {
        printf("\033[%d;%dH", game.bullet.y, game.bullet.x);
        printf("|");
    }

    /* Draw score */
    printf("\033[%d;%dH", ROWS * 2, 0);
    printf("SCORE: %d", score);
}

/* Move player */
void move_player(char direction, struct GameState *game)
{
    if (direction == 'a') {
        if (game->playerX > 0)
            game->playerX--;
    } else if (direction == 'd') {
        if (game->playerX < COLUMNS * 2 - 1)
            game->playerX++;
    }
}

/* Update bullet */
void update_bullet(struct GameState *game)
{
    if (game->bullet.y != -1 && game->bullet.y != 0) {
        game->bullet.y -= game->bullet.speed;

        /* Check if bullet hits an enemy */
        for (int i = 0; i < ENEMIES_COUNT; i++) {
            if (game->enemies[i].alive && game->enemies[i].x == game->bullet.x && game->enemies[i].y == game->bullet.y) {
                game->enemies[i].alive = false;
                game->bullet.y = -1;
                score++;
                break;
            }
        }

        /* Check if player is hit */
        if (game->bullet.x == game->playerX && game->bullet.y == game->playerY) {
            game->gameOver = true;
            return;
        }
    } else {
        game->bullet.y = -1;
    }
}

/* Update enemies */
void update_enemies(struct GameState *game)
{
    /* Check if any enemy is at bottom */
    for (int i = 0; i < ENEMIES_COUNT; i++) {
        if (game->enemies[i].alive && game->enemies[i].y == ROWS * 2 - 1) {
            game->gameOver = true;
            return;
        }
    }

    /* Move enemies */
    for (int i = 0; i < ENEMIES_COUNT; i++) {
        if (game->enemies[i].alive) {
            int direction = i % 2 == 0 ? 1 : -1; // alternate movement direction
            game->enemies[i].x += direction;

            if (is_key_pressed() && read_key() == 'q')
                exit(0);

            /* Check if enemy hits player */
            if (game->enemies[i].y == game->playerY && game->enemies[i].x == game->playerX) {
                game->gameOver = true;
                return;
            }

            /* Check if enemy hits bullet */
            if (game->bullet.y != -1 && game->enemies[i].x == game->bullet.x && game->enemies[i].y == game->bullet.y) {
                game->enemies[i].alive = false;
                game->bullet.y = -1;
                score++;
            }
        }
    }
}

/* Update game */
void update(struct GameState *game)
{
    /* Move bullet */
    update_bullet(game);

    /* Move enemies */
    update_enemies(game);

    /* Check if player won */
    bool allEnemiesDead = true;
    for (int i = 0; i < ENEMIES_COUNT; i++) {
        if (game->enemies[i].alive) {
            allEnemiesDead = false;
            break;
        }
    }
    if (allEnemiesDead)
        game->win = true;
}

int main()
{
    /* Disable buffer */
    enable_raw_mode();

    srand(time(NULL));

    /* Initialize game */
    struct GameState game = init_game_state();

    while (!game.gameOver && !game.win) {
        /* Handle input */
        if (is_key_pressed()) {
            char c = read_key();
            if (c == 'q') {
                exit(0);
            } else if (c == 'a' || c == 'd') {
                move_player(c, &game);
            } else if (c == ' ') {
                if (game.bullet.y == -1) {
                    game.bullet.x = game.playerX;
                    game.bullet.y = game.playerY - 1;
                }
            }
        }

        /* Draw game */
        draw(game);

        /* Update game */
        update(&game);

        /* Sleep */
        usleep(FRAME_RATE);
    }

    /* Print game end message */
    printf("\033[%d;%dH", ROWS * 2 + 1, 0);
    printf("GAME OVER");

    disable_raw_mode();
    return 0;
}