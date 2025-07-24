//FormAI DATASET v1.0 Category: Graph representation ; Style: automated
#include<stdio.h>

//Function to add an edge to the graph
void add_edge(int graph[][5], int vertex1, int vertex2){
    graph[vertex1][vertex2] = 1;
    graph[vertex2][vertex1] = 1;
}

//Function to print the adjacency matrix representation of the graph
void print_graph(int graph[][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
}

//Main function
int main(){

    //Creating a graph
    int graph[5][5] = {
                        {0, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1},
                        {1, 0, 0, 0, 1},
                        {0, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}
                    };

    //Printing the graph
    printf("Adjacency matrix representation of the graph:\n");
    print_graph(graph);

    //Adding an edge to the graph
    add_edge(graph, 2, 3);

    //Printing the graph after adding the edge
    printf("\nAdjacency matrix representation of the graph after adding an edge between vertex 2 and vertex 3:\n");
    print_graph(graph);

    return 0;
}