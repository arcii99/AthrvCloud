//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10
#define COL 10

struct node {
    int row;
    int col;
    int f;
    int g;
    int h;
    struct node *parent;
};

struct list {
    struct node *current;
    struct list *next;
};

static struct list *open_list, *closed_list;

// Function to initialize all the lists and nodes
void initialize() {
    open_list = NULL;
    closed_list = NULL;
}

// Function to check if the node is valid
int isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Function to check if the given node is not blocked
int isUnblocked(char grid[][COL], int row, int col) {
    return (grid[row][col] == ' ');
}

// Function to check if the given node is the destination
int isDestination(int row, int col, struct node *dest) {
    return (row == dest->row) && (col == dest->col);
}

// Function to calculate H-value using Manhattan Distance heuristic formula
int calculateHValue(int row, int col, struct node *dest) {
    return abs(row - dest->row) + abs(col - dest->col);
}

// Function to trace the path from destination to source
void tracePath(struct node *dest) {
    printf("Path: \n");
    struct node *current = dest;
    while(current != NULL) {
        printf("(%d, %d) -> ", current->row, current->col);
        current = current->parent;
    }
}

// Function to print the grid
void printGrid(char grid[][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to add a node to the list
void addToList(struct node *current, struct list **list) {
    struct list *new_node = (struct list *) malloc(sizeof(struct list));
    new_node->current = current;
    new_node->next = *list;
    *list = new_node;
}

// Function to delete a node from the list
void deleteFromList(struct node *current, struct list **list) {
    struct list *temp = *list, *prev;
    if(temp != NULL && temp->current == current) {
        *list = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->current != current) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to find the node with the lowest f-value in the open list
struct node* getNodeWithLowestFValue() {
    struct list *temp = open_list;
    struct node *nodeWithLowestFValue = temp->current;
    int lowestFValue = nodeWithLowestFValue->f;

    while(temp != NULL) {
        if(temp->current->f < lowestFValue) {
            lowestFValue = temp->current->f;
            nodeWithLowestFValue = temp->current;
        }
        temp = temp->next;
    }
    return nodeWithLowestFValue;
}

// Function to implement A* Pathfinding Algorithm
void aStarAlgorithm(char grid[][COL], struct node *source, struct node *dest) {
    initialize();
    source->parent = NULL;
    source->g = 0;
    source->h = calculateHValue(source->row, source->col, dest);
    source->f = source->g + source->h;
    addToList(source, &open_list);

    while(open_list != NULL) {
        struct node *current = getNodeWithLowestFValue();
        deleteFromList(current, &open_list);
        addToList(current, &closed_list);

        if(isDestination(current->row, current->col, dest)) {
            tracePath(dest);
            return;
        }

        int row, col;

        // Check the North neighbor
        row = current->row - 1;
        col = current->col;
        if(isValid(row, col) && isUnblocked(grid, row, col)) {
            int gNew = current->g + 1;
            int hNew = calculateHValue(row, col, dest);
            int fNew = gNew + hNew;
            struct node *node = (struct node *) malloc(sizeof(struct node));
            node->row = row;
            node->col = col;
            node->f = fNew;
            node->g = gNew;
            node->h = hNew;
            node->parent = current;
            struct list *temp = open_list;
            while(temp != NULL && temp->current != node) {
                temp = temp->next;
            }
            if(temp != NULL && temp->current == node && fNew >= temp->current->f) {
                free(node);
            }
            else {
                addToList(node, &open_list);
            }
        }

        // Check the South neighbor
        row = current->row + 1;
        col = current->col;
        if(isValid(row, col) && isUnblocked(grid, row, col)) {
            int gNew = current->g + 1;
            int hNew = calculateHValue(row, col, dest);
            int fNew = gNew + hNew;
            struct node *node = (struct node *) malloc(sizeof(struct node));
            node->row = row;
            node->col = col;
            node->f = fNew;
            node->g = gNew;
            node->h = hNew;
            node->parent = current;
            struct list *temp = open_list;
            while(temp != NULL && temp->current != node) {
                temp = temp->next;
            }
            if(temp != NULL && temp->current == node && fNew >= temp->current->f) {
                free(node);
            }
            else {
                addToList(node, &open_list);
            }
        }

        // Check the West neighbor
        row = current->row;
        col = current->col - 1;
        if(isValid(row, col) && isUnblocked(grid, row, col)) {
            int gNew = current->g + 1;
            int hNew = calculateHValue(row, col, dest);
            int fNew = gNew + hNew;
            struct node *node = (struct node *) malloc(sizeof(struct node));
            node->row = row;
            node->col = col;
            node->f = fNew;
            node->g = gNew;
            node->h = hNew;
            node->parent = current;
            struct list *temp = open_list;
            while(temp != NULL && temp->current != node) {
                temp = temp->next;
            }
            if(temp != NULL && temp->current == node && fNew >= temp->current->f) {
                free(node);
            }
            else {
                addToList(node, &open_list);
            }
        }

        // Check the East neighbor
        row = current->row;
        col = current->col + 1;
        if(isValid(row, col) && isUnblocked(grid, row, col)) {
            int gNew = current->g + 1;
            int hNew = calculateHValue(row, col, dest);
            int fNew = gNew + hNew;
            struct node *node = (struct node *) malloc(sizeof(struct node));
            node->row = row;
            node->col = col;
            node->f = fNew;
            node->g = gNew;
            node->h = hNew;
            node->parent = current;
            struct list *temp = open_list;
            while(temp != NULL && temp->current != node) {
                temp = temp->next;
            }
            if(temp != NULL && temp->current == node && fNew >= temp->current->f) {
                free(node);
            }
            else {
                addToList(node, &open_list);
            }
        }
    }
}

int main() {
    char grid[ROW][COL] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '*', '*', '*', ' ', '*', '*', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', '*', '*', ' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', ' '},
        {' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', ' '},
        {' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' '}
    };
    struct node source = {0, 0, 0, 0, 0, NULL};
    struct node dest = {7, 5, 0, 0, 0, NULL};

    printf("Grid: \n");
    printGrid(grid);

    aStarAlgorithm(grid, &source, &dest);

    return 0;
}