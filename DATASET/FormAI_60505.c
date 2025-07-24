//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define K 3 // Number of clusters
#define MAX_ITERATIONS 100

double distance(double x1, double y1, double x2, double y2){
    // Distance formula : sqrt((x2-x1)^2 + (y2-y1)^2)
    return sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
}

int main(){
    int i, j, k, t, iterations = 0;
    double x[10], y[10]; // Maximum ten points to test
    double means[K][2], distances[K], min_distance;
    int clusters[10]; // Maximum ten points to test
    
    // Randomly initialize the points
    x[0]=2; y[0]=3;
    x[1]=5; y[1]=4;
    x[2]=6; y[2]=5;
    x[3]=2; y[3]=10;
    x[4]=4; y[4]=11;
    x[5]=6; y[5]=12;
    x[6]=5; y[6]=15;
    x[7]=12; y[7]=4;
    x[8]=14; y[8]=5;
    x[9]=15; y[9]=7;
    
    // Randomly initialize the means
    for(i=0; i<K; i++){
        means[i][0] = x[i*3]; // Taking mean from every third point
        means[i][1] = y[i*3];
    }
    
    do {
        for(i=0; i<10; i++){
            // Calculate the distances of the point from the means of all clusters
            for(j=0; j<K; j++){
                distances[j] = distance(x[i], y[i], means[j][0], means[j][1]);
            }
            
            // Assign the point to the cluster with minimum distance
            min_distance = distances[0];
            clusters[i] = 0;
            for(j=1; j<K; j++){
                if(distances[j] < min_distance){
                    min_distance = distances[j];
                    clusters[i] = j;
                }
            }
        }
        
        // Recalculate the means of all clusters
        for(i=0; i<K; i++){
            means[i][0] = 0;
            means[i][1] = 0;
            t = 0;
            for(j=0; j<10; j++){
                if(clusters[j] == i){
                    means[i][0] += x[j];
                    means[i][1] += y[j];
                    t++;
                }
            }
            means[i][0] /= t;
            means[i][1] /= t;
        }
        
        iterations++;
    } while(iterations < MAX_ITERATIONS);
    
    // Print the final cluster points
    printf("Cluster 1 Points:\n");
    for(i=0; i<10; i++){
        if(clusters[i] == 0){
            printf("(%lf, %lf)\n", x[i], y[i]);
        }
    }
    printf("Cluster 2 Points:\n");
    for(i=0; i<10; i++){
        if(clusters[i] == 1){
            printf("(%lf, %lf)\n", x[i], y[i]);
        }
    }
    printf("Cluster 3 Points:\n");
    for(i=0; i<10; i++){
        if(clusters[i] == 2){
            printf("(%lf, %lf)\n", x[i], y[i]);
        }
    }
    
    return 0;
}