//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROW_SIZE 5
#define COLUMN_SIZE 5
#define MAX_SIZE 25

int start_index = 0;
int goal_index = 0;

// A* algorithm implementation
bool a_star_search(int start, int goal, int graph[][COLUMN_SIZE], int *path, int *path_len)
{
    // initializing variables
    int frontier[MAX_SIZE] = {0};
    int cost_so_far[MAX_SIZE] = {0};
    int came_from[MAX_SIZE] = {0};
    int priority[MAX_SIZE] = {0};
    bool visited[MAX_SIZE] = {false};
    int current_index = 0;
    int next_index = 0;
    int max_queue_size = 0;

    // inserting start node to the frontier
    frontier[start] = 1;
    priority[start] = 0;
    visited[start] = true;

    // loop through the frontier until goal node is found or frontier is empty
    while (true)
    {
        // get the next node with the highest priority from the frontier
        int highest_priority = -1;
        for (int i = 0; i < MAX_SIZE; i++)
        {
            if (frontier[i] == 1 && priority[i] > highest_priority)
            {
                highest_priority = priority[i];
                current_index = i;
            }
        }

        // if the goal node is reached
        if (current_index == goal)
        {
            break;
        }

        // remove current node from the frontier
        frontier[current_index] = 0;

        // explore neighbors of the current node
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            if (graph[current_index][i] == 0)
            {
                continue;
            }
            int tentative_cost = cost_so_far[current_index] + graph[current_index][i];

            // if neighbor is not visited or the tentative cost is less than the cost_so_far of the neighbor
            if (!visited[i] || tentative_cost < cost_so_far[i])
            {
                // mark neighbor as visited
                visited[i] = true;
                // add neighbor to the frontier
                frontier[i] = 1;
                // update the cost_so_far of the neighbor
                cost_so_far[i] = tentative_cost;
                // calculate the priority of the neighbor
                priority[i] = cost_so_far[i] + sqrt(pow(i / COLUMN_SIZE - goal / COLUMN_SIZE, 2) + pow(i % COLUMN_SIZE - goal % COLUMN_SIZE, 2));
                // set the index of the current node as the came from of the neighbor
                came_from[i] = current_index;

                // keep track of the maximum size of the frontier
                int queue_size = 0;
                for (int i = 0; i < MAX_SIZE; i++)
                {
                    if (frontier[i] == 1)
                    {
                        queue_size++;
                    }
                }
                if (queue_size > max_queue_size)
                {
                    max_queue_size = queue_size;
                }
            }
        }
    }

    // generate the path from start to goal
    int index = goal;
    int len = 0;
    while (index != start)
    {
        path[len] = index;
        len++;
        index = came_from[index];
    }
    path[len] = start;
    *path_len = len + 1;

    printf("Max queue size: %d\n", max_queue_size);

    return true;
}

int main()
{
    int graph[ROW_SIZE][COLUMN_SIZE] =
    {
        {1, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 1, 1}
    };

    int path[MAX_SIZE] = {0};
    int path_len = 0;

    // set the start and goal indices
    start_index = 0;
    goal_index = 24;

    if (a_star_search(start_index, goal_index, graph, path, &path_len))
    {
        printf("Path: ");
        for (int i = path_len - 1; i >= 0; i--)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Path not found.\n");
    }

    return 0;
}