//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: standalone
#include<stdio.h>

#define SIZE 3

void printCircuit(int circuit[][SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", circuit[i][j]);
        }
        printf("\n");
    }
}

int simulate(int circuit[][SIZE], int rows, int cols) {
    int posRow = 0, posCol = 0;
    int direction = 0; // 0 for east, 1 for south, 2 for west, 3 for north
    int numSteps = 0;
    
    while(1) {
        numSteps++;
        if(posRow < 0 || posCol < 0 || posRow >= rows || posCol >= cols) {
            // circuit is broken
            return -1;
        }
        
        if(circuit[posRow][posCol] == 1) {
            direction = (direction + 1) % 4; // turn right
        } else if (circuit[posRow][posCol] == 2) {
            direction = (direction - 1) % 4; // turn left
            if(direction < 0) {
                direction += 4;
            }
        } else if (circuit[posRow][posCol] == 3) {
            // circuit is complete
            return numSteps;
        }
        
        // move one step in the current direction
        switch(direction) {
            case 0:
                posCol++;
                break;
            case 1:
                posRow++;
                break;
            case 2:
                posCol--;
                break;
            case 3:
                posRow--;
                break;
        }
    }
}

int main() {
    int circuit[SIZE][SIZE] = { { 3, 0, 1 }, { 2, 1, 1 }, { 0, 1, 0 } };
    printf("Circuit:\n");
    printCircuit(circuit, SIZE, SIZE);
    int steps = simulate(circuit, SIZE, SIZE);
    if(steps == -1) {
        printf("Circuit is broken.\n");
    } else {
        printf("Circuit is complete in %d steps.\n", steps);
    }
    return 0;
}