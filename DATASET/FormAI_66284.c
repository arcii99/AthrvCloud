//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void display(char arr[ROWS][COLS], int size);

int main() {
    srand(time(NULL)); // seeding the random number generator
    
    char bingo[ROWS][COLS] = {{'B', 'I', 'N', 'G', 'O'},
                              {' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' '}};
    
    int numbers[75];
    for (int i = 0; i < 75; i++) {
        numbers[i] = i + 1;
    }
    
    int count = 0;
    
    while (count < 75) {
        printf("Enter any key to draw the next number.\n");
        getchar(); // waiting for user input to draw next number
        
        int index = rand() % (75 - count); // picking a random index from the remaining numbers
        int drawnNumber = numbers[index];
        numbers[index] = numbers[74 - count]; // swapping the drawn number with the last un-drawn number
        count++;
        
        printf("The drawn number is: %d\n", drawnNumber);
        
        // updating the bingo card
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingo[i][j] == (drawnNumber / 10 == 0 ? '0' : (drawnNumber / 10) + '0') && bingo[i][j + 1] == (drawnNumber % 10 + '0')) {
                    bingo[i][j] = 'X';
                }
            }
        }
        
        display(bingo, ROWS);
        
        // checking if game is over
        int flag = 0;
        for (int i = 0; i < ROWS && flag == 0; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingo[i][j] != 'X') {
                    flag = 1;
                    break;
                }
            }
        }
        
        if (flag == 0) {
            printf("Bingo! You win!\n");
            break;
        }
    }
    
    return 0;
}

void display(char arr[ROWS][COLS], int size) {
    printf("========================================\n");
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c\t", arr[i][j]); // printing each element of the bingo card
        }
        printf("\n");
    }
    
    printf("========================================\n");
}