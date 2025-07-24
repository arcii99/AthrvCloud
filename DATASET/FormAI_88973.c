//FormAI DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Starting Robot Movement Control Program...\n\n");

    // Set random seed
    srand(time(NULL));

    int robotX = 0, robotY = 0; // Initialize robot coordinates
    int targetX = rand() % 10 + 1, targetY = rand() % 10 + 1; // Initialize target coordinates
    int numMoves = 0; // Initialize number of moves

    printf("Target coordinates: (%d, %d)\n", targetX, targetY);

    while (robotX != targetX || robotY != targetY) // Move until robot reaches target
    {
        int dir = rand() % 4 + 1; // Generate random direction (1-North, 2-South, 3-East, 4-West)

        switch (dir)
        {
            case 1: // Move North
                if (robotY < 10) // Check if robot is not at the edge of the grid
                {
                    robotY++;
                    printf("Robot moved North to (%d, %d)\n", robotX, robotY);
                }
                else // Robot is at the edge of the grid
                {
                    printf("Robot can't move North anymore\n");
                }
                break;

            case 2: // Move South
                if (robotY > 1)  // Check if robot is not at the edge of the grid
                {
                    robotY--;
                    printf("Robot moved South to (%d, %d)\n", robotX, robotY);
                }
                else // Robot is at the edge of the grid
                {
                    printf("Robot can't move South anymore\n");
                }
                break;

            case 3: // Move East
                if (robotX < 10) // Check if robot is not at the edge of the grid
                {
                    robotX++;
                    printf("Robot moved East to (%d, %d)\n", robotX, robotY);
                }
                else // Robot is at the edge of the grid
                {
                    printf("Robot can't move East anymore\n");
                }
                break;

            case 4: // Move West
                if (robotX > 1) // Check if robot is not at the edge of the grid
                {
                    robotX--;
                    printf("Robot moved West to (%d, %d)\n", robotX, robotY);
                }
                else // Robot is at the edge of the grid
                {
                    printf("Robot can't move West anymore\n");
                }
                break;
        }

        numMoves++; // Increase number of moves
    }

    printf("Robot reached the target in %d moves!\n", numMoves);

    return 0;
}