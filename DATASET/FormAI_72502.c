//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

// Function to set terminal properties to prevent the need for pressing Enter after each key press
void set_terminal_properties() {
    struct termios old_t, new_t;

    tcgetattr(STDIN_FILENO, &old_t);
    new_t = old_t;
    new_t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
}

// Function to restore terminal properties back to normal
void restore_terminal_properties() {
    struct termios old_t, new_t;

    tcgetattr(STDIN_FILENO, &old_t);
    new_t = old_t;
    new_t.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
}

// Function to detect if a key has been pressed
bool key_pressed() {
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

int main() {
    set_terminal_properties();

    // Initializing variables
    const int ROWS = 20, COLS = 60;
    int player_row = ROWS-1, player_col = COLS/2, bullet_row = -1, bullet_col = -1;
    int enemy_rows = 4, enemy_cols = 10;
    int score = 0;
    bool is_game_over = false;
    char player_char = '^', enemy_char = 'X', bullet_char = '*';

    // Creating the game board
    char game_board[ROWS][COLS];
    memset(game_board, ' ', sizeof(game_board)); // Filling game board with empty spaces
    for(int i=0; i<enemy_rows; i++) {
        for(int j=0; j<enemy_cols; j++) {
            game_board[i][j*(COLS/enemy_cols)] = enemy_char; // Placing enemies on the board
        }
    }
    game_board[player_row][player_col] = player_char; // Placing the player on the board
    
    printf("Press 'a' to move left, 'd' to move right, and 'w' to shoot\n\n");

    // Game loop
    while(!is_game_over) {
        system("clear"); // Clearing the screen
        printf("+----------------------------------------------------+\n");
        for(int i=0; i<ROWS; i++) {
            printf("|");
            for(int j=0; j<COLS; j++) {
                printf("%c", game_board[i][j]);
            }
            printf("|\n");
        }
        printf("+----------------------------------------------------+\n");
        printf("Score: %d\n", score);

        if(key_pressed()) { // Detecting key press
            char key = getchar();
            if(key == 'a' && player_col > 0) { // Moving player left
                game_board[player_row][player_col] = ' ';
                game_board[player_row][player_col-1] = player_char;
                player_col--;
            }
            else if(key == 'd' && player_col < COLS-1) { // Moving player right
                game_board[player_row][player_col] = ' ';
                game_board[player_row][player_col+1] = player_char;
                player_col++;
            }
            else if(key == 'w' && bullet_row == -1) { // Shooting bullet
                bullet_row = player_row-1;
                bullet_col = player_col;
            }
        }

        // Moving bullet
        if(bullet_row > -1) {
            game_board[bullet_row][bullet_col] = bullet_char;
            bullet_row--;
            if(bullet_row == 0) { // Bullet has hit the top of the screen
                game_board[bullet_row][bullet_col] = ' ';
                bullet_row = -1;
            }
            else {
                for(int i=0; i<enemy_rows; i++) {
                    for(int j=0; j<enemy_cols; j++) {
                        if(game_board[i][j*(COLS/enemy_cols)] == enemy_char && bullet_row == i && bullet_col == j*(COLS/enemy_cols)) { // Enemy has been hit
                            game_board[i][j*(COLS/enemy_cols)] = ' ';
                            bullet_row = -1;
                            score++;
                            break;
                        }
                    }
                }
            }
        }

        // Moving enemies
        for(int i=0; i<enemy_rows; i++) {
            bool should_move_down = false;
            for(int j=0; j<enemy_cols; j++) {
                if(game_board[i][j*(COLS/enemy_cols)] == enemy_char) {
                    if(i == ROWS-2) { // Game over: enemies have reached the player
                        is_game_over = true;
                        break;
                    }
                    if(should_move_down) { // Enemy has hit the side of the screen and should move down
                        game_board[i+1][j*(COLS/enemy_cols)] = enemy_char;
                        game_board[i][j*(COLS/enemy_cols)] = ' ';
                    }
                    else if(j%2 == 0 && i < ROWS-2 && game_board[i+1][j*(COLS/enemy_cols)] == ' ') { // Enemy moves forward and shoots bullet
                        game_board[i+1][j*(COLS/enemy_cols)] = enemy_char;
                        game_board[i][j*(COLS/enemy_cols)] = ' ';
                        if(rand()%100 < 30) {
                            bullet_row = i+2;
                            bullet_col = j*(COLS/enemy_cols);
                        }
                    }
                    else { // Enemy moves forward
                        game_board[i][j*(COLS/enemy_cols)+((i%2==0)?1:-1)] = enemy_char;
                        game_board[i][j*(COLS/enemy_cols)] = ' ';
                    }
                }
            }
        }

        usleep(30000); // Waiting for a short amount of time to slow down the game
    }

    system("clear"); // Clearing the screen
    printf("Game over! Score: %d\n\n", score);
    restore_terminal_properties();

    return 0;
}