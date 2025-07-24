//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//function prototypes
void clustering(int n, double data[][2], int k, double c[][2], int* assignments);
void initializeCentroids(int k, double data[][2], int n, double c[][2]);
double getDistance(double x1, double y1, double x2, double y2);

//main function
int main(){

    //sample data
    double data[10][2] = {{1,2},{2,3},{8,7},{9,10},{15,13},{17,19},{20,22},{22,23},{10,5},{11,3}};
    //number of datapoints
    int n = 10;
    //number of clusters
    int k = 3;
    //centroid coordinates
    double c[k][2];
    //cluster assignments
    int assignments[n];
    
    initializeCentroids(k, data, n, c); //initialize centroids
    
    clustering(n, data, k, c, assignments); //perform clustering

    //display cluster assignments
    printf("\nCluster Assignments: \n");
    for(int i=0;i<n;i++){
        printf("Data %d --> Cluster %d\n", i+1, assignments[i]);
    }

    return 0;
}

//function to perform clustering
void clustering(int n, double data[][2], int k, double c[][2], int* assignments){
    int max_itr = 5000; //maximum number of iterations
    int itr = 0; //current iteration
    double threshold = 0.001; //convergence threshold

    while(itr<max_itr){
        double distances[k][n]; //distances between centroids and datapoints

        //calculate distances
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                distances[i][j] = getDistance(c[i][0], c[i][1], data[j][0], data[j][1]);
            }
        }

        //assign datapoints to clusters
        for(int j=0;j<n;j++){
            int min_index;
            double min_distance = INFINITY;
            for(int i=0;i<k;i++){
                if(distances[i][j]<min_distance){
                    min_distance = distances[i][j];
                    min_index = i;
                }
            }
            assignments[j] = min_index;
        }

        //update centroids
        double new_c[k][2];
        int counter[k];
        for(int i=0;i<k;i++){
            new_c[i][0] = 0;
            new_c[i][1] = 0;
            counter[i] = 0;
        }

        for(int j=0;j<n;j++){
            int index = assignments[j];
            new_c[index][0] += data[j][0];
            new_c[index][1] += data[j][1];
            counter[index]++;
        }

        for(int i=0;i<k;i++){
            if(counter[i]>0){
                new_c[i][0] /= counter[i];
                new_c[i][1] /= counter[i];
            }
            else{
                new_c[i][0] = c[i][0];
                new_c[i][1] = c[i][1];
            }
        }

        //check for convergence
        double diff = 0;
        for(int i=0;i<k;i++){
            diff += getDistance(c[i][0], c[i][1], new_c[i][0], new_c[i][1]);
        }
        if(diff<threshold){
            break;
        }

        //update centroids
        for(int i=0;i<k;i++){
            c[i][0] = new_c[i][0];
            c[i][1] = new_c[i][1];
        }

        itr++;
    }
}

//function to initialize centroids
void initializeCentroids(int k, double data[][2], int n, double c[][2]){
    for(int i=0;i<k;i++){
        int index = rand() % n;
        c[i][0] = data[index][0];
        c[i][1] = data[index][1];
    }
}

//function to calculate distance between two points
double getDistance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
}