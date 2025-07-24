//FormAI DATASET v1.0 Category: Memory Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define BOARD_SIZE 4

int board[BOARD_SIZE][BOARD_SIZE]; // Game board
int first_choice[2]; // Coordinates of the first choice
int second_choice[2]; // Coordinates of the second choice
int num_pairs_found = 0; // Number of matched pairs found

// Display the game board
void display_board() {
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Shuffle the game board
void shuffle_board() {
    srand(time(NULL));
    for(int i=0; i<BOARD_SIZE*BOARD_SIZE; i++) {
        int x1 = rand() % BOARD_SIZE;
        int y1 = rand() % BOARD_SIZE;
        int x2 = rand() % BOARD_SIZE;
        int y2 = rand() % BOARD_SIZE;
        int temp = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = temp;
    }
}

// Check if two pairs match
int check_match() {
    if(board[first_choice[0]][first_choice[1]] == board[second_choice[0]][second_choice[1]]) {
        return 1;
    }
    else {
        return 0;
    }
}

// Thread function to handle user input and check for matches
void* take_turn(void* arg) {
    int* turn_num = (int*) arg;
    int row;
    int col;
    printf("Turn %d:\nEnter the row coordinate of your first choice: ", *turn_num+1);
    scanf("%d", &row);
    printf("Enter the column coordinate of your first choice: ");
    scanf("%d", &col);
    first_choice[0] = row;
    first_choice[1] = col;
    printf("\n");
    display_board();
    printf("Turn %d:\nEnter the row coordinate of your second choice: ", *turn_num+1);
    scanf("%d", &row);
    printf("Enter the column coordinate of your second choice: ");
    scanf("%d", &col);
    second_choice[0] = row;
    second_choice[1] = col;
    printf("\n");
    display_board();
    if(check_match()) {
        printf("You found a match!\n");
        num_pairs_found++;
    }
    else {
        printf("Sorry, those cards do not match.\n");
    }
    return NULL;
}

int main() {
    // Initialize the game board
    int num_values = BOARD_SIZE*BOARD_SIZE/2;
    int values[num_values];
    for(int i=0; i<num_values; i++) {
        values[i] = i+1;
    }
    int count = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(count >= num_values) {
                count = 0;
            }
            board[i][j] = values[count];
            count++;
        }
    }
    shuffle_board();
    display_board();

    // Initialize the threads
    pthread_t threads[BOARD_SIZE*BOARD_SIZE/2];
    int turn_nums[BOARD_SIZE*BOARD_SIZE/2];
    for(int i=0; i<BOARD_SIZE*BOARD_SIZE/2; i++) {
        turn_nums[i] = i;
    }

    // Take turns until all pairs are found
    while(num_pairs_found < BOARD_SIZE*BOARD_SIZE/2) {
        for(int i=0; i<BOARD_SIZE*BOARD_SIZE/2; i++) {
            pthread_create(&threads[i], NULL, take_turn, (void*) &turn_nums[i]);
            pthread_join(threads[i], NULL);
        }
    }

    printf("\nCongratulations! You found all the pairs.\n");
    return 0;
}