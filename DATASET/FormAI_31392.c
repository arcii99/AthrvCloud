//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: medieval
#include <stdio.h>
#include <math.h>

// Define the structure of a medieval castle tower
struct tower {
    float x; // The x coordinate of the tower
    float y; // The y coordinate of the tower
    float r; // The radius of the tower
};

int main() {
    struct tower towers[3]; // Create an array of 3 medieval castle towers
    
    // Set the coordinates and radius of each tower using user input
    printf("Enter coordinates and radius for Tower 1:\n");
    scanf("%f %f %f", &towers[0].x, &towers[0].y, &towers[0].r);
    
    printf("Enter coordinates and radius for Tower 2:\n");
    scanf("%f %f %f", &towers[1].x, &towers[1].y, &towers[1].r);
    
    printf("Enter coordinates and radius for Tower 3:\n");
    scanf("%f %f %f", &towers[2].x, &towers[2].y, &towers[2].r);
    
    // Calculate the distance between each pair of towers
    float distances[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            distances[i][j] = sqrt(pow(towers[i].x - towers[j].x, 2) + pow(towers[i].y - towers[j].y, 2));
        }
    }
    
    // Determine the closest pair of towers
    int closest1, closest2;
    float shortest_distance = 99999.0f; // Set an initial value larger than any possible distance
    for(int i = 0; i < 2; i++){
        for(int j = i+1; j < 3; j++){
            if(distances[i][j] < shortest_distance){
                shortest_distance = distances[i][j];
                closest1 = i;
                closest2 = j;
            }
        }
    }
    
    // Determine the third tower that is farthest from the closest pair
    int farthest;
    float farthest_distance = 0.0f;
    for(int i = 0; i < 3; i++){
        if(i != closest1 && i != closest2){
            if(distances[i][closest1] > farthest_distance && distances[i][closest2] > farthest_distance){
                farthest_distance = fmax(distances[i][closest1], distances[i][closest2]);
                farthest = i;
            }
        }
    }
    
    // Calculate the area of the triangle formed by the three towers
    float a = distances[closest1][closest2];
    float b = distances[closest1][farthest];
    float c = distances[closest2][farthest];
    float s = (a + b + c)/2.0f;
    float area = sqrt(s*(s-a)*(s-b)*(s-c));
    
    // Output the results
    printf("\nThe closest pair of towers are Tower %d and Tower %d with a distance of %.2f\n", closest1+1, closest2+1, shortest_distance);
    printf("The farthest tower from the closest pair is Tower %d with a distance of %.2f\n", farthest+1, farthest_distance);
    printf("The area enclosed by these three towers is %.2f\n", area);
    
    return 0;
}