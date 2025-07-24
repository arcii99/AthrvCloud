//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 20
#define MAX_COLUMNS 20

typedef struct {
    int row;
    int column;
} Cell;

Cell queue[MAX_ROWS * MAX_COLUMNS];
int front = 0;
int rear = -1;
int queueLength = 0;

bool isOpen[MAX_ROWS][MAX_COLUMNS]; // true if site is open, false if site is blocked
bool isFull[MAX_ROWS][MAX_COLUMNS]; // true if site is connected to the top, false otherwise
bool percolates = false; // true if the system percolates, false otherwise

void enqueue(Cell cell) {
    rear++;
    queue[rear] = cell;
    queueLength++;
}

Cell dequeue() {
    Cell cell = queue[front];
    front++;
    queueLength--;
    return cell;
}

bool isEmpty() {
    return queueLength == 0;
}

void percolate(int grid[MAX_ROWS][MAX_COLUMNS], int row, int column) {
    isOpen[row][column] = true;
    // check neighboring cells and enqueue those that are open
    if (row > 0 && isOpen[row - 1][column]) enqueue((Cell){row - 1, column}); // check top neighbor
    if (row < MAX_ROWS - 1 && isOpen[row + 1][column]) enqueue((Cell){row + 1, column}); // check bottom neighbor
    if (column > 0 && isOpen[row][column - 1]) enqueue((Cell){row, column - 1}); // check left neighbor
    if (column < MAX_COLUMNS - 1 && isOpen[row][column + 1]) enqueue((Cell){row, column + 1}); // check right neighbor
    // check if the system percolates
    for (int i = 0; i < MAX_COLUMNS; i++) {
        if (isFull[MAX_ROWS - 1][i]) {
            percolates = true;
            break;
        }
    }
}

int main() {
    int grid[MAX_ROWS][MAX_COLUMNS];
    // initialize grid with random values
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            grid[i][j] = rand() % 2; // randomly set cell to open or blocked
            isOpen[i][j] = false;
            isFull[i][j] = false;
        }
    }
    // initialize top row to full
    for (int i = 0; i < MAX_COLUMNS; i++) {
        isFull[0][i] = true;
    }
    // process cells starting from the top row and checking each neighboring cell
    for (int j = 0; j < MAX_COLUMNS; j++) {
        if (isOpen[0][j]) {
            enqueue((Cell){0, j});
        }
    }
    while (!isEmpty()) {
        Cell cell = dequeue();
        if (!isFull[cell.row][cell.column]) {
            isFull[cell.row][cell.column] = true;
            percolate(grid, cell.row, cell.column);
        }
    }
    // output results
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            if (isFull[i][j]) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    if (percolates) {
        printf("The system percolates.\n");
    } else {
        printf("The system does not percolate.\n");
    }
    return 0;
}