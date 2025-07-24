//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define constants
#define ROWS 10
#define COLS 10
#define NUM_GHOSTS 3
#define WALL '%'
#define GHOST 'G'
#define PLAYER 'P'
#define EXIT 'E'
#define EMPTY_SPACE '.'


// Function prototypes
void clear_buffer();
void print_board(char board[][COLS], int player_pos[]);
void generate_board(char board[][COLS], int player_pos[], int ghost_pos[][2], int exit_pos[]);
void move_player(char board[][COLS], int player_pos[], int ghost_pos[][2]);
void move_ghost(char board[][COLS], int ghost_pos[][2], int player_pos[]);
bool game_over(char board[][COLS], int player_pos[], int ghost_pos[][2], int exit_pos[]);


int main()
{
    // Initialize random seed
    srand((unsigned int) time(NULL));

    // Declare variables
    char board[ROWS][COLS];
    int player_pos[2] = { 0, 0 }; // Player starts at top left corner
    int ghost_pos[NUM_GHOSTS][2];
    int exit_pos[2];

    // Generate board
    generate_board(board, player_pos, ghost_pos, exit_pos);

    // Loop until game over
    while (!game_over(board, player_pos, ghost_pos, exit_pos)) {
        // Print board and prompt for move
        print_board(board, player_pos);
        printf("Enter move (WASD): ");
        move_player(board, player_pos, ghost_pos);
        move_ghost(board, ghost_pos, player_pos);
    }

    // Print final board and game over message
    print_board(board, player_pos);
    printf("\nGAME OVER\n");

    return 0;
}


// Function to clear buffer
void clear_buffer()
{
    while(getchar() != '\n');
}


// Function to print board
void print_board(char board[][COLS], int player_pos[])
{
    // Clear screen
    system("clear");

    // Print board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == player_pos[0] && j == player_pos[1]) {
                printf("%c", PLAYER);
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
}


// Function to generate board
void generate_board(char board[][COLS], int player_pos[], int ghost_pos[][2], int exit_pos[])
{
    // Initialize board with wall characters
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = WALL;
        }
    }

    // Place player at top left corner
    board[player_pos[0]][player_pos[1]] = PLAYER;

    // Place ghosts at random positions
    for (int i = 0; i < NUM_GHOSTS; i++) {
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (board[row][col] != EMPTY_SPACE);
        board[row][col] = GHOST;
        ghost_pos[i][0] = row;
        ghost_pos[i][1] = col;
    }

    // Place exit at random position
    int row, col;
    do {
        row = rand() % ROWS;
        col = rand() % COLS;
    } while (board[row][col] != EMPTY_SPACE);
    board[row][col] = EXIT;
    exit_pos[0] = row;
    exit_pos[1] = col;
}


// Function to move player
void move_player(char board[][COLS], int player_pos[], int ghost_pos[][2])
{
    // Get user input
    char input;
    scanf("%c", &input);
    clear_buffer();

    // Determine new position
    int new_pos[2] = { player_pos[0], player_pos[1] };
    if (input == 'w' && player_pos[0] > 0) {
        new_pos[0] = player_pos[0] - 1;
    } else if (input == 'a' && player_pos[1] > 0) {
        new_pos[1] = player_pos[1] - 1;
    } else if (input == 's' && player_pos[0] < ROWS - 1) {
        new_pos[0] = player_pos[0] + 1;
    } else if (input == 'd' && player_pos[1] < COLS - 1) {
        new_pos[1] = player_pos[1] + 1;
    }

    // Move player if new position is empty
    if (board[new_pos[0]][new_pos[1]] == EMPTY_SPACE) {
        // Update board and player position
        board[player_pos[0]][player_pos[1]] = EMPTY_SPACE;
        board[new_pos[0]][new_pos[1]] = PLAYER;
        player_pos[0] = new_pos[0];
        player_pos[1] = new_pos[1];
    } else if (board[new_pos[0]][new_pos[1]] == GHOST) {
        // Game over if player hits a ghost
        clear_buffer();
        printf("\nYou have been caught by a ghost!\n");
    } else if (board[new_pos[0]][new_pos[1]] == EXIT) {
        // Game over if player reaches the exit
        clear_buffer();
        printf("\nYou have escaped!\n");
    } else {
        clear_buffer();
        printf("\nInvalid move!\n");
    }
}


// Function to move ghosts
void move_ghost(char board[][COLS], int ghost_pos[][2], int player_pos[])
{
    for (int i = 0; i < NUM_GHOSTS; i++) {
        // Determine new position for current ghost
        int new_pos[2] = { ghost_pos[i][0], ghost_pos[i][1] };
        if (ghost_pos[i][0] < player_pos[0]) {
            new_pos[0] = ghost_pos[i][0] + 1;
        } else if (ghost_pos[i][0] > player_pos[0]) {
            new_pos[0] = ghost_pos[i][0] - 1;
        }
        if (ghost_pos[i][1] < player_pos[1]) {
            new_pos[1] = ghost_pos[i][1] + 1;
        } else if (ghost_pos[i][1] > player_pos[1]) {
            new_pos[1] = ghost_pos[i][1] - 1;
        }

        // Update board and ghost position if new position is empty
        if (board[new_pos[0]][new_pos[1]] == EMPTY_SPACE) {
            board[ghost_pos[i][0]][ghost_pos[i][1]] = EMPTY_SPACE;
            board[new_pos[0]][new_pos[1]] = GHOST;
            ghost_pos[i][0] = new_pos[0];
            ghost_pos[i][1] = new_pos[1];
        } else if (board[new_pos[0]][new_pos[1]] == PLAYER) {
            // Game over if ghost catches player
            clear_buffer();
            printf("\nYou have been caught by a ghost!\n");
            return;
        }
    }
}


// Function to check if game is over
bool game_over(char board[][COLS], int player_pos[], int ghost_pos[][2], int exit_pos[])
{
    // Check if player has reached the exit or has been caught by a ghost
    for (int i = 0; i < NUM_GHOSTS; i++) {
        if (player_pos[0] == ghost_pos[i][0] && player_pos[1] == ghost_pos[i][1]) {
            return true;
        }
    }
    if (player_pos[0] == exit_pos[0] && player_pos[1] == exit_pos[1]) {
        return true;
    }

    return false;
}