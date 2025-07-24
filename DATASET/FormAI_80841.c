//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateGalaxy(int galaxy[][10]);
void printGalaxy(int galaxy[][10]);
void explore(int galaxy[][10], int x, int y, int *found);

// Main function
int main() {
    int galaxy[10][10]; // Declare a 2D array to represent the galaxy
    int x, y; // Declare variables to hold user input for starting coordinates
    int found = 0; // Declare a variable to track whether the user has found the alien planet
    srand(time(NULL)); // Initialize random number generator

    generateGalaxy(galaxy); // Generate the galaxy randomly
    printGalaxy(galaxy); // Print the galaxy for the user to see

    printf("Enter the starting coordinates (x,y): ");
    scanf("%d,%d", &x, &y); // Get user input for starting coordinates
    
    explore(galaxy, x, y, &found); // Start exploring the galaxy from the user's starting coordinates
    
    if (found) {
        printf("Congratulations, you found the alien planet!\n");
    } else {
        printf("Sorry, you did not find the alien planet.\n");
    }
    
    return 0;
}

// Function to randomly generate the galaxy
void generateGalaxy(int galaxy[][10]) {
    int i, j;
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            galaxy[i][j] = rand() % 3; // Assign values of 0, 1, or 2 randomly
        }
    }
    galaxy[9][9] = 3; // Assign the alien planet to the bottom right corner
}

// Function to print the galaxy
void printGalaxy(int galaxy[][10]) {
    int i, j;
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            if (galaxy[i][j] == 3) { // If the current position is the alien planet, print "A"
                printf("A ");
            } else {
                printf("%d ", galaxy[i][j]); // Otherwise, print the value of the current position
            }
        }
        printf("\n");
    }
}

// Recursive function to explore the galaxy
void explore(int galaxy[][10], int x, int y, int *found) {
    if (x < 0 || x > 9 || y < 0 || y > 9) { // If the current coordinates are outside the galaxy, return
        return;
    }

    int value = galaxy[x][y]; // Get the value of the current position

    if (value == 3) { // If the current position is the alien planet, set "found" to true and return
        *found = 1;
        return;
    } else if (value == 0) { // If the current position is empty space, mark it as visited (4) and continue exploring
        galaxy[x][y] = 4;
        explore(galaxy, x+1, y, found); // Explore right
        explore(galaxy, x-1, y, found); // Explore left
        explore(galaxy, x, y+1, found); // Explore down
        explore(galaxy, x, y-1, found); // Explore up
    } else { // If the current position is a planet, mark it as visited (4) and continue exploring
        galaxy[x][y] = 4;
        explore(galaxy, x+1, y, found); // Explore right
        explore(galaxy, x-1, y, found); // Explore left
        explore(galaxy, x, y+1, found); // Explore down
        explore(galaxy, x, y-1, found); // Explore up
    }
}