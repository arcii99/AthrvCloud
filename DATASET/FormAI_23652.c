//FormAI DATASET v1.0 Category: Graph representation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTICES 100

//Structure of a vertex
typedef struct vertex {
    int value;
    char color;
} vertex;

//Queue node structure
typedef struct queue_node {
    int value;
    struct queue_node *next;
} queue_node;

//Queue structure
typedef struct queue {
    queue_node *front;
    queue_node *rear;
} queue;

//Initialize vertex
vertex* initialize_vertex(int value) {
    vertex *new_vertex = (vertex*)malloc(sizeof(vertex));
    new_vertex->value = value;
    new_vertex->color = 'w'; //Initially, set the color to white
    return new_vertex;
}

//Initialize a queue
queue* initialize_queue() {
    queue *new_queue = (queue*)malloc(sizeof(queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

//Check if the queue is empty
bool is_queue_empty(queue* q) {
    return (q->front == NULL);
}

//Enqueue an element into the queue
void enqueue(queue *q, int value) {
    queue_node *new_node = (queue_node*)malloc(sizeof(queue_node));
    new_node->value = value;
    new_node->next = NULL;
    if(q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

//Dequeue an element from the front of the queue
int dequeue(queue *q) {
    if(is_queue_empty(q)) {
        return -1;
    }
    int value = q->front->value;
    queue_node *temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

//Check if the graph is cyclic
bool is_cyclic(int graph[][MAX_VERTICES], vertex **vertices, int num_vertices) {
    queue *q = initialize_queue();
    int indegree[num_vertices];

    //Calculate the indegree of each vertex
    for(int i = 0; i < num_vertices; i++) {
        int current_vertex = vertices[i]->value;
        indegree[i] = 0;
        for(int j = 0; j < num_vertices; j++) {
            if(graph[j][i] == 1) {
                indegree[i]++;
            }
        }
    }

    //Initially, enqueue all the vertices with indegree 0
    for(int i = 0; i < num_vertices; i++) {
        if(indegree[i] == 0) {
            enqueue(q, vertices[i]->value);
        }
    }

    //Keep dequeuing the vertices and updating the indegree of neighboring vertices
    int visited = 0;
    while(!is_queue_empty(q)) {
        int current_vertex = dequeue(q);
        visited++;
        for(int i = 0; i < num_vertices; i++) {
            if(graph[current_vertex][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    enqueue(q, vertices[i]->value);
                }
            }
        }
    }

    //If all the vertices have been visited, the graph is acyclic
    if(visited == num_vertices) {
        return false;
    }
    else { //If not, the graph is cyclic
        return true;
    }
}

int main() {
    int num_vertices, num_edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &num_vertices, &num_edges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    vertex **vertices = (vertex**)malloc(num_vertices * sizeof(vertex*));
    printf("Enter the vertices:\n");
    for(int i = 0; i < num_vertices; i++) {
        int value;
        scanf("%d", &value);
        vertices[i] = initialize_vertex(value);
    }
    printf("Enter the edges:\n");
    for(int i = 0; i < num_edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        graph[start][end] = 1;
    }

    bool is_graph_cyclic = is_cyclic(graph, vertices, num_vertices);
    if(is_graph_cyclic) {
        printf("The graph is cyclic\n");
    }
    else {
        printf("The graph is acyclic\n");
    }
    return 0;
}