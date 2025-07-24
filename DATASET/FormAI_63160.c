//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: statistical
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

#define ROW 10 // Rows of the graph
#define COL 10 // Columns of the graph

// Defining a structure to store node coordinates
struct Coordinates{
    int x;
    int y;
};

// Defining a structure to store information of each node of the graph
struct Node{
    int row;
    int col;
    int distance_from_source;
    int is_visited;
    struct Coordinates parent;
};

// Function to calculate minimum distance node from the source
struct Node min_distance_node(struct Node graph[ROW][COL]){
    int min_distance = INT_MAX;
    struct Node node;
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(graph[i][j].distance_from_source < min_distance && !graph[i][j].is_visited){
                node = graph[i][j];
                min_distance = node.distance_from_source;
            }
        }
    }
    return node;
}

// Function to print the shortest path from source to destination node
void print_shortest_path(struct Coordinates destination, struct Node graph[ROW][COL]){
    struct Coordinates path[ROW*COL];
    int i = 0;
    while(destination.x != -1 && destination.y != -1){
        path[i] = destination;
        destination = graph[destination.x][destination.y].parent;
        i++;
    }
    printf("Shortest path from source to destination:\n");
    for(int j=i-1; j>=0; j--){
        printf("(%d,%d) ", path[j].x, path[j].y);
    }
}

// Function to implement Dijkstra's algorithm for pathfinding
void dijkstra_algorithm(struct Node graph[ROW][COL], struct Coordinates source, struct Coordinates destination){
    // Initializing all nodes distances from source to infinity, is_visited flag to 0 and parent coordinates to -1
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            graph[i][j].distance_from_source = INT_MAX;
            graph[i][j].is_visited = 0;
            graph[i][j].parent.x = -1;
            graph[i][j].parent.y = -1;
            graph[i][j].row = i;
            graph[i][j].col = j;
        }
    }

    // Initializing source node distance from source to 0
    graph[source.x][source.y].distance_from_source = 0;

    // Loop until the destination node is visited or all nodes are visited
    while(!graph[destination.x][destination.y].is_visited){
        // Get the minimum distance node from the source
        struct Node current_node = min_distance_node(graph);
        // Mark the current node as visited
        graph[current_node.row][current_node.col].is_visited = 1;

        // Get the neighbors of the current node
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                // Ignore the current node and diagonal neighbors
                if(i==0 && j==0 || i!=0 && j!=0)
                    continue;
                int neighbor_row = current_node.row + i;
                int neighbor_col = current_node.col + j;
                // Ignore the neighbors outside of the graph
                if(neighbor_row<0 || neighbor_col<0 || neighbor_row>=ROW || neighbor_col>=COL)
                    continue;
                // Calculate the distance of the neighbor node from the source
                int distance_from_source = current_node.distance_from_source + 1;
                if(distance_from_source < graph[neighbor_row][neighbor_col].distance_from_source){
                    graph[neighbor_row][neighbor_col].distance_from_source = distance_from_source;
                    // Update the parent coordinates of the neighbor node
                    graph[neighbor_row][neighbor_col].parent.x = current_node.row;
                    graph[neighbor_row][neighbor_col].parent.y = current_node.col;
                }
            }
        }
    }
    // Print the shortest path
    print_shortest_path(destination, graph);
}

// Sample execution of dijkstra_algorithm
int main(){
    // Initializing the graph with values 0 and 1, 1 is the obstacle which can not go through
    int graph[ROW][COL]={
                {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
                {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 1, 0}};

    // Defining the source and destination coordinates
    struct Coordinates source = {0,0}; // source is at (0,0)
    struct Coordinates destination = {9,9}; // destination is at (9,9)

    // Creating a graph with the information of each node
    struct Node my_graph[ROW][COL];
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            my_graph[i][j].distance_from_source = INT_MAX;
            my_graph[i][j].is_visited = 0;
            my_graph[i][j].parent.x = -1;
            my_graph[i][j].parent.y = -1;
            my_graph[i][j].row = i;
            my_graph[i][j].col = j;
            if(graph[i][j] == 1){
                my_graph[i][j].distance_from_source = INT_MAX;
            }
        }
    }

    // Calling Dijkstra's algorithm function
    dijkstra_algorithm(my_graph, source, destination);

    return 0;
}