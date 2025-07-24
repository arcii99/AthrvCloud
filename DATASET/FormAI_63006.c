//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define HEIGHT 20
#define WIDTH 25
#define MAX_FRUIT 5

// Structures
struct Player {
    int x, y;
    int score;
};

// Global Variables
char board[HEIGHT][WIDTH];
int fruits[MAX_FRUIT][2];
int num_fruits = 0;
struct Player player;
int game_over = 0;

// Function Declarations
void init_board();
void draw_board();
void spawn_fruit();
void update_score();
void move_player(int dir);
void check_collision();
void game_loop();

int main() {
    srand(time(NULL)); // Seed random number generator
    init_board();
    game_loop();
    return 0;
}

void init_board() {
    int i, j;
    // Set all board spaces to '.'
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = '.';
        }
    }
    // Spawn player and fruit
    player.x = WIDTH / 2;
    player.y = HEIGHT / 2;
    player.score = 0;
    spawn_fruit();
}

void draw_board() {
    int i, j;
    system("clear"); // Clear console
    // Print board
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    // Print score
    printf("Score: %d\n", player.score);
}

void spawn_fruit() {
    if (num_fruits < MAX_FRUIT) {
        int x, y;
        do {
            // Find random empty board space
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        } while (board[y][x] != '.');
        board[y][x] = 'F'; // Spawn fruit
        fruits[num_fruits][0] = x;
        fruits[num_fruits][1] = y;
        num_fruits++;
    }
}

void update_score() {
    player.score++;
    spawn_fruit();
}

void move_player(int dir) {
    // Move player in given direction
    switch (dir) {
        case 0: // Up
            if (player.y > 0) player.y--;
            break;
        case 1: // Down
            if (player.y < HEIGHT - 1) player.y++;
            break;
        case 2: // Left
            if (player.x > 0) player.x--;
            break;
        case 3: // Right
            if (player.x < WIDTH - 1) player.x++;
            break;
    }
}

void check_collision() {
    int i;
    // Check if player collided with a fruit
    for (i = 0; i < num_fruits; i++) {
        if (player.x == fruits[i][0] && player.y == fruits[i][1]) {
            board[player.y][player.x] = '.'; // Remove fruit from board
            update_score();
            num_fruits--;
            for (; i < num_fruits; i++) {
                fruits[i][0] = fruits[i+1][0];
                fruits[i][1] = fruits[i+1][1];
            }
            break;
        }
    }
    // Check if player collided with a wall
    if (board[player.y][player.x] == '#') {
        game_over = 1;
    }
}

void game_loop() {
    char input;
    while (!game_over) {
        draw_board();
        input = getchar();
        switch (input) {
            case 'w': // Up
                move_player(0);
                break;
            case 's': // Down
                move_player(1);
                break;
            case 'a': // Left
                move_player(2);
                break;
            case 'd': // Right
                move_player(3);
                break;
            default:
                break;
        }
        check_collision();
    }
    // Game over
    draw_board();
    printf("\n\nGame over! Final score: %d\n", player.score);
}