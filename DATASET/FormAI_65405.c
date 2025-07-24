//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: invasive
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  

#define ROW 20
#define COL 20

// Define colors
#define BLUE "\x1B[34m"
#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

int board[ROW][COL];
int score = 0;

// Define structs
typedef struct node Node;
typedef struct list List;

// Define node struct for linked list
struct node {
    int x;
    int y;
    Node* next;
};

// Define list struct for linked list
struct list {
    Node* head;
    Node* tail;
};

// Initialize list
List* initList() {
    List* list = (List*) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Add node to list
void add(List* list, int x, int y) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    }
    else {
        list->tail->next = node;
        list->tail = node;
    }
}

// Remove node from list
void removeNode(List* list, int x, int y) {
    if (list->head == NULL) {
        return;
    }
    if (list->head->x == x && list->head->y == y) {
        Node* tmp = list->head;
        list->head = list->head->next;
        free(tmp);
        return;
    }
    Node* curr = list->head;
    while (curr->next != NULL) {
        if (curr->next->x == x && curr->next->y == y) {
            Node* tmp = curr->next;
            curr->next = curr->next->next;
            if (tmp == list->tail) {
                list->tail = curr;
            }
            free(tmp);
            return;
        }
        curr = curr->next;
    }
}

// Display board
void display() {
    system("clear");
    printf("Score: %d\n", score);
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == 0) {
                printf(" ");
            }
            else if (board[i][j] == 1) {
                printf(BLUE "o" RESET);
            }
            else if (board[i][j] == 2) {
                printf(GREEN "@" RESET);
            }
            else if (board[i][j] == 3) {
                printf(RED "#" RESET);
            }
            else if (board[i][j] == 4) {
                printf(YELLOW "X" RESET);
            }
        }
        printf("\n");
    }
}

// Move the Pac-Man
void movePacman(List* list, int direction) {
    int currX = list->head->x;
    int currY = list->head->y;
    if (direction == 0) { // up
        currX--;
    }
    else if (direction == 1) { // right
        currY++;
    }
    else if (direction == 2) { // down
        currX++;
    }
    else if (direction == 3) { // left
        currY--;
    }
    if (currX < 0) {
        currX = ROW - 1;
    }
    else if (currX > ROW - 1) {
        currX = 0;
    }
    if (currY < 0) {
        currY = COL - 1;
    }
    else if (currY > COL - 1) {
        currY = 0;
    }
    if (board[currX][currY] == 2) { // if Pac-Man eats a dot
        score++;
        add(list, currX, currY);
        board[currX][currY] = 0;
        placeDot();
    }
    else if (board[currX][currY] == 3) { // if Pac-Man hits a wall
        printf("Game Over!\n");
        exit(1);
    }
    else if (board[currX][currY] == 4) { // if Pac-Man eats a power-up
        score += 10;
        add(list, currX, currY);
        board[currX][currY] = 0;
        placePowerUp();
    }
    else { // if Pac-Man moves normally
        add(list, currX, currY);
        Node* tail = list->tail;
        list->tail = list->tail->next;
        removeNode(list, tail->x, tail->y);
    }
}

// Place dot on board
void placeDot() {
    int dotPlaced = 0;
    while (!dotPlaced) {
        int x = rand() % ROW;
        int y = rand() % COL;
        if (board[x][y] == 0) {
            board[x][y] = 1;
            dotPlaced = 1;
        }
    }
}

// Place power-up on board
void placePowerUp() {
    int powerUpPlaced = 0;
    while (!powerUpPlaced) {
        int x = rand() % ROW;
        int y = rand() % COL;
        if (board[x][y] == 0) {
            board[x][y] = 4;
            powerUpPlaced = 1;
        }
    }
}

int main() {
    // Initialize board
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = 0;
        }
    }
    for (int i = 0; i < ROW; i++) {
        board[i][0] = 3;
        board[i][COL - 1] = 3;
    }
    for (int i = 0; i < COL; i++) {
        board[0][i] = 3;
        board[ROW - 1][i] = 3;
    }
    placeDot();
    placePowerUp();

    // Initialize Pac-Man position and list
    int startX = ROW / 2;
    int startY = COL / 2;
    List* list = initList();
    add(list, startX, startY);

    // Main game loop
    int direction = 1;
    while (1) {
        display();
        int ch = getchar();
        if (ch == 'w' || ch == 'W') {
            direction = 0;
        }
        else if (ch == 'd' || ch == 'D') {
            direction = 1;
        }
        else if (ch == 's' || ch == 'S') {
            direction = 2;
        }
        else if (ch == 'a' || ch == 'A') {
            direction = 3;
        }
        movePacman(list, direction);
    }
    return 0;
}