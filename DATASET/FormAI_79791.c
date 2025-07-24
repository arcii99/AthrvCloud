//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The 2D array representing the maze
int maze[10][10] = {
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1}, 
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1}
};

// Struct representing a point in the maze
typedef struct {
    int x;
    int y;
} Point;

// Struct representing a node in the linked list used to store visited points
typedef struct Node {
    Point p;
    struct Node* next;
} Node;

// Function to check if a point is inside the maze
bool isInsideMaze(Point p) {
    if (p.x >= 0 && p.x < 10 && p.y >= 0 && p.y < 10) {
        return true;
    }
    return false;
}

// Function to check if a point is a valid move (i.e. not a wall and not visited)
bool isValidMove(Point p, bool visited[10][10]) {
    if (isInsideMaze(p) && maze[p.x][p.y] == 1 && !visited[p.x][p.y]) {
        return true;
    }
    return false;
}

// Function to add a node to the linked list
void addNode(Point p, Node** head) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->p = p;
    new_node->next = *head;
    *head = new_node;
}

// Function to remove the last node in the linked list
void removeLastNode(Node** head) {
    if (*head == NULL) {
        return;
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        Node* current = *head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}

// Main function that performs the pathfinding algorithm
void findPath(Point start, Point end) {
    // Create the visited array and initialize it to false
    bool visited[10][10];
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            visited[i][j] = false;
        }
    }
    
    // Create the linked list and add the starting point
    Node* head = NULL;
    addNode(start, &head);
    
    // Loop until the linked list is empty or the end point is found
    while (head != NULL) {
        // Get the current point and mark it as visited
        Point current = head->p;
        visited[current.x][current.y] = true;
        
        // Check if the current point is the end point
        if (current.x == end.x && current.y == end.y) {
            // If so, print the path by following the linked list backwards
            Point path[100];
            int path_length = 0;
            Node* current_node = head;
            while (current_node != NULL) {
                path[path_length] = current_node->p;
                path_length++;
                current_node = current_node->next;
            }
            printf("Path found:\n");
            for (int i=path_length-1; i>=0; i--) {
                printf("(%d, %d)", path[i].x, path[i].y);
                if (i != 0) {
                    printf(" -> ");
                }
            }
            return;
        }
        
        // Try all possible moves and add them to the linked list if they are valid
        if (isValidMove((Point) {current.x+1, current.y}, visited)) {
            addNode((Point) {current.x+1, current.y}, &head);
        }
        if (isValidMove((Point) {current.x-1, current.y}, visited)) {
            addNode((Point) {current.x-1, current.y}, &head);
        }
        if (isValidMove((Point) {current.x, current.y+1}, visited)) {
            addNode((Point) {current.x, current.y+1}, &head);
        }
        if (isValidMove((Point) {current.x, current.y-1}, visited)) {
            addNode((Point) {current.x, current.y-1}, &head);
        }
        
        // If no valid moves were found, remove the last node in the linked list
        removeLastNode(&head);
    }
    
    // If the linked list is empty, no path was found
    printf("No path found.\n");
}

// Main function
int main() {
    Point start = (Point) {0, 0};
    Point end = (Point) {9, 9};
    findPath(start, end);
    return 0;
}