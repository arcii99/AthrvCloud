//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 10
#define SPAWN_CHANCE 20
#define BULLET_SPEED 3
#define ASTEROID_SPEED 2
#define PLAYER_COLOR "\033[0;32m"
#define ASTEROID_COLOR "\033[0;33m"
#define BULLET_COLOR "\033[0;31m"
#define RESET_COLOR "\033[0m"
#define NEWLINE puts("")

typedef struct {
    int x;
    int y;
} Vector2;

typedef struct {
    Vector2 position;
    Vector2 velocity;
} Entity;

typedef struct {
    bool alive;
    Entity entity;
} Asteroid;

typedef struct {
    bool alive;
    Entity entity;
    int direction;
} Bullet;

void clear_screen() {
    system("clear");
}

void set_cursor_position(int x, int y) {
    printf("\033[%d;%df", y, x);
}

void set_color(char* color) {
    printf("%s", color);
}

Vector2 add_vectors(Vector2 v1, Vector2 v2) {
    Vector2 result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

float random_float(float min, float max) {
    return ((float)rand() / RAND_MAX) * (max - min) + min;
}

bool random_chance(float chance) {
    return random_float(0, 100) < chance;
}

int wrap(int value, int min, int max) {
    int range = max - min;
    return (value - min) % range + min;
}

void print_board(Asteroid asteroids[], int asteroid_count, Bullet bullets[], int bullet_count, Entity player) {
   for (int y = 0; y < BOARD_SIZE; y++) {
        printf("|");
        for (int x = 0; x < BOARD_SIZE; x++) {
            bool printed = false;
            if (x == player.position.x && y == player.position.y) {
                set_color(PLAYER_COLOR);
                printf("X");
                set_color(RESET_COLOR);
                printed = true;
            }

            for (int i = 0; i < asteroid_count; i++) {
                if (x == asteroids[i].entity.position.x && y == asteroids[i].entity.position.y) {
                    set_color(ASTEROID_COLOR);
                    printf("O");
                    set_color(RESET_COLOR);
                    printed = true;
                    break;
                }
            }

            if (!printed) {
                for (int i = 0; i < bullet_count; i++) {
                    if (x == bullets[i].entity.position.x && y == bullets[i].entity.position.y) {
                        set_color(BULLET_COLOR);
                        printf(".");
                        set_color(RESET_COLOR);
                        printed = true;
                        break;
                    }
                }
            }

            if (!printed) {
                printf(" ");
            }
        }
        printf("|\n");
    }
}

int main() {
    srand(time(NULL));
    Asteroid asteroids[BOARD_SIZE];
    Bullet bullets[BOARD_SIZE];
    int asteroid_count = 0;
    int bullet_count = 0;

    Entity player;
    player.position.x = BOARD_SIZE / 2;
    player.position.y = BOARD_SIZE / 2;

    bool running = true;
    while (running) {
        if (random_chance(SPAWN_CHANCE)) {
            if (asteroid_count < BOARD_SIZE) {
                asteroids[asteroid_count].alive = true;
                asteroids[asteroid_count].entity.position.x = random_float(0, BOARD_SIZE);
                asteroids[asteroid_count].entity.position.y = random_float(0, BOARD_SIZE);
                asteroids[asteroid_count].entity.velocity.x = random_float(-ASTEROID_SPEED, ASTEROID_SPEED);
                asteroids[asteroid_count].entity.velocity.y = random_float(-ASTEROID_SPEED, ASTEROID_SPEED);
                asteroid_count++;
            }
        }

        if (bullet_count < BOARD_SIZE) {
            if (getchar() == ' ') {
                bullets[bullet_count].alive = true;
                bullets[bullet_count].entity.position.x = player.position.x;
                bullets[bullet_count].entity.position.y = player.position.y;
                bullets[bullet_count].entity.velocity.x = BULLET_SPEED;
                bullets[bullet_count].entity.velocity.y = 0;
                bullets[bullet_count].direction = 1;
                bullet_count++;
            }
        }

        clear_screen();

        for (int i = 0; i < asteroid_count; i++) {
            asteroids[i].entity.position = add_vectors(asteroids[i].entity.position, asteroids[i].entity.velocity);
            asteroids[i].entity.position.x = wrap(asteroids[i].entity.position.x, 0, BOARD_SIZE);
            asteroids[i].entity.position.y = wrap(asteroids[i].entity.position.y, 0, BOARD_SIZE);
        }

        for (int i = 0; i < bullet_count; i++) {
            bullets[i].entity.position = add_vectors(bullets[i].entity.position, bullets[i].entity.velocity);
            bullets[i].entity.position.x = wrap(bullets[i].entity.position.x, 0, BOARD_SIZE);
            bullets[i].entity.position.y = wrap(bullets[i].entity.position.y, 0, BOARD_SIZE);
        }

        print_board(asteroids, asteroid_count, bullets, bullet_count, player);

        Vector2 movement;
        movement.x = 0;
        movement.y = 0;
        if (getchar() == 'w') {
            movement.y = -1;
        }
        if (getchar() == 'a') {
            movement.x = -1;
        }
        if (getchar() == 's') {
            movement.y = 1;
        }
        if (getchar() == 'd') {
            movement.x = 1;
        }
        player.position = add_vectors(player.position, movement);
        player.position.x = wrap(player.position.x, 0, BOARD_SIZE);
        player.position.y = wrap(player.position.y, 0, BOARD_SIZE);

        for (int i = 0; i < asteroid_count; i++) {
            for (int j = 0; j < bullet_count; j++) {
                if (asteroids[i].entity.position.x == bullets[j].entity.position.x && asteroids[i].entity.position.y == bullets[j].entity.position.y) {
                    asteroids[i].alive = false;
                    bullets[j].alive = false;
                }
            }
        }

        for (int i = 0; i < asteroid_count; i++) {
            if (asteroids[i].entity.position.x == player.position.x && asteroids[i].entity.position.y == player.position.y) {
                running = false;
            }
        }

        for (int i = 0; i < asteroid_count; i++) {
            if (!asteroids[i].alive) {
                asteroids[i] = asteroids[asteroid_count - 1];
                asteroid_count--;
            }
        }

        for (int i = 0; i < bullet_count; i++) {
            if (!bullets[i].alive) {
                bullets[i] = bullets[bullet_count - 1];
                bullet_count--;
            }
        }

        set_cursor_position(0, BOARD_SIZE + 1);
        printf("Press CTRL+C to exit...");

        usleep(100000);
    }

    clear_screen();
    set_cursor_position(0, 0);
    printf("Game over!\n");

    return 0;
}