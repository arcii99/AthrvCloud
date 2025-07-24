//FormAI DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int tableGame(int**, int**, int**, int, int);

int main() {
    
    int n, m;
    printf("Enter the dimensions of the table game:\n");
    scanf("%d %d", &n, &m);
    
    int **table;
    table = (int**) malloc(n * sizeof(int*));
    int **temp;
    temp = (int**) malloc(n * sizeof(int*));
    int **visited;
    visited = (int**) malloc(n * sizeof(int*));
    
    for(int i=0; i<n; i++){
        table[i] = (int*) malloc(m * sizeof(int));
        temp[i] = (int*) malloc(m * sizeof(int));
        visited[i] = (int*) malloc(m * sizeof(int));
    }
    
    printf("Enter the values of the table game:\n");
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &table[i][j]);
            temp[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    
    int result = tableGame(table, temp, visited, n, m);
    
    printf("The maximum score is: %d", result);
    
    return 0;
    
}

int tableGame(int** table, int** temp, int** visited, int n, int m){
    
    int maxScore = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j] == 0){
        
                visited[i][j] = 1;
                temp[i][j] = table[i][j];
                
                if(i+1<n && visited[i+1][j]==0 && table[i+1][j]==table[i][j]){
                    visited[i+1][j] = 1;
                    temp[i][j] += tableGame(table, temp, visited, n, m);
                    visited[i+1][j] = 0;
                }
                
                if(i-1>=0 && visited[i-1][j]==0 && table[i-1][j]==table[i][j]){
                    visited[i-1][j] = 1;
                    temp[i][j] += tableGame(table, temp, visited, n, m);
                    visited[i-1][j] = 0;
                }
                
                if(j+1<m && visited[i][j+1]==0 && table[i][j+1]==table[i][j]){
                    visited[i][j+1] = 1;
                    temp[i][j] += tableGame(table, temp, visited, n, m);
                    visited[i][j+1] = 0;
                }
                
                if(j-1>=0 && visited[i][j-1]==0 && table[i][j-1]==table[i][j]){
                    visited[i][j-1] = 1;
                    temp[i][j] += tableGame(table, temp, visited, n, m);
                    visited[i][j-1] = 0;
                }
                
                if(temp[i][j] > maxScore)
                    maxScore = temp[i][j];
                    
                temp[i][j] = 0;
                visited[i][j] = 0;
                
            }
        }
    }
    
    return maxScore;
    
}