//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define WIDTH 80
#define HEIGHT 24
#define PLAYER_START_X 36
#define PLAYER_START_Y 22
#define ENEMY_START_X 10
#define ENEMY_START_Y 4
#define MAX_ENEMIES 10
#define P_RED "\033[31m"
#define P_RESET "\033[0m"
#define E_RED "\033[91m"
#define E_RESET "\033[0m"

// Structs
typedef struct {
    int x;
    int y;
} Position;

typedef enum {
    PLAYER,
    ENEMY,
    BULLET
} Entity;

typedef struct {
    Entity type;
    Position pos;
} Object;

// Function Prototypes
void clear_screen();
void draw_screen(Object player, Object enemies[], int num_enemies, Object bullets[], int num_bullets);
void move_player(Object *player, char direction);
void move_enemies(Object enemies[], int num_enemies);
void fire_bullet(Object bullets[], int *num_bullets, int x, int y);
void move_bullets(Object bullets[], int *num_bullets);
int is_collision(Object obj1, Object obj2);
int rand_range(int min, int max);

// Main Function
int main() {
    // Initialize game objects
    Object player = {PLAYER, {PLAYER_START_X, PLAYER_START_Y}};
    Object enemies[MAX_ENEMIES];
    int num_enemies = 0;
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].type = ENEMY;
        enemies[i].pos.x = ENEMY_START_X + (i % 5) * 6;
        enemies[i].pos.y = ENEMY_START_Y + (i / 5) * 2;
        if (enemies[i].pos.y < HEIGHT) {
            num_enemies++;
        }
    }
    Object bullets[MAX_ENEMIES];
    int num_bullets = 0;

    // Seed random number generator
    srand(time(NULL));

    // Main game loop
    char input;
    int game_over = 0;
    int score = 0;
    while (!game_over) {
        // Clear screen and draw objects
        clear_screen();
        draw_screen(player, enemies, num_enemies, bullets, num_bullets);

        // Process user input
        input = getchar();
        if (input == 'q') {
            game_over = 1;
        }
        else if (input == 'a') {
            move_player(&player, 'L');
        }
        else if (input == 'd') {
            move_player(&player, 'R');
        }
        else if (input == ' ') {
            fire_bullet(bullets, &num_bullets, player.pos.x, player.pos.y - 1);
        }

        // Move enemies and bullets
        move_enemies(enemies, num_enemies);
        move_bullets(bullets, &num_bullets);

        // Check for collisions
        for (int i = 0; i < num_enemies; i++) {
            if (is_collision(player, enemies[i])) {
                printf(P_RED "You were hit by an alien! Game Over!\n" P_RESET);
                game_over = 1;
            }
            for (int j = 0; j < num_bullets; j++) {
                if (is_collision(enemies[i], bullets[j])) {
                    enemies[i].pos.y = HEIGHT + 1;
                    score += 10;
                }
            }
        }

        // Check win condition
        if (num_enemies == 0) {
            printf(E_RED "You have defeated all aliens! You win!\n" E_RESET);
            game_over = 1;
        }
    }

    // Print final score
    printf("Your final score is: %d\n", score);

    return 0;
}

// Function Definitions
void clear_screen() {
    system("clear");
}

void draw_screen(Object player, Object enemies[], int num_enemies, Object bullets[], int num_bullets) {
    // Draw player
    printf("%*s#\n", player.pos.x, "");

    // Draw enemies
    for (int i = 0; i < num_enemies; i++) {
        if (enemies[i].pos.y < HEIGHT) {
            printf("%*sO\n", enemies[i].pos.x, "");
        }
    }

    // Draw bullets
    for (int i = 0; i < num_bullets; i++) {
        printf("%*s|\n", bullets[i].pos.x, "");
    }

    // Draw bottom line
    printf("+");
    for (int i = 1; i < WIDTH; i++) {
        printf("-");
    }
    printf("+\n");
}

void move_player(Object *player, char direction) {
    if (direction == 'L' && player->pos.x > 0) {
        player->pos.x--;
    }
    else if (direction == 'R' && player->pos.x < WIDTH - 1) {
        player->pos.x++;
    }
}

void move_enemies(Object enemies[], int num_enemies) {
    for (int i = 0; i < num_enemies; i++) {
        if (enemies[i].pos.y < HEIGHT) {
            enemies[i].pos.x += rand_range(-1, 1);
            enemies[i].pos.y++;
        }
    }
}

void fire_bullet(Object bullets[], int *num_bullets, int x, int y) {
    if (*num_bullets < MAX_ENEMIES) {
        bullets[*num_bullets].type = BULLET;
        bullets[*num_bullets].pos.x = x;
        bullets[*num_bullets].pos.y = y;
        (*num_bullets)++;
    }
}

void move_bullets(Object bullets[], int *num_bullets) {
    for (int i = 0; i < *num_bullets; i++) {
        bullets[i].pos.y--;
    }
    int i = 0;
    while (i < *num_bullets) {
        if (bullets[i].pos.y < 0) {
            bullets[i] = bullets[*num_bullets - 1];
            (*num_bullets)--;
        }
        else {
            i++;
        }
    }
}

int is_collision(Object obj1, Object obj2) {
    if (obj1.pos.y == obj2.pos.y && abs(obj1.pos.x - obj2.pos.x) < 2) {
        return 1;
    }
    else {
        return 0;
    }
}

int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}