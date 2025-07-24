//FormAI DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4  // number of rows in the grid
#define COLS 4  // number of columns in the grid

// function prototypes
void display_grid(int grid[ROWS][COLS], int revealed[ROWS][COLS]);
void initialize_grid(int grid[ROWS][COLS]);
void shuffle(int grid[ROWS][COLS]);
void play_game(int grid[ROWS][COLS]);

int main()
{
    int grid[ROWS][COLS];
    initialize_grid(grid);
    shuffle(grid);
    play_game(grid);

    return 0;
}

// Displays the current state of the game grid
void display_grid(int grid[ROWS][COLS], int revealed[ROWS][COLS])
{
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(revealed[i][j] == 1) {
                printf("%d\t", grid[i][j]);
            } else {
                printf("X\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Initializes the game grid with unique numbers from 1 to (ROWS*COLS)/2
void initialize_grid(int grid[ROWS][COLS])
{
    int num = 1;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = num / 2 + 1;
            num++;
        }
    }
}

// Shuffles the numbers in the game grid
void shuffle(int grid[ROWS][COLS])
{
    srand(time(NULL));
    int temp, x1, y1, x2, y2;

    for(int i = 0; i < ROWS*COLS; i++) {
        x1 = rand() % ROWS;
        y1 = rand() % COLS;
        x2 = rand() % ROWS;
        y2 = rand() % COLS;

        temp = grid[x1][y1];
        grid[x1][y1] = grid[x2][y2];
        grid[x2][y2] = temp;
    }
}

// Runs the game and prompts the user to input their guesses
void play_game(int grid[ROWS][COLS])
{
    int revealed[ROWS][COLS] = {0};
    int guesses[2][2];
    int num_correct = 0, num_guesses = 0, num_pairs = (ROWS*COLS) / 2;

    while(num_correct < num_pairs) {
        display_grid(grid, revealed);
        printf("Enter row and column numbers (separated by spaces): ");
        scanf("%d %d", &guesses[num_guesses][0], &guesses[num_guesses][1]);

        if(num_guesses == 1 && guesses[0][0] == guesses[1][0] && guesses[0][1] == guesses[1][1]) {
            printf("Invalid guess. Please guess again.\n");
            continue;
        }

        if(revealed[guesses[num_guesses][0]][guesses[num_guesses][1]] == 1) {
            printf("Square already revealed. Please guess again.\n");
            continue;
        }

        revealed[guesses[num_guesses][0]][guesses[num_guesses][1]] = 1;
        num_guesses++;

        if(num_guesses == 2) {
            if(grid[guesses[0][0]][guesses[0][1]] == grid[guesses[1][0]][guesses[1][1]]) {
                printf("Correct!\n");
                num_correct++;
            } else {
                printf("Incorrect.\n");
                revealed[guesses[0][0]][guesses[0][1]] = 0;
                revealed[guesses[1][0]][guesses[1][1]] = 0;
            }
            num_guesses = 0;
        }
    }

    printf("Congratulations, you won!\n");
}