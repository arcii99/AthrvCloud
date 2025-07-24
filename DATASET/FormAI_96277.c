//FormAI DATASET v1.0 Category: Checkers Game ; Style: curious
#include <stdio.h>

/* define the checkers board */
#define BOARD_SIZE 8
char board[BOARD_SIZE][BOARD_SIZE] = {
    {'#', 'w', '#', 'w', '#', 'w', '#', 'w'},
    {'w', '#', 'w', '#', 'w', '#', 'w', '#'},
    {'#', 'w', '#', 'w', '#', 'w', '#', 'w'},
    {' ', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' '},
    {'r', '#', 'r', '#', 'r', '#', 'r', '#'},
    {'#', 'r', '#', 'r', '#', 'r', '#', 'r'},
    {'r', '#', 'r', '#', 'r', '#', 'r', '#'}
};

/* define the player colors */
#define PLAYER_1 'w'
#define PLAYER_2 'r'

/* print the board */
void print_board() {
    printf("  1 2 3 4 5 6 7 8\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* check if a player has won */
int has_won(char player) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == player || board[i][j] == (player + ('a' - 'A'))) {
                int x = i-1;
                int y = j-1;
                while(x >= 0 && y >= 0) {
                    if(board[x][y] != ' ') {
                        break;
                    }
                    x--;
                    y--;
                }
                if(x >= 0 && y >= 0 && board[x][y] == (player + ('a' - 'A'))) {
                    return 0;
                }
                x = i-1;
                y = j+1;
                while(x >= 0 && y < BOARD_SIZE) {
                    if(board[x][y] != ' ') {
                        break;
                    }
                    x--;
                    y++;
                }
                if(x >= 0 && y < BOARD_SIZE && board[x][y] == (player + ('a' - 'A'))) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

/* check if a move is valid */
int is_valid_move(int xi, int yi, int xf, int yf, char player) {
    if(xf < 0 || xf >= BOARD_SIZE || yf < 0 || yf >= BOARD_SIZE) {
        return 0;
    }
    if(board[xf][yf] != ' ') {
        return 0;
    }
    if(player == PLAYER_1) {
        if(xi-xf == 1 && (yi-yf == 1 || yi-yf == -1)) {
            return 1;
        }
        if(xi-xf == 2 && (yi-yf == 2 || yi-yf == -2)) {
            if(board[(xi+xf)/2][(yi+yf)/2] == PLAYER_2 || board[(xi+xf)/2][(yi+yf)/2] == PLAYER_2 + ('a' - 'A')) {
                return 1;
            }
        }
    }
    else {
        if(xf-xi == 1 && (yi-yf == 1 || yi-yf == -1)) {
            return 1;
        }
        if(xf-xi == 2 && (yi-yf == 2 || yi-yf == -2)) {
            if(board[(xi+xf)/2][(yi+yf)/2] == PLAYER_1 || board[(xi+xf)/2][(yi+yf)/2] == PLAYER_1 + ('a' - 'A')) {
                return 1;
            }
        }
    }
    return 0;
}

/* execute a move */
void do_move(int xi, int yi, int xf, int yf, char player) {
    board[xi][yi] = ' ';
    if(player == PLAYER_1 && xf == 0) {
        board[xf][yf] = 'W';
    }
    else if(player == PLAYER_2 && xf == BOARD_SIZE-1) {
        board[xf][yf] = 'M';
    }
    else {
        board[xf][yf] = player;
    }
    if(xi-xf == 2 || xi-xf == -2) {
        board[(xi+xf)/2][(yi+yf)/2] = ' ';
    }
}

/* main function */
int main() {
    int player = 1;
    int xi, yi, xf, yf;
    while(!has_won(PLAYER_1) && !has_won(PLAYER_2)) {
        system("clear");
        print_board();
        printf("Player %d (%c) turn\n", player, (player == 1) ? PLAYER_1 : PLAYER_2);
        printf("Enter initial position (x y): ");
        scanf("%d %d", &xi, &yi);
        printf("Enter target position (x y): ");
        scanf("%d %d", &xf, &yf);
        if(is_valid_move(xi-1, yi-1, xf-1, yf-1, (player == 1) ? PLAYER_1 : PLAYER_2)) {
            do_move(xi-1, yi-1, xf-1, yf-1, (player == 1) ? PLAYER_1 : PLAYER_2);
            player = (player == 1) ? 2 : 1;
        }
        else {
            printf("Invalid move!\n");
            printf("Press any key to try again...");
            getchar();
            getchar();
        }
    }
    system("clear");
    print_board();
    printf("Player %d has won!\n", (has_won(PLAYER_1)) ? 1 : 2);
    return 0;
}