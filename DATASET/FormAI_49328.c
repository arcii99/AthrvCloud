//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10  // size of the game board

int game_board[SIZE][SIZE];
int score;

/* Function to initialize the game board */
void initialize_board() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            game_board[i][j] = 0;
        }
    }
}

/* Function to print the game board */
void print_board() {
    printf("\nScore: %d\n\n", score);
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", game_board[i][j]);
        }
        printf("\n");
    }
}

/* Function to check if the game board is full */
bool is_full() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(game_board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

/* Function to generate a new number in the game board */
void generate_number() {
    if(is_full()) {
        printf("\nGAME OVER!\n");
        exit(0);
    }
    int x, y;
    do {
        x = rand() % SIZE;
        y = rand() % SIZE;
    } while(game_board[x][y] != 0);
    game_board[x][y] = (rand() % 2 + 1) * 2;
}

/* Function to move the numbers left */
void move_left() {
    int temp;
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE-1; j++) {
            if(game_board[i][j] != 0) {
                for(int k=j+1; k<SIZE; k++) {
                    if(game_board[i][k] != 0) {
                        if(game_board[i][j] == game_board[i][k]) {
                            temp = game_board[i][j] + game_board[i][k];
                            game_board[i][j] = temp;
                            game_board[i][k] = 0;
                            score += temp;
                        }
                        break;
                    }
                }
            }
        }
        for(int j=0; j<SIZE-1; j++) {
            if(game_board[i][j] == 0) {
                for(int k=j+1; k<SIZE; k++) {
                    if(game_board[i][k] != 0) {
                        game_board[i][j] = game_board[i][k];
                        game_board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}

/* Function to move the numbers right */
void move_right() {
    int temp;
    for(int i=0; i<SIZE; i++) {
        for(int j=SIZE-1; j>0; j--) {
            if(game_board[i][j] != 0) {
                for(int k=j-1; k>=0; k--) {
                    if(game_board[i][k] != 0) {
                        if(game_board[i][j] == game_board[i][k]) {
                            temp = game_board[i][j] + game_board[i][k];
                            game_board[i][j] = temp;
                            game_board[i][k] = 0;
                            score += temp;
                        }
                        break;
                    }
                }
            }
        }
        for(int j=SIZE-1; j>0; j--) {
            if(game_board[i][j] == 0) {
                for(int k=j-1; k>=0; k--) {
                    if(game_board[i][k] != 0) {
                        game_board[i][j] = game_board[i][k];
                        game_board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}

/* Function to move the numbers up */
void move_up() {
    int temp;
    for(int j=0; j<SIZE; j++) {
        for(int i=0; i<SIZE-1; i++) {
            if(game_board[i][j] != 0) {
                for(int k=i+1; k<SIZE; k++) {
                    if(game_board[k][j] != 0) {
                        if(game_board[i][j] == game_board[k][j]) {
                            temp = game_board[i][j] + game_board[k][j];
                            game_board[i][j] = temp;
                            game_board[k][j] = 0;
                            score += temp;
                        }
                        break;
                    }
                }
            }
        }
        for(int i=0; i<SIZE-1; i++) {
            if(game_board[i][j] == 0) {
                for(int k=i+1; k<SIZE; k++) {
                    if(game_board[k][j] != 0) {
                        game_board[i][j] = game_board[k][j];
                        game_board[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}

/* Function to move the numbers down */
void move_down() {
    int temp;
    for(int j=0; j<SIZE; j++) {
        for(int i=SIZE-1; i>0; i--) {
            if(game_board[i][j] != 0) {
                for(int k=i-1; k>=0; k--) {
                    if(game_board[k][j] != 0) {
                        if(game_board[i][j] == game_board[k][j]) {
                            temp = game_board[i][j] + game_board[k][j];
                            game_board[i][j] = temp;
                            game_board[k][j] = 0;
                            score += temp;
                        }
                        break;
                    }
                }
            }
        }
        for(int i=SIZE-1; i>0; i--) {
            if(game_board[i][j] == 0) {
                for(int k=i-1; k>=0; k--) {
                    if(game_board[k][j] != 0) {
                        game_board[i][j] = game_board[k][j];
                        game_board[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}

/* Function to handle user input */
void handle_input(char input) {
    switch (input) {
        case 'a':
            move_left();
            break;
        case 'd':
            move_right();
            break;
        case 'w':
            move_up();
            break;
        case 's':
            move_down();
            break;
        default:
            printf("\nInvalid input!\n");
            break;
    }
}

/* Main function */
int main() {
    char input;
    printf("Welcome to Visionary 2048 game!\n\n");
    initialize_board();
    generate_number();
    generate_number();
    print_board();
    while(true) {
        printf("\nEnter your move (a=left, d=right, w=up, s=down): ");
        scanf(" %c", &input);
        handle_input(input);
        generate_number();
        print_board();
    }
    return 0;
}