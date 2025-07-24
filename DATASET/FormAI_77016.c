//FormAI DATASET v1.0 Category: Graph representation ; Style: accurate
#include<stdio.h> 

int main() { 

    int V = 5; 
    int adj_mat[5][5] = { {0, 1, 0, 1, 1}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}, {1, 1, 1, 0, 1}, {1, 0, 0, 1, 0} }; 

    printf("The Adjacency Matrix Representation of the Graph is:\n"); 

    for(int i = 0; i < V; i++) { 
        for(int j = 0; j < V; j++) 
            printf("%d ", adj_mat[i][j]); 

        printf("\n"); 
    } 

    printf("The Graphical Representation of the Graph is:\n"); 

    for(int i = 0; i < V; i++) { 

        for(int j = 0; j < V; j++) { 

            if(adj_mat[i][j] == 1) 
                printf("     |      "); 

            else 
                printf("           "); 
        } 

        printf("\n"); 

        for(int j = 0; j < V; j++) { 

            if(adj_mat[i][j] == 1) 
                printf("    __     "); 

            else 
                printf("           "); 
        } 

        printf("\n"); 
    } 

    return 0; 
}