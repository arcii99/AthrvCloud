//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <math.h> 
  
// Define the point structure 
typedef struct point_t 
{ 
    double x; 
    double y; 
} point; 
  
point A, B, C; 
double a, b, c; 
 
// Define thread function
void* findSides(void* arg) 
{ 
    // Calculate the sides
    a = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
    b = sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y));
    c = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
  
    // Print the sides
    printf("Side a: %lf\n", a);
    printf("Side b: %lf\n", b);
    printf("Side c: %lf\n", c);
} 
  
int main() 
{ 
    // Create three points
    A = (point){0, 0};
    B = (point){0, 3};
    C = (point){4, 0};
  
    // Define the threads
    pthread_t thread1, thread2, thread3;
  
    // Create the threads
    pthread_create(&thread1, NULL, &findSides, NULL);
    pthread_create(&thread2, NULL, &findSides, NULL);
    pthread_create(&thread3, NULL, &findSides, NULL);
  
    // Wait for all threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
  
    return 0; 
}