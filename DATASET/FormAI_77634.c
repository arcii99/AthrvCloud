//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIRECTIONS 4
#define MOVE_COST 10

int player_x = 0;
int player_y = 0;
int credits = 0;

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST,
} DIRECTION;

/**
 * Moves the player in the specified direction and updates their position.
 * Returns 0 if the move is invalid (outside the game world), or 1 if the move is valid.
 */
int move_player(DIRECTION direction) {
    int new_x = player_x;
    int new_y = player_y;

    switch (direction) {
        case NORTH:
            new_y--;
            break;
        case EAST:
            new_x++;
            break;
        case SOUTH:
            new_y++;
            break;
        case WEST:
            new_x--;
            break;
    }

    if (new_x < 0 || new_x >= 10 || new_y < 0 || new_y >= 10) {
        // move is invalid
        return 0;
    }

    // move is valid
    player_x = new_x;
    player_y = new_y;
    credits -= MOVE_COST;
    return 1;
}

int main() {
    srand(time(NULL));
    credits = rand() % 1000;

    printf("Welcome to the Procedural Space Adventure!\n");
    printf("Your current starting location is (%d,%d).\n", player_x, player_y);
    printf("You start with %d credits.\n", credits);

    while (credits > 0) {
        // determine available directions
        int available_directions[MAX_DIRECTIONS];
        int num_available_directions = 0;

        if (player_y > 0) {
            available_directions[num_available_directions] = NORTH;
            num_available_directions++;
        }
        if (player_x < 9) {
            available_directions[num_available_directions] = EAST;
            num_available_directions++;
        }
        if (player_y < 9) {
            available_directions[num_available_directions] = SOUTH;
            num_available_directions++;
        }
        if (player_x > 0) {
            available_directions[num_available_directions] = WEST;
            num_available_directions++;
        }

        printf("You currently have %d credits.\n", credits);
        printf("You can move in the following directions:\n");
        for (int i = 0; i < num_available_directions; i++) {
            switch (available_directions[i]) {
                case NORTH:
                    printf("\tNORTH\n");
                    break;
                case EAST:
                    printf("\tEAST\n");
                    break;
                case SOUTH:
                    printf("\tSOUTH\n");
                    break;
                case WEST:
                    printf("\tWEST\n");
                    break;
            }
        }

        printf("Which direction do you want to move? ");
        char direction_input[10];
        fgets(direction_input, sizeof(direction_input), stdin);
        DIRECTION direction;
        if (direction_input[0] == 'n' || direction_input[0] == 'N') {
            direction = NORTH;
        } else if (direction_input[0] == 'e' || direction_input[0] == 'E') {
            direction = EAST;
        } else if (direction_input[0] == 's' || direction_input[0] == 'S') {
            direction = SOUTH;
        } else if (direction_input[0] == 'w' || direction_input[0] == 'W') {
            direction = WEST;
        } else {
            printf("Invalid direction. Try again.\n");
            continue;
        }

        if (!move_player(direction)) {
            printf("You cannot move in that direction. Try again.\n");
            continue;
        }

        printf("You moved to (%d,%d).\n", player_x, player_y);

        if (player_x == 9 && player_y == 9) {
            printf("Congratulations, you reached the end of the game!\n");
            break;
        }

        // randomly generate credits
        int credits_found = rand() % 100;
        credits += credits_found;
        printf("You found %d credits!\n", credits_found);
    }

    if (credits <= 0) {
        printf("You ran out of credits. Game over.\n");
    }

    return 0;
}