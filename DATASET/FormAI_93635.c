//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

const char PLAYER_ICON = '@';
const char TREASURE_ICON = '$';
const char EMPTY_ICON = '-';
const char OBSTACLE_ICON = '#';

int player_x, player_y, treasure_x, treasure_y;
char board[BOARD_SIZE][BOARD_SIZE];

void place_obstacles(int num_obstacles) {
    int x, y;
    for(int i = 0; i < num_obstacles; i++) {
        do {
            x = rand() % BOARD_SIZE;
            y = rand() % BOARD_SIZE;
        } while(board[y][x] != EMPTY_ICON);
        board[y][x] = OBSTACLE_ICON;
    }
}

void initialize_board() {
    // Initialize the board with empty spaces
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_ICON;
        }
    }

    // Place player and treasure on random positions
    player_x = rand() % BOARD_SIZE;
    player_y = rand() % BOARD_SIZE;
    treasure_x = rand() % BOARD_SIZE;
    treasure_y = rand() % BOARD_SIZE;

    // Make sure player and treasure are not in the same position
    while(player_x == treasure_x && player_y == treasure_y) {
        treasure_x = rand() % BOARD_SIZE;
        treasure_y = rand() % BOARD_SIZE;
    }

    // Place player and treasure on the board
    board[player_y][player_x] = PLAYER_ICON;
    board[treasure_y][treasure_x] = TREASURE_ICON;

    // Place random obstacles on the board
    place_obstacles(10);
}

void print_board() {
    printf(" ");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d ", i);
    }
    printf("\n");

    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d", i);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

void update_player_position(char direction) {
    int new_x = player_x;
    int new_y = player_y;

    switch(direction) {
        case 'W':
        case 'w':
            new_y--;
            break;
        case 'A':
        case 'a':
            new_x--;
            break;
        case 'S':
        case 's':
            new_y++;
            break;
        case 'D':
        case 'd':
            new_x++;
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }

    // Check if new position is within the board
    if(new_x >= 0 && new_x < BOARD_SIZE && new_y >= 0 && new_y < BOARD_SIZE) {
        // Check if new position is an obstacle
        if(board[new_y][new_x] != OBSTACLE_ICON) {
            // Update player position on board
            board[player_y][player_x] = EMPTY_ICON;
            board[new_y][new_x] = PLAYER_ICON;
            player_x = new_x;
            player_y = new_y;
        } else {
            printf("You hit an obstacle!\n");
        }
    } else {
        printf("You hit a wall!\n");
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    initialize_board();

    printf("Welcome to Treasure Hunter!\n");
    printf("Your goal is to find the treasure ($) without hitting any obstacles (#).\n");
    printf("You can move using the W, A, S, and D keys.\n");
    printf("Good luck!\n\n");

    char direction;
    while(board[player_y][player_x] != TREASURE_ICON) {
        print_board();

        printf("\nEnter direction (W, A, S, D): ");
        scanf(" %c", &direction);

        update_player_position(direction);
    }

    printf("\nCongratulations, you found the treasure!\n");

    return 0;
}