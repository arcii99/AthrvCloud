//FormAI DATASET v1.0 Category: Robot movement control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the hilarious Robot movement control program!\n\n");
    printf("Press any key to start the program...\n");
    getchar();

    srand(time(NULL));
    int x = 0, y = 0; // initialize x and y coordinates to 0

    // loop until user wants to exit
    while (1) {
        printf("Your Robot is at position (%d,%d)\n", x, y);
        printf("Enter a direction to move (up, down, left, right) or 'exit' to quit: ");

        char direction[10];
        fgets(direction, 10, stdin); // get user input

        if (strcmp(direction, "exit\n") == 0) {
            break;
        }
        else if (strcmp(direction, "up\n") == 0) {
            printf("Moving up...\n");
            y++;
        }
        else if (strcmp(direction, "down\n") == 0) {
            printf("Moving down...\n");
            y--;
        }
        else if (strcmp(direction, "left\n") == 0) {
            printf("Moving left...\n");
            x--;
        }
        else if (strcmp(direction, "right\n") == 0) {
            printf("Moving right...\n");
            x++;
        }
        else {
            printf("Invalid direction! Try again.\n");
        }

        if (x == 0 && y == 0) { // if Robot is back at origin
            printf("Congratulations, you have won the game!\n");
            break;
        }

        // randomly generate a silly message
        int rand_num = rand() % 5;
        switch (rand_num) {
            case 0:
                printf("Watch out for that banana peel!\n");
                break;
            case 1:
                printf("Oops...you just stepped on a Lego!\n");
                break;
            case 2:
                printf("You're doing great! Keep it up!\n");
                break;
            case 3:
                printf("Uh oh, you just ran into a wall!\n");
                break;
            default:
                printf("Yikes! That was close!\n");
        }
    }

    printf("\nGoodbye user! Thanks for playing the hilarious Robot movement control game.\n");

    return 0;
}