//FormAI DATASET v1.0 Category: Data mining ; Style: Cryptic
#include <stdio.h>

#define MAX_ITERATIONS 100

// Function to calculate the distance between two data points
float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));  
}

int main() 
{
    // Initialize the data points
    int data[10][2] = {{5,3}, {10,15}, {15,12}, {24,10}, {30,45}, {85,70}, {71,80}, {60,78}, {55,52}, {80,91}};    
    int centroids[3][2] = {{5,3}, {10, 15}, {30, 45}};

    // Cluster assignment array for keeping track of data point clusters
    int c_assignments[10];
    
    // Counter for keeping track of number of iterations
    int iterations = 0;

    while(iterations < MAX_ITERATIONS)
    {
        // Assign each data point to the nearest centroid
        for(int i=0; i<10; i++)
        {
            float min_dist = 10000; // Set an initial large minimum distance
            int min_index = -1;     // Initialize minimum index to -1
            
            for(int j=0; j<3; j++)
            {
                float dist = distance(data[i][0], data[i][1], centroids[j][0], centroids[j][1]);
                
                if(dist < min_dist)
                {
                    min_dist = dist;
                    min_index = j;
                }
                
            }
            
            c_assignments[i] = min_index;   // Assign data point to nearest cluster
        }
        
        // Move centroids to the mean of assigned data points
        for(int i=0; i<3; i++)
        {
            int x_sum = 0;
            int y_sum = 0;
            int count = 0;
            
            for(int j=0; j<10; j++)
            {
                if(c_assignments[j] == i)
                {
                    x_sum += data[j][0];
                    y_sum += data[j][1];
                    count++;
                }
            }
            
            centroids[i][0] = x_sum/count;
            centroids[i][1] = y_sum/count;
        }
        
        iterations++;
    }
    
    // Print final cluster assignments and centroids
    printf("Final cluster assignments:\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ", c_assignments[i]);
    }
    
    printf("\nFinal centroids:\n");
    for(int i=0; i<3; i++)
    {
        printf("(%d, %d) ", centroids[i][0], centroids[i][1]);
    }  
    
    return 0;
}