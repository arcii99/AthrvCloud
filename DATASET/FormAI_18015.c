//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x, y;
    struct node *parent;
    int cost, heuristic, total;
    int closed;
} node;

node* create_node(int x, int y, int cost, int heuristic, node* parent) {
    node* n = malloc(sizeof(node));
    n->x = x;
    n->y = y;
    n->cost = cost;
    n->heuristic = heuristic;
    n->total = cost + heuristic;
    n->parent = parent;
    n->closed = 0;
    return n;
}

int main() {
    printf("Welcome to the A* Pathfinding Algorithm!\n");
    printf("It's like GPS for video game characters, but with more math!\n");
    printf("So, let's give it a try, shall we?\n");
    printf("\n");

    int start_x = 0, start_y = 0, end_x = 5, end_y = 7;
    int map[10][10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,1,1,0,1,1,0,0,1,0},
            {0,0,1,0,0,1,1,1,0,0},
            {0,0,1,1,1,0,0,0,1,0},
            {0,0,0,0,0,1,1,0,0,0},
            {0,0,1,1,1,1,1,1,0,0},
            {0,0,0,0,0,1,1,1,1,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
    };

    printf("Here's our map:\n");
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Now, let's get to the start and end points.\n");
    printf("Enter the start point (x y): ");
    scanf("%d %d", &start_x, &start_y);
    printf("Enter the end point (x y): ");
    scanf("%d %d", &end_x, &end_y);
    printf("\n");

    node* start = create_node(start_x, start_y, 0, 0, NULL);
    node* end = create_node(end_x, end_y, 0, 0, NULL);

    node* open_list[100];
    int open_count = 0;

    node* closed_list[100];
    int closed_count = 0;

    open_list[open_count++] = start;

    while(open_count > 0) {
        int current_index = 0;
        for(int i=0; i<open_count; i++) {
            if(open_list[i]->total < open_list[current_index]->total) {
                current_index = i;
            }
        }

        node* current = open_list[current_index];

        if(current->x == end->x && current->y == end->y) {
            printf("Hooray! We found the path to the treasure!\n");
            printf("Here's the path we took:\n");
            printf("(%d, %d) -> ", current->x, current->y);
            while(current->parent != NULL) {
                current = current->parent;
                printf("(%d, %d) -> ", current->x, current->y);
            }
            printf("\nThe treasure is ours!\n");
            return 0;
        }

        open_list[current_index] = open_list[--open_count];
        closed_list[closed_count++] = current;
        current->closed = 1;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++) {
            int new_x = current->x + dx[i];
            int new_y = current->y + dy[i];

            if(new_x < 0 || new_x >= 10) continue;
            if(new_y < 0 || new_y >= 10) continue;
            if(map[new_x][new_y] == 1) continue;

            int cost = current->cost + 1;
            int heuristic = abs(new_x - end_x) + abs(new_y - end_y);

            node* successor = NULL;
            for(int j=0; j<open_count; j++) {
                if(open_list[j]->x == new_x && open_list[j]->y == new_y) {
                    successor = open_list[j];
                    break;
                }
            }

            if(successor == NULL) {
                for(int j=0; j<closed_count; j++) {
                    if(closed_list[j]->x == new_x && closed_list[j]->y == new_y) {
                        successor = closed_list[j];
                        break;
                    }
                }
            }

            if(successor == NULL) {
                successor = create_node(new_x, new_y, cost, heuristic, current);
                open_list[open_count++] = successor;
            } else if(cost < successor->cost) {
                successor->cost = cost;
                successor->heuristic = heuristic;
                successor->total = cost + heuristic;
                successor->parent = current;
            }
        }
    }

    printf("Oh no! We couldn't find the path to the treasure...\n");
    printf("We must have taken a wrong turn at Albuquerque or something.\n");
    return 0;
}