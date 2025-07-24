//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROW 15
#define COLUMN 20
#define WALL 1
#define PATH 0
#define VISITED 2

typedef struct Node{
    int x;
    int y;
    int parent_x;
    int parent_y;
    float f_cost;
    float g_cost;
    float h_cost;
}Node;

Node start_node, end_node;
Node* open_list[ROW*COLUMN];
Node* closed_list[ROW*COLUMN];
int grid[ROW][COLUMN];

bool is_valid(int x, int y){
    if(x < 0 || y < 0 || x >= ROW || y >= COLUMN){
        return false;
    }
    if(grid[x][y] == WALL){
        return false;
    }
    if(grid[x][y] == VISITED){
        return false;
    }
    return true;
}

void calculate_costs(Node* node){
    node->g_cost = sqrt(pow((node->x - start_node.x), 2) + pow((node->y - start_node.y), 2));
    node->h_cost = sqrt(pow((end_node.x - node->x), 2) + pow((end_node.y - node->y), 2));
    node->f_cost = node->g_cost + node->h_cost;
}

bool is_in_list(Node* node, Node** list, int length){
    for(int i = 0; i < length; i++){
        if(list[i]->x == node->x && list[i]->y == node->y){
            return true;
        }
    }
    return false;
}

void add_to_list(Node* node, Node** list, int* length){
    list[*length] = node;
    (*length)++;
}

Node* get_node_with_min_f_cost(){
    float min_f_cost = INFINITY;
    Node* min_node = NULL;
    for(int i = 0; i < ROW*COLUMN; i++){
        if(open_list[i] != NULL && open_list[i]->f_cost < min_f_cost){
            min_f_cost = open_list[i]->f_cost;
            min_node = open_list[i];
        }
    }
    return min_node;
}

void remove_from_list(Node* node, Node** list, int* length){
    int index;
    for(int i = 0; i < *length; i++){
        if(list[i]->x == node->x && list[i]->y == node->y){
            index = i;
            break;
        }
    }
    for(int i = index; i < *length - 1; i++){
        list[i] = list[i+1];
    }
    (*length)--;
}

void print_path(){
    Node* current = &end_node;
    while(current != NULL && !(current->x == start_node.x && current->y == start_node.y)){
        grid[current->x][current->y] = PATH;
        current = &closed_list[current->parent_x*COLUMN + current->parent_y];
    }
}

void find_path(){
    int open_list_length = 0;
    int closed_list_length = 0;
    add_to_list(&start_node, open_list, &open_list_length);
    while(open_list_length > 0){
        Node* current = get_node_with_min_f_cost();
        if(current == NULL){
            return; // No path found
        }
        if(current->x == end_node.x && current->y == end_node.y){
            print_path();
            return;
        }
        remove_from_list(current, open_list, &open_list_length);
        add_to_list(current, closed_list, &closed_list_length);
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                if(is_valid(current->x + i, current->y + j)){
                    Node* neighbor = &closed_list[(current->x + i)*COLUMN + current->y + j];
                    if(!is_in_list(neighbor, closed_list, closed_list_length)){
                        if(!is_in_list(neighbor, open_list, open_list_length)){
                            neighbor->x = current->x + i;
                            neighbor->y = current->y + j;
                            neighbor->parent_x = current->x;
                            neighbor->parent_y = current->y;
                            calculate_costs(neighbor);
                            add_to_list(neighbor, open_list, &open_list_length);
                        }
                        else{
                            float new_g_cost = current->g_cost + sqrt(pow(i, 2) + pow(j, 2));
                            if(new_g_cost < neighbor->g_cost){
                                neighbor->parent_x = current->x;
                                neighbor->parent_y = current->y;
                                neighbor->g_cost = new_g_cost;
                                neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;
                            }
                        }
                    }
                }
            }
        }
    }
}

void print_map(){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            if(grid[i][j] == WALL){
                printf("#");
            }
            else if(grid[i][j] == PATH){
                printf("*");
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
}

int main(){
    // Initialize grid
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            if(i == 0 || j == 0 || i == ROW - 1 || j == COLUMN - 1){
                grid[i][j] = WALL;
            }
            else{
                grid[i][j] = PATH;
            }
        }
    }
    // Set start and end nodes
    start_node.x = 1;
    start_node.y = 1;
    end_node.x = ROW - 2;
    end_node.y = COLUMN - 2;
    // Find path
    find_path();
    // Print map with path
    print_map();
    return 0;
}