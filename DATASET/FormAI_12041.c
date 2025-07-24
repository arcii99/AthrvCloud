//FormAI DATASET v1.0 Category: Graph representation ; Style: standalone
#include <stdio.h>

int main() {
    int matrix[5][5] = {{1,0,0,0,0},
                        {0,1,0,0,0},
                        {0,0,1,0,0},
                        {0,0,0,1,0},
                        {0,0,0,0,1}};
    printf("Graph Representation:\n");
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(matrix[i][j] == 1)
                printf("Vertex %d -> Vertex %d\n",i+1,j+1);   
        }
    }
    return 0;
}