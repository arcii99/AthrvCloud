//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 40

char board[HEIGHT][WIDTH]; // The playing board

// Function to print the board to console
void print_board()
{
    // Print top border
    for (int x = 0; x < WIDTH+2; x++)
        printf("#");
    printf("\n");

    // Print playing area
    for (int y = 0; y < HEIGHT; y++)
    {
        printf("|"); // Left border
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%c", board[y][x]); // Print actual playing area
        }
        printf("|"); // Right border
        printf("\n");
    }

    // Print bottom border
    for (int x = 0; x < WIDTH+2; x++)
        printf("#");
    printf("\n");

    return;
}

// Function to initialize the board with random bricks
void init_board()
{
    // Set all board positions to empty spaces initially
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            board[y][x] = ' ';

    // Seed random number generator
    srand(time(NULL));

    // Add random bricks to the board
    for (int y = 0; y < HEIGHT/2; y++)
        for (int x = 0; x < WIDTH; x++)
            if (rand() % 5 == 0) // 1 in 5 chance of creating a brick in this position
                board[y][x] = '*';

    return;
}

int main()
{
    // Initialize playing board
    init_board();

    // Set initial player position
    int player_pos = WIDTH/2;

    // Print initial board
    print_board();

    // Loop until game over
    while (1)
    {
        // Ask for player input
        printf("Enter left (l) or right (r) to move player, or q to quit: ");
        char input;
        scanf(" %c", &input);

        // Quit game if user inputs 'q'
        if (input == 'q')
        {
            printf("Thanks for playing!\n");
            break;
        }

        // Update player position based on input
        if (input == 'l')
            player_pos--;
        else if (input == 'r')
            player_pos++;

        // Ensure player stays within bounds of playing area
        if (player_pos < 0)
            player_pos = 0;
        else if (player_pos >= WIDTH)
            player_pos = WIDTH-1;

        // Update board with player position
        for (int x = 0; x < WIDTH; x++)
            board[HEIGHT-1][x] = ' '; // Clear player's previous position
        board[HEIGHT-1][player_pos] = 'P'; // Set player's new position

        // Print updated board
        print_board();
    }

    return 0;
}