//FormAI DATASET v1.0 Category: Memory Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
int visited[BOARD_SIZE][BOARD_SIZE];

int random_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void reset_board() {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void print_board() {
    int i, j;
    printf("    1 2 3 4 5 6 7 8\n");
    printf("   -----------------\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%c | ", i + 65);
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("   -----------------\n");
}

int validate_input(char* input, int* row, int* col) {
    if(input[0] >= 'A' && input[0] <= 'H' && input[1] >= '1' && input[1] <= '8') {
        *row = (int)input[0] - 65;
        *col = (int)input[1] - 49;
        return 1;
    }
    return 0;
}

void place_numbers(int count) {
    int i;
    for(i = 1; i <= count; i++) {
        int row = random_num(0, BOARD_SIZE-1);
        int col = random_num(0, BOARD_SIZE-1);
        if(board[row][col] == 0) {
            board[row][col] = i;
        }
        else {
            //If the cell is already occupied, try again
            i--;
        }
    }
}

int find_by_number(int num, int* row, int* col) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == num) {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}

void mark_as_visited(int row, int col) {
    visited[row][col] = 1;
}

int is_visited(int row, int col) {
    return visited[row][col] == 1;
}

int is_adjacent(int row1, int col1, int row2, int col2) {
    return abs(row1 - row2) <= 1 && abs(col1 - col2) <= 1;
}

int is_valid_move(int curr_row, int curr_col, int move_row, int move_col) {
    if(move_row < 0 || move_row >= BOARD_SIZE || move_col < 0 || move_col >= BOARD_SIZE) {
        return 0;
    }
    if(is_visited(move_row, move_col)) {
        return 0;
    }
    if(!is_adjacent(curr_row, curr_col, move_row, move_col)) {
        return 0;
    }
    return 1;
}

int play_game(int count) {
    int i;
    int curr_row, curr_col;
    for(i = 1; i <= count; i++) {
        print_board();
        int num_row, num_col;
        if(find_by_number(i, &num_row, &num_col)) {
            printf("Found number %d\n", i);
            mark_as_visited(num_row, num_col);
            curr_row = num_row;
            curr_col = num_col;
        }
        else {
            char input[3];
            int move_row, move_col;
            while(1) {
                printf("Enter move for %d: ", i);
                scanf("%2s", input);
                if(validate_input(input, &move_row, &move_col)) {
                    break;
                }
                printf("Invalid input. Please enter valid input in the format [A-H][1-8]\n");
            }
            if(is_valid_move(curr_row, curr_col, move_row, move_col)) {
                mark_as_visited(move_row, move_col);
                curr_row = move_row;
                curr_col = move_col;
            }
            else {
                i--; //If it is an invalid move, try again for this number
                printf("Invalid move. Please enter a valid adjacent location\n");
            }
        }
    }
    printf("Congratulations! You won the game!\n");
    print_board();
    return 1;
}

int main() {
    srand(time(NULL));
    reset_board();
    place_numbers(20);
    play_game(20);
    return 0;
}