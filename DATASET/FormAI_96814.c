//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function prototypes
void clear_screen();
void print_gameboard(int gameboard[][8], int score);
void move_up(int gameboard[][8], int *score);
void move_down(int gameboard[][8], int *score);
void move_left(int gameboard[][8], int *score);
void move_right(int gameboard[][8], int *score);
int generate_new_number();
int check_gameover(int gameboard[][8]);

//Main function
int main() {
    int gameboard[8][8] = {0};  //Initialize gameboard with all zeros
    int score = 0;  //Initialize score to 0
    int gameover = 0;  //Initialize gameover flag to 0
    int direction;  //Variable for storing the user's chosen direction

    //Seed random number generator with current time
    srand(time(NULL));

    //Generate two initial random numbers
    gameboard[2][2] = generate_new_number();
    gameboard[5][5] = generate_new_number();

    //Game loop
    while (!gameover) {
        clear_screen();
        print_gameboard(gameboard, score);
        printf("Enter direction (1=up, 2=down, 3=left, 4=right): ");
        scanf("%d", &direction);

        //Call appropriate move function based on user's chosen direction
        switch(direction) {
            case 1:
                move_up(gameboard, &score);
                break;
            case 2:
                move_down(gameboard, &score);
                break;
            case 3:
                move_left(gameboard, &score);
                break;
            case 4:
                move_right(gameboard, &score);
                break;
        }

        //Check for gameover
        gameover = check_gameover(gameboard);
    }

    //Game over
    clear_screen();
    print_gameboard(gameboard, score);
    printf("GAME OVER\n");

    return 0;
}

//Function to clear the screen
void clear_screen() {
    system("clear");
}

//Function to print the gameboard and score
void print_gameboard(int gameboard[][8], int score) {
    printf("Score: %d\n\n", score);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", gameboard[i][j]);
        }
        printf("\n");
    }
}

//Function to move tiles up
void move_up(int gameboard[][8], int *score) {
    int moved = 0;

    for (int j = 0; j < 8; j++) {
        for (int i = 1; i < 8; i++) {
            if (gameboard[i][j] != 0) {
                int k = i;
                while (k > 0 && gameboard[k-1][j] == 0) {
                    gameboard[k-1][j] = gameboard[k][j];
                    gameboard[k][j] = 0;
                    k--;
                    moved = 1;
                }
                if (k > 0 && gameboard[k-1][j] == gameboard[k][j]) {
                    gameboard[k-1][j] = gameboard[k-1][j] * 2;
                    gameboard[k][j] = 0;
                    *score += gameboard[k-1][j];
                    moved = 1;
                }
            }
        }
    }
    if (moved) {
        gameboard[7][rand() % 8] = generate_new_number();
    }
}

//Function to move tiles down
void move_down(int gameboard[][8], int *score) {
    int moved = 0;

    for (int j = 0; j < 8; j++) {
        for (int i = 6; i >= 0; i--) {
            if (gameboard[i][j] != 0) {
                int k = i;
                while (k < 7 && gameboard[k+1][j] == 0) {
                    gameboard[k+1][j] = gameboard[k][j];
                    gameboard[k][j] = 0;
                    k++;
                    moved = 1;
                }
                if (k < 7 && gameboard[k+1][j] == gameboard[k][j]) {
                    gameboard[k+1][j] = gameboard[k+1][j] * 2;
                    gameboard[k][j] = 0;
                    *score += gameboard[k+1][j];
                    moved = 1;
                }
            }
        }
    }
    if (moved) {
        gameboard[0][rand() % 8] = generate_new_number();
    }
}

//Function to move tiles left
void move_left(int gameboard[][8], int *score) {
    int moved = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            if (gameboard[i][j] != 0) {
                int k = j;
                while (k > 0 && gameboard[i][k-1] == 0) {
                    gameboard[i][k-1] = gameboard[i][k];
                    gameboard[i][k] = 0;
                    k--;
                    moved = 1;
                }
                if (k > 0 && gameboard[i][k-1] == gameboard[i][k]) {
                    gameboard[i][k-1] = gameboard[i][k-1] * 2;
                    gameboard[i][k] = 0;
                    *score += gameboard[i][k-1];
                    moved = 1;
                }
            }
        }
    }
    if (moved) {
        gameboard[rand() % 8][7] = generate_new_number();
    }
}

//Function to move tiles right
void move_right(int gameboard[][8], int *score) {
    int moved = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 6; j >= 0; j--) {
            if (gameboard[i][j] != 0) {
                int k = j;
                while (k < 7 && gameboard[i][k+1] == 0) {
                    gameboard[i][k+1] = gameboard[i][k];
                    gameboard[i][k] = 0;
                    k++;
                    moved = 1;
                }
                if (k < 7 && gameboard[i][k+1] == gameboard[i][k]) {
                    gameboard[i][k+1] = gameboard[i][k+1] * 2;
                    gameboard[i][k] = 0;
                    *score += gameboard[i][k+1];
                    moved = 1;
                }
            }
        }
    }
    if (moved) {
        gameboard[rand() % 8][0] = generate_new_number();
    }
}

//Function to generate a new number (either 2 or 4)
int generate_new_number() {
    return (rand() % 2 + 1) * 2;
}

//Function to check if the game is over
int check_gameover(int gameboard[][8]) {
    //Check if any empty spaces remain
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (gameboard[i][j] == 0) {
                return 0;  //Game is not over
            }
        }
    }

    //Check if any adjacent tiles have the same value
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i < 7 && gameboard[i][j] == gameboard[i+1][j]) {
                return 0;  //Game is not over
            }
            if (j < 7 && gameboard[i][j] == gameboard[i][j+1]) {
                return 0;  //Game is not over
            }
        }
    }

    return 1;  //Game is over
}