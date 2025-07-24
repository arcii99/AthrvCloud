//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the width and height of the game board
#define WIDTH 10
#define HEIGHT 10

// Define the maximum number of aliens allowed
#define MAX_ALIENS 10

// Define the ASCII values for the player and alien characters
#define PLAYER_CHAR 'P'
#define ALIEN_CHAR 'A'

// Define the player's starting position
#define PLAYER_START_X (WIDTH / 2)
#define PLAYER_START_Y (HEIGHT - 1)

// Define the speed at which the player can move
#define PLAYER_SPEED 1

// Define the speed at which the aliens move
#define ALIEN_SPEED 1

// Define the player's score
int score = 0;

// Define the player's position struct
struct position {
    int x;
    int y;
};

// Define the alien struct
struct alien {
    struct position pos;
    int health;
    int is_alive;
};

// Define an array of aliens
struct alien aliens[MAX_ALIENS];

// Initialize the player's position
struct position player_position = {
    .x = PLAYER_START_X,
    .y = PLAYER_START_Y
};

// Move the player left or right
void move_player(int direction) {
    if (direction == -1 && player_position.x > 0) {
        player_position.x -= PLAYER_SPEED;
    } else if (direction == 1 && player_position.x < WIDTH - 1) {
        player_position.x += PLAYER_SPEED;
    }
}

// Initialize the aliens
void init_aliens() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the aliens' initial positions
    for (int i = 0; i < MAX_ALIENS; i++) {
        aliens[i].pos.x = rand() % WIDTH;
        aliens[i].pos.y = rand() % HEIGHT;
        aliens[i].health = 3;
        aliens[i].is_alive = 1;
    }
}

// Move the aliens
void move_aliens() {
    for (int i = 0; i < MAX_ALIENS; i++) {
        if (aliens[i].is_alive) {
            aliens[i].pos.y += ALIEN_SPEED;
            if (aliens[i].pos.y == player_position.y && aliens[i].pos.x == player_position.x) {
                printf("You were hit by an alien and lost a life!\n");
                exit(0);
            }
        }
    }
}

// Draw the game board
void draw_board() {
    // Clear the console
    system("clear");
    
    // Print the aliens
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int is_alien = 0;
            
            // Check if there is an alien at this position
            for (int i = 0; i < MAX_ALIENS; i++) {
                if (aliens[i].is_alive && aliens[i].pos.x == x && aliens[i].pos.y == y) {
                    is_alien = 1;
                    printf("%c", ALIEN_CHAR);
                }
            }
            
            // If there is not an alien at this position, print either the player or a blank space
            if (!is_alien) {
                if (x == player_position.x && y == player_position.y) {
                    printf("%c", PLAYER_CHAR);
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    
    // Print the score
    printf("Score: %d\n", score);
}

// Check if the player has killed an alien
void check_for_kill() {
    for (int i = 0; i < MAX_ALIENS; i++) {
        if (aliens[i].is_alive && aliens[i].pos.y == player_position.y && aliens[i].pos.x == player_position.x) {
            aliens[i].health--;
            if (aliens[i].health == 0) {
                aliens[i].is_alive = 0;
                score++;
            }
        }
    }
}

int main() {
    // Initialize the aliens
    init_aliens();
    
    // Keep looping until the player loses
    while (1) {
        // Move the player
        int move_direction = 0;
        scanf("%d", &move_direction);
        move_player(move_direction);
        
        // Move the aliens
        move_aliens();
        
        // Check for a kill
        check_for_kill();
        
        // Draw the board
        draw_board();
    }
    
    return 0;
}