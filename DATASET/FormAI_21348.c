//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define ROWS 5
#define COLS 8

//Structure to hold the details of each node
typedef struct 
{
    int x,y; //Coordinate values
    float f,g,h; //Distance variables
    bool obstacle; 
    struct Node *parent; //Parent node for pathfinding
} Node;

Node map[ROWS][COLS]; //2D grid to represent map

//Function to compute the Euclidian distance between two nodes
float distance(Node *start_node, Node *end_node)
{
    float x1 = start_node->x;
    float y1 = start_node->y;
    float x2 = end_node->x;
    float y2 = end_node->y;
    
    float dx = x2 - x1;
    float dy = y2 - y1;
    
    return sqrt((dx*dx) + (dy*dy));
}

//Function to check if the given node is a valid neighbor
bool is_valid_node(Node *node, int row, int col)
{
    if(row < 0 || row >= ROWS)
        return false;
    if(col < 0 || col >= COLS)
        return false;
    if(map[row][col].obstacle)
        return false;
    if(map[row][col].x == node->x && map[row][col].y == node->y)
        return false;
    
    return true;
}

//Function to find neighbors of the given node
//Each node can have up to 8 neighbors
int get_neighbors(Node *node, Node **neighbors)
{
    int count = 0;
    
    for(int row = -1; row <= 1; row++)
    {
        for(int col = -1; col <= 1; col++)
        {
            if(!is_valid_node(node, node->x + row, node->y + col))
                continue;
            neighbors[count++] = &map[node->x + row][node->y + col];
        }
    }
    
    return count;
}

//Function to find the optimal path using A* algorithm
bool find_path(Node *start, Node *end, Node **path, int *length)
{
    //Check if start and end nodes are valid
    if(start == NULL || end == NULL)
        return false;
    
    //Initialize the open and closed lists
    Node *open[ROWS*COLS];
    Node *closed[ROWS*COLS];
    int open_count = 0;
    int closed_count = 0;
    
    //Add start node to the open list
    start->g = 0;
    start->h = distance(start, end);
    start->f = start->g + start->h;
    start->parent = NULL;
    open[open_count++] = start;
    
    //Loop until the open list is empty
    while(open_count > 0)
    {
        //Find the node with the lowest f value
        int current_index = 0;
        float current_f = open[0]->f;
        
        for(int i = 1; i < open_count; i++)
        {
            float f = open[i]->f;
            if(f < current_f)
            {
                current_index = i;
                current_f = f;
            }
        }
        
        Node *current = open[current_index];
        
        //Check if current node is the end node
        if(current == end)
        {
            //Construct the path from start to end
            *length = 0;
            Node *temp = current;
            while(temp != NULL)
            {
                (*length)++;
                temp = temp->parent;
            }
            
            *path = (Node*)malloc(sizeof(Node) * (*length));
            
            temp = current;
            for(int i = (*length) - 1; i >= 0; i--)
            {
                (*path)[i] = *temp;
                temp = temp->parent;
            }
            
            return true;
        }
        
        //Move current node from open to closed list
        open[current_index] = open[--open_count];
        closed[closed_count++] = current;
        
        //Find the neighbors of the current node and update their distances
        Node* neighbors[8];
        int count = get_neighbors(current, neighbors);
        
        for(int i = 0; i < count; i++)
        {
            Node *neighbor = neighbors[i];
            
            //Check if neighbor is in the closed list
            bool in_closed = false;
            for(int j = 0; j < closed_count; j++)
            {
                if(closed[j] == neighbor)
                {
                    in_closed = true;
                    break;
                }
            }
            
            if(in_closed)
                continue;
            
            //Compute the distance from start node to neighbor node
            float tent_g = current->g + distance(current, neighbor);
            
            //Check if neighbor is in the open list
            bool in_open = false;
            for(int j = 0; j < open_count; j++)
            {
                if(open[j] == neighbor)
                {
                    in_open = true;
                    break;
                }
            }
            
            if(!in_open || tent_g < neighbor->g)
            {
                neighbor->parent = current;
                neighbor->g = tent_g;
                neighbor->h = distance(neighbor, end);
                neighbor->f = neighbor->g + neighbor->h;
                
                if(!in_open)
                    open[open_count++] = neighbor;
            }
        }
    }
    
    return false;
}

//Main function to test the A* pathfinding algorithm
int main()
{
    //Initialize map with obstacle nodes
    int obstacles[][2] = {{1,1},{1,2},{1,3},{2,3},{3,3},{3,4},{3,5},{4,5},{0,6},{1,6}};
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            bool obstacle = false;
            for(int i = 0; i < sizeof(obstacles) / sizeof(obstacles[0]); i++)
            {
                int *coord = obstacles[i];
                if(coord[0] == row && coord[1] == col)
                {
                    obstacle = true;
                    break;
                }
            }
            map[row][col].x = row;
            map[row][col].y = col;
            map[row][col].obstacle = obstacle;
        }
    }
    
    //Print the map
    printf("Map:\n");
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            if(map[row][col].obstacle)
                printf("X ");
            else
                printf(". ");
        }
        
        printf("\n");
    }
    
    //Find path from start to end nodes
    Node *start = &map[0][0];
    Node *end = &map[ROWS-1][COLS-1];
    
    Node *path;
    int length;
    
    if(find_path(start, end, &path, &length))
    {
        //Print the path
        printf("Path:\n");
        for(int row = 0; row < ROWS; row++)
        {
            for(int col = 0; col < COLS; col++)
            {
                bool in_path = false;
                for(int i = 0; i < length; i++)
                {
                    Node *temp = &path[i];
                    if(temp->x == row && temp->y == col)
                    {
                        in_path = true;
                        break;
                    }
                }
                if(in_path)
                    printf("+ ");
                else if(map[row][col].obstacle)
                    printf("X ");
                else
                    printf(". ");
            }
        
            printf("\n");
        }
    }
    else
    {
        printf("No path found\n");
    }
    
    return 0;
}