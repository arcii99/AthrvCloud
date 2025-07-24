//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 10
#define COLS 10

//Graph data structure
typedef struct Graph {
    int mat[ROWS][COLS];
}Graph;

//Queue data structure
typedef struct Queue {
    int x;
    int y;
    struct Queue *next;
}Queue;

//Function to add node to the queue
void addQueue(Queue **head, Queue **tail, int x, int y) {
    Queue *temp = (Queue*)malloc(sizeof(Queue));
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    if(*tail == NULL) {
        *head = *tail = temp;
    }
    else {
        (*tail)->next = temp;
        *tail = temp;
    }
}

//Function to remove node from the queue
void removeQueue(Queue **head, Queue **tail) {
    if(*head == NULL) {
        return;
    }
    Queue *temp = *head;
    *head = (*head)->next;
    if(*head == NULL) {
        *tail = NULL;
    }
    free(temp);
}

//Function to check if node is present in the queue
int inQueue(Queue *head, Queue *tail, int x, int y) {
    for(Queue *temp = head; temp != NULL; temp = temp->next) {
        if(temp->x == x && temp->y == y) {
            return 1;
        }
    }
    return 0;
}

//Function to generate random graph with obstacles
void generateGraph(Graph *g) {
    srand(time(0));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(rand()%4 == 0) {
                g->mat[i][j] = 1;
            }
            else {
                g->mat[i][j] = 0;
            }
        }
    }
}

//Function to print the graph
void printGraph(Graph g) {
    printf("\n\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(g.mat[i][j] == 1) {
                printf("X ");
            }
            else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

//Function to find path using BFS algorithm
void bfs(Graph g, int startX, int startY, int endX, int endY) {
    Queue *head = NULL, *tail = NULL;
    int visited[ROWS][COLS] = {0};
    int parent[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            parent[i][j] = -1;
        }
    }
    visited[startX][startY] = 1;
    addQueue(&head, &tail, startX, startY);
    while(head != NULL) {
        int x = head->x;
        int y = head->y;
        if(x == endX && y == endY) {
            printf("\nPath found using BFS!\n");
            printf("(%d, %d) ", x, y);
            while(parent[x][y] != -1) {
                int tempX = parent[x][y]/10;
                int tempY = parent[x][y]%10;
                printf("<-- (%d, %d) ", tempX, tempY);
                x = tempX;
                y = tempY;
            }
            printf("\n\n");
            return;
        }
        removeQueue(&head, &tail);
        if(x-1 >= 0 && g.mat[x-1][y] != 1 && visited[x-1][y] == 0) {
            visited[x-1][y] = 1;
            parent[x-1][y] = x*10 + y;
            addQueue(&head, &tail, x-1, y);
        }
        if(y-1 >= 0 && g.mat[x][y-1] != 1 && visited[x][y-1] == 0) {
            visited[x][y-1] = 1;
            parent[x][y-1] = x*10 + y;
            addQueue(&head, &tail, x, y-1);
        }
        if(x+1 < ROWS && g.mat[x+1][y] != 1 && visited[x+1][y] == 0) {
            visited[x+1][y] = 1;
            parent[x+1][y] = x*10 + y;
            addQueue(&head, &tail, x+1, y);
        }
        if(y+1 < COLS && g.mat[x][y+1] != 1 && visited[x][y+1] == 0) {
            visited[x][y+1] = 1;
            parent[x][y+1] = x*10 + y;
            addQueue(&head, &tail, x, y+1);
        }
    }
    printf("\nFailed to find path using BFS!\n\n");
}

//Main function
int main() {
    Graph g;
    generateGraph(&g);
    printGraph(g);
    bfs(g, 0, 0, ROWS-1, COLS-1);
    return 0;
}