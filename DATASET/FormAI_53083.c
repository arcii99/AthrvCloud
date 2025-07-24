//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

int main() {
    int i, j, k, score = 0, remaining = 50, shots[COLS] = { 0 }; // shots array keeps track of shots fired in each column
    bool endgame = false;
    char input;
    int aliens[ROWS][COLS] = { 0 }; // initialize all aliens to be dead (0)

    printf("\n Welcome to the C Space Invaders Clone! \n");
    printf("Shoot all 50 aliens before they reach the bottom of the screen. \n");
    printf("Press 'a' and 'd' to move the player left and right. \n");
    printf("Press 'space' to shoot. \n");

    // randomly set 10 aliens in the first row as alive (1)
    srand(time(0));
    for (i = 0; i < COLS; i++) {
        aliens[0][i] = rand() % 2;
        if (aliens[0][i]) remaining++; // if the alien is alive, add to remaining count
    }

    while (!endgame) {
        // prints the game board
        printf("\n SCORE:%d \t REMAINING ALIENS:%d \n", score, remaining);
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (aliens[i][j]) printf("*"); // print alive aliens as *
                else printf(" ");
            }
            printf("\n");
        }

        // checks for endgame condition
        if (remaining == 0) {
            printf("\n YOU WIN!!! \n");
            printf("FINAL SCORE:%d \n", score);
            return 0;
        }

        // player input
        printf("\n MOVE: ");
        scanf(" %c", &input);

        // move player left or right
        if (input == 'a') {
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    if (aliens[i][j] == 2) {
                        aliens[i][j-1] = 2;
                        aliens[i][j] = 0;
                    }
                }
            }
        }
        else if (input == 'd') {
            for (i = 0; i < ROWS; i++) {
                for (j = COLS-1; j >= 0; j--) {
                    if (aliens[i][j] == 2) {
                        aliens[i][j+1] = 2;
                        aliens[i][j] = 0;
                    }
                }
            }
        }

        // move aliens down 1 row
        for (i = ROWS-1; i > 0; i--) {
            for (j = 0; j < COLS; j++) {
                aliens[i][j] = aliens[i-1][j];
            }
        }

        // randomly generate new aliens at the top row
        for (k = 0; k < COLS; k++) {
            if (aliens[0][k] == 0) { // if the alien above is dead, generate new random alien
                aliens[0][k] = rand() % 2;
                if (aliens[0][k]) remaining++; // if the alien is alive, add to remaining count
            }
        }

        // player shoots
        if (input == ' ') {
            for (k = 0; k < COLS; k++) {
                if (aliens[ROWS-1][k] == 2 && shots[k] == 0) { // if there's a player at the bottom and the column hasn't been shot before
                    aliens[ROWS-1][k] = 0;
                    score += 10;
                    remaining--;
                    shots[k] = 1;
                }
            }
        }

        // set player position as '2' in aliens[][] for printing later
        for (j = 0; j < COLS; j++) {
            if (aliens[ROWS-1][j] == 2) aliens[ROWS-1][j] = 0;
        }
        aliens[ROWS-1][COLS/2] = 2;

        // checks for endgame condition
        if (aliens[ROWS-1][0] == 1 || aliens[ROWS-1][COLS-1] == 1) {
            printf("\n YOU LOSE!!! \n");
            printf("FINAL SCORE:%d \n", score);
            return 0;
        }

    }
}