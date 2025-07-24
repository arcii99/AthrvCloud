//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 8
#define BOMB_PERCENTAGE 0.1

typedef struct {
    bool bomb;
    bool flagged;
    bool revealed;
    int nearby_bombs;
} Cell;

void initialize_board(Cell board[][BOARD_SIZE]) {
    // Set all cells to default values
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j].bomb = false;
            board[i][j].flagged = false;
            board[i][j].revealed = false;
            board[i][j].nearby_bombs = 0;
        }
    }
    
    // Set bombs randomly
    srand(time(NULL));
    int total_cells = BOARD_SIZE * BOARD_SIZE;
    int bomb_count = total_cells * BOMB_PERCENTAGE;
    while(bomb_count > 0) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if(!board[x][y].bomb) {
            board[x][y].bomb = true;
            bomb_count--;
        }
    }
    
    // Count nearby bombs for each cell
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j].bomb) continue;
            int count = 0;
            for(int x=i-1; x<=i+1; x++) {
                for(int y=j-1; y<=j+1; y++) {
                    if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) continue;
                    if(board[x][y].bomb) count++;
                }
            }
            board[i][j].nearby_bombs = count;
        }
    }
}

void print_board(Cell board[][BOARD_SIZE], bool show_bombs) {
    // Print column labels
    printf("  ");
    for(int j=0; j<BOARD_SIZE; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");
    
    // Print board with row labels and cell state
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j].revealed) {
                if(board[i][j].bomb && show_bombs) {
                    printf("* ");
                } else if(board[i][j].bomb && !show_bombs) {
                    printf("  ");
                } else if(board[i][j].nearby_bombs > 0) {
                    printf("%d ", board[i][j].nearby_bombs);
                } else {
                    printf(". ");
                }
            } else if(board[i][j].flagged) {
                printf("F ");
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
}

bool is_game_over(Cell board[][BOARD_SIZE]) {
    // Game over if any bomb is revealed
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j].bomb && board[i][j].revealed) {
                return true;
            }
        }
    }
    return false;
}

bool is_game_won(Cell board[][BOARD_SIZE]) {
    // Game won if all non-bomb cells are revealed
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(!board[i][j].bomb && !board[i][j].revealed) {
                return false;
            }
        }
    }
    return true;
}

int play_game(Cell board[][BOARD_SIZE]) {
    int remaining_cells = BOARD_SIZE * BOARD_SIZE;
    while(true) {
        printf("\nRemaining Cells: %d\n", remaining_cells);
        print_board(board, false);
        printf("\nEnter cell coordinates (eg. B3), or 'F' to flag/unflag a cell, or 'Q' to quit: ");
        char input[10];
        scanf("%s", input);
        if(input[0] == 'Q' || input[0] == 'q') {
            return -1;
        }
        if(input[0] == 'F' || input[0] == 'f') {
            int x, y;
            printf("Enter cell coordinates to flag/unflag (eg. B3): ");
            scanf("%d%c", &y, &x);
            x = x - 'A';
            y = y - 1;
            if(board[y][x].revealed) {
                printf("This cell is already revealed!\n");
            } else {
                board[y][x].flagged = !board[y][x].flagged;
            }
            continue;
        }
        int x, y;
        sscanf(input, "%d%c", &y, &x);
        x = x - 'A';
        y = y - 1;
        if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            printf("Invalid cell coordinates!\n");
            continue;
        }
        if(board[y][x].flagged) {
            printf("This cell is flagged!\n");
            continue;
        }
        if(board[y][x].revealed) {
            printf("This cell is already revealed!\n");
            continue;
        }
        board[y][x].revealed = true;
        remaining_cells--;
        if(board[y][x].bomb) {
            printf("\nGAME OVER!\n");
            print_board(board, true);
            return 0;
        } else if(is_game_won(board)) {
            printf("\nCONGRATULATIONS! YOU WON THE GAME!\n");
            print_board(board, true);
            return 1;
        }
    }
}

int main() {
    printf("MINESWEEPER - TERMINAL VERSION\n");
    printf("*************************************************\n");
    printf("INSTRUCTIONS: \n");
    printf("Uncover all cells except bombs\n");
    printf("Enter cell coordinates in format (column)(row). Eg-> B3\n");
    printf("Enter 'F' before cell coordinates to flag/unflag. Eg-> F B3\n");
    printf("Enter 'Q' to quit the game\n");
    printf("*************************************************\n\n");
    Cell board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    int result = play_game(board);
    if(result == 1) {
        printf("You beat the game! Congrats!\n");
    } else if(result == 0) {
        printf("You lost the game! Sorry!\n");
    }
    return 0;
}