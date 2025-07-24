//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: calm
#include<stdio.h>
#include<math.h>

#define MAX 1000

struct Point {
    double x;
    double y;
};

// Global variable for storing navigation history
struct Point navigationHistory[MAX];
int historyIndex = 0;

// Function for calculating distance between two points
double calcDistance(struct Point p1, struct Point p2) {
    double distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distance;
}

// Function for adding a new point to navigation history
void addNavigationHistory(struct Point newPoint) {
    navigationHistory[historyIndex] = newPoint;
    historyIndex++;
}

// Function for simulating GPS navigation
void gpsNavigationSimulation() {
    int numPoints, i;
    double totalDistance = 0;
    struct Point startPoint, endPoint, currentPoint, previousPoint;

    // Get input from user
    printf("Enter the number of points for navigation: ");
    scanf("%d", &numPoints);

    printf("Enter the starting point (x, y): ");
    scanf("%lf %lf", &startPoint.x, &startPoint.y);

    // Set the current point to starting point
    currentPoint = startPoint;
    addNavigationHistory(currentPoint);

    // Loop for getting input and calculating distance
    for(i=1; i<=numPoints; i++) {
        printf("Enter the next point (x, y): ");
        scanf("%lf %lf", &endPoint.x, &endPoint.y);
        
        // Calculate distance between current and next point
        double distance = calcDistance(currentPoint, endPoint);
        totalDistance += distance;
        currentPoint = endPoint;

        // Add new point to navigation history
        addNavigationHistory(currentPoint);
    }
    
    // Print the navigation history
    printf("\nNavigation History:\n");
    for(i=0; i<historyIndex; i++) {
        printf("(%lf, %lf)\n", navigationHistory[i].x, navigationHistory[i].y);
    }

    // Output the total distance
    printf("\nTotal distance travelled: %lf\n", totalDistance);

    // Calculate and output the average speed
    double time = totalDistance/60.0;
    double avgSpeed = totalDistance/time;
    printf("Average speed: %lf km/h\n", avgSpeed);
}

int main() {
    // Call the GPS navigation simulation function
    gpsNavigationSimulation();

    return 0;
}