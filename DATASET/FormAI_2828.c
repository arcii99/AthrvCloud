//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define ROW 10
#define COL 10

int graph[ROW][COL] = {
    {0, 8, 2, 10, 5},
    {8, 0, 6, 4, 11},
    {2, 6, 0, 7, 7},
    {10, 4, 7, 0, 3},
    {5, 11, 7, 3, 0}
};

int visited[ROW];
int distance[ROW];
int parent[ROW];

void dijkstra(int source) {
    for(int i=0; i<ROW; i++) {
        visited[i] = 0;
        distance[i] = INT_MAX; //Setting initial distance to infinity.
        parent[i] = -1;
    }

    distance[source] = 0;

    for(int i=0; i<ROW-1; i++) {
        int min = INT_MAX, min_index;
        for(int j=0; j<ROW; j++) {
            if(visited[j]==0 && distance[j] < min) {  //Finding minimum distance vertex
                min = distance[j];
                min_index = j;
            }
        }

        visited[min_index] = 1;

        for(int k=0; k<ROW; k++) {
            if(graph[min_index][k] && visited[k]==0 && (distance[min_index] + graph[min_index][k]) < distance[k]) {  //Updating neighboring vertices' distances
                distance[k] = distance[min_index] + graph[min_index][k];
                parent[k] = min_index;
            }
        }
    }
}

int main() {
    int source = 0;
    dijkstra(source);

    printf("Vertex\t Distance\t Path");

    for(int i=0; i<ROW; i++) {
        if(i!=source) {
            printf("\n%d -> %d\t\t %d\t\t%d", source, i, distance[i], source);
            int j = i;
            do {
                j = parent[j];
                printf("->%d", j);
            }while(j != source);
        }
    }

    return 0;
}