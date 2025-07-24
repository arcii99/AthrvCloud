//FormAI DATASET v1.0 Category: Checkers Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col, int player);
int jump_available(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int player);
int is_game_over(int board[BOARD_SIZE][BOARD_SIZE]);
int get_opponent(int player);

int main()
{
    //Initial board setup, '1' represents black pieces and '2' represents white pieces
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 2, 0, 2, 0, 2, 0},
        {0, 2, 0, 2, 0, 2, 0, 2},
        {2, 0, 2, 0, 2, 0, 2, 0},
    };

    int current_player = 1;
    int game_over = 0;
    int move_count = 0;

    while(!game_over) {
        printf("-------------- Move #%d --------------\n", move_count+1);

        //Print the board
        print_board(board);

        //Get move input from player
        int from_row, from_col, to_row, to_col;
        printf("\nPlayer %d, please enter move (format: row,column to row,column): ", current_player);
        scanf("%d,%d to %d,%d", &from_row, &from_col, &to_row, &to_col);

        //Check if move is valid
        if(is_valid_move(board, from_row, from_col, to_row, to_col, current_player)) {
            //Make move
            board[to_row][to_col] = current_player;
            board[from_row][from_col] = 0;

            //Check if jump is available
            while(jump_available(board, to_row, to_col, current_player)) {
                int jump_row, jump_col;
                printf("Jump is available. Please enter jump (format: row,column): ");
                scanf("%d,%d", &jump_row, &jump_col);

                //Check if jump is valid
                if(is_valid_move(board, to_row, to_col, jump_row, jump_col, current_player)) {
                    //Make jump
                    board[jump_row][jump_col] = current_player;
                    board[to_row][to_col] = 0;
                    board[from_row][from_col] = 0;

                    //Update current position
                    from_row = jump_row;
                    from_col = jump_col;
                } else {
                    printf("Invalid jump. Please try again.\n");
                }
            }

            //Switch to next player
            current_player = get_opponent(current_player);
            move_count++;
        } else {
            printf("Invalid move. Please try again.\n");
        }

        //Check if game is over
        game_over = is_game_over(board);
    }

    //Print final board and winner
    print_board(board);
    printf("\nGame over! Player %d wins!\n", get_opponent(current_player));
    return 0;
}

//Prints the current game board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

//Checks if a given move is valid for a player on a given board
int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col, int player) {
    //Check if move is within bounds
    if(from_row < 0 || from_row >= BOARD_SIZE || from_col < 0 || from_col >= BOARD_SIZE ||
       to_row < 0 || to_row >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE) {
        return 0;
    }

    //Check if piece belongs to player
    if(board[from_row][from_col] != player) {
        return 0;
    }

    //Check if destination is empty
    if(board[to_row][to_col] != 0) {
        return 0;
    }

    //Check if move is diagonal and within range
    if(abs(to_row-from_row) != abs(to_col-from_col) || abs(to_row-from_row) > 2) {
        return 0;
    }

    //Check if move is one or two spaces
    if(abs(to_row-from_row) == 1) {
        return 1;
    }

    //Check if move is a jump and piece to jump over exists
    int jumped_row = (from_row+to_row)/2;
    int jumped_col = (from_col+to_col)/2;
    int opponent = get_opponent(player);

    if(board[jumped_row][jumped_col] != opponent) {
        return 0;
    }

    return 1;
}

//Checks if a jump is available for a given player from a given position
int jump_available(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int player) {
    int opponent = get_opponent(player);

    if(row >= 2) {
        if(col >= 2) {
            if(board[row-1][col-1] == opponent && board[row-2][col-2] == 0) {
                return 1;
            }
        }
        if(col <= (BOARD_SIZE-3)) {
            if(board[row-1][col+1] == opponent && board[row-2][col+2] == 0) {
                return 1;
            }
        }
    }

    if(row <= (BOARD_SIZE-3)) {
        if(col >= 2) {
            if(board[row+1][col-1] == opponent && board[row+2][col-2] == 0) {
                return 1;
            }
        }
        if(col <= (BOARD_SIZE-3)) {
            if(board[row+1][col+1] == opponent && board[row+2][col+2] == 0) {
                return 1;
            }
        }
    }

    return 0;
}

//Checks if the game is over
int is_game_over(int board[BOARD_SIZE][BOARD_SIZE]) {
    int black_pieces = 0;
    int white_pieces = 0;

    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 1) {
                black_pieces++;
            } else if(board[i][j] == 2) {
                white_pieces++;
            }
        }
    }

    return (black_pieces == 0 || white_pieces == 0);
}

//Gets the opponent player given the current player
int get_opponent(int player) {
    if(player == 1) {
        return 2;
    } else {
        return 1;
    }
}