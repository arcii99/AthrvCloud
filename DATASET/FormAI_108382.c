//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

#define ROW 10   
#define COL 10  

#define OBSTACLE 0     
#define EMPTY 1         
#define START 2     
#define GOAL 3       

struct Node {  
    int x, y;        
    int g;    
    int h;    
    int f;    
    struct Node* parent;  
}; 

typedef struct Node node;

node* create_node(int x, int y, node* parent, int g, int h)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->x = x;
    new_node->y = y;
    new_node->parent = parent;
    new_node->g = g;
    new_node->h = h;
    new_node->f = g + h;
    return new_node;
}

int is_valid(int x, int y)
{
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

int is_obstacle(int x, int y, int matrix[ROW][COL])
{
    return (matrix[x][y] == OBSTACLE);
}

int is_empty(int x, int y, int matrix[ROW][COL])
{
    return (matrix[x][y] == EMPTY);
}

int is_goal(int x, int y, int matrix[ROW][COL])
{
    return (matrix[x][y] == GOAL);
}

int get_heuristic(int x, int y, int goal_x, int goal_y)
{
    return abs(goal_x - x) + abs(goal_y - y);
}

node* get_cheapest_node(node* node_list[], int size)
{
    node* cheapest_node = node_list[0];
    for (int i = 1; i < size; i++)
    {
        if (node_list[i]->f < cheapest_node->f)
        {
            cheapest_node = node_list[i];
        }
    }
    return cheapest_node;
}

void print_path(node* goal_node, int matrix[ROW][COL])
{
    node* current_node = goal_node;
    while (current_node != NULL)
    {
        printf("(%d, %d)\n", current_node->x, current_node->y);
        matrix[current_node->x][current_node->y] = 4;
        current_node = current_node->parent;
    }
}

void print_matrix(int matrix[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void A_star(int matrix[ROW][COL], int start_x, int start_y, int goal_x, int goal_y)
{
    node* open_list[ROW*COL];
    node* closed_list[ROW*COL];

    for (int i = 0; i < ROW*COL; i++)
    {
        open_list[i] = NULL;
        closed_list[i] = NULL;
    }

    int open_list_index = 0, closed_list_index = 0;

    node* start_node = create_node(start_x, start_y, NULL, 0, get_heuristic(start_x, start_y, goal_x, goal_y));
    open_list[open_list_index++] = start_node;

    while (open_list_index != 0)
    {
        node* current_node = get_cheapest_node(open_list, open_list_index--);

        if (is_goal(current_node->x, current_node->y, matrix))
        {
            printf("Path found!\n");
            print_path(current_node, matrix);
            printf("\n");
            print_matrix(matrix);
            exit(0);
        }

        int successors_x[4] = { current_node->x, current_node->x, current_node->x + 1, current_node->x - 1 };
        int successors_y[4] = { current_node->y + 1, current_node->y - 1, current_node->y, current_node->y };
        for (int i = 0; i < 4; i++)
        {
            if (is_valid(successors_x[i], successors_y[i]) && !is_obstacle(successors_x[i], successors_y[i], matrix))
            {
                node* successor = create_node(successors_x[i], successors_y[i], current_node, current_node->g + 1, get_heuristic(successors_x[i], successors_y[i], goal_x, goal_y));

                int exists = 0;
                for (int i = 0; i < closed_list_index; i++)
                {
                    if (successor->x == closed_list[i]->x && successor->y == closed_list[i]->y)
                    {
                        exists = 1;
                        break;
                    }
                }
                if (!exists)
                {
                    for (int i = 0; i < open_list_index; i++)
                    {
                        if (successor->x == open_list[i]->x && successor->y == open_list[i]->y)
                        {
                            if (successor->f < open_list[i]->f)
                            {
                                open_list[i] = successor;
                            }
                            exists = 1;
                            break;
                        }
                    }
                    if (!exists)
                    {
                        open_list[open_list_index++] = successor;
                    }
                }
            }
        }
        closed_list[closed_list_index++] = current_node;
    }
    printf("No path found.\n");
    print_matrix(matrix);
}

int main()
{
    int matrix[ROW][COL] = {
        { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
    };
    A_star(matrix, 3, 3, 6, 7);
    return 0;
}