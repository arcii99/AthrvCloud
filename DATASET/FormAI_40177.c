//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NODE_COUNT 100
#define MAX_LINK_COUNT 500

// node structure to store information about each node
struct node {
    char name[20];
    int id;
    int x, y; // coordinates of the node in the map
};

// link structure to store information about each link
struct link {
    int from_node_id, to_node_id;
    int weight; // link weight
    int is_directed; // 1 if the link is directed, 0 otherwise
};

// network map structure to store all nodes and links
struct network_map {
    struct node nodes[MAX_NODE_COUNT];
    struct link links[MAX_LINK_COUNT];
    int node_count;
    int link_count;
};

// function to add a new node to the map
int add_node(struct network_map* map, char* name, int x, int y) {
    if(map->node_count >= MAX_NODE_COUNT) {
        printf("Maximum node count reached!\n");
        return -1;
    }

    struct node* new_node = &(map->nodes[map->node_count]);
    strcpy(new_node->name, name);
    new_node->id = map->node_count;
    new_node->x = x;
    new_node->y = y;

    (map->node_count)++;
    return new_node->id;
}

// function to add a new link between two nodes
void add_link(struct network_map* map, int from_node_id, int to_node_id, int weight, int is_directed) {
    if(map->link_count >= MAX_LINK_COUNT) {
        printf("Maximum link count reached!\n");
        return;
    }

    struct link* new_link = &(map->links[map->link_count]);
    new_link->from_node_id = from_node_id;
    new_link->to_node_id = to_node_id;
    new_link->weight = weight;
    new_link->is_directed = is_directed;

    (map->link_count)++;
}

// function to print the network map
void print_network_map(struct network_map* map) {
    printf("Nodes:\n");
    for(int i=0; i<map->node_count; i++) {
        struct node* n = &(map->nodes[i]);
        printf("%d. %s (%d, %d)\n", n->id, n->name, n->x, n->y);
    }

    printf("\nLinks:\n");
    for(int i=0; i<map->link_count; i++) {
        struct link* l = &(map->links[i]);
        printf("%d to %d (weight=%d, %s)\n", l->from_node_id, l->to_node_id, l->weight, l->is_directed ? "directed" : "undirected");
    }
}

// main function to test the network mapper
int main() {
    struct network_map map = {0};

    int n1 = add_node(&map, "Node 1", 0, 0);
    int n2 = add_node(&map, "Node 2", 50, 50);
    int n3 = add_node(&map, "Node 3", -10, 20);

    add_link(&map, n1, n2, 10, 0); // undirected link between Node 1 and Node 2 with weight 10
    add_link(&map, n2, n3, 20, 1); // directed link from Node 2 to Node 3 with weight 20

    print_network_map(&map);
    return 0;
}