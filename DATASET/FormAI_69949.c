//FormAI DATASET v1.0 Category: Memory Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to shuffle an array
void shuffle(int array[], int size){
    int i, temp, randIndex;
    srand(time(NULL));
    for(i=0; i<size; i++){
        randIndex = rand()%size;
        temp = array[i];
        array[i] = array[randIndex];
        array[randIndex] = temp;
    }
}

int main() {
    int size, i, j, row, col, choice1, choice2, count=0;
    printf("Enter the size of the grid (even number between 2 and 10): ");
    scanf("%d", &size);
    int grid[size][size];
    int match[size*size/2];
    //Creating an array with matching pairs and shuffling them
    for(i=0; i<size*size/2; i++){
        match[i] = i+1;
    }
    shuffle(match, size*size/2);
    //Populating the grid with the matching pairs
    for(i=0; i<size*size/2; i++){
        for(j=0; j<2; j++){
            do{
                row = rand()%size;
                col = rand()%size;
            }while(grid[row][col] != 0);
            grid[row][col] = match[i];
        }
    }
    //Printing the grid
    printf("\n  ");
    for(i=0; i<size; i++){
        printf("%d ", i+1);
    }
    printf("\n");
    for(i=0; i<size; i++){
        printf("%d ", i+1);
        for(j=0; j<size; j++){
            printf("* ");
        }
        printf("\n");
    }
    //Playing the game
    do{
        printf("\nEnter the row number of your first choice: ");
        scanf("%d", &row);
        printf("Enter the column number of your first choice: ");
        scanf("%d", &col);
        printf("Your first choice is %d.\n", grid[row-1][col-1]);
        choice1 = grid[row-1][col-1];
        printf("Enter the row number of your second choice: ");
        scanf("%d", &row);
        printf("Enter the column number of your second choice: ");
        scanf("%d", &col);
        printf("Your second choice is %d.\n", grid[row-1][col-1]);
        choice2 = grid[row-1][col-1];
        if(choice1 == choice2){
            printf("Match Found!\n");
            count++;
            //Revealing the matching cards
            for(i=0; i<size; i++){
                for(j=0; j<size; j++){
                    if(grid[i][j] == choice1){
                        printf("%d ", choice1);
                        grid[i][j] = 0;
                    }
                    else if(grid[i][j] == choice2){
                        printf("%d ", choice2);
                        grid[i][j] = 0;
                    }
                    else{
                        printf("* ");
                    }
                }
                printf("\n");
            }
        }
        else{
            printf("No Match!\n");
            //Covering the non-matching cards
            printf("\n  ");
            for(i=0; i<size; i++){
                printf("%d ", i+1);
            }
            printf("\n");
            for(i=0; i<size; i++){
                printf("%d ", i+1);
                for(j=0; j<size; j++){
                    if(grid[i][j] == 0){
                        printf("  ");
                    }
                    else{
                        printf("* ");
                    }
                }
                printf("\n");
            }
        }
    }while(count<size*size/2);

    printf("\nCongratulations! You have won the game!\n");
    return 0;
}