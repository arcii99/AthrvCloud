//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables to keep track of player's position
int player_row = 10;
int player_col = 10;

// Function to display the game board
void display_board() {
    // Create a 20 x 20 game board
    char board[20][20];

    // Fill the board with empty space characters
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            board[i][j] = ' ';
        }
    }

    // Place the player on the board
    board[player_row][player_col] = 'P';

    // Display the game board
    printf("+--------------------+\n");
    for (int i = 0; i < 20; i++) {
        printf("|");
        for (int j = 0; j < 20; j++) {
            printf("%c", board[i][j]);
        }
        printf("|\n");
    }
    printf("+--------------------+\n");
}

// Function to move the player
void move_player(char direction) {
    switch(direction) {
        case 'N':
            player_row--;
            break;
        case 'S':
            player_row++;
            break;
        case 'E':
            player_col++;
            break;
        case 'W':
            player_col--;
            break;
        default:
            printf("Invalid direction\n");
            break;
    }
}

// Function to generate a random encounter
void encounter() {
    int dice = rand() % 6 + 1;

    printf("You've encountered a hostile alien ship!\n");

    switch(dice) {
        case 1:
        case 2:
        case 3:
            printf("You've successfully negotiated a peaceful resolution.\n");
            break;
        case 4:
        case 5:
            printf("You've engaged in combat and defeated the alien ship.\n");
            break;
        case 6:
            printf("The alien ship has damaged your engines and you're forced to retreat.\n");
            move_player('N');
            break;
    }
}

int main() {
    char input;
    srand(time(NULL));

    printf("Welcome to Procedural Space Adventure!\n");

    do {
        display_board();

        printf("Enter a direction (N/S/E/W): ");
        scanf(" %c", &input);

        move_player(input);

        if (rand() % 6 == 0) {
            encounter();
        }

    } while (input != 'Q');

    printf("Thanks for playing!\n");

    return 0;
}