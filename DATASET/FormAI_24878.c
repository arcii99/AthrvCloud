//FormAI DATASET v1.0 Category: Sudoku solver ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int sudoku_solver(int puzzle[9][9]){
	int row_location, column_location, num;
	
    for(row_location = 0; row_location < 9; row_location++){
        for(column_location = 0; column_location < 9; column_location++){
            if(puzzle[row_location][column_location] == 0){
                for(num = 1; num <= 9; num++){
                    if(surrealist_rule(puzzle, row_location, column_location, num)){
                        puzzle[row_location][column_location] = num;

                        if(sudoku_solver(puzzle))
                            return 1;
                        else
                            puzzle[row_location][column_location] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int surrealist_rule(int puzzle[9][9], int row_location, int column_location, int num){

    int box_row_location = row_location - row_location % 3;
    int box_column_location = column_location - column_location % 3;

    for(int i = 0; i < 9; i++){
        if(puzzle[row_location][i] == num)
            return 0;
        if(puzzle[i][column_location] == num)
            return 0;
        if(puzzle[box_row_location + (i % 3)][box_column_location + (i / 3)] == num)
            return 0;
    }
    return 1;
}

int main(){
    printf("\n\n\tSURREALIST SUDOKU SOLVER\n\n");

    int puzzle[9][9] = {
                        {0, 3, 0, 0, 0, 0, 0, 9, 0},
                        {1, 0, 9, 0, 0, 0, 6, 0, 8},
                        {0, 8, 0, 2, 0, 9, 0, 4, 0},
                        {0, 0, 7, 0, 0, 5, 0, 0, 0},
                        {0, 0, 0, 0, 3, 0, 0, 0, 0},
                        {0, 0, 0, 4, 0, 0, 3, 0, 0},
                        {0, 0, 0, 9, 0, 7, 0, 0, 0},
                        {5, 0, 6, 0, 0, 0, 8, 0, 4},
                        {0, 2, 0, 0, 0, 0, 0, 7, 0}
                       };

    if(sudoku_solver(puzzle)){
        printf("\nSurreal Solution:\n");
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(j == 3 || j == 6)
                    printf("    ");
                printf("%d ", puzzle[i][j]);
            }
            if(i == 2 || i == 5){
                printf("\n\n");
            }
            printf("\n");
        }
    }
    else{
        printf("\nImpossible Puzzle\n");
    }
    return 0;
}