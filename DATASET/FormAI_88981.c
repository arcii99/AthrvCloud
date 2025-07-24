//FormAI DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to initialize the game board
void init_board(char board[4][4]) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            board[i][j] = '-';
        }
    }
}

//Function to display the game board to the user
void display_board(char board[4][4]) {
    printf("\n");
    printf("   1 2 3 4\n");
    printf("  ---------\n");
    for(int i=0;i<4;i++) {
        printf("%c |", 'A'+i);
        for(int j=0;j<4;j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  ---------\n");
}

//Function to randomly place the numbers on the board
void place_numbers(char board[4][4]) {
    int count=0;
    srand(time(NULL)); //To generate random numbers
    while(count<8) {
        int row = rand()%4;  //Generate a random row number between 0 and 3
        int col = rand()%4;  //Generate a random column number between 0 and 3
        if(board[row][col] == '-') {    //Check if the spot is empty
            board[row][col] = count+'0'; //Place the number on the board
            count++; 
        }
    }
}

//Function to get the user's input and flip the cards
void flip_cards(char board[4][4], char card1[2], char card2[2]) {
    int row1,col1,row2,col2;
    while(1) {
        printf("Enter the position of the first card: ");
        scanf(" %c%c", card1, card1+1);  //Get the user input
        row1 = card1[0] - 'A';  //Convert the row value to integer
        col1 = card1[1] - '1';  //Convert the column value to integer
        if(board[row1][col1] != '-') {  //Check if the spot is already flipped
            printf("That spot is already flipped. Please choose another spot.\n");
            continue;
        }
        break;
    }
    board[row1][col1] = board[row1][col1] + '0';   //Flip the card
    display_board(board);   //Display the updated board

    while(1) {
        printf("Enter the position of the second card: ");
        scanf(" %c%c", card2, card2+1);  //Get the user input
        row2 = card2[0] - 'A';  //Convert the row value to integer
        col2 = card2[1] - '1';  //Convert the column value to integer
        if(row1 == row2 && col1 == col2) {   //Check if the user entered the same position twice
            printf("Please enter a different position for the second card.\n");
            continue;
        }
        if(board[row2][col2] != '-') {  //Check if the spot is already flipped
            printf("That spot is already flipped. Please choose another spot.\n");
            continue;
        }
        break;
    }
    board[row2][col2] = board[row2][col2] + '0';  //Flip the card
    display_board(board);  //Display the updated board

    if(board[row1][col1] != board[row2][col2]) { //If the numbers do not match
        board[row1][col1] = '-';    //Flip the cards back
        board[row2][col2] = '-';
    }
}

//Function to check if the game is over
int check_game(char board[4][4]) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(board[i][j] == '-') {   //If there is any empty spot left
                return 0;
            }
        }
    }
    return 1;   //If all the spots are filled
}

int main() {
    char board[4][4];
    char card1[2], card2[2];
    int turns = 0;
    init_board(board);
    place_numbers(board);
    display_board(board);
    while(1) {
        flip_cards(board, card1, card2);
        turns++;
        if(check_game(board)) { //If the game is over
            printf("Congratulations! You have won the game in %d turns.", turns);
            break;
        }
    }
    return 0;
}