//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ROW 10
#define COL 10

int row_delta[] = {1,0,-1,0};  // delta values for rows and columns
int col_delta[] = {0,1,0,-1};

typedef struct Node { // Structure for each node in the grid
    int row, col;
    int g, h, f;     // f,g and h values
    struct Node *parent; // pointer to the parent node
} Node;

Node *start_node, *end_node, *final_path[ROW*COL];  // initial and end nodes
Node *open_set[ROW*COL],*closed_set[ROW*COL],*tmp_set[ROW*COL]; // open, closed and tmp arrays
int open_size, closed_size, tmp_size, total_hops;
int grid[ROW][COL];  // The grid for pathfinding

// function to check if the node is in the closed set
bool closed_set_contains(Node *check_node){
    for(int i=0;i<closed_size;i++)
        if(closed_set[i]==check_node) return true;
    return false;
}

// function to check if the node is in the open set and return its index
// return -1 if not found
int open_set_contains(Node *check_node){
    for(int i=0;i<open_size;i++)
        if(open_set[i]==check_node) return i;
    return -1;
}

// function to get the h_value(manhattan distance) between a node and the end node
int get_h_value(Node *current){
    return abs(current->row-end_node->row)+abs(current->col-end_node->col);
}

// function to expand a node to the neighbours
void expand_node(Node *current){
    for(int i=0;i<4;i++){  // There are potentially 4 neighbours
        Node *neighbor = (Node*) malloc(sizeof(Node));  // Create the neighbor node
        neighbor->row = current->row + row_delta[i];
        neighbor->col = current->col + col_delta[i];
        if(neighbor->row <0 || neighbor->col<0 || neighbor->row>=ROW || neighbor->col>=COL) {
            free(neighbor);  // if its not within grid size free it
            continue;
        }
        if(grid[neighbor->row][neighbor->col] == 1){ // if the neighbor is a wall (1) free it
            free(neighbor);
            continue;
        }
        neighbor->g = current->g + 1;  // set the g value of the neighbor
        neighbor->h = get_h_value(neighbor);  // set the h value of the neighbor
        neighbor->f = neighbor->g + neighbor->h; // set the f value of the neighbor
        neighbor->parent = current;  // set the parent of the neighbor to the current node
        if(closed_set_contains(neighbor)) { // if the neighbor is already in the closed set free it
            free(neighbor);
            continue;
        }
        int idx = open_set_contains(neighbor); // check if the neighbor is in the open set and get its index
        if(idx==-1){
            open_set[open_size++] = neighbor; // add the neighbor to the open set
        }
        else{
            if(neighbor->g < open_set[idx]->g){  // if the current path has lesser g value than old path to the same node
                open_set[idx] = neighbor;   // Update the neighbor node and set its parent as the current node
            }
            else{
                free(neighbor);  // if the existing path is shorter free the new node
                continue;
            }
        } 
    }
}

// function to get the final path and print it
void print_final_path(Node *current){
    if(current == start_node) { // if the parent node is the start node
        final_path[total_hops] = current;
        printf("\nFinal Path:\n");
        for(int i=total_hops;i>=0;i--){
            printf("[%d][%d]\n",final_path[i]->row, final_path[i]->col);
        }
        printf("\nTotal Hops: %d\n",total_hops);
        return;
    }
    final_path[total_hops--] = current;
    print_final_path(current->parent); // recursively call the function for the parent node
}

int main(void) {
    // initialize the grid
    for(int i=0;i<ROW*COL;i++){
        int val;
        do{
            val = rand()%3 - 1;
        }while(val>0);
        grid[i/COL][i%COL]=val==0?0:1;
    }
    // initialize the start_node and end_node
    start_node = (Node*) malloc(sizeof(Node));
    end_node = (Node*) malloc(sizeof(Node));
    start_node->row = 0, start_node->col = 0;
    end_node->row = 9, end_node->col = 9;
    start_node->g = start_node->h = start_node->f = 0;
    start_node->parent = NULL;
    open_set[open_size++] = start_node;
    while(open_size>0){ // keep running till you reach the end node or there is no path
        Node *current = open_set[0];  // get the node from the open set with the lowest f value
        for(int i=0;i<open_size-1;i++)
            open_set[i] = open_set[i+1];
        open_size--;
        closed_set[closed_size++] = current; // add the current node to the closed set
        if(current == end_node){ // if the current node is the final node, get the final path
            total_hops = current->g; // set the number of hops taken
            print_final_path(current);
            break;
        }
        // Expand the current node
        expand_node(current);
    }
    // free the memory
    for(int i=0;i<closed_size;i++) free(closed_set[i]);
    for(int i=0;i<open_size;i++) free(open_set[i]);

    return 0;
}