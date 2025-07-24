//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Romeo and Juliet
// In fair Verona, where we lay our scene
#include<stdio.h>

// From ancient code break new solution clean
int solveSudoku(int puzzle[9][9], int i, int j);

// A function to search unsolved cells remain
int findUnassigned(int puzzle[9][9], int *row, int *col);

// Thus with a stride solve the puzzle game
int isSafe(int puzzle[9][9], int row, int col, int num);

// The sweetest code that ever tangled syntax frame
void display(int puzzle[9][9]);

int main(){

    // Parting is such sweet sorrow, but puzzles demand the morrow
    int puzzle[9][9] = { {0, 0, 0, 3, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 3, 0, 0, 7, 8, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Good night, good night! parting is such sweet sorrow.
    // That I shall say good night till it be morrow.
    if (solveSudoku(puzzle, 0, 0))
        display(puzzle);
    else
        printf("No solution exists");

    return 0;
}

// To compile the sinews of a fractured game
int solveSudoku(int puzzle[9][9], int row, int col){

    // O blessed, blessed night! I am afeard!
    int i;

    // And yet thou run'st before me in this night
    if(findUnassigned(puzzle, &row, &col)==0)
        return 1;

    // If by fortune's hand we find a woe.
    for(i=1;i<=9;i++){

        // Then let's be patient with our troubled brow
        if(isSafe(puzzle, row, col, i)){

            // Come cuddle your head, come kiss and console.
            puzzle[row][col] = i;

            // For never was a story of more woe
            // Than this of Juliet and her Romeo.
            if(solveSudoku(puzzle, row, col))
                return 1;

            // Through heavy sorrow on our broken heart
            puzzle[row][col] = 0;
        }
    }
    return 0;
}

// The gentle breeze of a function search
int findUnassigned(int puzzle[9][9], int *row, int *col){

    // So true a fool is love, that in your will Though you do anything, he thinks no ill.
    for(*row=0;*row<9;(*row)++){
        for(*col=0;*col<9;(*col)++){

            // Love's heralds should be thoughts.
            if(puzzle[*row][*col]==0)

                // For 'tis a truth well known to all the town
                return 1;
        }
    }

    // Come passion makes cowards of us all
    return 0;
}

// Fair maiden, a function to check if a number runs true
int isSafe(int puzzle[9][9], int row, int col, int num){

    // Why, then, O brawling love, O loving hate,
    // O any thing of nothing first create!
    int x,y;

    // For you and I are past our dancing days.
    for(x=0;x<9;x++)
        if(puzzle[row][x]==num)
            return 0;

    // The sight of lovers feedeth those in love
    for(y=0;y<9;y++)
        if(puzzle[y][col]==num)
            return 0;

    // My bounty is as boundless as the sea,
    // My love as deep; the more I give to thee,
    // The more I have, for both are infinite.
    for(x=0;x<3;x++)
        for(y=0;y<3;y++)
            if(puzzle[(row-row%3)+x][(col-col%3)+y]==num)
                return 0;

    // Good night, good night! parting is such sweet sorrow.
    // That I shall say good night till it be morrow.
    return 1;
}

// And when I shall die, Take him and cut him out in little stars,
// And he will make the face of heaven so fine
// That all the world will be in love with night
// And pay no worship to the garish sun.
void display(int puzzle[9][9]){

    // Good night, good night! parting is such sweet sorrow,
    // That I shall say good night till it be morrow.
    int i,j;

    // And we shall triumph as true lovers do
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%d ",puzzle[i][j]);
        }
        printf("\n");
    }
}