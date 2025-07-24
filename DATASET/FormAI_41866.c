//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
	{1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
	{0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
	{0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
	{0, 0, 1, 0, 1, 1, 1, 1, 0, 0},
	{1, 0, 1, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
	{0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
	{0, 0, 1, 0, 0, 1, 1, 0, 0, 1}
};

bool is_valid(int row, int col) {
	if (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 1) {
		return true;
	}
	return false;
}

bool find_path(int x, int y, int sol[ROW][COL]) {
	if (x == ROW-1 && y == COL-1) {
		sol[x][y] = 1;
		return true;
	}

	if (is_valid(x, y)) {
		sol[x][y] = 1;

		if (find_path(x+1, y, sol)) {
			return true;
		}

		if (find_path(x, y+1, sol)) {
			return true;
		}

		sol[x][y] = 0; 
		return false;
	}

	return false;
}

int main() {
	int sol[ROW][COL] = {{0}};
	if (find_path(0, 0, sol)) {
		printf("Found the path:\n");
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				printf("%2d", sol[i][j]);
			}
			printf("\n");
		}
	} else {
		printf("No path found.\n");
	}

	return 0;
}