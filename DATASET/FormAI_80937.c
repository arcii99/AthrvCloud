//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: systematic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define BOARD_WIDTH 30
#define BOARD_HEIGHT 20
#define SHIP_HEIGHT 2
#define SHIP_WIDTH 5
#define ENEMY_HEIGHT 2
#define ENEMY_WIDTH 3
#define MAX_ENEMIES 15

bool game_over = false;
bool win = false;

int score = 0;

int random_number(int min_num, int max_num) {
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1;
    } else {
        low_num = max_num + 1;
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

struct Point {
    int x;
    int y;
};

struct Board {
    char board[BOARD_HEIGHT][BOARD_WIDTH];
};

struct Ship {
    struct Point topLeft;
};

struct Enemy {
    struct Point topLeft;
    bool alive;
};

struct Board board;
struct Ship ship;
struct Enemy enemies[MAX_ENEMIES];

void init_board() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (i == BOARD_HEIGHT - 1) {
                board.board[i][j] = '-';
            } else {
                board.board[i][j] = ' ';
            }
        }
    }
}

void init_ship() {
    ship.topLeft.x = (BOARD_WIDTH - SHIP_WIDTH) / 2;
    ship.topLeft.y = BOARD_HEIGHT - SHIP_HEIGHT - 1;

    for (int i = 0; i < SHIP_HEIGHT; i++) {
        for (int j = 0; j < SHIP_WIDTH; j++) {
            board.board[ship.topLeft.y + i][ship.topLeft.x + j] = '|';
        }
    }
}

void init_enemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].topLeft.x = random_number(0, BOARD_WIDTH - ENEMY_WIDTH);
        enemies[i].topLeft.y = random_number(0, BOARD_HEIGHT / 2);
        enemies[i].alive = true;

        for (int j = 0; j < ENEMY_HEIGHT; j++) {
            for (int k = 0; k < ENEMY_WIDTH; k++) {
                board.board[enemies[i].topLeft.y + j][enemies[i].topLeft.x + k] = '*';
            }
        }
    }
}

void print_board() {
    system("clear");

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board.board[i][j]);
        }
        printf("\n");
    }

    printf("Score: %d\n", score);
}

void remove_entity(struct Point pos, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board.board[pos.y + i][pos.x + j] = ' ';
        }
    }
}

void update_entity(struct Point oldPos, struct Point newPos, int height, int width, char symbol) {
    remove_entity(oldPos, height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board.board[newPos.y + i][newPos.x + j] = symbol;
        }
    }
}

bool check_collision(struct Point point, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (point.y + i >= BOARD_HEIGHT || point.x + j >= BOARD_WIDTH) {
                return true;
            }
            if (board.board[point.y + i][point.x + j] != ' ') {
                return true;
            }
        }
    }
    return false;
}

void move_ship_left() {
    if (ship.topLeft.x > 0) {
        struct Point oldPos = ship.topLeft;
        ship.topLeft.x -= 1;
        if (!check_collision(ship.topLeft, SHIP_HEIGHT, SHIP_WIDTH)) {
            update_entity(oldPos, ship.topLeft, SHIP_HEIGHT, SHIP_WIDTH, '|');
        } else {
            ship.topLeft = oldPos;
        }
    }
}

void move_ship_right() {
    if (ship.topLeft.x < BOARD_WIDTH - SHIP_WIDTH) {
        struct Point oldPos = ship.topLeft;
        ship.topLeft.x += 1;
        if (!check_collision(ship.topLeft, SHIP_HEIGHT, SHIP_WIDTH)) {
            update_entity(oldPos, ship.topLeft, SHIP_HEIGHT, SHIP_WIDTH, '|');
        } else {
            ship.topLeft = oldPos;
        }
    }
}

void move_enemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].alive) {
            struct Point oldPos = enemies[i].topLeft;
            enemies[i].topLeft.y += 1;
            if (enemies[i].topLeft.y >= BOARD_HEIGHT) {
                enemies[i].topLeft.y = 0;
                enemies[i].topLeft.x = random_number(0, BOARD_WIDTH - ENEMY_WIDTH);
            } else {
                if (!check_collision(enemies[i].topLeft, ENEMY_HEIGHT, ENEMY_WIDTH)) {
                    update_entity(oldPos, enemies[i].topLeft, ENEMY_HEIGHT, ENEMY_WIDTH, '*');
                } else {
                    enemies[i].topLeft = oldPos;
                }
            }
            if (enemies[i].topLeft.y == ship.topLeft.y) {
                if (enemies[i].topLeft.x >= ship.topLeft.x && enemies[i].topLeft.x < ship.topLeft.x + SHIP_WIDTH) {
                    remove_entity(ship.topLeft, SHIP_HEIGHT, SHIP_WIDTH);
                    game_over = true;
                }
            }
        }
    }
}

void fire() {
    struct Point bulletPos = {ship.topLeft.x + 2, ship.topLeft.y - 1};
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].alive) {
            if (bulletPos.y == enemies[i].topLeft.y && bulletPos.x >= enemies[i].topLeft.x && bulletPos.x < enemies[i].topLeft.x + ENEMY_WIDTH) {
                enemies[i].alive = false;
                remove_entity(enemies[i].topLeft, ENEMY_HEIGHT, ENEMY_WIDTH);
                score += 10;
                if (score >= 150) {
                    win = true;
                    game_over = true;
                }
                return;
            }
        }
    }
    struct Point oldPos = bulletPos;
    bulletPos.y -= 1;
    if (!check_collision(bulletPos, 1, 1)) {
        update_entity(oldPos, bulletPos, 1, 1, '.');
    }
}

int main() {
    init_board();
    init_ship();
    init_enemies();
    struct termios old_settings, new_settings;
    tcgetattr(fileno(stdin), &old_settings);
    new_settings = old_settings;
    new_settings.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(fileno(stdin), TCSANOW, &new_settings);

    while (!game_over) {
        print_board();

        int c = getchar();
        if (c == 'a') {
            move_ship_left();
        } else if (c == 'd') {
            move_ship_right();
        } else if (c == ' ') {
            fire();
        }

        move_enemies();

        usleep(100000);
    }

    print_board();
    if (win) {
        printf("You Win!\n");
    } else {
        printf("Game Over\n");
    }
    printf("Final Score: %d\n", score);

    tcsetattr(fileno(stdin), TCSANOW, &old_settings);

    return 0;
}