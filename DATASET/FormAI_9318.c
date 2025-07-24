//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: ephemeral
//Ephemeral Pathfinding Algorithm
//Created by Chatbot

#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10

//Create a grid to act as map
int map[MAX_ROWS][MAX_COLS] = 
{
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

//Define a node in the map
typedef struct node{
    int x;
    int y;
    int visited;
}node;

//Helper function to check if a node is blocked
int is_blocked(int x, int y){
    if(map[x][y] == 1)
        return 1;
    else
        return 0;
}

//Helper function to check if node is out of map bounds
int is_out_of_bounds(int x, int y){
    if(x < 0 || y < 0 || x > MAX_ROWS - 1 || y > MAX_COLS - 1)
        return 1;
    else
        return 0;   
}

//Helper function to check if a node is destination
int is_destination(int x, int y, int endx, int endy){
    if(x == endx && y == endy)
        return 1;
    else
        return 0;
}

//Main pathfinding function
void pathfinding(node current_node, int endx, int endy){
    //Create a stack to store visited nodes
    node stack[MAX_ROWS * MAX_COLS];
    int top = 0;

    //Add current node to stack
    current_node.visited = 1;
    stack[top++] = current_node;

    //Loop while stack is not empty
    while(top > 0){
        //Pop the node at the top of the stack
        node current = stack[--top];
        printf("Current Node: (%d, %d)\n", current.x, current.y);

        //Check if current node is destination
        if(is_destination(current.x, current.y, endx, endy)){
            printf("Destination Found!\n");
            return;
        }

        //Check all adjacent nodes and push them to stack if unvisited and not blocked
        if(!is_out_of_bounds(current.x + 1, current.y) && !is_blocked(current.x + 1, current.y)){
            node adjacent_node = {current.x + 1, current.y, 1};
            if(!adjacent_node.visited){
                adjacent_node.visited = 1;
                stack[top++] = adjacent_node;
            }
        }

        if(!is_out_of_bounds(current.x - 1, current.y) && !is_blocked(current.x - 1, current.y)){
            node adjacent_node = {current.x - 1, current.y, 1};
            if(!adjacent_node.visited){
                adjacent_node.visited = 1;
                stack[top++] = adjacent_node;
            }
        }

        if(!is_out_of_bounds(current.x, current.y + 1) && !is_blocked(current.x, current.y + 1)){
            node adjacent_node = {current.x, current.y + 1, 1};
            if(!adjacent_node.visited){
                adjacent_node.visited = 1;
                stack[top++] = adjacent_node;
            }
        }

        if(!is_out_of_bounds(current.x, current.y - 1) && !is_blocked(current.x, current.y - 1)){
            node adjacent_node = {current.x, current.y - 1, 1};
            if(!adjacent_node.visited){
                adjacent_node.visited = 1;
                stack[top++] = adjacent_node;
            }
        }
    }

    //If destination not found, print error message
    printf("Could not find destination");
}

int main(){

    //Start pathfinding from (0,0) to (9,9)
    node start_node = {0, 0, 0};
    pathfinding(start_node, 9, 9);

    return 0;
}