//FormAI DATASET v1.0 Category: Graph representation ; Style: introspective
#include<stdio.h>

int main(){

    //Declare a 2D array to represent the graph
    int graph[5][5] = {
                        {0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 0},
                        {0, 1, 0, 1, 1},
                        {1, 1, 1, 0, 1},
                        {0, 0, 1, 1, 0}
                      };

    printf("  A B C D E\n");
    printf("  ---------\n");

    //Iterate over the 2D array to print the graph
    for(int i=0;i<5;i++){
        printf("%c|", 65+i);
        for(int j=0;j<5;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}