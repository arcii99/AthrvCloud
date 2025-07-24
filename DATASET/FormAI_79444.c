//FormAI DATASET v1.0 Category: Database querying ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a database record
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Define a struct to represent a node in a decentralized network
typedef struct {
    int node_id;
    char url[100];
} Node;

// Define a function to query a given node for a record with a given id
Record query_node(Node node, int record_id) {
    // In a real implementation, this function would use HTTP or another
    // protocol to query the node's REST API or other interface
    // For simplicity, we'll just return a random record
    Record ret;
    ret.id = record_id;
    strcpy(ret.name, "Alice");
    ret.age = 25;
    return ret;
}

// Define an array of nodes in the network
Node nodes[] = {
    {1, "http://node1.example.com"},
    {2, "http://node2.example.com"},
    {3, "http://node3.example.com"},
};

int main() {
    int record_id = 42;
    Record record;
    int node_index = 0;
    // Loop through each node in the network until we find a node that returns a record
    while (node_index < sizeof(nodes) / sizeof(nodes[0])) {
        record = query_node(nodes[node_index], record_id);
        if (record.id != 0) {
            break;
        }
        node_index++;
    }
    // Print the record we found
    printf("Record found: %d, %s, %d\n", record.id, record.name, record.age);
    return 0;
}