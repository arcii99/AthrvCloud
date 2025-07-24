//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30

typedef struct node {
    int x, y;
    struct node *next;
} Node;

// generates a random map with obstacles
void generate_map(int map[][COLS])
{
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (rand() % 10 == 0) {
                map[i][j] = -1; // obstacle
            } else {
                map[i][j] = 0; // empty cell
            }
        }
    }
}

// prints the map
void print_map(int map[][COLS])
{
    printf("Map:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == -1) {
                printf("# "); // obstacle
            } else {
                printf(". "); // empty cell
            }
        }
        printf("\n");
    }
}

// adds a new node at the beginning of the list
void push_front(Node **head, int x, int y)
{
    Node *node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = *head;
    *head = node;
}

// frees the list
void free_list(Node *head)
{
    while (head) {
        Node *node = head;
        head = head->next;
        free(node);
    }
}

// finds the shortest path using breadth-first search
void find_path(int map[][COLS], int start_x, int start_y, int end_x, int end_y)
{
    Node *queue = malloc(sizeof(Node));
    queue->next = NULL;
    queue->x = start_x;
    queue->y = start_y;
    map[start_x][start_y] = 1;
    while (queue) {
        int x = queue->x;
        int y = queue->y;
        Node *node = queue;
        queue = queue->next;
        free(node);
        if (x == end_x && y == end_y) {
            printf("Found a path!\n");
            free_list(queue);
            return;
        }
        int dist = map[x][y] + 1;
        if (x > 0 && map[x - 1][y] == 0) { // left
            push_front(&queue, x - 1, y);
            map[x - 1][y] = dist;
        }
        if (y > 0 && map[x][y - 1] == 0) { // up
            push_front(&queue, x, y - 1);
            map[x][y - 1] = dist;
        }
        if (x < ROWS - 1 && map[x + 1][y] == 0) { // right
            push_front(&queue, x + 1, y);
            map[x + 1][y] = dist;
        }
        if (y < COLS - 1 && map[x][y + 1] == 0) { // down
            push_front(&queue, x, y + 1);
            map[x][y + 1] = dist;
        }
    }
    printf("No path found!\n");
    free_list(queue);
}

int main()
{
    int map[ROWS][COLS];
    generate_map(map);
    print_map(map);
    int start_x, start_y, end_x, end_y;
    printf("Enter start position (row column): ");
    scanf("%d %d", &start_x, &start_y);
    printf("Enter end position (row column): ");
    scanf("%d %d", &end_x, &end_y);
    find_path(map, start_x, start_y, end_x, end_y);
    return 0;
}