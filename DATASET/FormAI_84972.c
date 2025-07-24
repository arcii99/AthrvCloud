//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Defining a struct of colors
typedef struct colors {
    char* name;
    int available;
}color;

int main() {
    //Initializing random number generator
    srand(time(0));
    
    //Number of vertices in the graph
    int n = 10;
    
    //Creating a graph with n vertices
    int graph[n][n];
    
    //Initializing the graph with 0s and 1s randomly
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            graph[i][j] = rand()%2;
        }
    }
    
    //Creating a struct of colors with color names and availability status
    color colors[5] = {
        {"Red", 1},
        {"Green", 1},
        {"Blue", 1},
        {"Yellow", 1},
        {"Purple", 1}
    };
    
    //Assigning colors to vertices in the graph
    for(int i=0; i<n; i++) {
        //Checking if any color is available
        int available_colors = 0;
        for(int j=0; j<5; j++) {
            if(colors[j].available == 1) {
                available_colors++;
            }
        }
        
        //If no color is available, print a surprised message and exit
        if(available_colors == 0) {
            printf("Oh no! There are no colors available!\n");
            printf("This graph cannot be colored!\n");
            exit(0);
        }
        
        //Choosing a random available color and assigning it to the vertex
        int color_index = rand()%5;
        while(colors[color_index].available == 0) {
            color_index = rand()%5;
        }
        printf("Assigning %s color to vertex %d\n", colors[color_index].name, i+1);
        colors[color_index].available = 0;
    }
    
    //Printing the colored graph
    printf("\nColored Graph:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    //Printing the available colors
    printf("\nAvailable Colors:\n");
    for(int j=0; j<5; j++) {
        if(colors[j].available == 1) {
            printf("%s\n", colors[j].name);
        }
    }
    
    return 0;
}