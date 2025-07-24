//FormAI DATASET v1.0 Category: Checkers Game ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 8
#define COLS 8
#define RED 'R'
#define WHITE 'W'
#define EMPTY 'E'
#define RED_KING 'K'
#define WHITE_KING 'Q'

char board[ROWS][COLS];
int eaten = 0;

void initialize_board() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if((i+j) % 2 == 0) {
                if(i < 3)
                    board[i][j] = WHITE;
                else if(i >= 5)
                    board[i][j] = RED;
                else
                    board[i][j] = EMPTY;
            }
            else
                board[i][j] = EMPTY;
        }
    }
}

void print_board() {
    printf("   0 1 2 3 4 5 6 7\n");
    for(int i = 0; i < ROWS; i++) {
        printf("%d  ", i);
        for(int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int row, int col, int row_dest, int col_dest, char player) {
    if(player == RED) {
        if(board[row][col] != RED && board[row][col] != RED_KING)
            return 0;
        if(board[row_dest][col_dest] != EMPTY)
            return 0;
        if(row_dest < row)
            return 0;
        if(row_dest == row || col_dest == col)
            return 0;
        if(abs(row_dest - row) == abs(col_dest - col)) {
            int r_inc = (row_dest > row) ? 1 : -1;
            int c_inc = (col_dest > col) ? 1 : -1;
            int r = row + r_inc;
            int c = col + c_inc;
            while(r != row_dest && c != col_dest) {
                if(board[r][c] != EMPTY)
                    return 0;
                r += r_inc;
                c += c_inc;
            }
            if(board[r][c] != EMPTY)
                return 0;
            return 1;
        }
    }
    else if(player == WHITE) {
        if(board[row][col] != WHITE && board[row][col] != WHITE_KING)
            return 0;
        if(board[row_dest][col_dest] != EMPTY)
            return 0;
        if(row_dest > row)
            return 0;
        if(row_dest == row || col_dest == col)
            return 0;
        if(abs(row_dest - row) == abs(col_dest - col)) {
            int r_inc = (row_dest > row) ? 1 : -1;
            int c_inc = (col_dest > col) ? 1 : -1;
            int r = row + r_inc;
            int c = col + c_inc;
            while(r != row_dest && c != col_dest) {
                if(board[r][c] != EMPTY)
                    return 0;
                r += r_inc;
                c += c_inc;
            }
            if(board[r][c] != EMPTY)
                return 0;
            return 1;
        }
    }
    return 0;
}

void move_piece(int row, int col, int row_dest, int col_dest, char player) {
    if(player == RED) {
        if(row_dest == 0)
            board[row_dest][col_dest] = RED_KING;
        else
            board[row_dest][col_dest] = RED;
        board[row][col] = EMPTY;
    }
    else if(player == WHITE) {
        if(row_dest == 7)
            board[row_dest][col_dest] = WHITE_KING;
        else
            board[row_dest][col_dest] = WHITE;
        board[row][col] = EMPTY;
    }
}

int can_eat(int row, int col, char player) {
    if(player == RED) {
        if(board[row][col] == RED || board[row][col] == RED_KING) {
            int r_inc[4] = {-1, -1, 1, 1};
            int c_inc[4] = {-1, 1, -1, 1};
            for(int k = 0; k < 4; k++) {
                int r = row + r_inc[k];
                int c = col + c_inc[k];
                int r_jump = r + r_inc[k];
                int c_jump = c + c_inc[k];
                if(r_jump >= 0 && r_jump < 8 && c_jump >= 0 && c_jump < 8 &&
                   board[r][c] == WHITE && board[r_jump][c_jump] == EMPTY) {
                    eaten = 1;
                    board[r][c] = EMPTY;
                    move_piece(row, col, r_jump, c_jump, RED);
                    return 1;
                }
            }
        }
        else if(board[row][col] == RED_KING) {
            int r_inc[4] = {-1, -1, 1, 1};
            int c_inc[4] = {-1, 1, -1, 1};
            for(int k = 0; k < 4; k++) {
                int r = row + r_inc[k];
                int c = col + c_inc[k];
                while(r >= 0 && r < 8 && c >= 0 && c < 8) {
                    if(board[r][c] == WHITE) {
                        int r_jump = r + r_inc[k];
                        int c_jump = c + c_inc[k];
                        if(r_jump >= 0 && r_jump < 8 && c_jump >= 0 && c_jump < 8 &&
                           board[r_jump][c_jump] == EMPTY) {
                            eaten = 1;
                            board[r][c] = EMPTY;
                            move_piece(row, col, r_jump, c_jump, RED);
                            return 1;
                        }
                        break;
                    }
                    else if(board[r][c] == RED || board[r][c] == RED_KING)
                        break;
                    r += r_inc[k];
                    c += c_inc[k];
                }
            }
        }
    }
    else if(player == WHITE) {
        if(board[row][col] == WHITE || board[row][col] == WHITE_KING) {
            int r_inc[4] = {-1, -1, 1, 1};
            int c_inc[4] = {-1, 1, -1, 1};
            for(int k = 0; k < 4; k++) {
                int r = row + r_inc[k];
                int c = col + c_inc[k];
                int r_jump = r + r_inc[k];
                int c_jump = c + c_inc[k];
                if(r_jump >= 0 && r_jump < 8 && c_jump >= 0 && c_jump < 8 &&
                   board[r][c] == RED && board[r_jump][c_jump] == EMPTY) {
                    eaten = 1;
                    board[r][c] = EMPTY;
                    move_piece(row, col, r_jump, c_jump, WHITE);
                    return 1;
                }
            }
        }
        else if(board[row][col] == WHITE_KING) {
            int r_inc[4] = {-1, -1, 1, 1};
            int c_inc[4] = {-1, 1, -1, 1};
            for(int k = 0; k < 4; k++) {
                int r = row + r_inc[k];
                int c = col + c_inc[k];
                while(r >= 0 && r < 8 && c >= 0 && c < 8) {
                    if(board[r][c] == RED) {
                        int r_jump = r + r_inc[k];
                        int c_jump = c + c_inc[k];
                        if(r_jump >= 0 && r_jump < 8 && c_jump >= 0 && c_jump < 8 &&
                           board[r_jump][c_jump] == EMPTY) {
                            eaten = 1;
                            board[r][c] = EMPTY;
                            move_piece(row, col, r_jump, c_jump, WHITE);
                            return 1;
                        }
                        break;
                    }
                    else if(board[r][c] == WHITE || board[r][c] == WHITE_KING)
                        break;
                    r += r_inc[k];
                    c += c_inc[k];
                }
            }
        }
    }
    return 0;
}

int can_eat_any(char player) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == player || board[i][j] == player - 17) {
                if(can_eat(i, j, player))
                    return 1;
            }
        }
    }
    return 0;
}

