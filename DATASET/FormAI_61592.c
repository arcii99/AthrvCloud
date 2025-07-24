//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// function to shuffle an array
void shuffle(int *array, size_t n)
{
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int temp = array[j];
          array[j] = array[i];
          array[i] = temp;
        }
    }
}

// a function to find the minimum number of moves required to solve the puzzle
int solve(int n, int m, int puzzle[n][m])
{
    int moves = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(puzzle[i][j] != i*m + j + 1) { // if the puzzle piece is not in the correct position
                int val = puzzle[i][j]; // store the value of the incorrect puzzle piece
                int row = (val-1) / m; // find the row in which the correct puzzle piece should be
                int col = (val-1) % m; // find the column in which the correct puzzle piece should be
                puzzle[row][col] = val; // swap the incorrect puzzle piece with the correct one
                puzzle[i][j] = i*m + j + 1;
                moves++;
            }
        }
    }
    
    return moves;
}

int main()
{
    // create a 4x4 puzzle
    int n = 4, m = 4;
    int puzzle[n][m];
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            puzzle[i][j] = i*m + j + 1;
        }
    }
    
    // shuffle the puzzle pieces
    srand(time(NULL));
    shuffle((int *)puzzle, n*m);
    
    // print the shuffled puzzle
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
    
    // solve the puzzle and print the number of moves required
    int moves = solve(n, m, puzzle);
    printf("Number of moves required to solve the puzzle: %d\n", moves);
    
    return 0;
}