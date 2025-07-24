//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include<stdio.h>

#define COLORS 3

int main(){

int n, index, min_conflicts = 99999;

printf("\nEnter the number of nodes in the graph: ");
scanf("%d", &n);

int adjacency_matrix[n][n]; // 2D array for storing the adjacency matrix of the graph
int colors[n]; // array for storing the colors of the nodes

// Accept the adjacency matrix of the graph from the user
printf("\nEnter the adjacency matrix of the graph:\n");
for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        scanf("%d", &adjacency_matrix[i][j]);
    }
}

// Assign random colors to all the nodes in the graph
for(int i = 0; i < n; i++){
    colors[i] = rand() % COLORS;
}

// Run the Min-Conflicts algorithm
for(int i = 0; i < 5000; i++){

    // Select a random node
    index = rand() % n;

    // Calculate the number of conflicts of the selected node
    int conflicts = 0;
    for(int j = 0; j < n; j++){
        if(adjacency_matrix[index][j] == 1 && colors[index] == colors[j])
            conflicts++;
    }

    // Select the color with minimum conflicts for the selected node
    int min_conf_color = colors[index];
    int curr_conflicts;
    for(int j = 0; j < COLORS; j++){
        colors[index] = j;
        curr_conflicts = 0;
        for(int k = 0; k < n; k++){
            if(adjacency_matrix[index][k] == 1 && colors[index] == colors[k])
                curr_conflicts++;
        }
        if(curr_conflicts < conflicts){
            conflicts = curr_conflicts;
            min_conf_color = j;
        }
    }

    // Assign the selected color to the selected node
    colors[index] = min_conf_color;

    // Calculate the total number of conflicts in the graph
    int total_conflicts = 0;
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            if(adjacency_matrix[j][k] == 1 && colors[j] == colors[k])
                total_conflicts++;
        }
    }

    // Update the minimum number of conflicts if a better solution is found
    if(total_conflicts < min_conflicts){
        min_conflicts = total_conflicts;

        // Print the solution
        printf("\nSolution:");
        for(int j = 0; j < n; j++){
            printf("\nThe color of node %d is %d", j + 1, colors[j]);
        }
        printf("\nTotal number of conflicts: %d", min_conflicts);
    }

    // Stop the algorithm if a solution with 0 conflicts is obtained
    if(min_conflicts == 0){
        printf("\n\nOptimal solution found!");
        break;
    }
}

return 0;

}