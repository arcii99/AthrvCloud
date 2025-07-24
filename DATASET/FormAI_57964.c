//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int bingo[ROWS][COLS] = {{0}};
int called[ROWS*COLS] = {0};
int counter = 0;

void generate_board() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((i == 2) && (j == 2)) {
                bingo[i][j] = 0;
            } else {
                bingo[i][j] = (rand() % 15) + (j * 15) + 1;
            }
        }
    }
}

void print_board() {
    printf("\n");
    printf(" B   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        printf("--------------------\n");
        for (int j = 0; j < COLS; j++) {
            if (bingo[i][j] == 0) {
                printf("| F ");
            } else if (bingo[i][j] < 10) {
                printf("| %d ", bingo[i][j]);
            } else {
                printf("| %d", bingo[i][j]);
            }   
        }
        printf("|\n");
    }
    printf("--------------------\n");
}

void call_number() {
    int number;
    do {
        number = (rand() % 75) + 1;
    } while (called[number] == 1);
    called[number] = 1;
    counter++;

    printf("\n");
    printf("Called number: %d\n", number);
    for(int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bingo[i][j] == number) {
                bingo[i][j] = 0;
                return;
            }
        }
    }
}

int check_bingo() {
    int rows_bingo = 0;
    int cols_bingo = 0;
    int diag_bingo_1 = 0;
    int diag_bingo_2 = 0;

    // Check rows
    for(int i = 0; i < ROWS; i++) {
        int sum = 0;
        for(int j = 0; j < COLS; j++) {
            sum += bingo[i][j];
        }
        if (sum == 0) {
            rows_bingo++;
        }
    }

    // Check columns
    for (int i = 0; i < COLS; i++) {
        int sum = 0;
        for (int j = 0; j < ROWS; j++) {
            sum += bingo[j][i];
        }
        if (sum == 0) {
            cols_bingo++;
        }
    }
    
    // Check diagonal from top left to bottom right
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        sum += bingo[i][i];
    }
    if (sum == 0) {
        diag_bingo_1 = 1;
    }

    // Check diagonal from bottom left to top right
    sum = 0;
    for (int i = 0; i < ROWS; i++) {
        sum += bingo[ROWS-1-i][i];
    }
    if (sum == 0) {
        diag_bingo_2 = 1;
    }

    if (rows_bingo + cols_bingo + diag_bingo_1 + diag_bingo_2 > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    printf("*** Welcome to Bingo! ***\n\n");
    printf("Generating board...\n");
    generate_board();
    print_board();

    while (1) {
        printf("\n");
        printf("Press enter to call a number: ");
        getchar();
        call_number();
        print_board();

        if (check_bingo()) {
            printf("\n");
            printf("*** BINGO! ***\n");
            printf("You got it in %d calls!\n", counter);
            break;
        }
    }

    return 0;
}