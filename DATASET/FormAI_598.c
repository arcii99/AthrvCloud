//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 100

//function to calculate distance between two points
double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

//function to print clusters
void print_clusters(int clusters[], int n){
    int i, j;
    for(i=1; i<=n; i++){
        printf("\nCluster %d: ", i);
        for(j=0; j<SIZE; j++){
            if(clusters[j]==i)
                printf("%d ", j+1);
        }
    }
}

//function implementing the clustering algorithm 
void clustering(int n, double x[], double y[], int clusters[]){
    int i, j, k;
    int count = n;
    double min_distance;
    int min_i, min_j;
    double d[SIZE][SIZE];
    
    //initializing clusters
    for(i=0; i<SIZE; i++){
        clusters[i] = i+1;
    }
    
    //calculate the distance matrix
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            d[i][j] = distance(x[i], y[i], x[j], y[j]);
            d[j][i] = d[i][j];
        }
    }
    
    //clustering loop
    while(count>1){
        //find minimum distance between clusters
        min_distance = INFINITY;
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                if(clusters[i]!=clusters[j]){
                    if(d[i][j]<min_distance){
                        min_distance = d[i][j];
                        min_i = i;
                        min_j = j;
                    }
                }
            }
        }
        
        //merge the two clusters
        for(k=0; k<n; k++){
            if(clusters[k]==clusters[min_i] || clusters[k]==clusters[min_j]){
               clusters[k] = count;
            }
        }
        
        count--;
    }
}

int main(){
    int n = 10;
    double x[SIZE] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
    double y[SIZE] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int clusters[SIZE];
    clustering(n, x, y, clusters);
    print_clusters(clusters, n);
    return 0;
}