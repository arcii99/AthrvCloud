//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

int main() {
    srand(time(0)); //initialize the random number generator
    
    int bingo[5][5] = {{0}}; // create an empty 5x5 array
    int num, count = 0, row, col;
    char choice;

    // populate array with random numbers between 1 to 25
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            do{
                num = rand() % 25 + 1;
            } while(numInArray(num, bingo) == 1); // function checks if num is unique in array
            bingo[i][j] = num;
        }
    }
    
    // display the bingo grid
    displayGrid(bingo);

    // game loop
    while(1){
        printf("Enter 'c' to continue, 'q' to quit: ");
        scanf(" %c", &choice);

        if(choice == 'q') break; // exit the game loop
        
        // select random number between 1 to 25
        do{
            num = rand() % 25 + 1;
        } while(numInArray(num, bingo) == 0); // function checks if num is present in array
        printf("\n\nThe number is: %d\n\n", num);
        
        // check if the number is present in the array and update it to zero
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(bingo[i][j] == num) {
                    bingo[i][j] = 0;
                    count++;
                }
            }
        }

        if(count == 25) { // check if all numbers have been struck
            printf("BINGO! You have won the game.\n");
            break; // exit the game loop
        }

        // display updated bingo grid
        displayGrid(bingo);
    }
    return 0;
}

// function to check if a number is already present in the array
int numInArray(int num, int arr[][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(arr[i][j] == num) return 1;
        }
    }
    return 0;
}

// function to display the bingo grid
void displayGrid(int arr[][5]){
    printf("---------------\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(arr[i][j] == 0) printf("|  X  ");
            else printf("| %2d  ", arr[i][j]);
        }
        printf("|\n---------------\n");
    }
}