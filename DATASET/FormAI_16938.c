//FormAI DATASET v1.0 Category: Game of Life ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 50
#define HEIGHT 20

int board[WIDTH][HEIGHT]; // Global board state

int count_live_neighbors(int x, int y)
{
    int count = 0;
    int xi, yi;

    for (xi = x - 1; xi <= x + 1; xi++) {
        for (yi = y - 1; yi <= y + 1; yi++) {
            if (xi == x && yi == y) // Skip the current cell
                continue;
            if (xi < 0 || xi >= WIDTH || yi < 0 || yi >= HEIGHT) // Don't go out of bounds
                continue;
            if (board[xi][yi]) // Check if the neighbor is alive
                count++;
        }
    }

    return count;
}

void step() // One step of the simulation
{
    int x, y;
    int neighbors;

    int new_board[WIDTH][HEIGHT]; // Create a new board to hold the next state

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            neighbors = count_live_neighbors(x, y);

            if (board[x][y]) { // If the cell is alive
                if (neighbors < 2 || neighbors > 3) // Die from underpopulation or overpopulation
                    new_board[x][y] = 0;
                else // Survive
                    new_board[x][y] = 1;
            } else { // If the cell is dead
                if (neighbors == 3) // Come to life
                    new_board[x][y] = 1;
                else // Stay dead
                    new_board[x][y] = 0;
            }
        }
    }

    // Copy the new board back to the global board
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            board[x][y] = new_board[x][y];
        }
    }
}

void clear_screen()
{
    printf("\x1B[2J");
    printf("\x1B[H");
}

void draw_board()
{
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (board[x][y])
                printf("\u25A0"); // Black square for live cell
            else
                printf("\u25A1"); // White square for dead cell
        }
        printf("\n");
    }
}

int main()
{
    clear_screen();

    // Initialize the board randomly
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            board[x][y] = rand() % 2;
        }
    }

    while (1) {
        draw_board();
        step();
        usleep(100000); // Wait for 100ms
        clear_screen();
    }

    return 0; // Never reached
}