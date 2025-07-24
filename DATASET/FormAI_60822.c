//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_MOVES 30

// define direction constants
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// define game status constants
#define PLAYING 0
#define WON 1
#define LOST 2

int board[BOARD_SIZE][BOARD_SIZE];
int moves[MAX_MOVES];
int num_moves = 0;
int current_row = BOARD_SIZE - 1;
int current_col = 0;
int game_status = PLAYING;

// function declarations
void initialize_board();
void print_board();
void make_move(int direction);
int move_available(int direction);
int check_game_status();

int main() {
    // seed random number generator
    srand(time(NULL));
    
    // initialize game board
    initialize_board();
    
    // print initial board
    printf("\nWelcome to the Robot Game!\n");
    printf("Use the arrow keys to move the robot to the finish line.\n\n");
    print_board();
    
    // game loop
    while (game_status == PLAYING) {
        // get user input
        int input = getchar();
        
        // clear input buffer
        while (getchar() != '\n');
        
        // determine direction based on input
        int direction = 0;
        switch (input) {
            case 'w':
            case 'W':
                direction = UP;
                break;
            case 's':
            case 'S':
                direction = DOWN;
                break;
            case 'a':
            case 'A':
                direction = LEFT;
                break;
            case 'd':
            case 'D':
                direction = RIGHT;
                break;
            default:
                printf("Invalid input.\n");
                continue;
        }
        
        // check if move is available
        if (move_available(direction)) {
            // log move
            moves[num_moves++] = direction;
            
            // make move
            make_move(direction);
            
            // print updated board
            print_board();
            
            // check game status
            game_status = check_game_status();
        } else {
            printf("Cannot move in that direction.\n");
        }
    }
    
    // print end of game message
    switch (game_status) {
        case WON:
            printf("Congratulations! You won!\n");
            break;
        case LOST:
            printf("You lost. Better luck next time!\n");
            break;
    }
    
    return 0;
}

void initialize_board() {
    // set all cells to empty
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    
    // set start and finish positions
    board[current_row][current_col] = 1;
    board[0][BOARD_SIZE - 1] = 2;
    
    // randomly place obstacles on board
    int num_obstacles = BOARD_SIZE * 2;
    for (int i = 0; i < num_obstacles; i++) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        if (board[row][col] == 0) {
            board[row][col] = -1;
        } else {
            i--;
        }
    }
}

void print_board() {
    printf("  ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col + 1);
    }
    printf("\n");
    
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%c ", 'A' + row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch (board[row][col]) {
                case -1:
                    printf("x ");
                    break;
                case 0:
                    printf(". ");
                    break;
                case 1:
                    printf("R ");
                    break;
                case 2:
                    printf("F ");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void make_move(int direction) {
    // update current position
    switch (direction) {
        case UP:
            current_row--;
            break;
        case DOWN:
            current_row++;
            break;
        case LEFT:
            current_col--;
            break;
        case RIGHT:
            current_col++;
            break;
    }
    
    // update board
    board[current_row][current_col] = 1;
    board[current_row + (direction == UP) - (direction == DOWN)][current_col + (direction == LEFT) - (direction == RIGHT)] = 0;
}

int move_available(int direction) {
    int row_offset = (direction == UP) - (direction == DOWN);
    int col_offset = (direction == LEFT) - (direction == RIGHT);
    
    int new_row = current_row + row_offset;
    int new_col = current_col + col_offset;
    
    // check if new position is within bounds
    if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE) {
        return 0;
    }
    
    // check if new position is obstacle
    if (board[new_row][new_col] == -1) {
        return 0;
    }
    
    return 1;
}

int check_game_status() {
    // check if robot has reached finish
    if (board[0][BOARD_SIZE - 1] == 1) {
        return WON;
    }
    
    // check if robot has no more moves
    if (num_moves == MAX_MOVES) {
        return LOST;
    }
    
    return PLAYING;
}