//FormAI DATASET v1.0 Category: Memory Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16

void print_board(char board[][4]) {
    printf("\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c\t", board[i][j]);
        }
        printf("\n");
    }
}
int main() {
    char values[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char board[4][4];
    int flipped[2][2] = {{-1, -1}, {-1, -1}}; // x, y coordinates of the last 2 flipped cards
    char input[5]; // store the 2 user inputs as a string
    srand(time(NULL)); // randomize seed for creating pairs of values
    int count = 0; // number of pairs found
    // generate the pairs and initialize the board
    for (int i = 0; i < 8; i++) {
        int first_x, first_y, sec_x, sec_y;
        do {
            first_x = rand() % 4;
            first_y = rand() % 4;
        } while (board[first_x][first_y] != '\0');
        do {
            sec_x = rand() % 4;
            sec_y = rand() % 4;
        } while (board[sec_x][sec_y] != '\0' || (first_x == sec_x && first_y == sec_y));
        board[first_x][first_y] = values[i];
        board[sec_x][sec_y] = values[i];
    }
    // game loop
    while (count < 8) {
        print_board(board);
        printf("Enter coordinates (x,y) of first card: ");
        fgets(input, 5, stdin);
        int first_x = (int)(input[0] - '0') - 1;
        int first_y = (int)(input[2] - '0') - 1;
        // check if user input is valid
        while (first_x < 0 || first_x > 3 || first_y < 0 || first_y > 3 || board[first_x][first_y] == '\0'
              || (first_x == flipped[0][0] && first_y == flipped[0][1]) 
              || (first_x == flipped[1][0] && first_y == flipped[1][1])) {
            printf("Invalid input. Enter coordinates (x,y) of first card: ");
            fgets(input, 5, stdin);
            first_x = (int)(input[0] - '0') - 1;
            first_y = (int)(input[2] - '0') - 1;
        }
        printf("Enter coordinates (x,y) of second card: ");
        fgets(input, 5, stdin);
        int sec_x = (int)(input[0] - '0') - 1;
        int sec_y = (int)(input[2] - '0') - 1;
        // check if user input is valid
        while (sec_x < 0 || sec_x > 3 || sec_y < 0 || sec_y > 3 || board[sec_x][sec_y] == '\0' 
              || (sec_x == first_x && sec_y == first_y) 
              || (sec_x == flipped[0][0] && sec_y == flipped[0][1]) 
              || (sec_x == flipped[1][0] && sec_y == flipped[1][1])) {
            printf("Invalid input. Enter coordinates (x,y) of second card: ");
            fgets(input, 5, stdin);
            sec_x = (int)(input[0] - '0') - 1;
            sec_y = (int)(input[2] - '0') - 1;
        }
        printf("Flipped: %c and %c\n", board[first_x][first_y], board[sec_x][sec_y]);
        // check if the flipped cards are a match
        if (board[first_x][first_y] == board[sec_x][sec_y]) {
            board[first_x][first_y] = '\0';
            board[sec_x][sec_y] = '\0';
            count++;
            printf("Match found! You have found %d out of 8 pairs.\n", count);
        } else {
            // if not a match, flip the cards back over
            board[first_x][first_y] = '*';
            board[sec_x][sec_y] = '*';
            flipped[0][0] = first_x;
            flipped[0][1] = first_y;
            flipped[1][0] = sec_x;
            flipped[1][1] = sec_y;
        }
    }
    printf("You won! Congrats!\n");
    return 0;
}