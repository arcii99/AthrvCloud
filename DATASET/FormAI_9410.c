//FormAI DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_NODE 10

struct Node{
    int id;
    int weight;
    struct Node* next;
};

struct Graph{
    struct Node* head[MAX_NODE];
    int node_count;
    int edge_count;
    bool visited[MAX_NODE];
};

void init_graph(struct Graph* G){
    G->node_count = 0;
    G->edge_count = 0;
    for(int i=0; i<MAX_NODE; i++){
        G->head[i] = NULL;
    }
    for(int i=0; i<MAX_NODE; i++){
        G->visited[i] = false;
    }
}

void add_node(struct Graph* G){
    G->node_count++;
}

void add_edge(struct Graph* G, int source, int destination, int weight){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->id = destination;
    new_node->weight = weight;
    new_node->next = G->head[source];
    G->head[source] = new_node;
    G->edge_count++;
}

void print_graph(struct Graph* G){
    printf("Number of nodes: %d\n", G->node_count);
    printf("Number of edges: %d\n", G->edge_count);
    for(int i=0; i<MAX_NODE; i++){
        if(G->head[i] != NULL){
            struct Node* temp = G->head[i];
            while(temp != NULL){
                printf("(%d, %d, %d) ", i, temp->id, temp->weight);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

void dfs(struct Graph* G, int node_id){
    printf("%d ", node_id);
    G->visited[node_id] = true;
    struct Node* temp = G->head[node_id];
    while(temp != NULL){
        int next_node = temp->id;
        if(!G->visited[next_node]){
            dfs(G, next_node);
        }
        temp = temp->next;
    }
}

void* dfs_thread(void* threadarg){
    struct Graph* G;
    G = (struct Graph*) threadarg;
    printf("DFS result: ");
    dfs(G, 0);
    printf("\n");
    pthread_exit(NULL);
}

int get_random(int min, int max){
    return rand() % (max - min + 1) + min;
}

void generate_random_graph(struct Graph* G){
    srand(time(NULL));
    int node_count = get_random(5, MAX_NODE);
    int edge_count = get_random(node_count-1, (node_count*(node_count-1))/2);
    G->node_count = node_count;
    for(int i=0; i<edge_count; i++){
        int source = get_random(0, node_count-1);
        int destination = get_random(0, node_count-1);
        int weight = get_random(1, 10);
        add_edge(G, source, destination, weight);
    }
}

int main(){
    struct Graph G;
    init_graph(&G);
    generate_random_graph(&G);
    print_graph(&G);

    pthread_t thread;
    pthread_create(&thread, NULL, dfs_thread, (void*) &G);
    pthread_join(thread, NULL);

    return 0;
}