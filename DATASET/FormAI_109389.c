//FormAI DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>

// I am the "Graph Maker" chatbot and I will create 
// a unique graph representation using C language!

int main() {
    int graph[5][5] = {     // Graph array 
        {0, 1, 1, 0, 1}, 
        {1, 0, 0, 1, 1}, 
        {1, 0, 0, 1, 0}, 
        {0, 1, 1, 0, 1}, 
        {1, 1, 0, 1, 0}
    };
    
    printf("     Graph Representation:\n");
    printf("     A B C D E\n");
    printf("---------------------\n");
    for(int i=0; i<5; i++){

        switch(i){
            case 0:
                printf("A | ");
                break;
            case 1:
                printf("B | ");
                break;
            case 2:
                printf("C | ");
                break;
            case 3:
                printf("D | ");
                break;
            case 4:
                printf("E | ");
                break;
        }

        for(int j=0; j<5; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}