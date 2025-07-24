//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int map[ROW][COL];
int visited[ROW][COL];

struct node {
    int r;
    int c;
    struct node* next;
};
typedef struct node Node;

Node* head = NULL;
Node* tail = NULL;

void enqueue(int r, int c) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->r = r;
    temp->c = c;
    temp->next = NULL;
    if (head == NULL && tail == NULL) {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void dequeue() {
    Node* temp = head;
    if (head == NULL) {
        return;
    }
    if (head == tail) {
        head = tail = NULL;
    }
    else {
        head = head->next;
    }
    free(temp);
}

Node* front() {
    return head;
}

int is_empty() {
    if (head == NULL) {
        return 1;
    }
    return 0;
}

void print() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d,%d -> ", temp->r, temp->c);
        temp = temp->next;
    }
    printf("NULL\n");
}

void generate_map() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            map[i][j] = rand() % 2;
            visited[i][j] = 0;
        }
    }
}

void print_map() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (map[i][j] == 1) {
                printf("# ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int bfs(int r, int c, int dr, int dc) {
    enqueue(r, c);
    visited[r][c] = 1;
    int row[] = {-1, 0, 0, 1};
    int col[] = {0, -1, 1, 0};
    while (!is_empty()) {
        Node* curr = front();
        dequeue();
        if (curr->r == dr && curr->c == dc) {
            return 1;
        }
        int i;
        for (i = 0; i < 4; i++) {
            int new_row = curr->r + row[i];
            int new_col = curr->c + col[i];
            if (new_row >= 0 && new_row < ROW && new_col >= 0 && new_col < COL && map[new_row][new_col] == 0 && 
                visited[new_row][new_col] == 0) {
                visited[new_row][new_col] = 1;
                enqueue(new_row, new_col);
                print();
            }
        }
    }
    return 0;
}

int main() {
    generate_map();
    printf("Map:\n");
    print_map();
    int start_r, start_c, dest_r, dest_c;
    printf("Enter start position (row,column): ");
    scanf("%d,%d", &start_r, &start_c);
    printf("Enter destination position (row,column): ");
    scanf("%d,%d", &dest_r, &dest_c);
    int result = bfs(start_r, start_c, dest_r, dest_c);
    if (result) {
        printf("Destination reached!\n");
    }
    else {
        printf("Could not reach destination.\n");
    }
    return 0;
}