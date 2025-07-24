//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

#define START_X 3
#define START_Y 3

#define END_X 7
#define END_Y 7

#define BLOCKED 1
#define NOT_BLOCKED 0

typedef struct Node {
    int x;  // x coordinate of node
    int y;  // y coordinate of node
    int f;  // f = g + h

    int g;  // cost from start node to current node
    int h;  // heuristic cost from current node to end node

    struct Node* parent;  // parent node in path
} Node;

void initialize_grid(int grid[][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            grid[i][j] = NOT_BLOCKED;
        }
    }
    // add obstacles to grid
    grid[4][1] = BLOCKED;
    grid[4][2] = BLOCKED;
    grid[4][3] = BLOCKED;
    grid[4][4] = BLOCKED;
    grid[4][5] = BLOCKED;
    grid[4][6] = BLOCKED;
}

void print_grid(int grid[][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (grid[i][j] == BLOCKED)
            {
                printf("# ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

Node* find_min_f_node(Node* open_list[], int open_list_size)
{
    Node* min_node = open_list[0];
    int min_f = min_node->f;

    for (int i = 1; i < open_list_size; i++)
    {
        if (open_list[i]->f < min_f)
        {
            min_node = open_list[i];
            min_f = min_node->f;
        }
    }

    return min_node;
}

int calculate_h_cost(int x, int y)
{
    return abs(x - END_X) + abs(y - END_Y);
}

Node* find_neighbour(int x, int y, int g_cost, Node* parent)
{
    Node* neighbour = (Node*)malloc(sizeof(Node));
    neighbour->x = x;
    neighbour->y = y;
    neighbour->g = g_cost;
    neighbour->h = calculate_h_cost(x, y);
    neighbour->f = neighbour->g + neighbour->h;
    neighbour->parent = parent;
    return neighbour;
}

void add_to_open_list(Node* open_list[], int* open_list_size, Node* neighbour)
{
    for (int i = 0; i < *open_list_size; i++)
    {
        if (open_list[i]->x == neighbour->x && open_list[i]->y == neighbour->y)
        {
            // node already in open list, update if necessary
            if (open_list[i]->f > neighbour->f)
            {
                open_list[i]->f = neighbour->f;
                open_list[i]->g = neighbour->g;
                open_list[i]->parent = neighbour->parent;
            }
            return;
        }
    }
    // node not in open list, insert in sorted order
    int i = 0;
    for (; i < *open_list_size; i++)
    {
        if (open_list[i]->f > neighbour->f)
        {
            break;
        }
    }
    for (int j = *open_list_size; j > i; j--)
    {
        open_list[j] = open_list[j - 1];
    }
    open_list[i] = neighbour;
    (*open_list_size)++;
}

Node* search_path(int grid[][COL])
{
    Node* open_list[100];
    int open_list_size = 1;

    Node* start_node = find_neighbour(START_X, START_Y, 0, NULL);
    start_node->f = start_node->h;
    printf("Start position: (%d, %d)\n", start_node->x, start_node->y);

    open_list[0] = start_node;

    while (open_list_size > 0)
    {
        Node* current_node = find_min_f_node(open_list, open_list_size);
        printf("Current position: (%d, %d)\n", current_node->x, current_node->y);

        if (current_node->x == END_X && current_node->y == END_Y) // end node found
        {
            return current_node;
        }

        int x = current_node->x;
        int y = current_node->y;

        if (x > 0 && !grid[x - 1][y])  // check north neighbour
        {
            Node* neighbour = find_neighbour(x - 1, y, current_node->g + 1, current_node);
            add_to_open_list(open_list, &open_list_size, neighbour);
        }
        if (y < COL - 1 && !grid[x][y + 1])  // check east neighbour
        {
            Node* neighbour = find_neighbour(x, y + 1, current_node->g + 1, current_node);
            add_to_open_list(open_list, &open_list_size, neighbour);
        }
        if (x < ROW - 1 && !grid[x + 1][y])  // check south neighbour
        {
            Node* neighbour = find_neighbour(x + 1, y, current_node->g + 1, current_node);
            add_to_open_list(open_list, &open_list_size, neighbour);
        }
        if (y > 0 && !grid[x][y - 1])  // check west neighbour
        {
            Node* neighbour = find_neighbour(x, y - 1, current_node->g + 1, current_node);
            add_to_open_list(open_list, &open_list_size, neighbour);
        }

        for (int i = 0; i < open_list_size; i++) // remove current node from open list
        {
            if (open_list[i] == current_node)
            {
                for (int j = i; j < open_list_size - 1; j++)
                {
                    open_list[j] = open_list[j + 1];
                }
                open_list_size--;
                break;
            }
        }
    }

    // path not found
    return NULL;
}

void print_path(Node* end_node)
{
    if (end_node == NULL)
    {
        printf("Path not found.\n");
        return;
    }

    printf("Path: ");
    Node* current = end_node;
    while (current != NULL)
    {
        printf("(%d, %d) ", current->x, current->y);
        current = current->parent;
    }
}

int main()
{
    int grid[ROW][COL];
    initialize_grid(grid);

    printf("Grid:\n");
    print_grid(grid);

    Node* end_node = search_path(grid);

    print_path(end_node);

    return 0;
}