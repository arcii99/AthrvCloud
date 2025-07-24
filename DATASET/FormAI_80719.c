//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX
#define ROW 10
#define COL 10

// Creating a structure for each node of the graph
struct Node
{
    int row, col; // position of the node in the graph
    int fScore, gScore, hScore; // scores used in A* algorithm
    struct Node* parent; // pointer to parent node
    int isObstacle; // boolean variable to indicate if node is an obstacle or not
};

// Creating the graph by using above Node structure
struct Node graph[ROW][COL];

// Function to initialize each node of the graph
void initialize_graph()
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            graph[i][j].row = i;
            graph[i][j].col = j;
            graph[i][j].fScore = INT_MAX;
            graph[i][j].gScore = INT_MAX;
            graph[i][j].hScore = INT_MAX;
            graph[i][j].parent = NULL;
            graph[i][j].isObstacle = 0; // initialize all nodes as non-obstacles
        }
    }
}

// Function to add obstacles to the graph
void add_obstacles()
{
    graph[2][3].isObstacle = 1;
    graph[3][3].isObstacle = 1;
    graph[4][3].isObstacle = 1;
    graph[5][3].isObstacle = 1;
    graph[6][3].isObstacle = 1;
    graph[7][3].isObstacle = 1;
    graph[8][3].isObstacle = 1;
}

// Function to calculate the Manhattan distance between two nodes
int manhattan_distance(struct Node a, struct Node b)
{
    int distance = abs(a.row - b.row) + abs(a.col - b.col);
    return distance;
}

// Function to find the node with the lowest fScore in the open set
struct Node* get_lowest_fScore_node(struct Node openSet[])
{
    struct Node* current = NULL;
    int lowest_fScore = INT_MAX;
    for(int i=0; i<ROW*COL; i++)
    {
        if(openSet[i].row != -1 && openSet[i].col != -1 && openSet[i].fScore < lowest_fScore)
        {
            current = &openSet[i];
            lowest_fScore = openSet[i].fScore;
        }
    }
    return current;
}

// Function to check if node is in the open set
int is_in_open_set(struct Node openSet[], struct Node* node)
{
    for(int i=0; i<ROW*COL; i++)
    {
        if(openSet[i].row == node->row && openSet[i].col == node->col)
        {
            return 1; // node is in open set
        }
    }
    return 0; // node is not in open set
}

// Function to check if node is in the closed set
int is_in_closed_set(struct Node closedSet[], struct Node* node)
{
    for(int i=0; i<ROW*COL; i++)
    {
        if(closedSet[i].row == node->row && closedSet[i].col == node->col)
        {
            return 1; // node is in closed set
        }
    }
    return 0; // node is not in closed set
}

// Function to find the optimal path using the A* algorithm
void A_star(struct Node start, struct Node goal)
{
    struct Node openSet[ROW*COL]; // set of nodes to be evaluated
    struct Node closedSet[ROW*COL]; // set of nodes already evaluated
    int openSetCount = 0;
    int closedSetCount = 0;
    openSet[openSetCount] = start;
    openSetCount++;
    start.gScore = 0;
    start.hScore = manhattan_distance(start, goal);
    start.fScore = start.gScore + start.hScore;
    while(openSetCount > 0)
    {
        struct Node* current = get_lowest_fScore_node(openSet);
        if(current->row == goal.row && current->col == goal.col)
        {
            // Found optimal path
            printf("Optimal Path:\n");
            struct Node* node = current;
            while(node != NULL)
            {
                printf("(%d,%d)\n", node->row, node->col);
                node = node->parent;
            }
            return;
        }
        openSetCount--;
        closedSet[closedSetCount] = *current;
        closedSetCount++;
        for(int i=-1; i<=1; i++)
        {
            for(int j=-1; j<=1; j++)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }
                int newRow = current->row + i;
                int newCol = current->col + j;
                if(newRow < 0 || newRow >= ROW || newCol < 0 || newCol >= COL)
                {
                    continue;
                }
                if(graph[newRow][newCol].isObstacle == 1)
                {
                    continue;
                }
                if(is_in_closed_set(closedSet, &graph[newRow][newCol]) == 1)
                {
                    continue;
                }
                int tentative_gScore = current->gScore + manhattan_distance(*current, graph[newRow][newCol]);
                if(is_in_open_set(openSet, &graph[newRow][newCol]) == 0)
                {
                    openSet[openSetCount] = graph[newRow][newCol];
                    openSetCount++;
                }
                else if(tentative_gScore >= graph[newRow][newCol].gScore)
                {
                    continue;
                }
                graph[newRow][newCol].parent = current;
                graph[newRow][newCol].gScore = tentative_gScore;
                graph[newRow][newCol].hScore = manhattan_distance(graph[newRow][newCol], goal);
                graph[newRow][newCol].fScore = graph[newRow][newCol].gScore + graph[newRow][newCol].hScore;
            }
        }
    }
    // Failed to find optimal path
    printf("Failed to find optimal path.\n");
}

int main()
{
    initialize_graph();
    add_obstacles();
    struct Node start = {0, 0};
    struct Node goal = {9, 9};
    A_star(start, goal);
    return 0;
}