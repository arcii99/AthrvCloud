//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define ROWS 20
#define COLS 20
#define WALL '#'
#define FOOD '.'
#define PACMAN 'P'
#define GHOST 'G'

int score = 0; // global score variable

// define the game board
char board[ROWS][COLS] = {
    {"###################"},
    {"#.................#"},
    {"#.###.#.#.#.#.#.#.#"},
    {"#.#...#.#.#.#.#.#.#"},
    {"#.###.#.#.#.#.#.#.#"},
    {"#.................."},
    {"#.###.#.#.#.#.#.#.#"},
    {"#.#...#.#.#.#.#.#.#"},
    {"#.###.###.#.#.#.#.#"},
    {"#.......#...#.#.#.#"},
    {"##########.#.#.#.#."},
    {"#...........#.#.#.#"},
    {"#.#####.#.#.#.#.#.#"},
    {"#.#.....#.#.#.#.#.#"},
    {"#.###.#####.#.#.#.#"},
    {"#.................#"},
    {"#.###.###.#.#.#.#.#"},
    {"#.#.......#.#.#.#.#"},
    {"#.#.###.###.#.#.#.#"},
    {"###################"}
};

// create a struct for the characters in the game
typedef struct {
    char symbol;
    int x, y;
} Character;

// function declarations
void display_board();
Character create_character(char symbol, int x, int y);
bool move(Character *character, int x, int y);
void move_ghost(Character *ghost, Character pacman);
bool is_wall(int x, int y);
bool is_food(int x, int y);

int main() {
    // initialize positions of pacman and ghost
    Character pacman = create_character(PACMAN, 1, 1);
    Character ghost = create_character(GHOST, ROWS-2, COLS-2);

    // display initial board
    display_board();

    // set up for user input
    char direction;
    bool valid_move;

    // loop through game until user quits or eats all the food
    while (score < 216) {
        printf("Enter direction (w,a,s,d) or 'q' to quit: ");
        scanf(" %c", &direction);

        // convert input to lowercase
        direction = tolower(direction);

        // validate user input
        if (direction != 'w' && direction != 'a' && direction != 's' && direction != 'd' && direction != 'q') {
            printf("Invalid direction. Please enter 'w', 'a', 's', 'd', or 'q'.\n");
            continue;
        }

        // move pacman
        switch (direction) {
            case 'w':
                valid_move = move(&pacman, -1, 0);
                break;
            case 'a':
                valid_move = move(&pacman, 0, -1);
                break;
            case 's':
                valid_move = move(&pacman, 1, 0);
                break;
            case 'd':
                valid_move = move(&pacman, 0, 1);
                break;
            case 'q':
                return 0; // quit game
                break;
        }

        // if pacman's move is valid, move the ghost
        if (valid_move) {
            move_ghost(&ghost, pacman);
        }

        // display updated board
        display_board();
    }

    // game over
    printf("Congratulations, you won with a score of %d!\n", score);
    return 0;
}

// function to display the game board
void display_board() {
    system("clear"); // clear the console

    // print each row of the game board
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", board[i]);
    }

    // print current score
    printf("Score: %d\n", score);
}

// function to create a character on the game board
Character create_character(char symbol, int x, int y) {
    Character character = {symbol, x, y};
    board[x][y] = symbol;
    return character;
}

// function to move a character on the game board
bool move(Character *character, int x, int y) {
    // calculate new x and y coordinates
    int new_x = character->x + x;
    int new_y = character->y + y;

    // check if move is valid
    if (is_wall(new_x, new_y)) {
        return false;
    } else if (is_food(new_x, new_y)) {
        score++;
        board[new_x][new_y] = character->symbol;
        board[character->x][character->y] = FOOD;
        character->x = new_x;
        character->y = new_y;
        return true;
    } else {
        board[new_x][new_y] = character->symbol;
        board[character->x][character->y] = FOOD;
        character->x = new_x;
        character->y = new_y;
        return true;
    }
}

// function to move the ghost randomly
void move_ghost(Character *ghost, Character pacman) {
    // calculate x and y distances between ghost and pacman
    int x_distance = pacman.x - ghost->x;
    int y_distance = pacman.y - ghost->y;

    // randomly choose to move horizontally or vertically towards pacman
    if (rand() % 2 == 0) {
        if (x_distance > 0) {
            move(ghost, 1, 0);
        } else if (x_distance < 0) {
            move(ghost, -1, 0);
        }
    } else {
        if (y_distance > 0) {
            move(ghost, 0, 1);
        } else if (y_distance < 0) {
            move(ghost, 0, -1);
        }
    }
}

// function to check if a space is a wall
bool is_wall(int x, int y) {
    if (board[x][y] == WALL) {
        return true;
    } else {
        return false;
    }
}

// function to check if a space is food
bool is_food(int x, int y) {
    if (board[x][y] == FOOD) {
        return true;
    } else {
        return false;
    }
}