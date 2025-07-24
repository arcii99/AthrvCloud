//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 6
#define COLS 10
#define ALIEN_ROWS 3
#define ALIEN_COLS 5

// ALIENS
char aliens[ALIEN_ROWS][ALIEN_COLS] = {'^', '^', '^', '^', '^', 'o', 'o', 'o', 'o', 'o', '*', '*', '*', '*', '*'};
int alien_direction = 1;
int alien_move_count = 0;

// PLAYER SHIP
char player_ship = '=';
int player_position = 4;
int player_move_count = 0;

// BULLETS
bool player_bullet_exists = false;
int player_bullet_row = -1;
int player_bullet_col = -1;
bool alien_bullet_exists = false;
int alien_bullet_row = -1;
int alien_bullet_col = -1;

// GAME BOARD
char board[ROWS][COLS];

// FUNCTION PROTOTYPES
void setup_game();
void draw_game_board();
void move_aliens();
void move_player_ship(char);
void fire_player_bullet();
void fire_alien_bullet();
void update_player_bullet();
void update_alien_bullet();
bool check_game_over();

// MAIN FUNCTION
int main() {
    char player_input;
    bool game_over = false;
    
    setup_game();
    
    while (!game_over) {
        // DRAW GAME BOARD
        draw_game_board();
        
        // MOVE ALIENS
        move_aliens();
        
        // MOVE PLAYER SHIP
        player_move_count++;
        if (player_move_count == 2) {
            player_move_count = 0;
            move_player_ship(player_input);
        }
        
        // FIRE PLAYER BULLET
        if (player_input == ' ') {
            fire_player_bullet();
        }
        
        // FIRE ALIEN BULLET
        if (rand() % 25 == 0 && !alien_bullet_exists) {
            fire_alien_bullet();
        }
        
        // UPDATE PLAYER BULLET
        if (player_bullet_exists) {
            update_player_bullet();
        }
        
        // UPDATE ALIEN BULLET
        if (alien_bullet_exists) {
            update_alien_bullet();
        }
        
        // CHECK GAME OVER
        game_over = check_game_over();
        
        // GET PLAYER INPUT
        player_input = getchar();
    }
    
    printf("\nGame Over!\n");
    
    return 0;
}

// FUNCTION DEFINITIONS
void setup_game() {
    // Initialize RNG
    srand(time(NULL));
    
    // Initialize game board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
    
    // Place aliens on game board
    int alien_index = 0;
    for (int i = 0; i < ALIEN_ROWS; i++) {
        for (int j = 0; j < ALIEN_COLS; j++) {
            board[i][j + (COLS - ALIEN_COLS) / 2] = aliens[alien_index++];
        }
    }
    
    // Place player ship on game board
    board[ROWS - 1][player_position] = player_ship;
}

void draw_game_board() {
    system("clear");
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void move_aliens() {
    alien_move_count++;
    
    if (alien_move_count == 10) {
        alien_move_count = 0;
        
        // Move aliens
        bool hit_wall = false;
        for (int i = 0; i < ALIEN_ROWS; i++) {
            for (int j = 0; j < ALIEN_COLS; j++) {
                if (board[i][j] == '^' || board[i][j] == 'o' || board[i][j] == '*') {
                    board[i][j + alien_direction] = board[i][j];
                    board[i][j] = ' ';
                    
                    // Check if aliens hit wall
                    if (j + alien_direction >= COLS || j + alien_direction < 0) {
                        hit_wall = true;
                    }
                }
            }
        }
        
        // Change direction of aliens if they hit wall
        if (hit_wall) {
            alien_direction = -alien_direction;
            for (int i = 0; i < ALIEN_ROWS; i++) {
                for (int j = 0; j < ALIEN_COLS; j++) {
                    if (board[i][j] == '^' || board[i][j] == 'o' || board[i][j] == '*') {
                        board[i + 1][j] = board[i][j];
                        board[i][j] = ' ';
                    }
                }
            }
        }
    }
}

void move_player_ship(char input) {
    // Move ship left
    if (input == 'a' && player_position > 0) {
        board[ROWS - 1][player_position + 1] = ' ';
        player_position--;
        board[ROWS - 1][player_position] = player_ship;
    }
    // Move ship right
    else if (input == 'd' && player_position < COLS - 1) {
        board[ROWS - 1][player_position] = ' ';
        player_position++;
        board[ROWS - 1][player_position] = player_ship;
    }
}

void fire_player_bullet() {
    if (!player_bullet_exists) {
        player_bullet_exists = true;
        player_bullet_row = ROWS - 2;
        player_bullet_col = player_position;
        board[player_bullet_row][player_bullet_col] = '|';
    }
}

void fire_alien_bullet() {
    // Select random alien to shoot from
    int row = rand() % ALIEN_ROWS;
    int col = rand() % ALIEN_COLS;
    
    // Check if alien is available
    if (board[row][col + (COLS - ALIEN_COLS) / 2] == '^' || board[row][col + (COLS - ALIEN_COLS) / 2] == 'o' || board[row][col + (COLS - ALIEN_COLS) / 2] == '*') {
        // Fire bullet from alien
        alien_bullet_exists = true;
        alien_bullet_row = row;
        alien_bullet_col = col + (COLS - ALIEN_COLS) / 2;
        board[alien_bullet_row][alien_bullet_col] = '|';
    }
}

void update_player_bullet() {
    board[player_bullet_row][player_bullet_col] = ' ';
    player_bullet_row--;
    
    // Check if bullet hits alien
    if (board[player_bullet_row][player_bullet_col] == '^' || board[player_bullet_row][player_bullet_col] == 'o' || board[player_bullet_row][player_bullet_col] == '*') {
        board[player_bullet_row][player_bullet_col] = ' ';
        player_bullet_exists = false;
    }
    // Check if bullet goes off screen
    else if (player_bullet_row < 0) {
        player_bullet_exists = false;
    }
    // Move bullet up
    else {
        board[player_bullet_row][player_bullet_col] = '|';
    }
}

void update_alien_bullet() {
    board[alien_bullet_row][alien_bullet_col] = ' ';
    alien_bullet_row++;
    
    // Check if bullet hits player
    if (board[alien_bullet_row][alien_bullet_col] == player_ship) {
        board[alien_bullet_row][alien_bullet_col] = ' ';
        alien_bullet_exists = false;
    }
    // Check if bullet goes off screen
    else if (alien_bullet_row >= ROWS) {
        alien_bullet_exists = false;
    }
    // Move bullet down
    else {
        board[alien_bullet_row][alien_bullet_col] = '|';
    }
}

bool check_game_over() {
    // Check if player ship is hit
    for (int i = 0; i < COLS; i++) {
        if (board[ROWS - 2][i] == '|') {
            return true;
        }
    }
    
    // Check if all aliens are destroyed
    for (int i = 0; i < ALIEN_ROWS; i++) {
        for (int j = 0; j < ALIEN_COLS; j++) {
            if (board[i][j + (COLS - ALIEN_COLS) / 2] == '^' || board[i][j + (COLS - ALIEN_COLS) / 2] == 'o' || board[i][j + (COLS - ALIEN_COLS) / 2] == '*') {
                return false;
            }
        }
    }
    
    return true;
}