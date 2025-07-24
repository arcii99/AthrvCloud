//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>

/*

    Cyberpunk Geometric Algorithm:

    In a futuristic world where cities are built up vertically instead of horizontally, 
    traversal between buildings has become a major issue. But fear not, the Neon District 
    PD has developed a geometric algorithm to calculate the shortest path between two buildings.

    The algorithm involves 3D coordinates of two buildings and height information of all other
    buildings in between them. It works by calculating the distance between the two buildings and
    creating a cylindrical bounding box around them. The algorithm then calculates the intersection
    of the bounding box with all the rectangular prisms (buildings) in between them and removes
    the unneeded parts of the prisms. Finally, the algorithm calculates the shortest path using
    the modified prisms and returns it as output.

    This program uses the Cyberpunk Geometric Algorithm to calculate the shortest path between two
    buildings in the Neon District.

*/

struct Point3D {
    float x, y, z;
};

struct Building {
    struct Point3D center;
    float width, height, depth;
};

int main() {
    // Input the 3D coordinates of the two buildings
    struct Point3D building1 = { 4.5, 2.3, 7.8 }, building2 = { 2.1, 8.2, 6.4 };

    // Input the building information for all other buildings in between the two
    struct Building buildings[] = {
        { { 1.2, 1.6, 3.5 }, 2.5, 4.1, 3.8 },
        { { 3.4, 4.5, 5.3 }, 3.0, 3.4, 2.1 },
        { { 5.6, 7.8, 8.8 }, 2.2, 5.1, 1.5 },
        { { 2.7, 6.3, 3.9 }, 4.3, 2.1, 1.2 },
        { { 3.9, 1.8, 5.6 }, 3.2, 3.9, 2.8 },
        { { 7.1, 3.5, 4.2 }, 1.8, 4.6, 3.1 }
    };

    int numBuildings = sizeof(buildings) / sizeof(buildings[0]);

    // Calculate the distance between the two buildings
    float distance = sqrt(pow((building2.x - building1.x), 2.0) + pow((building2.y - building1.y), 2.0) + pow((building2.z - building1.z), 2.0));

    // Create a cylindrical bounding box around the two buildings
    float radius = (distance / 2.0) + 0.5; // 0.5 is added for a little buffer space
    struct Point3D center = { (building1.x + building2.x) / 2.0, (building1.y + building2.y) / 2.0, (building1.z + building2.z) / 2.0 };

    // Calculate the intersection of the bounding box with each building
    for (int i = 0; i < numBuildings; i++) {
        float xMin = buildings[i].center.x - (buildings[i].width / 2.0);
        float xMax = buildings[i].center.x + (buildings[i].width / 2.0);
        float yMin = buildings[i].center.y - (buildings[i].height / 2.0);
        float yMax = buildings[i].center.y + (buildings[i].height / 2.0);
        float zMin = buildings[i].center.z - (buildings[i].depth / 2.0);
        float zMax = buildings[i].center.z + (buildings[i].depth / 2.0);

        // Remove the unneeded parts of the prism by modifying the x, y, and z values
        if (xMin < center.x - radius) xMin = center.x - radius;
        if (xMax > center.x + radius) xMax = center.x + radius;
        if (yMin < center.y - radius) yMin = center.y - radius;
        if (yMax > center.y + radius) yMax = center.y + radius;
        if (zMin < center.z - radius) zMin = center.z - radius;
        if (zMax > center.z + radius) zMax = center.z + radius;

        // Calculate the new height of the prism after removing the unneeded parts
        float height = yMax - yMin;

        // Calculate the shortest path through the modified prism
        float shortestPath = sqrt(pow((xMax - xMin), 2.0) + pow((zMax - zMin), 2.0) + pow(height, 2.0));

        // Print the shortest path for each building
        printf("Shortest path through Building %d: %.2f\n", i+1, shortestPath);
    }

    return 0;
}