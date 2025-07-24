//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

/* Data Structure to represent a node in the graph */
struct Node {
    int x, y;
};

/* Function to find the shortest path between two nodes using A* Algorithm */
void A_star_algorithm(struct Node* start, struct Node* dest) {

    // Initialize the Open and Closed Lists
    int open_list[1000][2], closed_list[1000][2];
    int o_index=0, c_index=0;
    int neighbor[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
    int g_score[1000], f_score[1000];
    int came_from[1000];
    for(int i=0;i<1000;i++) {
        g_score[i] = 1000000;
        f_score[i] = 1000000;
        came_from[i] = -1;
    }

    // Push the start node to the Open List
    open_list[o_index][0] = start->x;
    open_list[o_index][1] = start->y;
    g_score[o_index] = 0;
    f_score[o_index] = abs(dest->x-start->x) + abs(dest->y-start->y);

    while(o_index >= 0) {
        // Find the node in the open list with the lowest f_score
        int min_score = 1000000, min_index = -1;
        for(int i=0;i<=o_index;i++) {
            if(f_score[i] < min_score) {
                min_score = f_score[i];
                min_index = i;
            }
        }

        // If the current node is the destination node, then we have found the shortest path
        if(open_list[min_index][0] == dest->x && open_list[min_index][1] == dest->y) {
            int current = min_index;
            while(came_from[current] != -1) {
                printf("(%d,%d)", open_list[current][0], open_list[current][1]);
                if(came_from[current] != 0)
                    printf(" -> ");
                current = came_from[current];
            }
            printf("(%d,%d)\n", open_list[current][0], open_list[current][1]);
            return;
        }

        // Pop the current node from the Open List and add it to the Closed List
        int current_x = open_list[min_index][0], current_y = open_list[min_index][1];
        for(int i=min_index;i<o_index;i++) {
            open_list[i][0] = open_list[i+1][0];
            open_list[i][1] = open_list[i+1][1];
            g_score[i] = g_score[i+1];
            f_score[i] = f_score[i+1];
        }
        o_index--;
        closed_list[c_index][0] = current_x;
        closed_list[c_index][1] = current_y;
        c_index++;

        // Explore all the neighbors of the current node
        for(int i=0;i<8;i++) {
            int x = current_x + neighbor[i][0];
            int y = current_y + neighbor[i][1];

            // Skip this neighbor if it is in the Closed List or if it is not a valid position in the graph
            int skipped = 0;
            for(int j=0;j<c_index;j++) {
                if(closed_list[j][0] == x && closed_list[j][1] == y) {
                    skipped = 1;
                    break;
                }
            }
            if(skipped || x < 0 || x > 100 || y < 0 || y > 100) {
                continue;
            }

            // Calculate the g_score of this neighbor
            int tentative_g_score = g_score[min_index] + 1;

            // Skip this neighbor if it is already in the Open List and the new g_score is larger than the old one
            skipped = 0;
            for(int j=0;j<=o_index;j++) {
                if(open_list[j][0] == x && open_list[j][1] == y) {
                    if(g_score[j] <= tentative_g_score) {
                        skipped = 1;
                        break;
                    }
                    else {
                        for(int k=j;k<o_index;k++) {
                            open_list[k][0] = open_list[k+1][0];
                            open_list[k][1] = open_list[k+1][1];
                            g_score[k] = g_score[k+1];
                            f_score[k] = f_score[k+1];
                        }
                        o_index--;
                        break;
                    }
                }
            }
            if(skipped) {
                continue;
            }

            // Add this neighbor to the Open List
            o_index++;
            open_list[o_index][0] = x;
            open_list[o_index][1] = y;
            g_score[o_index] = tentative_g_score;
            f_score[o_index] = tentative_g_score + abs(dest->x-x) + abs(dest->y-y);
            came_from[o_index] = min_index;
        }
    }
    printf("Path not found!\n");
}

int main() {
    // Initialize the nodes
    struct Node start, dest;
    start.x = 1;
    start.y = 1;
    dest.x = 20;
    dest.y = 20;

    // Call the A* Algorithm function to find the shortest path
    A_star_algorithm(&start, &dest);
    return 0;
}