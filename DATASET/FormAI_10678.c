//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_CHAR '#'
#define PLAYER_CHAR 'O'
#define FRUIT_CHAR 'F'

#define MAX_PLAYER_MOVE 2
#define MAX_FRUIT 10

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

typedef struct {
    int x, y;
} position;

void init_board(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = BOARD_CHAR;
        }
    }
}

void print_board(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void put_player(char board[BOARD_HEIGHT][BOARD_WIDTH], position player_position) {
    board[player_position.y][player_position.x] = PLAYER_CHAR;
}

void remove_player(char board[BOARD_HEIGHT][BOARD_WIDTH], position player_position) {
    board[player_position.y][player_position.x] = BOARD_CHAR;
}

void put_fruit(char board[BOARD_HEIGHT][BOARD_WIDTH], position fruit_position) {
    board[fruit_position.y][fruit_position.x] = FRUIT_CHAR;
}

void remove_fruit(char board[BOARD_HEIGHT][BOARD_WIDTH], position fruit_position) {
    board[fruit_position.y][fruit_position.x] = BOARD_CHAR;
}

position get_random_position() {
    position p;
    p.x = rand() % BOARD_WIDTH;
    p.y = rand() % BOARD_HEIGHT;
    return p;
}

bool is_player_position_valid(position player_position) {
    if (player_position.x < 0 || player_position.x >= BOARD_WIDTH) {
        return false;
    }
    if (player_position.y < 0 || player_position.y >= BOARD_HEIGHT) {
        return false;
    }
    return true;
}

bool is_fruit_position_valid(position fruit_position, char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    if (fruit_position.x < 0 || fruit_position.x >= BOARD_WIDTH) {
        return false;
    }
    if (fruit_position.y < 0 || fruit_position.y >= BOARD_HEIGHT) {
        return false;
    }
    if (board[fruit_position.y][fruit_position.x] != BOARD_CHAR) {
        return false;
    }
    return true;
}

void update_player_position(position *player_position, int dx, int dy) {
    player_position->x += dx;
    player_position->y += dy;
}

void play_game() {
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    position player_position = { BOARD_WIDTH / 2, BOARD_HEIGHT / 2 };
    position fruit_positions[MAX_FRUIT];
    int n_fruits = 0;
    srand(time(NULL));
    init_board(board);
    while (true) {
        system("clear"); // clear the terminal
        put_player(board, player_position);
        for (int i = 0; i < n_fruits; i++) {
            put_fruit(board, fruit_positions[i]);
        }
        print_board(board);
        remove_player(board, player_position);
        for (int i = 0; i < n_fruits; i++) {
            remove_fruit(board, fruit_positions[i]);
        }
        char input[10]; // allow up to 10 characters for input
        printf("Please enter your move (up/down/left/right): ");
        scanf("%s", input);
        int dx = 0, dy = 0;
        if (strcmp(input, "up") == 0) {
            dy = -1;
        } else if (strcmp(input, "down") == 0) {
            dy = 1;
        } else if (strcmp(input, "left") == 0) {
            dx = -1;
        } else if (strcmp(input, "right") == 0) {
            dx = 1;
        }
        update_player_position(&player_position, dx, dy);

        // check if player ate any fruit
        for (int i = 0; i < n_fruits; i++) {
            if (player_position.x == fruit_positions[i].x && player_position.y == fruit_positions[i].y) {
                n_fruits--;
                remove_fruit(board, fruit_positions[i]);
                fruit_positions[i] = fruit_positions[n_fruits];
                break;
            }
        }

        // check if we need to add new fruit
        while (n_fruits < MAX_FRUIT) {
            position fruit_position = get_random_position();
            if (is_fruit_position_valid(fruit_position, board)) {
                fruit_positions[n_fruits] = fruit_position;
                put_fruit(board, fruit_positions[n_fruits]);
                n_fruits++;
            }
        }

        // check if player lost
        if (!is_player_position_valid(player_position)) {
            printf("Game over! You lost.\n");
            break;
        }
    }
}

int main() {
    printf("Welcome to the Fruit Game!\n");
    printf("Collect as many fruits as you can.\n");
    printf("But be careful not to fall off the board!\n");
    play_game();
    return 0;
}