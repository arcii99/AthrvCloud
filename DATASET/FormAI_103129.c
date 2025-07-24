//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100   //max number of nodes in the network

char *nodes[MAX_NODES];     //array of nodes
int weight[MAX_NODES][MAX_NODES];    //array to store weight of every edge between any two nodes
int num_nodes;      //number of nodes in the network
int num_edges;      //number of edges in the network

void add_node(char *node_name)
{
    if(num_nodes == MAX_NODES)
    {
        printf("Too many nodes in the network!\n");
        return;
    }

    //check if node already exists in the network
    for(int i=0; i<num_nodes; i++)
    {
        if(strcmp(node_name, nodes[i]) == 0)
        {
            printf("Node %s already exists in the network!\n", node_name);
            return;
        }
    }

    nodes[num_nodes] = (char*) malloc(strlen(node_name)+1);  //allocate memory for new node name
    strcpy(nodes[num_nodes], node_name);     //copy the new node name into the nodes array
    num_nodes++;        //increment the number of nodes in the network
}

void add_edge(char *node1, char *node2, int weight_value)
{
    int index1 = -1, index2 = -1;   //store the index position of the two nodes in the node array

    //find the index positions of the two nodes in the node array
    for(int i=0; i<num_nodes; i++)
    {
        if(strcmp(node1, nodes[i]) == 0)
            index1 = i;
        else if(strcmp(node2, nodes[i]) == 0)
            index2 = i;

        //if we have found both nodes, break out of the loop
        if(index1 != -1 && index2 != -1)
            break;
    }

    //if either of the nodes is not in the network, return with error message
    if(index1 == -1 || index2 == -1)
    {
        printf("One or both nodes not found in the network!\n");
        return;
    }

    weight[index1][index2] = weight_value;      //store the weight of the edge in the weight array
    weight[index2][index1] = weight_value;      //store the weight of the edge in the weight array (since the network is undirected)
}

void print_network()
{
    printf("Nodes in the network:\n");
    for(int i=0; i<num_nodes; i++)
        printf("%s\n", nodes[i]);

    printf("\nEdges in the network:\n");
    for(int i=0; i<num_nodes; i++)
    {
        for(int j=i+1; j<num_nodes; j++)    //j starts from i+1 because the network is undirected
        {
            if(weight[i][j] != 0)
                printf("%s <--> %s, weight: %d\n", nodes[i], nodes[j], weight[i][j]);
        }
    }
}

int main()
{
    //initialize the node and weight arrays
    for(int i=0; i<MAX_NODES; i++)
    {
        nodes[i] = NULL;
        for(int j=0; j<MAX_NODES; j++)
            weight[i][j] = 0;
    }

    //add some nodes to the network
    add_node("Router1");
    add_node("Switch1");
    add_node("Server1");
    add_node("Server2");

    //add some edges to the network
    add_edge("Router1", "Switch1", 10);
    add_edge("Switch1", "Server1", 5);
    add_edge("Switch1", "Server2", 8);

    //print the network
    print_network();

    return 0;
}