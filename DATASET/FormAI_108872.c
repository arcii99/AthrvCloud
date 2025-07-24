//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 10

typedef struct {
    int x;
    int y;
} Position;

const char PLAYER = '^';
const char ALIEN = 'V';
const char BULLET = '*';

int score = 0;

char grid[ROWS][COLS];

void init_grid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
    }
}

void print_grid() {
    printf("SCORE: %d\n", score);
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void init_player(Position *player) {
    player->x = COLS/2;
    player->y = ROWS-1;
    grid[player->y][player->x] = PLAYER;
}

void init_aliens(Position aliens[]) {
    for(int i = 0; i < COLS; i++) {
        aliens[i].x = i;
        aliens[i].y = 0;
        grid[aliens[i].y][aliens[i].x] = ALIEN;
    }
}

void move_alien(Position *alien) {
    grid[alien->y][alien->x] = ' ';
    alien->y++;
    grid[alien->y][alien->x] = ALIEN;
}

void move_bullet(Position *bullet) {
    grid[bullet->y][bullet->x] = ' ';
    bullet->y--;
    grid[bullet->y][bullet->x] = BULLET;
}

bool is_collision(Position a, Position b) {
    if(a.x == b.x && a.y == b.y) {
        return true;
    }
    return false;
}

void shoot(Position *bullet, Position player) {
    bullet->x = player.x;
    bullet->y = player.y-1;
    grid[bullet->y][bullet->x] = BULLET;
}

int main() {
    srand(time(NULL));

    Position player;
    Position aliens[COLS];
    Position bullet;

    init_grid();
    init_player(&player);
    init_aliens(aliens);
    print_grid();

    char input = '\0';
    while(input != 'q') {
        if(rand() % 10 == 0) {
            int random_index = rand() % COLS;
            shoot(&bullet, aliens[random_index]);
        }

        if(input == 'a' && player.x > 0) {
            grid[player.y][player.x] = ' ';
            player.x--;
            grid[player.y][player.x] = PLAYER;
        } else if(input == 'd' && player.x < COLS-1) {
            grid[player.y][player.x] = ' ';
            player.x++;
            grid[player.y][player.x] = PLAYER;
        }

        for(int i = 0; i < COLS; i++) {
            if(is_collision(bullet, aliens[i])) {
                score++;
                grid[aliens[i].y][aliens[i].x] = ' ';
                grid[bullet.y][bullet.x] = ' ';
            }
        }

        if(bullet.y > 0) {
            move_bullet(&bullet);
        } else {
            grid[bullet.y][bullet.x] = ' ';
        }

        for(int i = 0; i < COLS; i++) {
            if(is_collision(player, aliens[i])) {
                printf("GAME OVER\n");
                return 0;
            }
        }

        for(int i = 0; i < COLS; i++) {
            if(aliens[i].y == ROWS-1) {
                printf("GAME OVER\n");
                return 0;
            }
        }

        for(int i = 0; i < COLS; i++) {
            move_alien(&aliens[i]);
        }
        
        print_grid();

        printf("Enter 'a' to move left, 'd' to move right, and 'q' to quit: ");
        scanf(" %c", &input);
    }

    printf("Thanks for playing!\n");
    return 0;
}