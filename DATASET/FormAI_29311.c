//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/time.h>

#define ROWS 8
#define COLS 8

// Define the invader character
char invader = 'O';

// Define the player character
char player = 'X';

// Define the empty space character
char empty = ' ';

// Define the bullet character
char bullet = '|';

// Define the speed of the game
int speed = 1000000;

// Define the maximum number of invader moves
int max_invader_moves = 20;

// Define the maximum number of bullet moves
int max_bullet_moves = 50;

// Define the game board
char board[ROWS][COLS];

// Define the player position
int player_pos = COLS/2;

// Define the invader position
int invader_pos = ROWS/2;

// Define the bullet position
int bullet_pos = -1;

// Define the number of invader moves
int num_invader_moves = 0;

// Define the number of bullet moves
int num_bullet_moves = 0;

// Define the number of points
int points = 0;

// Define the function to update the game board
void update_board() {
    int i, j;

    // Clear the board
    system("clear");

    // Update the board with the player and invader positions
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(i == ROWS-1 && j == player_pos) {
                board[i][j] = player;
            } else if(i == invader_pos && j == COLS/2) {
                board[i][j] = invader;
            } else if(i == bullet_pos && j == player_pos) {
                board[i][j] = bullet;
            } else {
                board[i][j] = empty;
            }
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Print the score
    printf("Score: %d\n", points);
}

// Define the function to move the invader
void move_invader() {
    if(num_invader_moves < max_invader_moves) {
        invader_pos++;
        num_invader_moves++;
    } else {
        invader_pos--;
        num_invader_moves = 0;
    }
}

// Define the function to move the bullet
void move_bullet() {
    if(num_bullet_moves < max_bullet_moves) {
        bullet_pos--;
        num_bullet_moves++;
    } else {
        bullet_pos = -1;
        num_bullet_moves = 0;
    }
}

// Define the function to check for collisions
void check_collisions() {
    if(bullet_pos == invader_pos && player_pos == COLS/2) { // player shoots invader
        points++;
        bullet_pos = -1;
    } else if(invader_pos == ROWS-2 && player_pos != COLS/2) { // invader reaches player
        printf("Game over! You lose.\n");
        exit(0);
    } else if(bullet_pos == -1 && invader_pos == ROWS/2 && player_pos == COLS/2) { // invader shoots player
        printf("Game over! You lose.\n");
        exit(0);
    }
}

// Define the function to read a char from STDIN
char getch() {
    char buf = 0;
    struct termios old = {0};
    if(tcgetattr(0, &old) < 0) {
        perror("tcsetattr()");
    }
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0) {
        perror("tcsetattr ICANON");
    }
    if(read(0, &buf, 1) < 0) {
        perror("read()");
    }
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0) {
        perror("tcsetattr ~ICANON");
    }
    return buf;
}

// Define the main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Configure the STDIN to not block
    fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);

    // Initialize the board
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = empty;
        }
    }

    // Initialize the player and invader positions
    player_pos = COLS/2;
    invader_pos = ROWS/2;

    // Game loop
    while(1) {
        // Update the game board
        update_board();

        // Read input
        char input = getch();

        // Move the player
        if(input == 'a' && player_pos > 0) {
            player_pos--;
        } else if(input == 'd' && player_pos < COLS-1) {
            player_pos++;
        }

        // Move the invader
        move_invader();

        // Move the bullet
        move_bullet();

        // Check for collisions
        check_collisions();

        // Randomly shoot a bullet 
        if(rand() % 10 == 0 && bullet_pos == -1 && invader_pos != ROWS/2) {
            bullet_pos = invader_pos-1;
        }

        // Sleep to control game speed
        usleep(speed);
    }

    return 0;
}