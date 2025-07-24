//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_WIDTH 50
#define BOARD_HEIGHT 20

int board[BOARD_HEIGHT][BOARD_WIDTH];
int player_pos;
int score = 0;
int num_invaders = 30;
int invaders_speed = 1;
int game_over = 0;
int shoot_ready = 1;

void print_board() {
    system("clear");
    printf("SCORE: %d\n\n", score);
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            if (y == BOARD_HEIGHT-1 && x == player_pos) printf("V"); // player
            else if (board[y][x] == 1) printf("*"); // invader
            else if (board[y][x] == -1) printf("|"); // bullet
            else printf(" ");
        }
        printf("\n");
    }
}

void fire_bullet() {
    for (int y = BOARD_HEIGHT-2; y >= 0; y--) {
        if (board[y][player_pos] == 1) { // hit invader
            board[y][player_pos] = 0;
            score++;
            num_invaders--;
            if (num_invaders == 0) {
                game_over = 1;
                printf("YOU WIN!\n");
            }
            return;
        }
        else if (board[y][player_pos] == -1) return; // bullet already in this position
    }
    board[0][player_pos] = -1; // bullet fired
}

void move_player(int dir) {
    player_pos += dir;
    if (player_pos < 0) player_pos = 0;
    if (player_pos >= BOARD_WIDTH) player_pos = BOARD_WIDTH-1;
}

void move_invaders() {
    for (int y = BOARD_HEIGHT-2; y >= 0; y--) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            if (board[y][x] == 1) { // invader found
                if (y == BOARD_HEIGHT-2) { // invader reached bottom
                    game_over = 1;
                    printf("GAME OVER\n");
                    return;
                }
                board[y+1][x] = 1;
                board[y][x] = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // initialize board
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            board[y][x] = 0;
        }
    }

    // place invaders
    for (int i = 0; i < num_invaders; i++) {
        int x = rand() % BOARD_WIDTH;
        int y = rand() % (BOARD_HEIGHT-10);
        board[y][x] = 1;
    }

    while (!game_over) {
        print_board();

        // get input
        int input = getchar();

        // shoot
        if (input == ' ' && shoot_ready) {
            shoot_ready = 0;
            fire_bullet();
        }
        else if (input != '\n') {
            // move player
            int dir = 0;
            if (input == 'a') dir = -1;
            else if (input == 'd') dir = 1;
            move_player(dir);
        }
        
        // move invaders
        move_invaders();
        
        // delay
        for (int i = 0; i < 5000000/invaders_speed; i++) {}

        shoot_ready = 1;
    }

    return 0;
}