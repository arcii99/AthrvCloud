//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define MAX_NODES 100
#define MAX_EDGES_PER_NODE 10

int number_of_nodes;
int graph[MAX_NODES][MAX_EDGES_PER_NODE];
int visited[MAX_NODES];
int distance[MAX_NODES];

void print_graph(){
    printf("----- Network Topology Map -----\n");
    for(int i=0;i<number_of_nodes;i++){
        printf("[%d]",i+1);
        for(int j=0;j<MAX_EDGES_PER_NODE;j++){
            if(graph[i][j]!=0){
                printf(" -> [%d]",graph[i][j]);
            }else{
                break;
            }
        }
        printf("\n");
    }
}

void add_edge(int a, int b){
    for(int i=0;i<MAX_EDGES_PER_NODE;i++){
        if(graph[a][i]==0){
            graph[a][i]=b;
            break;
        }
    }
}

void create_sample_topology(){
    add_edge(0,2);
    add_edge(0,3);
    add_edge(1,2);
    add_edge(1,3);
    add_edge(2,0);
    add_edge(2,1);
    add_edge(2,3);
    add_edge(3,0);
    add_edge(3,1);
    add_edge(3,2);
    number_of_nodes=4;
}

void reset_visited_and_distance(){
    for(int i=0;i<number_of_nodes;i++){
        visited[i]=0;
        distance[i]=-1;
    }
}

void bfs(int start_node){
    reset_visited_and_distance();
    visited[start_node]=1;
    distance[start_node]=0;
    printf("BFS from Node [%d]\n",start_node+1);
    printf("------------------------------\n");
    printf("Node\t\tDistance\n");
    printf("------------------------------\n");
    printf("[%d]\t\t[%d]\n",start_node+1,distance[start_node]);
    int queue[MAX_NODES],head=0,tail=0;
    queue[tail++]=start_node;
    while(head<tail){
        int current_node=queue[head++];
        for(int i=0;i<MAX_EDGES_PER_NODE;i++){
            int neighbour=graph[current_node][i];
            if(neighbour==0){
                break;
            }
            if(!visited[neighbour]){
                visited[neighbour]=1;
                distance[neighbour]=distance[current_node]+1;
                printf("[%d]\t\t[%d]\n",neighbour+1,distance[neighbour]);
                queue[tail++]=neighbour;
            }
        }
    }
    printf("------------------------------\n");
}

void dfs(int current_node){
    visited[current_node]=1;
    printf("[%d] ",current_node+1);
    for(int i=0;i<MAX_EDGES_PER_NODE;i++){
        int neighbour=graph[current_node][i];
        if(neighbour==0){
            break;
        }
        if(!visited[neighbour]){
            dfs(neighbour);
        }
    }
}

void run_dfs(){
    reset_visited_and_distance();
    printf("DFS on Network Topology Map\n------------------------------\n");
    for(int i=0;i<number_of_nodes;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    printf("\n------------------------------\n");
}

int main(){
    create_sample_topology();
    print_graph();
    bfs(2);
    run_dfs();
    return 0;
}