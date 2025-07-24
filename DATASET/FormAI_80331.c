//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Clustering algorithm implementation program
//Sherlock Holmes style:
//It was a dark and stormy night. I sat at my desk pondering over the cluster of suspects. 
//My mind raced through the clues, but the solution to the problem remained elusive.
//I decided to implement a clustering algorithm in C to help solve the mystery.

//Function to calculate Euclidean distance between two points
double euclidean_distance(double x1, double y1, double x2, double y2) {
    double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return distance;
}

//The clustering algorithm implementation
int main() {
    //Collecting input from user for number of data points
    int num_points;
    printf("Enter number of data points: ");
    scanf("%d", &num_points);

    double points[num_points][2];
    printf("Enter the %d data points(x, y): \n", num_points);
    for(int i=0; i<num_points; i++) {
        scanf("%lf %lf", &points[i][0], &points[i][1]);
    }

    //Denoting the number of clusters desired
    int num_clusters;
    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);

    //Denoting the maximum number of iterations in the algorithm
    int max_iterations;
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    //Initializing the centroids for the clusters
    double centroids[num_clusters][2];
    for(int i=0; i<num_clusters; i++) {
        centroids[i][0] = points[i][0];
        centroids[i][1] = points[i][1];
    }

    //Assigning data points to clusters
    int clusters[num_points];
    for(int i=0; i<num_points; i++) {
        double min_distance = 999999;
        int cluster_index = 0;
        for(int j=0; j<num_clusters; j++) {
            double distance = euclidean_distance(points[i][0], points[i][1], centroids[j][0], centroids[j][1]);
            if(distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }
        clusters[i] = cluster_index;
    }

    //Updating the centroids
    for(int i=0; i<num_clusters; i++) {
        double sumx = 0;
        double sumy = 0;
        int count = 0;
        for(int j=0; j<num_points; j++) {
            if(clusters[j] == i) {
                sumx += points[j][0];
                sumy += points[j][1];
                count++;
            }
        }
        if(count != 0) {
            centroids[i][0] = sumx / count;
            centroids[i][1] = sumy / count;
        }
    }

    //Repeating the assigning and updating process for max_iterations
    int iteration = 0;
    while(iteration < max_iterations) {
        //Assigning data points to clusters
        for(int i=0; i<num_points; i++) {
            double min_distance = 999999;
            int cluster_index = 0;
            for(int j=0; j<num_clusters; j++) {
                double distance = euclidean_distance(points[i][0], points[i][1], centroids[j][0], centroids[j][1]);
                if(distance < min_distance) {
                    min_distance = distance;
                    cluster_index = j;
                }
            }
            clusters[i] = cluster_index;
        }

        //Updating the centroids
        for(int i=0; i<num_clusters; i++) {
            double sumx = 0;
            double sumy = 0;
            int count = 0;
            for(int j=0; j<num_points; j++) {
                if(clusters[j] == i) {
                    sumx += points[j][0];
                    sumy += points[j][1];
                    count++;
                }
            }
            if(count != 0) {
                centroids[i][0] = sumx / count;
                centroids[i][1] = sumy / count;
            }
        }
        iteration++;
    }

    //Printing the final clusters
    printf("Final clusters: \n");
    for(int i=0; i<num_clusters; i++) {
        printf("Cluster %d: ", i+1);
        for(int j=0; j<num_points; j++) {
            if(clusters[j] == i) {
                printf("(%lf, %lf) ", points[j][0], points[j][1]);
            }
        }
        printf("\n");
    }

    return 0;
}