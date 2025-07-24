//FormAI DATASET v1.0 Category: Checkers Game ; Style: automated
#include <stdio.h>

#define BOARD_SIZE 8
#define EMPTY_CELL ' '
#define BLACK_PIECE 'b'
#define WHITE_PIECE 'w'

char board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_CELL}};

int get_player_input(char player) {
    int input;
    printf("%c player, please select a piece to move (row column): ", player);
    scanf("%d %d", &input);
    return input;
}

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i < 3 && (i + j) % 2 == 0)
                board[i][j] = BLACK_PIECE;
            else if (i > 4 && (i + j) % 2 == 0)
                board[i][j] = WHITE_PIECE;
            else
                board[i][j] = EMPTY_CELL;
        }
    }
}

void print_board() {
    printf("\n   ");
    for (int i = 0; i < BOARD_SIZE; i++)
        printf("%d ", i+1);
    printf("\n  +");
    for (int i = 0; i < BOARD_SIZE; i++)
        printf("-+");
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i+1);
        for (int j = 0; j < BOARD_SIZE; j++)
            printf("%c|", board[i][j]);
        printf("\n  +");
        for (int j = 0; j < BOARD_SIZE; j++)
            printf("-+");
        printf("\n");
    }
}

int is_valid_move(int from_x, int from_y, int to_x, int to_y, char player) {
    if (to_x < 0 || to_y < 0 || to_x >= BOARD_SIZE || to_y >= BOARD_SIZE)
        return 0;
    if (board[to_x][to_y] != EMPTY_CELL)
        return 0;
    if (player == WHITE_PIECE && from_x > to_x)
        return 0;
    if (player == BLACK_PIECE && from_x < to_x)
        return 0;
    if (abs(from_x - to_x) == 1 && abs(from_y - to_y) == 1)
        return 1;
    if (abs(from_x - to_x) == 2 && abs(from_y - to_y) == 2) {
        int middle_x = (from_x + to_x) / 2;
        int middle_y = (from_y + to_y) / 2;
        if (board[middle_x][middle_y] == EMPTY_CELL)
            return 0;
        if (player == WHITE_PIECE && board[middle_x][middle_y] == BLACK_PIECE)
            return 1;
        if (player == BLACK_PIECE && board[middle_x][middle_y] == WHITE_PIECE)
            return 1;
    }
    return 0;
}

void move_piece(int from_x, int from_y, int to_x, int to_y, char player) {
    board[to_x][to_y] = player;
    board[from_x][from_y] = EMPTY_CELL;
    if (abs(from_x - to_x) == 2 && abs(from_y - to_y) == 2) {
        int middle_x = (from_x + to_x) / 2;
        int middle_y = (from_y + to_y) / 2;
        board[middle_x][middle_y] = EMPTY_CELL;  
    }
}

int game_over() {
    int white_pieces = 0;
    int black_pieces = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == WHITE_PIECE || board[i][j] == 'W')
                white_pieces++;
            else if (board[i][j] == BLACK_PIECE || board[i][j] == 'B')
                black_pieces++;
        }
    }
    return (black_pieces == 0 || white_pieces == 0);
}

int main() {
    initialize_board();
    char current_player = WHITE_PIECE;
    while (!game_over()) {
        print_board();
        int from_x, from_y, to_x, to_y;
        do {
            from_x = get_player_input(current_player) - 1;
            from_y = get_player_input(current_player) - 1;
        } while (board[from_x][from_y] != current_player);
        do {
            to_x = get_player_input(current_player) - 1;
            to_y = get_player_input(current_player) - 1;
        } while (!is_valid_move(from_x, from_y, to_x, to_y, current_player));
        move_piece(from_x, from_y, to_x, to_y, current_player);
        if (current_player == WHITE_PIECE && to_x == 0)
            board[to_x][to_y] = 'W';
        else if (current_player == BLACK_PIECE && to_x == BOARD_SIZE - 1)
            board[to_x][to_y] = 'B';
        current_player = (current_player == WHITE_PIECE) ? BLACK_PIECE : WHITE_PIECE;
    }
    print_board();
    printf("%c player wins!", current_player);
    return 0;
}