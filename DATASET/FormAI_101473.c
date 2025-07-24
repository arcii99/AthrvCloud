//FormAI DATASET v1.0 Category: Robot movement control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2

int main() {
	// Initialize robot's starting position
	int x = 0; // x-axis position
	int y = 0; // y-axis position
	int orientation = FORWARD; // robot's orientation
	printf("Robot starts at (%d, %d), facing FORWARD\n", x, y);

	// Move robot forward 5 steps
	for (int i = 1; i <= 5; i++) {
		if (orientation == FORWARD) {
			y++; // Move robot up along y-axis
		} else if (orientation == BACKWARD) {
			y--; // Move robot down along y-axis
		} else if (orientation == LEFT) {
			x--; // Move robot left along x-axis
		} else if (orientation == RIGHT) {
			x++; // Move robot right along x-axis
		}
		printf("Step %d: Robot moves forward to (%d, %d)\n", i, x, y);
	}

	// Turn robot left
	orientation = LEFT;
	printf("Robot turns LEFT and is now facing LEFT\n");

	// Move robot left 3 steps
	for (int i = 1; i <= 3; i++) {
		if (orientation == FORWARD) {
			y++; // Move robot up along y-axis
		} else if (orientation == BACKWARD) {
			y--; // Move robot down along y-axis
		} else if (orientation == LEFT) {
			x--; // Move robot left along x-axis
		} else if (orientation == RIGHT) {
			x++; // Move robot right along x-axis
		}
		printf("Step %d: Robot moves left to (%d, %d)\n", i, x, y);
	}

	// Turn robot right
	orientation = RIGHT;
	printf("Robot turns RIGHT and is now facing RIGHT\n");

	// Move robot right 2 steps
	for (int i = 1; i <= 2; i++) {
		if (orientation == FORWARD) {
			y++; // Move robot up along y-axis
		} else if (orientation == BACKWARD) {
			y--; // Move robot down along y-axis
		} else if (orientation == LEFT) {
			x--; // Move robot left along x-axis
		} else if (orientation == RIGHT) {
			x++; // Move robot right along x-axis
		}
		printf("Step %d: Robot moves right to (%d, %d)\n", i, x, y);
	}

	// Move robot backward 4 steps
	orientation = BACKWARD;
	printf("Robot turns BACKWARD and is now facing BACKWARD\n");
	for (int i = 1; i <= 4; i++) {
		if (orientation == FORWARD) {
			y++; // Move robot up along y-axis
		} else if (orientation == BACKWARD) {
			y--; // Move robot down along y-axis
		} else if (orientation == LEFT) {
			x--; // Move robot left along x-axis
		} else if (orientation == RIGHT) {
			x++; // Move robot right along x-axis
		}
		printf("Step %d: Robot moves backward to (%d, %d)\n", i, x, y);
	}

	printf("Robot reached its final destination of (%d, %d)\n", x, y);
	return 0;
}