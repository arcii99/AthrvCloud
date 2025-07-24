//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10
#define COL 10

int start[2] = {0, 0}; // starting position
int finish[2] = {9, 9}; // finishing position

struct node {
    int x, y; // position of the node in the grid
    int f, g, h; // f = g + h, g = distance from starting node, h = distance from finishing node
    struct node* parent; // pointer to previous node in the path
};

int is_valid(int x, int y, int grid[][COL])
{
    // check if the node is within the bounds of the grid and not blocked
    if (x >= 0 && x < ROW && y >= 0 && y < COL && grid[x][y] == 0)
        return 1;
    return 0;
}

int is_destination(int x, int y)
{
    // check if the node matches the finishing position
    if (x == finish[0] && y == finish[1])
        return 1;
    return 0;
}

int calculate_h(int x, int y)
{
    // calculate heuristic distance from the node to the finishing position
    return sqrt(pow((x - finish[0]), 2) + pow((y - finish[1]), 2));
}

void print_grid(int grid[][COL])
{
    // function to print the grid
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (grid[i][j] == 1)
                printf("# ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

struct node* create_node(int x, int y, int g, int h, struct node* parent)
{
    // function to create a new node
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->x = x;
    new_node->y = y;
    new_node->g = g;
    new_node->h = h;
    new_node->f = g + h;
    new_node->parent = parent;
    return new_node;
}

void free_node(struct node* n)
{
    // function to free memory allocated for the node
    free(n);
}

struct list {
    struct node* n;
    struct list* next;
};

struct list* create_list(struct node* n)
{
    // function to create a new list
    struct list* new_list = (struct list*) malloc(sizeof(struct list));
    new_list->n = n;
    new_list->next = NULL;
    return new_list; 
}

void free_list(struct list* l)
{
    // function to free memory allocated for the list
    struct list* temp;
    while (l) {
        temp = l->next;
        free_node(l->n);
        free(l);
        l = temp;
    }
}

void insert_list(struct list** l, struct node* n)
{
    // function to insert a node into the list in ascending order of f value
    struct list* new_list = create_list(n);
    struct list* temp = *l;
    if (*l == NULL) {
        *l = new_list;
        return;
    }
    if ((*l)->n->f >= n->f) {
        new_list->next = *l;
        *l = new_list;
        return;
    }
    while (temp->next != NULL && temp->next->n->f < n->f)
        temp = temp->next;
    new_list->next = temp->next;
    temp->next = new_list;
}

void delete_list(struct list** l, struct node* n)
{
    // function to delete a node from the list
    struct list* temp = *l, *prev;
    if (temp != NULL && temp->n == n) {
        *l = temp->next;
        free_node(temp->n);
        free(temp);
        return;
    }
    while (temp != NULL && temp->n != n) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free_node(temp->n);
    free(temp);
}

struct node* find_min_f(struct list* open_list)
{
    // function to find the node with the lowest f value in the open list
    if (open_list == NULL)
        return NULL;
    struct node* min_node = open_list->n;
    open_list = open_list->next;
    while (open_list != NULL) {
        if (open_list->n->f < min_node->f)
            min_node = open_list->n;
        open_list = open_list->next;
    }
    return min_node;
}

void traceback_path(struct node* n, int grid[][COL])
{
    // function to print the path from finishing node to starting node
    while (n) {
        grid[n->x][n->y] = -1;
        n = n->parent;
    }
    print_grid(grid);
}

int A_star(int grid[][COL])
{
    struct list* open_list = NULL;
    struct list* closed_list = NULL;
    insert_list(&open_list, create_node(start[0], start[1], 0, calculate_h(start[0], start[1]), NULL));
    while (open_list != NULL) {
        struct node* current_node = find_min_f(open_list);
        delete_list(&open_list, current_node);
        insert_list(&closed_list, current_node);
        if (is_destination(current_node->x, current_node->y)) {
            traceback_path(current_node, grid);
            free_list(open_list);
            free_list(closed_list);
            return 1;
        }
        int neighbours_x[] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int neighbours_y[] = {0, 1, 0, -1, -1, 1, 1, -1};
        for (int i = 0; i < 8; i++) {
            int neighbour_x = current_node->x + neighbours_x[i];
            int neighbour_y = current_node->y + neighbours_y[i];
            int neighbour_g = current_node->g + 1;
            int neighbour_h = calculate_h(neighbour_x, neighbour_y);
            if (is_valid(neighbour_x, neighbour_y, grid)) {
                struct node* neighbour_node = create_node(neighbour_x, neighbour_y, neighbour_g, neighbour_h, current_node);
                struct list* temp = closed_list;
                while (temp) {
                    if (temp->n->x == neighbour_x && temp->n->y == neighbour_y)
                        break;
                    temp = temp->next;
                }
                if (temp != NULL)
                    continue;
                temp = open_list;
                while (temp) {
                    if (temp->n->x == neighbour_x && temp->n->y == neighbour_y) {
                        if (neighbour_g < temp->n->g) {
                            temp->n->g = neighbour_g;
                            temp->n->f = neighbour_g + neighbour_h;
                            temp->n->parent = current_node;
                        }
                        break;
                    }
                    temp = temp->next;
                }
                if (temp == NULL)
                    insert_list(&open_list, neighbour_node);
            }
        }
    }
    printf("No path found.\n");
    free_list(open_list);
    free_list(closed_list);
    return 0;
}

int main()
{
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    printf("Grid:\n");
    print_grid(grid);
    A_star(grid);
    return 0;
}