//FormAI DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>

#define ROWS 5
#define COLS 5

int main() {
    // Declare array
    int arr[ROWS][COLS];

    // Initialize array with puzzle values
    arr[0][0] = 5;
    arr[0][1] = 9;
    arr[0][2] = 4;
    arr[0][3] = 7;
    arr[0][4] = 1;
    arr[1][0] = 3;
    arr[1][1] = 6;
    arr[1][2] = 8;
    arr[1][3] = 2;
    arr[1][4] = 5;
    arr[2][0] = 1;
    arr[2][1] = 7;
    arr[2][2] = 2;
    arr[2][3] = 4;
    arr[2][4] = 9;
    arr[3][0] = 8;
    arr[3][1] = 2;
    arr[3][2] = 6;
    arr[3][3] = 9;
    arr[3][4] = 3;
    arr[4][0] = 4;
    arr[4][1] = 5;
    arr[4][2] = 3;
    arr[4][3] = 1;
    arr[4][4] = 6;

    // Print puzzle
    printf("Puzzle:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Initialize struct to hold row and col of max value
    struct {
        int row;
        int col;
    } max = {0,0};

    // Find max value and its position
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(arr[i][j] > arr[max.row][max.col]) {
                max.row = i;
                max.col = j;
            }
        }
    }

    // Print max value and its position
    printf("Max value: %d\n", arr[max.row][max.col]);
    printf("Position: row %d, col %d\n\n", max.row+1, max.col+1);

    // Initialize struct to hold row and col of min value
    struct {
        int row;
        int col;
    } min = {0,0};

    // Find min value and its position
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(arr[i][j] < arr[min.row][min.col]) {
                min.row = i;
                min.col = j;
            }
        }
    }

    // Print min value and its position
    printf("Min value: %d\n", arr[min.row][min.col]);
    printf("Position: row %d, col %d\n", min.row+1, min.col+1);

    return 0;
}