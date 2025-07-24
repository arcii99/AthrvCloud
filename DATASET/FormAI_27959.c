//FormAI DATASET v1.0 Category: Memory Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROWS 4
#define COLS 4

char matrix[4][4] = {' ', ' ', ' ', ' ',
                     ' ', ' ', ' ', ' ',
                     ' ', ' ', ' ', ' ',
                     ' ', ' ', ' ', ' '};

void print_matrix() {
    printf("\nMEMORY GAME\n\n");
    printf("  1 2 3 4\n");
    for(int i = 0; i < ROWS; i++) {
        printf("%c ", 'A'+i);
        for(int j = 0; j < COLS; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void sleep_ms(int ms) {
    usleep(ms*1000);
}

void clear_console() {
    printf("\033[2J\033[1;1H");
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    srand(time(NULL)); //Initialize random seed
    
    //Set up game
    int num_pairs = (ROWS*COLS) / 2;
    char pairs[num_pairs];
    for(int i = 0; i < num_pairs; i++) {
        pairs[i] = 'A' + i;
    }

    //Scramble pairs
    for(int i = 0; i < num_pairs; i++) {
        int r = rand() % num_pairs;
        char temp = pairs[i];
        pairs[i] = pairs[r];
        pairs[r] = temp;
    }

    //Place pairs in matrix
    int pairs_placed = 0;
    while (pairs_placed < num_pairs) {
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                int r = rand() % 2;
                if (r == 0) {
                    matrix[i][j] = pairs[pairs_placed];
                    pairs_placed++;
                    if (pairs_placed == num_pairs) {
                        break;
                    }
                }
            }
            if (pairs_placed == num_pairs) {
                break;
            }
        }
    }

    //Main game loop
    int num_guesses = 0;
    while (num_guesses < (ROWS*COLS)) {
        //Clear console and print matrix
        clear_console();
        print_matrix();

        //Get guess 1
        printf("Enter row and column for guess 1: ");
        char row1, col1;
        scanf(" %c%c", &row1, &col1);
        clear_input_buffer();

        int i1 = row1 - 'A';
        int j1 = col1 - '1';
        char guess1 = matrix[i1][j1];
        if (guess1 == ' ') {
            continue;
        }

        matrix[i1][j1] = ' ';
        clear_console();
        print_matrix();

        //Get guess 2
        printf("Enter row and column for guess 2: ");
        char row2, col2;
        scanf(" %c%c", &row2, &col2);
        clear_input_buffer();

        int i2 = row2 - 'A';
        int j2 = col2 - '1';
        char guess2 = matrix[i2][j2];
        if (guess2 == ' ') {
            continue;
        }

        //Check for match
        if (guess1 == guess2) {
            matrix[i2][j2] = ' ';
            num_guesses += 2;
        } else {
            matrix[i1][j1] = guess1;
            matrix[i2][j2] = guess2;
        }

        //Delay before clearing console and printing matrix
        sleep_ms(1000);
    }

    //Game over
    printf("Game over! You win!\n");
    return 0;
}