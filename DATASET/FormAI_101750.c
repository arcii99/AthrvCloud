//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 5
#define COL 5

// define a structure for the node in the path
typedef struct node {
    int row, col;
    int distance;
    int visited;
    struct node* prev_node;
} Node;

Node grid[ROW][COL]; // 2D array to hold the grid

// function to initialize the grid
void init_grid()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].distance = INT_MAX; // initialize distance to infinity
            grid[i][j].visited = 0; // set visited to 0
            grid[i][j].prev_node = NULL; // set prev_node to NULL
        }
    }
}

// function to print the grid
void print_grid()
{
    printf("\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%d ", grid[i][j].distance);
        }
        printf("\n");
    }
    printf("\n");
}

// function to get the node with minimum distance
Node* get_minimum_distance_node()
{
    int min_distance = INT_MAX;
    Node* min_node = NULL;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (grid[i][j].visited == 0 && grid[i][j].distance < min_distance)
            {
                min_distance = grid[i][j].distance;
                min_node = &grid[i][j];
            }
        }
    }
    return min_node;
}

// function to check if a node is valid or not
int is_valid_node(int row, int col)
{
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

// function to update the distance of a node
void update_distance(Node* curr, Node* neighbor)
{
    int distance = curr->distance + 1; // set distance to curr's distance + 1
    if (distance < neighbor->distance)
    {
        neighbor->distance = distance;
        neighbor->prev_node = curr;
    }
}

// function to find the shortest path using Dijkstra's algorithm
void dijkstra(int start_row, int start_col, int end_row, int end_col)
{
    // initialize the start node
    grid[start_row][start_col].distance = 0;

    // loop through all nodes
    for (int i = 0; i < ROW * COL; i++)
    {
        Node* curr = get_minimum_distance_node();
        if (curr == NULL)
        {
            break;
        }
        curr->visited = 1;
        if (curr->row == end_row && curr->col == end_col)
        {
            break;
        }

        // loop through all neighbors
        for (int dr = -1; dr <= 1; dr++)
        {
            for (int dc = -1; dc <= 1; dc++)
            {
                if (dr == 0 && dc == 0)
                {
                    continue;
                }

                int neighbor_row = curr->row + dr;
                int neighbor_col = curr->col + dc;

                if (!is_valid_node(neighbor_row, neighbor_col))
                {
                    continue;
                }

                Node* neighbor = &grid[neighbor_row][neighbor_col];
                if (neighbor->visited == 1)
                {
                    continue;
                }

                update_distance(curr, neighbor);
            }
        }
    }
}

int main()
{
    init_grid(); // initialize the grid

    int start_row, start_col, end_row, end_col;
    printf("Enter the start row and column: ");
    scanf("%d %d", &start_row, &start_col);
    printf("Enter the end row and column: ");
    scanf("%d %d", &end_row, &end_col);

    dijkstra(start_row, start_col, end_row, end_col); // find the shortest path

    Node* curr = &grid[end_row][end_col];
    printf("The shortest path from (%d,%d) to (%d,%d) is: ", start_row, start_col, end_row, end_col);
    while (curr != NULL)
    {
        printf("(%d,%d) ", curr->row, curr->col);
        curr = curr->prev_node;
    }
    printf("\n");

    print_grid(); // print the grid with distances

    return 0;
}