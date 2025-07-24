//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SHIP_MAX_HEALTH 1000
#define ALIEN_MAX_HEALTH 500
#define MAX_ENEMY_COUNT 20

struct ship {
    int x;
    int y;
    int health;
};

struct alien {
    int x;
    int y;
    int health;
};

typedef struct ship Ship;
typedef struct alien Alien;

void print_banner() {
    printf("=== Procedural Space Adventure ===\n");
}

void initialize_ship(Ship *ship) {
    ship->x = 0;
    ship->y = 0;
    ship->health = SHIP_MAX_HEALTH;
}

void move_ship(Ship *ship, int dx, int dy) {
    ship->x += dx;
    ship->y += dy;
}

void fire_lasers(Ship *ship, Alien *enemy) {
    double distance = sqrt(pow(ship->x - enemy->x, 2) + pow(ship->y - enemy->y, 2));
    double hit_probability = exp(-distance / 100.0);
    if ((double)rand() / RAND_MAX < hit_probability) {
        enemy->health -= 100;
    }
}

void initialize_enemy(Alien *enemy) {
    enemy->x = rand() % 1000 + 1000;
    enemy->y = rand() % 1000 + 1000;
    enemy->health = ALIEN_MAX_HEALTH;
}

void update_enemy_positions(Alien *enemies, int count) {
    for (int i = 0; i < count; ++i) {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        enemies[i].x += dx;
        enemies[i].y += dy;
    }
}

void draw_ship(Ship *ship) {
    printf("Ship is at (%d, %d) with %d health\n", ship->x, ship->y, ship->health);
}

void draw_enemy(Alien *enemy) {
    printf("Alien is at (%d, %d) with %d health\n", enemy->x, enemy->y, enemy->health);
}

int main() {
    srand(time(NULL));
    print_banner();

    Ship my_ship;
    initialize_ship(&my_ship);

    Alien enemies[MAX_ENEMY_COUNT];
    for (int i = 0; i < MAX_ENEMY_COUNT; ++i) {
        initialize_enemy(&enemies[i]);
    }

    while (my_ship.health > 0) {
        int dx = 0;
        int dy = 0;
        printf("Enter movement direction (dx dy): ");
        scanf("%d %d", &dx, &dy);

        move_ship(&my_ship, dx, dy);
        draw_ship(&my_ship);

        int hit_count = 0;
        for (int i = 0; i < MAX_ENEMY_COUNT; ++i) {
            if (enemies[i].health > 0) {
                fire_lasers(&my_ship, &enemies[i]);
                if (enemies[i].health <= 0) {
                    printf("Enemy %d destroyed!\n", i);
                }
                else {
                    draw_enemy(&enemies[i]);
                    ++hit_count;
                }
            }
        }

        if (hit_count == 0) {
            printf("All enemies destroyed! You win!");
            break;
        }

        update_enemy_positions(enemies, MAX_ENEMY_COUNT);
    }

    printf("Game over. Thanks for playing!\n");

    return 0;
}