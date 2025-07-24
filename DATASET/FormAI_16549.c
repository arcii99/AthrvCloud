//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to display the bingo card
void display_card(int card[ROWS][COLS]){
    printf("\nBINGO CARD\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given row is complete
int check_row(int card[ROWS][COLS], int row){
    for(int i=0; i<COLS; i++){
        if(card[row][i] != -1){
            return 0;
        }
    }
    return 1;
}

// Function to check if the given column is complete
int check_column(int card[ROWS][COLS], int column){
    for(int i=0; i<ROWS; i++){
        if(card[i][column] != -1){
            return 0;
        }
    }
    return 1;
}

// Function to check if the diagonal is complete
int check_diagonal(int card[ROWS][COLS]){
    int left_to_right = 1, right_to_left = 1;
    
    for(int i=0; i<ROWS; i++){
        if(card[i][i] != -1){
            left_to_right = 0;
        }
        if(card[i][COLS-i-1] != -1){
            right_to_left = 0;
        }
    }
    
    if(left_to_right || right_to_left){
        return 1;
    }else{
        return 0;
    }
}

// Function to mark the number on the card
void mark_number(int card[ROWS][COLS], int number){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(card[i][j] == number){
                card[i][j] = -1;
            }
        }
    }
}

int main(){
    int card[ROWS][COLS] = {{-1, -1, -1, -1, -1},
                            {-1, -1, -1, -1, -1},
                            {-1, -1, -1, -1, -1},
                            {-1, -1, -1, -1, -1},
                            {-1, -1, -1, -1, -1}};
    int numbers[75], index = 0;
    
    // Add numbers to the array
    for(int i=1; i<=75; i++){
        numbers[index++] = i;
    }
    
    // Shuffle the array
    srand(time(0));
    for(int i=0; i<75; i++){
        int random_index = rand() % 75;
        int temp = numbers[i];
        numbers[i] = numbers[random_index];
        numbers[random_index] = temp;
    }
    
    // Mark the center of the card
    card[ROWS/2][COLS/2] = -1;
    
    // Display the card
    display_card(card);
    
    // Play the game
    int number, row, column;
    while(1){
        printf("\n\nEnter the next number (1-75): ");
        scanf("%d", &number);
        
        // Mark the number on the card
        mark_number(card, number);
        
        // Check if any row or column is complete
        for(int i=0; i<ROWS; i++){
            if(check_row(card, i)){
                printf("\nHurray! You completed row %d", i+1);
                return 0;
            }
            if(check_column(card, i)){
                printf("\nHurray! You completed column %d", i+1);
                return 0;
            }
        }
        
        // Check if diagonal is complete
        if(check_diagonal(card)){
            printf("\nHurray! You completed a diagonal");
            return 0;
        }
        
        // Display the updated card
        display_card(card);
    }
    
    return 0;
}