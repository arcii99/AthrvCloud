//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: statistical
// C Maze Route Finder Example Program 
// By [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

char maze[ROWS][COLS] = {
    {'*', '*', '*', '*', '*'},
    {'*', ' ', '*', ' ', '*'},
    {'*', ' ', '*', ' ', '*'},
    {'*', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*'}
};

struct Node {
    int row;
    int col;
    struct Node* next;
};

typedef struct Node Node;

Node* front = NULL;
Node* rear = NULL;

void Enqueue(int row, int col) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->row = row;
    temp->col = col;
    temp->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue() {
    Node* temp = front;
    if (front == NULL) {
        return;
    }
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
}

Node* Peek() {
    return front;
}

bool IsEmpty() {
    if (front == NULL && rear == NULL) {
        return true;
    } else {
        return false;
    }
}

bool IsSafe(int row, int col, bool visited[ROWS][COLS]) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == ' ' && !visited[row][col]) {
        return true;
    } else {
        return false;
    }
}

void BFS(int startRow, int startCol, int endRow, int endCol) {
    bool visited[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = false;
        }
    }
    visited[startRow][startCol] = true;
    Enqueue(startRow, startCol);
    while (!IsEmpty()) {
        Node* curr = Peek();
        int row = curr->row;
        int col = curr->col;
        if (row == endRow && col == endCol) {
            printf("Path Found\n");
            while (curr != NULL) {
                printf("(%d,%d)->", curr->row, curr->col);
                curr = curr->next;
            }
            printf("EXIT\n");
            return;
        }
        Dequeue();
        if (IsSafe(row-1, col, visited)) {
            visited[row-1][col] = true;
            Enqueue(row-1, col);
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->row = row-1;
            newNode->col = col;
            newNode->next = curr;
            curr->next = newNode;
        }
        if (IsSafe(row+1, col, visited)) {
            visited[row+1][col] = true;
            Enqueue(row+1, col);
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->row = row+1;
            newNode->col = col;
            newNode->next = curr;
            curr->next = newNode;
        }
        if (IsSafe(row, col-1, visited)) {
            visited[row][col-1] = true;
            Enqueue(row, col-1);
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->row = row;
            newNode->col = col-1;
            newNode->next = curr;
            curr->next = newNode;
        }
        if (IsSafe(row, col+1, visited)) {
            visited[row][col+1] = true;
            Enqueue(row, col+1);
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->row = row;
            newNode->col = col+1;
            newNode->next = curr;
            curr->next = newNode;
        }
    }
    printf("Path not found\n");
}

int main() {
    BFS(1, 3, 3, 2);
    return 0;
}