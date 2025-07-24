//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MISSILES 5
#define BOARD_WIDTH 80
#define BOARD_HEIGHT 20
#define INVADERS_ROW 2

char board[BOARD_HEIGHT][BOARD_WIDTH];

struct Invader {
    int row, col;
    char symbol;
    int destroyed;
};

struct Missile {
    int row, col;
    int active;
};

struct Invader invaders[BOARD_WIDTH - 1];
struct Missile missiles[MAX_MISSILES];

int score = 0;

void create_board() {
    int i, j;
    for(i = 0; i < BOARD_HEIGHT; i++)
        for(j = 0; j < BOARD_WIDTH; j++)
            board[i][j] = ' ';
}

void draw_board() {
    int i, j;
    printf("Score: %d\n", score);
    for(i = 0; i < BOARD_HEIGHT; i++) {
        for(j = 0; j < BOARD_WIDTH; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}

void create_invaders() {
    int i;
    for(i = 0; i < BOARD_WIDTH - 1; i++) {
        invaders[i].symbol = 'I';
        invaders[i].row = INVADERS_ROW;
        invaders[i].col = i + 1;
        invaders[i].destroyed = 0;
    }
}

void draw_missile(int i) {
    if(missiles[i].active) {
        board[missiles[i].row][missiles[i].col] = '|';
        if(missiles[i].row > 0)
            missiles[i].row--;
        else
            missiles[i].active = 0;
    }
}

void draw_invader(int i) {
    if(!invaders[i].destroyed) {
        board[invaders[i].row][invaders[i].col] = invaders[i].symbol;
        if(invaders[i].row < BOARD_HEIGHT - 1)
            invaders[i].row++;
        else
            invaders[i].destroyed = 1;
    }
}

void draw_missiles() {
    int i;
    for(i = 0; i < MAX_MISSILES; i++)
        draw_missile(i);
}

void draw_invaders() {
    int i;
    for(i = 0; i < BOARD_WIDTH - 1; i++)
        draw_invader(i);
}

void fire_missile(int col) {
    int i;
    for(i = 0; i < MAX_MISSILES; i++) {
        if(!missiles[i].active) {
            missiles[i].row = BOARD_HEIGHT - 2;
            missiles[i].col = col;
            missiles[i].active = 1;
            break;
        }
    }
}

void move_player(int offset) {
    int i;
    for(i = 0; i < MAX_MISSILES; i++) {
        if(missiles[i].active && missiles[i].row == BOARD_HEIGHT - 2 && missiles[i].col == offset) {
            return;
        }
    }
    board[BOARD_HEIGHT - 1][offset] = 'P';
    if(offset > 0)
        board[BOARD_HEIGHT - 1][offset - 1] = ' ';
    if(offset < BOARD_WIDTH - 1)
        board[BOARD_HEIGHT - 1][offset + 1] = ' ';
}

void process_input(char input) {
    int offset, i;
    switch(input) {
        case 'a':
            offset = 0;
            break;
        case 'd':
            offset = 2;
            break;
        case ' ':
            fire_missile((board[BOARD_HEIGHT - 1][1] == 'P') ? 1 : (board[BOARD_HEIGHT - 1][2] == 'P') ? 2 : 3);
            break;
        default:
            return;
    }
    move_player(offset);
}

void update_board() {
    int i;
    draw_missiles();
    draw_invaders();
    for(i = 0; i < BOARD_WIDTH - 1; i++) {
        if(!invaders[i].destroyed && invaders[i].row == BOARD_HEIGHT - 1) {
            printf("Game Over! You were killed\n");
            exit(0);
        }
    }
}

void setup() {
    create_board();
    create_invaders();
    move_player(BOARD_WIDTH / 2 - 1);
    srand(time(NULL));
}

int main() {
    char input;
    setup();
    while(1) {
        if(rand() % 3 == 0) // Chance to fire missile
            fire_missile(rand() % BOARD_WIDTH - 1);
        draw_board();
        input = getchar();
        process_input(input);
        update_board();
        score++;
        system("clear"); // Clear screen
    }
    return 0;
}