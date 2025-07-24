//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 4
#define MAX_SHOTS 10

struct player {
    int x;
    int y;
};

struct enemy {
    int x;
    int y;
    int alive;
};

struct shot {
    int x;
    int y;
    int fired;
};

void draw_board(char board[10][10], struct player p, struct enemy e[MAX_ENEMIES], struct shot s[MAX_SHOTS]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == p.y && j == p.x) {
                printf("P");
            } else if (s[i * 10 + j].fired) {
                printf("*");
            } else {
                int k;
                int enemy_found = 0;
                for (k = 0; k < MAX_ENEMIES; k++) {
                    if (e[k].alive && e[k].x == j && e[k].y == i) {
                        printf("E");
                        enemy_found = 1;
                        break;
                    }
                }
                if (!enemy_found) {
                    printf("%c", board[i][j]);
                }
            }
        }
        printf("\n");
    }
}

void move_enemies(struct enemy e[MAX_ENEMIES]) {
    int i;
    for (i = 0; i < MAX_ENEMIES; i++) {
        if (e[i].alive) {
            e[i].y++;
        }
    }
}

int fire_shot(struct shot s[MAX_SHOTS], int x, int y) {
    int i;
    for (i = 0; i < MAX_SHOTS; i++) {
        if (!s[i].fired) {
            s[i].x = x;
            s[i].y = y;
            s[i].fired = 1;
            return 1;
        }
    }
    return 0;
}

void move_shots(struct shot s[MAX_SHOTS]) {
    int i;
    for (i = 0; i < MAX_SHOTS; i++) {
        if (s[i].fired) {
            s[i].y--;
            if (s[i].y < 0) {
                s[i].fired = 0;
            }
        }
    }
}

void check_collision(struct player p, struct enemy e[MAX_ENEMIES], struct shot s[MAX_SHOTS], int* score) {
    int i, j;
    for (i = 0; i < MAX_SHOTS; i++) {
        if (s[i].fired) {
            for (j = 0; j < MAX_ENEMIES; j++) {
                if (e[j].alive && s[i].x == e[j].x && s[i].y == e[j].y) {
                    e[j].alive = 0;
                    s[i].fired = 0;
                    (*score)++;
                }
            }
        }
    }
    for (i = 0; i < MAX_ENEMIES; i++) {
        if (e[i].alive && e[i].y == p.y && e[i].x == p.x) {
            printf("Game Over\n");
            exit(0);
        }
    }
}

int main() {
    char board[10][10] = {
        "##########",
        "#        #",
        "#        #",
        "#        #",
        "#        #",
        "#        #",
        "#        #",
        "#        #",
        "#        #",
        "##########"
    };
    struct player p = {5, 8};
    struct enemy e[MAX_ENEMIES];
    struct shot s[MAX_SHOTS];
    int i, score = 0;

    srand(time(NULL));
    for (i = 0; i < MAX_ENEMIES; i++) {
        e[i].x = rand() % 10;
        e[i].y = rand() % 3;
        e[i].alive = 1;
    }

    while (1) {
        system("clear");
        draw_board(board, p, e, s);
        printf("Score: %d\n", score);

        char c = getchar();
        if (c == 'a') {
            if (p.x > 0) p.x--;
        } else if (c == 'd') {
            if (p.x < 9) p.x++;
        } else if (c == ' ') {
            fire_shot(s, p.x, p.y - 1);
        }

        move_enemies(e);
        move_shots(s);
        check_collision(p, e, s, &score);

        if (rand() % 2) {
            fire_shot(s, e[rand() % MAX_ENEMIES].x, e[rand() % MAX_ENEMIES].y + 1);
        }
    }

    return 0;
}