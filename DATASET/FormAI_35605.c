//FormAI DATASET v1.0 Category: Graph representation ; Style: excited
#include <stdio.h>

void printGraph(){
    int graph[6][6] = { // Initializing graph
        { 0, 1, 1, 0, 0, 0 },
        { 1, 0, 1, 1, 0, 0 },
        { 1, 1, 0, 1, 1, 0 },
        { 0, 1, 1, 0, 1, 1 },
        { 0, 0, 1, 1, 0, 1 },
        { 0, 0, 0, 1, 1, 0 }
    };
    
    printf("\n\n  Graph: \n\n");

    // Printing graph
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            printf(" %d", graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("\n\n  Welcome to my C Graph representation program!\n\n");
    printGraph();
    printf("\n\n  Thank you for using my program!\n\n");

    return 0;
}