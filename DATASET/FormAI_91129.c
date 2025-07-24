//FormAI DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 10

char board[HEIGHT][WIDTH];

void initialize_board() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                board[i][j] = '#';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(board[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    initialize_board();
    print_board();

    int x = WIDTH / 2, y = HEIGHT / 2;
    board[y][x] = '@';
    print_board();

    int moves = 0;
    while (1) {
        char input = getchar();
        if (input == 'q') {
            printf("Goodbye!\n");
            exit(0);
        }

        board[y][x] = ' ';

        if (input == 'w') {
            y--;
        } else if (input == 'a') {
            x--;
        } else if (input == 's') {
            y++;
        } else if (input == 'd') {
            x++;
        }

        if (x < 1 || x > WIDTH - 2 || y < 1 || y > HEIGHT - 2) {
            printf("Game over!\n");
            exit(0);
        }

        board[y][x] = '@';
        print_board();
        moves++;
        printf("Moves: %d\n", moves);
    }

    return 0;
}