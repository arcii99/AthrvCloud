//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//Structure to store details of each node
struct node{
    char name[20];
    int num_links;
    char links[MAX][20];
    int visited; // Used to keep track of nodes visited during traversal
};

struct node t[MAX]; // Array to store all nodes in network

int n; //Total number of nodes in network
int connected[MAX][MAX]; // to store topology information

// Function to setup network for traversals -
// Initializes all nodes with null values and sets visited flag to 0
void setup_network(){
    for(int i = 0; i < MAX; i++){
        t[i].name[0] = '\0';
        t[i].num_links = 0;
        for(int j = 0; j < MAX; j++){
            connected[i][j] = 0;
        }
        t[i].visited = 0; 
    }
    n = 0;
}

// Utility function to add a node to the network
void add_node(char* name){
    strcpy(t[n].name, name);
    n++;
}

// Utility function to add link between two nodes
void add_link(char* node1, char* node2){
    for(int i = 0; i < n; i++){
        if(strcmp(t[i].name, node1) == 0){
            strcpy(t[i].links[t[i].num_links], node2);
            t[i].num_links++;
        }
        if(strcmp(t[i].name, node2) == 0){
            strcpy(t[i].links[t[i].num_links], node1);
            t[i].num_links++;
        }
    }
}

// Utility function to check if two nodes are connected
int nodes_are_connected(char* node1, char* node2){
    for(int i = 0; i < n; i++){
        if(strcmp(t[i].name, node1) == 0){
            for(int j = 0; j < t[i].num_links; j++){
                if(strcmp(t[i].links[j], node2) == 0){
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Visits all nodes connected to given node 
// and marks them visited using depth-first search
void visit_node(char* node){
    int node_index;
    for(int i = 0; i < n; i++){
        if(strcmp(t[i].name, node) == 0){
            node_index = i;
            break;
        }
    }
    t[node_index].visited = 1;
    for(int i = 0; i < t[node_index].num_links; i++){
        char* linked_node = t[node_index].links[i];
        for(int j = 0; j < n; j++){
            if(strcmp(t[j].name, linked_node) == 0){
                if(!t[j].visited){
                    connected[node_index][j] = connected[j][node_index] = 1;
                    visit_node(linked_node);
                }
            }
        }
    }
}

// Function to generate topology map of entire network
void generate_topology(){
    for(int i = 0; i < n; i++){
        visit_node(t[i].name);
    }
}

//Prints out the topology information
void print_topology(){
    printf("Topology Map:\n");
    printf("|\t");
    for(int i = 0; i < n; i++){
        printf("%s\t|\t", t[i].name);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%s\t|\t", t[i].name);
        for(int j = 0; j < n; j++){
            printf("%d\t|\t", connected[i][j]);
        }
        printf("\n");
    }
}

// Sample network topology
int main(){
    setup_network();
    add_node("Router 1");
    add_node("Switch 1");
    add_node("Server 1");
    add_node("Server 2");
    add_node("Router 2");
    add_node("Switch 2");
    add_link("Router 1", "Switch 1");
    add_link("Switch 1", "Server 1");
    add_link("Switch 1", "Server 2");
    add_link("Switch 1", "Router 2");
    add_link("Router 2", "Switch 2");
    add_link("Switch 2", "Server 1");
    generate_topology();
    print_topology();
    return 0;
}