char get_opponent(char player) {
    if(player == RED)
        return WHITE;
    else
        return RED;
}

void make_move(char player, int comp) {
    int row, col, row_dest, col_dest;
    if(comp) {
        do {
            srand(time(NULL));
            row = rand() % 8;
            col = rand() % 8;
        } while(board[row][col] != player && board[row][col] != player - 17);
        int moved = 0;
        if(can_eat_any(player)) {
            while(can_eat(row, col, player)) {
                print_board();
                printf("\n");
            }
            if(!eaten)
                return;
            else {
                while(eaten) {
                    eaten = 0;
                    can_eat(row_dest, col_dest, player);
                    row = row_dest;
                    col = col_dest;
                    moved = 1;
                }
                if(moved) {
                    if(can_eat_any(player))
                        make_move(player, comp);
                    else {
                        print_board();
                        return;
                    }
                }
            }
        }
        else {
            do {
                row_dest = rand() % 8;
                col_dest = rand() % 8;
            } while(!is_valid_move(row, col, row_dest, col_dest, player));
            print_board();
            move_piece(row, col, row_dest, col_dest, player);
        }
    }
    else {
        do {
            printf("Enter row and column of piece to move: ");
            scanf("%d %d", &row, &col);
        } while(board[row][col] != player && board[row][col] != player - 17);
        int moved = 0;
        if(can_eat_any(player)) {
            while(can_eat(row, col, player)) {
                print_board();
                printf("\n");
            }
            if(!eaten)
                return;
            else {
                while(eaten) {
                    eaten = 0;
                    can_eat(row_dest, col_dest, player);
                    row = row_dest;
                    col = col_dest;
                    moved = 1;
                }
                if(moved) {
                    if(can_eat_any(player))
                        make_move(player, comp);
                    else {
                        print_board();
                        return;
                    }
                }
            }
        }
        else {
            do {
                printf("Enter row and column to move piece to: ");
                scanf("%d %d", &row_dest, &col_dest);
            } while(!is_valid_move(row, col, row_dest, col_dest, player));
            print_board();
            move_piece(row, col, row_dest, col_dest, player);
        }
    }
}

int game_over() {
    int white_count = 0;
    int red_count = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == WHITE || board[i][j] == WHITE_KING)
                white_count++;
            else if(board[i][j] == RED || board[i][j] == RED_KING)
                red_count++;
        }
    }
    if(red_count == 0) {
        printf("\n\nWHITE WINS!\n");
        return 1;
    }
    else if(white_count == 0) {
        printf("\n\nRED WINS!\n");
        return 1;
    }
    else
        return 0;
}

int main() {
    initialize_board();
    int comp = 0;
    do {
        printf("Choose your player: (R/W): ");
        char player;
        scanf(" %c", &player);
        if(player == RED || player == WHITE)
            comp = 1;
        else
            printf("Invalid player. Try again.\n");
    } while(!comp);
    print_board();
    while(!game_over()) {
        make_move(RED, comp);
        if(game_over())
            break;
        make_move(WHITE, comp);
    }
    return 0;
}