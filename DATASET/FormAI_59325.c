//FormAI DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 //Size of the board
#define MAX 16 //Max value of the cards
#define MIN 1  //Min value of the cards

void initialize_array(int arr[], int size); 
void shuffle_array(int arr[], int size); 
void print_board(int board[][SIZE]); 
int check_match(int board[][SIZE], int card1_row, int card1_col, int card2_row, int card2_col);

int main()
{
    srand(time(0));
    int board[SIZE][SIZE] = {{0}}; //2D array to store the cards
    int cards[MAX] = {0}; //1D array to store the values of the cards
    initialize_array(cards, MAX); //Initialize the array with values 1-16
    shuffle_array(cards, MAX); //Shuffle the values
    
    //Map the shuffled values to the board
    int i, j, k = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = cards[k];
            k++;
        }
    }
    
    int card1_row, card1_col, card2_row, card2_col; //Variables for card positions
    int score = 0; //Variable to keep track of the score
    
    do {
        print_board(board); //Print the current board
        printf("Enter the row and column for the first card: ");
        scanf("%d %d", &card1_row, &card1_col);
        printf("Enter the row and column for the second card: ");
        scanf("%d %d", &card2_row, &card2_col);
        
        if (check_match(board, card1_row, card1_col, card2_row, card2_col)) { //Check if the cards match
            board[card1_row][card1_col] = 0; //Remove the cards from the board
            board[card2_row][card2_col] = 0; 
            score++; //Increase the score
        } else {
            printf("Cards do not match!\n");
        }
    } while (score < MAX/2); //Continue until all matches are found
    
    printf("You won!\n");
    return 0;
}

//Function to initialize the array with values 1-16
void initialize_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = i+1;
    }
}

//Function to shuffle the array
void shuffle_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        int temp = arr[i];
        int random_index = rand() % size;
        arr[i] = arr[random_index];
        arr[random_index] = temp;
    }
}

//Function to print the board
void print_board(int board[][SIZE]) {
    int i, j;
    printf("\n  ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n  ");
    for (i = 0; i < SIZE; i++) {
        printf("- ");
    }
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d|", i);
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf("  ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

//Function to check if the two selected cards match
int check_match(int board[][SIZE], int card1_row, int card1_col, int card2_row, int card2_col) {
    if (board[card1_row][card1_col] == board[card2_row][card2_col]) {
        return 1;
    } else {
        return 0;
    }
}