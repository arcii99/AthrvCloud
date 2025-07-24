//FormAI DATASET v1.0 Category: Graph representation ; Style: happy
#include<stdio.h>

int main(){
    printf("Hello there! Let's draw a happy graph using C language.\n");

    printf("Enter the dimensions of the graph (rows, columns): ");
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int graph[rows][cols];

    printf("Great! Now, let's fill in some happy values for our graph.\n");

    // initialize graph with happy values
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(i%2==0 && j%2==0){
                graph[i][j] = 2; // happy value
            }
            else{
                graph[i][j] = 1; // neutral value
            }
        }
    }

    printf("\nAwesome! Let's take a look at our happy graph: \n\n");

    // print the graph
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(graph[i][j] == 2){
                printf(":)");
            }
            else{
                printf(":|");
            }
        }
        printf("\n");
    }

    printf("\nYay! Our happy graph is complete. Hope you liked it :)\n");

    return 0;
}