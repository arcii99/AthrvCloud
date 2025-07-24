//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 10

char nodes[MAX_NODES][MAX_NAME_LENGTH];
int node_index = 0;

struct Component {
    char name[MAX_NAME_LENGTH];
    int n1, n2;
    double complex value;
} components[MAX_NODES];

int component_index = 0;

void add_node(char *node_name) {
    for(int i=0; i<node_index; i++){
        if(strcmp(nodes[i], node_name) == 0){
            return;
        }
    }
    strcpy(nodes[node_index], node_name);
    node_index++;
}

int get_node_index(char *node_name){
    for(int i=0; i<node_index; i++){
        if(strcmp(nodes[i], node_name) == 0){
            return i;
        }
    }
    return -1;
}

void add_component(char *command) {
    char *component_type = strtok(NULL, " ");
    char *node1 = strtok(NULL, " ");
    char *node2 = strtok(NULL, " ");
    double complex value;
    sscanf(command, "%*s %*s %*s %*s %lf", &value);
    components[component_index].n1 = get_node_index(node1);
    components[component_index].n2 = get_node_index(node2);
    components[component_index].value = value;
    strcpy(components[component_index].name, component_type);
    component_index++;
    add_node(node1);
    add_node(node2);
}

double complex calculate_resistance(int i, double complex freq){
    double complex r = components[i].value;
    return r;
}

int main() {
    char command[MAX_NODES];
    while (1) {
        scanf("%[^\n]", command);
        getchar();
        if (strcmp(command, "exit") == 0) {
            break;
        }
        add_component(command);
    }

    printf("\nNodes:");
    for(int i=0; i<node_index; i++){
        printf("%s ", nodes[i]);
    }
    printf("\n\n");

    printf("Components:\n");
    for(int i=0; i<component_index; i++){
        printf("%s %d %d %lf\n", components[i].name, components[i].n1, components[i].n2, creal(components[i].value));
    }
    printf("\n");

    return 0;
}