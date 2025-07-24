//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
#include<stdio.h>

// function to print the graph
void printGraph(int graph[], int size) {

    for(int i=0; i<size; i++) {

        //print the bar for each data point
        printf("%d: ", i);
        for(int j=0; j<graph[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main () {

    // declare and initialize the data
    int data[] = {3, 5, 2, 7, 9, 4, 2, 6, 3, 1};
    int size = sizeof(data) / sizeof(int);

    // find the maximum value in the data
    int max = data[0];
    for(int i=1; i<size; i++) {
        if(data[i] > max) {
            max = data[i];
        }
    }

    // create the graph
    int graph[max+1];
    for(int i=0; i<=max; i++) {
        graph[i] = 0;
    }

    // populate the graph with data
    for(int i=0; i<size; i++) {
        graph[data[i]]++;
    }

    // print the graph
    printf("Here's a cheerful graph:\n");
    printGraph(graph, max+1);

    return 0;
}