//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNum(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    char shape = ' ';
    int pos_x = 0, pos_y = 0;
    int score = 0;
    int move_counter = 0;

    // Initialize the haunted house map
    int house_map[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    // Start the game loop
    while (1) {
        // Print out the current state of the haunted house
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == pos_y && j == pos_x) {
                    printf("%c", shape);
                } else if (house_map[i][j]) {
                    printf("#");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }

        // Check if the player has won
        if (pos_y == 5 && pos_x == 5) {
            printf("Congratulations, you have escaped the haunted house!\n");
            printf("Final score: %d\n", score);
            break;
        }

        // Take input from the user
        char input;
        printf("Move your character: ");
        scanf("%c", &input);
        getchar();

        // Move the character based on the input
        switch (input) {
            case 'w':
                if (!house_map[pos_y - 1][pos_x]) {
                    pos_y--;
                    move_counter++;
                    score += randomNum(0, 10);
                    if (move_counter == 3) {
                        shape = 'v';
                    }
                }
                break;
            case 's':
                if (!house_map[pos_y + 1][pos_x]) {
                    pos_y++;
                    move_counter++;
                    score += randomNum(0, 10);
                    if (move_counter == 3) {
                        shape = '$';
                    }
                }
                break;
            case 'a':
                if (!house_map[pos_y][pos_x - 1]) {
                    pos_x--;
                    move_counter++;
                    score += randomNum(0, 10);
                    if (move_counter == 3) {
                        shape = '@';
                    }
                }
                break;
            case 'd':
                if (!house_map[pos_y][pos_x + 1]) {
                    pos_x++;
                    move_counter++;
                    score += randomNum(0, 10);
                    if (move_counter == 3) {
                        shape = '^';
                    }
                }
                break;
            default:
                printf("Invalid input. Try again.\n");
                break;
        }
    }

    return 0;
}