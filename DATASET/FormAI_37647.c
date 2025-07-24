//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DELAY 200000000

typedef struct {
    int row;
    int col;
} POSITION;

int GAME_BOARD[10][10] = {{0}};

void print_board();
void generate_random_num(POSITION* pos);
void move(POSITION* pos, int dx, int dy);

int main() {
    POSITION player_pos = {4, 4};
    srand(time(NULL));

    while(1) {
        system("clear");
        print_board();
        POSITION rand_pos;
        generate_random_num(&rand_pos);
        printf("\nRandom number generated at (%d, %d)\n", rand_pos.row, rand_pos.col);

        int dx = rand_pos.col - player_pos.col;
        int dy = rand_pos.row - player_pos.row;
        printf("dx: %d, dy: %d\n", dx, dy);

        if (dx > 0)
            move(&player_pos, 1, 0);
        else if (dx < 0)
            move(&player_pos, -1, 0);

        if (dy > 0)
            move(&player_pos, 0, 1);
        else if (dy < 0)
            move(&player_pos, 0, -1);

        usleep(DELAY);
    }

    return 0;
}

void generate_random_num(POSITION* pos) {
    pos->row = rand() % 10;
    pos->col = rand() % 10;
}

void move(POSITION* pos, int dx, int dy) {
    int new_row = pos->row + dy;
    int new_col = pos->col + dx;
    if (new_row >= 0 && new_row < 10 && new_col >= 0 && new_col < 10) {
        pos->row = new_row;
        pos->col = new_col;
    }
}

void print_board() {
    for (int i = 0; i < 10; i++) {
        printf("| ");
        for (int j = 0; j < 10; j++) {
            if (i == 4 && j == 4)
                printf("P ");
            else
                printf("%d ", GAME_BOARD[i][j]);
        }
        printf("|\n");
    }
}