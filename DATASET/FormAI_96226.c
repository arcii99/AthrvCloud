//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define PLAYER_SYMBOL 'X'
#define ENEMY_SYMBOL 'O'
#define BULLET_SYMBOL '|'

void sleep(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void clear_screen() {
    system("clear");
}

void draw(char matrix[HEIGHT][WIDTH]) {
    clear_screen();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

void initialize_matrix(char matrix[HEIGHT][WIDTH], char symbol) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] = symbol;
        }
    }
}

void place_player(char matrix[HEIGHT][WIDTH], int x, int y) {
    matrix[y][x] = PLAYER_SYMBOL;
}

void place_enemy(char matrix[HEIGHT][WIDTH], int x, int y) {
    matrix[y][x] = ENEMY_SYMBOL;
}

void place_bullet(char matrix[HEIGHT][WIDTH], int x, int y) {
    matrix[y][x] = BULLET_SYMBOL;
}

void move_enemy(char matrix[HEIGHT][WIDTH], int *enemy_x, int *enemy_y, int *enemy_direction, int speed) {
    if (*enemy_direction == 1) {
        if (*enemy_x < WIDTH - 1) {
            matrix[*enemy_y][*enemy_x] = ' ';
            *enemy_x += speed;
        } else {
            *enemy_direction = -1;
            *enemy_y += 1;
        }
    } else {
        if (*enemy_x > 0) {
            matrix[*enemy_y][*enemy_x] = ' ';
            *enemy_x -= speed;
        } else {
            *enemy_direction = 1;
            *enemy_y += 1;
        }
    }
    place_enemy(matrix, *enemy_x, *enemy_y);
}

void move_bullet(char matrix[HEIGHT][WIDTH], int *bullet_x, int *bullet_y, int speed) {
    matrix[*bullet_y][*bullet_x] = ' ';
    *bullet_y -= speed;
    place_bullet(matrix, *bullet_x, *bullet_y);
}

bool check_collision(int bullet_x, int bullet_y, int enemy_x, int enemy_y) {
    return bullet_y == enemy_y && bullet_x == enemy_x;
}

int main() {
    char matrix[HEIGHT][WIDTH];
    int player_x = WIDTH / 2;
    int enemy_x = WIDTH / 2;
    int enemy_y = 2;
    int enemy_direction = 1;
    int bullet_x = -1;
    int bullet_y = -1;
    bool game_over = false;

    srand(time(NULL));
    initialize_matrix(matrix, ' ');

    while (!game_over) {
        place_player(matrix, player_x, HEIGHT - 1);
        move_enemy(matrix, &enemy_x, &enemy_y, &enemy_direction, 1);

        if (bullet_y >= 0) {
            move_bullet(matrix, &bullet_x, &bullet_y, 1);
            if (bullet_y < 0) {
                bullet_x = -1;
                bullet_y = -1;
            }
        }

        draw(matrix);
        sleep(500);

        if (bullet_y >= 0 && check_collision(bullet_x, bullet_y, enemy_x, enemy_y)) {
            matrix[bullet_y][bullet_x] = ' ';
            bullet_x = -1;
            bullet_y = -1;
            enemy_x = rand() % WIDTH;
            enemy_y = 2;
        }

        if (enemy_y == HEIGHT - 1) {
            game_over = true;
        }

        if (bullet_y == enemy_y - 1 && (bullet_x == enemy_x || bullet_x == enemy_x + 1)) {
            game_over = true;
        }

        char input = getchar();
        if (input == 'a' && player_x > 0) {
            matrix[HEIGHT - 1][player_x] = ' ';
            player_x -= 1;
        } else if (input == 'd' && player_x < WIDTH - 1) {
            matrix[HEIGHT - 1][player_x] = ' ';
            player_x += 1;
        } else if (input == 's' && bullet_y < 0) {
            bullet_x = player_x;
            bullet_y = HEIGHT - 2;
        }
    }

    printf("Game over\n");
    return 0;
}