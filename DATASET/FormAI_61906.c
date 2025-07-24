//FormAI DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void readFile(char *filename, int row, int col, float arr[MAX_ROWS][MAX_COLS]) {
    FILE *fp;
    fp = fopen(filename, "r");

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            fscanf(fp, "%f", &arr[i][j]);
        }
    }
    fclose(fp);
}

int main() {
    float data[MAX_ROWS][MAX_COLS];
    readFile("data.txt", MAX_ROWS, MAX_COLS, data);

    // Data analysis code here

    return 0;
}