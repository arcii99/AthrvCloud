//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define ROWS 21
#define COLS 21
#define DOT_SYMBOL '.'
#define WALL_SYMBOL '#'
#define GHOST_SYMBOL 'G'
#define PACMAN_SYMBOL 'P'
#define NUM_GHOSTS 4
#define LEVELS 3

// function declarations
void initialize_board(char board[ROWS][COLS], int level);
void print_board(char board[ROWS][COLS]);
void move_pacman(char board[ROWS][COLS], int *pac_row, int *pac_col);
void move_ghosts(char board[ROWS][COLS]);
void end_game(char msg[]);
int is_legal_move(char board[ROWS][COLS], int row, int col);
int get_random_direction();

// main function
int main(void) 
{
    // initialize variables
    char board[ROWS][COLS];
    int level = 1;
    int pac_row = ROWS/2;
    int pac_col = COLS/2;
    
    // game loop
    while (level <= LEVELS) {
        // initialize board
        initialize_board(board, level);
        
        // game play loop
        int game_over = 0;
        while (!game_over) {
            // print board
            print_board(board);
            
            // move pacman
            move_pacman(board, &pac_row, &pac_col);
            
            // move ghosts
            move_ghosts(board);
            
            // check for game over conditions
            if (board[pac_row][pac_col] == GHOST_SYMBOL) {
                end_game("Game Over! You were caught by a ghost.");
                game_over = 1;
            } else if (board[pac_row][pac_col] == DOT_SYMBOL) {
                board[pac_row][pac_col] = ' ';
            }
            int num_dots = 0;
            for (int row = 0; row < ROWS; row++) {
                for (int col = 0; col < COLS; col++) {
                    if (board[row][col] == DOT_SYMBOL) {
                        num_dots++;
                    }
                }
            }
            if (num_dots == 0) {
                printf("You have completed level %d! Onto the next level.\n", level);
                game_over = 1;
                level++;
            }
        }
    }
    
    // end game
    end_game("Congratulations! You have completed all levels.");
    
    return 0;
}

// function definitions

void initialize_board(char board[ROWS][COLS], int level)
{
    // set random seed
    srand(time(NULL));
    
    // populate board with walls
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (row == 0 || row == ROWS-1 || col == 0 || col == COLS-1) {
                board[row][col] = WALL_SYMBOL;
            } else {
                board[row][col] = ' ';
            }
        }
    }
    
    // add dots
    int num_dots = (ROWS-2)*(COLS-2)/10*level;
    for (int i = 0; i < num_dots; i++) {
        int row = rand() % (ROWS-2) + 1;
        int col = rand() % (COLS-2) + 1;
        if (board[row][col] == ' ') {
            board[row][col] = DOT_SYMBOL;
        } else {
            i--;
        }
    }
    
    // add pacman
    board[ROWS/2][COLS/2] = PACMAN_SYMBOL;
    
    // add ghosts
    for (int i = 0; i < NUM_GHOSTS; i++) {
        int row = rand() % (ROWS-2) + 1;
        int col = rand() % (COLS-2) + 1;
        if (board[row][col] == ' ') {
            board[row][col] = GHOST_SYMBOL;
        } else {
            i--;
        }
    }
}

void print_board(char board[ROWS][COLS])
{
    system("clear");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

void move_pacman(char board[ROWS][COLS], int *pac_row, int *pac_col)
{
    // get user input
    char input;
    printf("Move: ");
    scanf(" %c", &input);
    
    // move pacman
    int new_row = *pac_row;
    int new_col = *pac_col;
    switch (input) {
        case 'w':
            new_row--;
            break;
        case 'a':
            new_col--;
            break;
        case 's':
            new_row++;
            break;
        case 'd':
            new_col++;
            break;
    }
    
    // check if legal move and update board
    if (is_legal_move(board, new_row, new_col)) {
        board[*pac_row][*pac_col] = ' ';
        board[new_row][new_col] = PACMAN_SYMBOL;
        *pac_row = new_row;
        *pac_col = new_col;
    }
}

void move_ghosts(char board[ROWS][COLS])
{
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == GHOST_SYMBOL) {
                int new_row = row;
                int new_col = col;
                
                // get random direction
                int direction = get_random_direction();
                
                // move ghost
                switch (direction) {
                    case 0:
                        new_row--;
                        break;
                    case 1:
                        new_col--;
                        break;
                    case 2:
                        new_row++;
                        break;
                    case 3:
                        new_col++;
                        break;
                }
                
                // check if legal move and update board
                if (is_legal_move(board, new_row, new_col)) {
                    board[row][col] = ' ';
                    board[new_row][new_col] = GHOST_SYMBOL;
                }
            }
        }
    }
}

void end_game(char msg[]) {
    printf("\n%s\n", msg);
}

int is_legal_move(char board[ROWS][COLS], int row, int col)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    } else if (board[row][col] == WALL_SYMBOL) {
        return 0;
    } else {
        return 1;
    }
}

int get_random_direction()
{
    return rand() % 4;
}