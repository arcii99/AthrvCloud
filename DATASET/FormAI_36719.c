//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

int main() {
    printf("Greetings user, welcome to the happy graph program!\n");
    printf("We will now create a graph representation using an adjacency matrix!\n");

    int n;
    printf("Please enter the number of nodes in the graph:\n");
    scanf("%d", &n);

    int i, j;
    int graph[n][n];

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Great, now let's add edges to the graph!\n");
    printf("Enter -1 to stop adding edges.\n");

    int source, destination;
    int count = 1;

    while(1) {
        printf("Enter source node for edge %d:\n", count);
        scanf("%d", &source);

        if(source == -1) {
            break;
        }

        printf("Enter destination node for edge %d:\n", count);
        scanf("%d", &destination);

        if(destination == -1) {
            break;
        }

        if(source >= n || destination >= n) {
            printf("Invalid input, please try again.\n");
            continue;
        }

        graph[source][destination] = 1;
        count++;
    }

    printf("Thank you for adding edges to the graph! Here is the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("Yay! We have successfully created a graph representation using an adjacency matrix!\n");
    printf("Have a great day ahead!\n");

    return 0;
}