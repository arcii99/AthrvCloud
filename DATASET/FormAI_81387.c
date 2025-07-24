//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define ROWS 20
#define COLS 20
#define PACMAN 'C'
#define GHOST 'G'
#define WALL '#'
#define FOOD '.'
#define POWER_UP 'o'
#define EMPTY ' '

// Function prototypes
void initialize_board(char board[ROWS][COLS], int *pacman_row, int *pacman_col);
void print_board(char board[ROWS][COLS]);
void move_ghosts(char board[ROWS][COLS]);
bool move_pacman(char board[ROWS][COLS], int *pacman_row, int *pacman_col);
void eat_food(char board[ROWS][COLS], int row, int col, int *score, int *power_up_counter);
void generate_power_up(char board[ROWS][COLS]);
void update_board(char board[ROWS][COLS], int *pacman_row, int *pacman_col, int *score, int *power_up_counter);
bool game_over(char board[ROWS][COLS]);

int main(void)
{
    // Initialize random seed
    srand(time(NULL));

    // Initialize board and pacman position
    char board[ROWS][COLS];
    int pacman_row, pacman_col;
    initialize_board(board, &pacman_row, &pacman_col);

    // Initialize game variables
    int score = 0;
    int power_up_counter = 0;

    // Main game loop
    while (!game_over(board))
    {
        // Print board and score
        print_board(board);
        printf("Score: %d\n", score);

        // Let the user move pacman
        bool moved = move_pacman(board, &pacman_row, &pacman_col);

        // If the user moved, update the board and score
        if (moved)
        {
            eat_food(board, pacman_row, pacman_col, &score, &power_up_counter);
            update_board(board, &pacman_row, &pacman_col, &score, &power_up_counter);
            move_ghosts(board);
        }
    }

    // Print final board and score
    print_board(board);
    printf("Final score: %d\n", score);

    return 0;
}

void initialize_board(char board[ROWS][COLS], int *pacman_row, int *pacman_col)
{
    // Initialize all board cells to empty
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            board[row][col] = EMPTY;
        }
    }

    // Add walls to the board
    for (int row = 0; row < ROWS; row++)
    {
        board[row][0] = WALL;
        board[row][COLS - 1] = WALL;
    }
    for (int col = 0; col < COLS; col++)
    {
        board[0][col] = WALL;
        board[ROWS - 1][col] = WALL;
    }
    board[7][9] = WALL;
    board[8][9] = WALL;
    board[9][9] = WALL;
    board[10][9] = WALL;
    board[11][9] = WALL;
    board[12][9] = WALL;
    board[13][9] = WALL;
    board[14][9] = WALL;
    board[7][10] = WALL;
    board[14][10] = WALL;
    board[9][11] = WALL;
    board[12][11] = WALL;
    board[9][12] = WALL;
    board[10][12] = WALL;
    board[11][12] = WALL;
    board[12][12] = WALL;
    board[7][13] = WALL;
    board[8][13] = WALL;
    board[9][13] = WALL;
    board[12][13] = WALL;
    board[13][13] = WALL;
    board[14][13] = WALL;

    // Add food to the board
    for (int row = 1; row < ROWS - 1; row++)
    {
        for (int col = 1; col < COLS - 1; col++)
        {
            if (board[row][col] != WALL)
            {
                board[row][col] = FOOD;
            }
        }
    }

    // Add power up to the board
    generate_power_up(board);

    // Add pacman to the board
    *pacman_row = ROWS / 2;
    *pacman_col = COLS / 2;
    board[*pacman_row][*pacman_col] = PACMAN;
}

void print_board(char board[ROWS][COLS])
{
    printf("\n");
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void move_ghosts(char board[ROWS][COLS])
{
    // TODO: Implement ghost movement
}

bool move_pacman(char board[ROWS][COLS], int *pacman_row, int *pacman_col)
{
    // Get user input
    char direction;
    printf("Enter direction (w/a/s/d): ");
    scanf(" %c", &direction);

    // Compute new position
    int new_row = *pacman_row;
    int new_col = *pacman_col;
    switch (direction)
    {
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

    // Check if new position is valid
    if (board[new_row][new_col] == WALL)
    {
        return false;
    }

    // Move pacman to new position
    board[*pacman_row][*pacman_col] = EMPTY;
    board[new_row][new_col] = PACMAN;
    *pacman_row = new_row;
    *pacman_col = new_col;

    return true;
}

void eat_food(char board[ROWS][COLS], int row, int col, int *score, int *power_up_counter)
{
    // If cell contains food, eat it and increment score
    if (board[row][col] == FOOD)
    {
        *score += 10;
        board[row][col] = EMPTY;

        // If score reaches a multiple of 100, generate a power-up
        if (*score % 100 == 0)
        {
            generate_power_up(board);
            *power_up_counter = 0;
        }
    }
    // If cell contains power-up, eat it and increment power-up counter
    else if (board[row][col] == POWER_UP)
    {
        *score += 50;
        board[row][col] = EMPTY;
        *power_up_counter = 1;
    }
}

void generate_power_up(char board[ROWS][COLS])
{
    // Find a random cell that is not a wall or already contains food/power-up
    int row, col;
    do
    {
        row = rand() % (ROWS - 2) + 1;
        col = rand() % (COLS - 2) + 1;
    } while (board[row][col] != EMPTY);

    // Add power-up to the board
    board[row][col] = POWER_UP;
}

void update_board(char board[ROWS][COLS], int *pacman_row, int *pacman_col, int *score, int *power_up_counter)
{
    // If power-up was eaten, move ghosts away from pacman
    if (*power_up_counter > 0)
    {
        // TODO: Implement ghost fleeing
    }

    // If pacman has been caught by a ghost, reset board and score
    if (board[*pacman_row][*pacman_col] == GHOST)
    {
        *score = 0;
        initialize_board(board, pacman_row, pacman_col);
    }
}

bool game_over(char board[ROWS][COLS])
{
    // Iterate over all cells and check if any food is left
    for (int row = 1; row < ROWS - 1; row++)
    {
        for (int col = 1; col < COLS - 1; col++)
        {
            if (board[row][col] == FOOD)
            {
                return false;
            }
        }
    }

    return true;
}