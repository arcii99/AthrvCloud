//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Color Codes */
#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"

#define MAX_VERTICES 10
#define MAX_EDGES 20

/* Graph structure */
struct graph
{
    int vertices[MAX_VERTICES];
    int num_vertices;
    struct edge
    {
        int vertex1;
        int vertex2;
        int color;
    } edges[MAX_EDGES];
    int num_edges;
};

/* Function prototypes */
void initialize_graph(struct graph *g);
void add_vertex(struct graph *g, int vertex);
void add_edge(struct graph *g, int vertex1, int vertex2);
void print_graph(struct graph *g, int result[]);

/* Main function */
int main()
{
    srand(time(NULL));  // Random seed
    printf("%sWelcome to Graph Coloring Problem!%s\n", CYAN, RESET);
    struct graph g;  // Create a graph
    initialize_graph(&g);  // Initialize the graph

    printf("%sAdding vertices...%s\n", MAGENTA, RESET);
    add_vertex(&g, 1);
    add_vertex(&g, 2);
    add_vertex(&g, 3);
    add_vertex(&g, 4);
    add_vertex(&g, 5);
    add_vertex(&g, 6);
    add_vertex(&g, 7);
    add_vertex(&g, 8);
    add_vertex(&g, 9);
    add_vertex(&g, 10);

    printf("%sAdding edges...%s\n", MAGENTA, RESET);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 1, 4);
    add_edge(&g, 1, 5);
    add_edge(&g, 2, 3);
    add_edge(&g, 2, 4);
    add_edge(&g, 2, 6);
    add_edge(&g, 3, 5);
    add_edge(&g, 3, 6);
    add_edge(&g, 4, 5);
    add_edge(&g, 4, 7);
    add_edge(&g, 5, 6);
    add_edge(&g, 5, 7);
    add_edge(&g, 5, 8);
    add_edge(&g, 6, 8);
    add_edge(&g, 7, 8);
    add_edge(&g, 7, 9);
    add_edge(&g, 8, 9);
    add_edge(&g, 9, 10);

    printf("%sPrinting the graph...%s\n", MAGENTA, RESET);
    print_graph(&g, NULL);

    printf("%sColoring the graph...%s\n", MAGENTA, RESET);
    int result[MAX_VERTICES] = {0};  // Initialize with 0s
    int colors[6] = {1, 2, 3, 4, 5, 6};  // Available colors
    int i, j;  // Loop variables
    for (i = 0; i < g.num_vertices; i++)
    {
        int taken_colors[6] = {0};  // Initialize with 0s
        for (j = 0; j < g.num_edges; j++)
        {
            if (g.edges[j].vertex1 == g.vertices[i] || g.edges[j].vertex2 == g.vertices[i])
            {
                if (result[g.edges[j].vertex1-1] != 0)
                {
                    taken_colors[result[g.edges[j].vertex1-1]-1] = 1;
                }
                if (result[g.edges[j].vertex2-1] != 0)
                {
                    taken_colors[result[g.edges[j].vertex2-1]-1] = 1;
                }
            }
        }
        for (j = 0; j < 6; j++)
        {
            if (taken_colors[colors[j]-1] == 0)  // Check if color is available
            {
                result[g.vertices[i]-1] = colors[j];
                printf("%sVertex %d has been colored with color %d.%s\n", GREEN, g.vertices[i], colors[j], RESET);
                break;
            }
        }
        if (result[g.vertices[i]-1] == 0)  // If a vertex has not been colored
        {
            printf("%sVertex %d could not be colored. Restarting...%s\n", RED, g.vertices[i], RESET);
            i = -1;  // Restart loop
            for (j = 0; j < g.num_vertices; j++)
            {
                result[j] = 0;  // Reset result array
            }
        }
    }
    printf("%sGraph coloring is complete!%s\n", CYAN, RESET);
    print_graph(&g, result);
    return 0;
}

/* Function to initialize the graph */
void initialize_graph(struct graph *g)
{
    g->num_vertices = 0;
    g->num_edges = 0;
}

/* Function to add a vertex to the graph */
void add_vertex(struct graph *g, int vertex)
{
    g->vertices[g->num_vertices++] = vertex;
}

/* Function to add an edge to the graph */
void add_edge(struct graph *g, int vertex1, int vertex2)
{
    g->edges[g->num_edges].vertex1 = vertex1;
    g->edges[g->num_edges].vertex2 = vertex2;
    g->edges[g->num_edges].color = 0;
    g->num_edges++;
}

/* Function to print the graph */
void print_graph(struct graph *g, int result[])
{
    int i, j;  // Loop variables
    for (i = 0; i < g->num_vertices; i++)
    {
        printf("%s%d%s", CYAN, g->vertices[i], RESET);
        printf(" is connected to: ");
        for (j = 0; j < g->num_edges; j++)
        {
            if (g->edges[j].vertex1 == g->vertices[i])
            {
                printf("%d ", g->edges[j].vertex2);
            }
            else if (g->edges[j].vertex2 == g->vertices[i])
            {
                printf("%d ", g->edges[j].vertex1);
            }
        }
        if (result != NULL && result[i] != 0)
        {
            printf("(%d)\n", result[i]);
        }
        else
        {
            printf("\n");
        }
    }
}