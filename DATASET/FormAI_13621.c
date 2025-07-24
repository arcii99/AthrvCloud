//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int x;
    int y;
    int f;
    int g;
    int h;
    struct node *parent;
} Node;

typedef struct list {
    Node *node;
    struct list *next;
} List;

int heuristic(Node *current, Node *goal) {
    int dx = abs(goal->x - current->x);
    int dy = abs(goal->y - current->y);
    return dx + dy;
}

List *push(List* head, Node *node) {
    List *new_node = (List*) malloc(sizeof(List));
    if (new_node != NULL) {
        new_node->node = node;
        new_node->next = head;
        return new_node;
    }
    return NULL;
}

Node *pop(List **head) {
    if (*head == NULL) {
        return NULL;
    }
    List *temp = *head;
    Node *node = temp->node;
    *head = (*head)->next;
    free(temp);
    return node;
}

void remove_node(List **head, Node *node) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->node == node) {
        *head = (*head)->next;
        return;
    }
    List *current = *head;
    while (current->next != NULL && current->next->node != node) {
        current = current->next;
    }
    if (current->next != NULL) {
        List *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

void print_path(Node *node) {
    if (node == NULL) {
        printf("No path found!\n");
    } else {
        print_path(node->parent);
        printf("(%d, %d)\n", node->x, node->y);
    }
}

void destroy(List **head) {
    List *current = *head;
    while (current != NULL) {
        List *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

void find_path(int **map, int width, int height, Node *start, Node *goal) {
    List *open = push(NULL, start);
    List *closed = NULL;
    while (open != NULL) {
        Node *current = pop(&open);
        if (current == goal) {
            print_path(current);
            destroy(&open);
            destroy(&closed);
            return;
        }
        closed = push(closed, current);
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int x = current->x + i;
                int y = current->y + j;
                if (x < 0 || x >= width || y < 0 || y >= height) {
                    continue;
                }
                if (map[y][x] == 1) {
                    continue;
                }
                Node *successor = (Node*) malloc(sizeof(Node));
                successor->x = x;
                successor->y = y;
                successor->parent = current;
                successor->g = current->g + 1;
                successor->h = heuristic(successor, goal);
                successor->f = successor->g + successor->h;
                List *t;
                for (t = closed; t != NULL; t = t->next) {
                    if (t->node->x == successor->x && t->node->y == successor->y) {
                        break;
                    }
                }
                if (t != NULL) {
                    free(successor);
                    continue;
                }
                int found = 0;
                for (t = open; t != NULL; t = t->next) {
                    if (t->node->x == successor->x && t->node->y == successor->y) {
                        found = 1;
                        if (t->node->g > successor->g) {
                            t->node->g = successor->g;
                            t->node->h = successor->h;
                            t->node->f = successor->f;
                            t->node->parent = successor->parent;
                        }
                        free(successor);
                        break;
                    }
                }
                if (!found) {
                    open = push(open, successor);
                }
            }
        }
    }
    destroy(&closed);
    printf("No path found!\n");
}

int main() {
    int map[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int width = 10;
    int height = 10;
    Node start = {1, 0, 0, 0, 0, NULL};
    Node goal = {5, 9, 0, 0, 0, NULL};
    find_path((int**) map, width, height, &start, &goal);
    return 0;
}