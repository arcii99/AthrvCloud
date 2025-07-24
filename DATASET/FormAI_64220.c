//FormAI DATASET v1.0 Category: Scientific ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Function to generate a random integer between min and max (inclusive)
// Taken from https://stackoverflow.com/a/6852396
int rand_int(int min, int max)
{
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

// A struct to hold a pair of integers
typedef struct {
    int x;
    int y;
} Point;

// A struct to represent a circle
typedef struct {
    Point center;
    int radius;
} Circle;

// Function to determine if a point is inside a circle
int is_point_in_circle(Point point, Circle circle)
{
    int dx = point.x - circle.center.x;
    int dy = point.y - circle.center.y;
    return (dx * dx + dy * dy) < (circle.radius * circle.radius);   
}

// Function to asynchronously generate random points
void* generate_points(void* arg)
{
    Circle circle = *(Circle*)arg;
    int num_points = 0;
    while (1)
    {
        // Generate a random point within the specified constraints
        Point point;
        point.x = rand_int(circle.center.x - circle.radius, circle.center.x + circle.radius);
        point.y = rand_int(circle.center.y - circle.radius, circle.center.y + circle.radius);
        
        // Check if the point is inside the circle
        if (is_point_in_circle(point, circle))
        {
            num_points++;
        }
        
        // Sleep for a random amount of time between 10 and 100 milliseconds
        int sleep_time = rand_int(10, 100);
#ifdef _WIN32
        Sleep(sleep_time);
#else
        usleep(sleep_time * 1000);
#endif

        // Print the number of points inside the circle every 1000 points
        if (num_points % 1000 == 0)
        {
            printf("Number of points inside circle: %d\n", num_points);
        }
    }
}

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create a circle
    Circle circle;
    circle.center.x = 0;
    circle.center.y = 0;
    circle.radius = 10;

    // Create the thread that will generate random points
#ifdef _WIN32
    HANDLE thread = CreateThread(NULL, 0, generate_points, &circle, 0, NULL);
#else
    pthread_t thread;
    pthread_create(&thread, NULL, generate_points, &circle);
#endif

    // Wait for user input to exit the program
    char input[50];
    printf("Press ENTER to exit\n");
    fgets(input, sizeof(input), stdin);

    // Clean up the thread
#ifdef _WIN32
    TerminateThread(thread, 0);
    CloseHandle(thread);
#else
    pthread_cancel(thread);
#endif

    return 0;
}