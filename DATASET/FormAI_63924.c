//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program uses a special kind of searching algorithm called
   "multidimensional binary search". This algorithm is very efficient
   when searching in multiple dimensions, such as in a 3D or 4D space.
   In this example, we will use a 3D space with random points. */

/* Define the size of the 3D space */
#define SPACE_SIZE 20

/* Define the number of dimensions in the search space */
#define NUM_DIMENSIONS 3

/* Define the number of points to generate randomly in the 3D space */
#define NUM_POINTS 50

/* Define the structure for a point in 3D space */
typedef struct point {
    int x, y, z;
} Point;

/* Define the structure for a node in the multidimensional binary search tree */
typedef struct node {
    Point point;
    struct node *left, *right;
} Node;

/* Function prototypes */
Node *create_node(Point);
void insert_node(Node **, Point);
void search_node(Node *, Point, int, int *);

int main() {
    /* Randomize the seed for the pseudo-random number generator */
    srand(time(NULL));
    
    /* Generate random points in 3D space */
    Point points[NUM_POINTS];
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i].x = rand() % SPACE_SIZE;
        points[i].y = rand() % SPACE_SIZE;
        points[i].z = rand() % SPACE_SIZE;
    }
    
    /* Print the randomly generated points */
    printf("Randomly generated points in 3D space:\n");
    for (int i = 0; i < NUM_POINTS; i++) {
        printf("(%d, %d, %d)\n", points[i].x, points[i].y, points[i].z);
    }
    
    /* Build the multidimensional binary search tree */
    Node *root = NULL;
    for (int i = 0; i < NUM_POINTS; i++) {
        insert_node(&root, points[i]);
    }
    
    /* Ask the user to input a point to search for in 3D space */
    Point search_point;
    printf("\nEnter a point to search for in 3D space (x y z): ");
    scanf("%d %d %d", &search_point.x, &search_point.y, &search_point.z);
    
    /* Search for the point in the multidimensional binary search tree */
    int found = 0;
    search_node(root, search_point, 0, &found);
    
    if (found) {
        printf("\nPoint (%d, %d, %d) found in 3D space!\n", search_point.x, search_point.y, search_point.z);
    } else {
        printf("\nPoint (%d, %d, %d) not found in 3D space.\n", search_point.x, search_point.y, search_point.z);
    }
    
    /* Free memory allocated for the nodes in the multidimensional binary search tree */
    return 0;
}

/* Function to create a new node in the multidimensional binary search tree */
Node *create_node(Point point) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: could not allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    
    new_node->point = point;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}

/* Function to insert a node in the multidimensional binary search tree */
void insert_node(Node **node, Point point) {
    if (*node == NULL) {
        *node = create_node(point);
    } else if (point.x < (*node)->point.x) {
        insert_node(&((*node)->left), point);
    } else if (point.x > (*node)->point.x) {
        insert_node(&((*node)->right), point);
    } else if (point.y < (*node)->point.y) {
        insert_node(&((*node)->left), point);
    } else if (point.y > (*node)->point.y) {
        insert_node(&((*node)->right), point);
    } else if (point.z < (*node)->point.z) {
        insert_node(&((*node)->left), point);
    } else if (point.z > (*node)->point.z) {
        insert_node(&((*node)->right), point);
    }
}

/* Function to search for a node in the multidimensional binary search tree */
void search_node(Node *node, Point point, int depth, int *found) {
    if (node == NULL) {
        return;
    }
    
    if (node->point.x == point.x && node->point.y == point.y && node->point.z == point.z) {
        *found = 1;
    } else if (depth % NUM_DIMENSIONS == 0) {
        if (point.x < node->point.x) {
            search_node(node->left, point, depth + 1, found);
        } else {
            search_node(node->right, point, depth + 1, found);
        }
    } else if (depth % NUM_DIMENSIONS == 1) {
        if (point.y < node->point.y) {
            search_node(node->left, point, depth + 1, found);
        } else {
            search_node(node->right, point, depth + 1, found);
        }
    } else if (depth % NUM_DIMENSIONS == 2) {
        if (point.z < node->point.z) {
            search_node(node->left, point, depth + 1, found);
        } else {
            search_node(node->right, point, depth + 1, found);
        }
    }
}