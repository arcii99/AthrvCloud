//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 10

int board[ROW][COL];
int score = 0;
int lives = 3;

void initialize_board() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board() {
    int i, j;
    printf("Score: %d Lives: %d\n", score, lives);
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void add_spaceships() {
    int i;
    for (i = 0; i < COL; i++) {
        board[0][i] = 1;
    }
}

void add_player(int position) {
    board[ROW-1][position] = 2;
}

void add_bullet(int position) {
    int i;
    for (i = ROW-2; i >= 0; i--) {
        if (board[i][position] == 1) {
            board[i][position] = 0;
            score++;
            return;
        }
        else if (board[i][position] == 2) {
            lives--;
            return;
        }
    }
    board[i+1][position] = 3;
}

void move_spaceships() {
    int i, j;
    for (i = ROW-1; i > 0; i--) {
        for (j = 0; j < COL; j++) {
            board[i][j] = board[i-1][j];
        }
    }
    add_spaceships();
}

int main() {
    int position = COL/2;
    srand(time(NULL));
    initialize_board();
    add_spaceships();
    add_player(position);
    print_board();
    while (lives > 0) {
        int random_number = rand() % COL;
        add_bullet(random_number);
        move_spaceships();
        print_board();
        printf("Enter your move (left: 'a', right: 'd', shoot: 's'):");
        char move;
        scanf("%c", &move);
        if (move == 'a' && position > 0) {
            board[ROW-1][position] = 0;
            position--;
            add_player(position);
        }
        else if (move == 'd' && position < COL-1) {
            board[ROW-1][position] = 0;
            position++;
            add_player(position);
        }
        else if (move == 's') {
            add_bullet(position);
        }
        print_board();
    }
    printf("Game over! Your score is %d.\n", score);
    return 0;
}