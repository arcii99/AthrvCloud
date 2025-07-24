//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Recursive GPS Navigation Simulation\n\n");

    int route[10] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int start = 4, end = 13;

    recursiveNavigate(route, start, end);

    return 0;
}

void recursiveNavigate(int route[], int start, int end)
{
    if (start == end)
    {
        printf("You have reached your destination!\n");
        return;
    }
    else
    {
        printf("You are currently at point %d.\n", start);
        int nextLocation;

        // Choose the next location randomly
        nextLocation = rand() % 10;

        if (route[nextLocation] == start)
        {
            // Do not backtrack
            nextLocation = (nextLocation + 1) % 10;
        }

        printf("Proceeding to point %d.\n", route[nextLocation]);

        // Recursive call
        recursiveNavigate(route, route[nextLocation], end);
    }
}