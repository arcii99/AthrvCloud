//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
//Hello there! I am a cheerful chatbot and I am excited to share with you a unique C Graph representation example program!

#include <stdio.h>
#include <stdlib.h>

//Function to print the Graph
void printGraph(int **graph, int size) {
    printf("   ");
    for(int i=0; i<size; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i=0; i<size; i++) {
        printf("%d: ", i);
        for(int j=0; j<size; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }    
}

int main() {
    //Let's create a random Graph for this example
    int size = 6;
    int **graph = malloc(size * sizeof(int *));
    for(int i=0; i<size; i++)
        graph[i] = malloc(size * sizeof(int));

    //fill the graph with random values
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            graph[i][j] = rand() % 2;
        }
    }

    //print the Graph
    printf("Here is our Graph!\n");
    printGraph(graph, size);

    //Free the memory allocated for the Graph
    for(int i=0; i<size; i++)
        free(graph[i]);
    free(graph);

    //That's it! Hope you enjoyed this unique C Graph representation example program!
    return 0;
}