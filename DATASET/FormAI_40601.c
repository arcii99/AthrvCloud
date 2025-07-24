//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define MAX 100

int matrix[SIZE][SIZE] = {0};
int visited[SIZE][SIZE] = {0};
int queue[MAX][2];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

void enqueue(int row, int col) {
    if(rear == MAX - 1) return;
    if(front == -1) front = 0;
    rear++;
    queue[rear][0] = row;
    queue[rear][1] = col;
}

void dequeue(int *row, int *col) {
    *row = queue[front][0];
    *col = queue[front][1];
    if(front == rear) front = rear = -1;
    else front++;
}

void percolate() {
    int row = 0, col = 0;
    visited[row][col] = 1;
    enqueue(row, col);

    while(!isEmpty()) {
        dequeue(&row, &col);
        if(row == SIZE - 1) {
            printf("Percolation Occurred\n");
            exit(0);
        }
        if(row < SIZE-1 && matrix[row+1][col] && !visited[row+1][col]) {
            visited[row+1][col] = 1;
            enqueue(row+1, col);
        }
        if(row > 0 && matrix[row-1][col] && !visited[row-1][col]) {
            visited[row-1][col] = 1;
            enqueue(row-1, col);
        }
        if(col < SIZE-1 && matrix[row][col+1] && !visited[row][col+1]) {
            visited[row][col+1] = 1;
            enqueue(row, col+1);
        }
        if(col > 0 && matrix[row][col-1] && !visited[row][col-1]) {
            visited[row][col-1] = 1;
            enqueue(row, col-1);
        }
    }
}

int main() {
    srand(time(NULL));

    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(rand() % 2) matrix[i][j] = 1;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    percolate();

    printf("Percolation Did Not Occur\n");
    return 0;
}