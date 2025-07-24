//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#define ROW 5
#define COL 6
#define INF 1000000

int graph[ROW][COL] = {{0, 5, INF, 10, INF, INF},
                        {INF, 0, 3, INF, INF, INF},
                        {INF, INF, 0, INF, 1, INF},
                        {INF, INF, INF, 0, INF, 5},
                        {INF, INF, INF, INF, 0, INF}};
 
int dist[ROW];
int path[ROW];

void dijkstra(int start){
    int visited[ROW];
    int count, min_dist, next_node, i, j;
    // initialize dist and visited for the algorithm
    for(i=0;i<ROW;i++){
        dist[i] = graph[start][i];
        visited[i] = 0;
        path[i] = start;
    }
    dist[start] = 0;
    visited[start] = 1;
    count = 1;
    // dijkstra's algorithm
    while(count < ROW-1){
        min_dist = INF;
        for(i=0;i<ROW;i++){
            if(dist[i] < min_dist && !visited[i]){
                min_dist = dist[i];
                next_node = i;
            }
        }
        visited[next_node] = 1;
        for(i=0;i<ROW;i++){
            if(!visited[i]){
                if(min_dist+graph[next_node][i] < dist[i]){
                    dist[i] = min_dist + graph[next_node][i];
                    path[i] = next_node;
                }
            }
        }
        count++;
    }
    // print shortest path from start to each vertex
    for(i=0;i<ROW;i++){
        if(i != start){
            printf("\nShortest path from %d to %d is %d", start, i, dist[i]);
            printf("\nPath: %d", i);
            j = i;
            do{
                j = path[j];
                printf("<-%d", j);
            }while(j != start);
        }
    }
}
 
int main(){
    int start_node = 1;
    dijkstra(start_node);
    return 0;
}