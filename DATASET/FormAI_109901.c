//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define N 50     //number of data points
#define K 3      //number of clusters

typedef struct{
    double x;
    double y;
}point;

double distance(point a, point b){        //function to calculate distance between two points
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main(){
    point data[N];            //array to store data points
    point center[K];          //array to store centers of clusters
    int cluster[N];           //array to store which cluster each data point belongs to
    int i, j, iters = 0;
    double d, min_d;
    srand(time(0));           //seed the random number generator
    
    //initialize data points
    printf("Generating data points...\n");
    for(i=0; i<N; i++){
        data[i].x = rand()%100-50;    //random value between -50 and 50
        data[i].y = rand()%100-50;
    }
    printf("Data points generated.\n\n");
    
    //initialize centers of clusters
    printf("Initializing centers of clusters...\n");
    for(i=0; i<K; i++){
        center[i].x = rand()%100-50;
        center[i].y = rand()%100-50;
        printf("Cluster %d center: (%.2f, %.2f)\n", i+1, center[i].x, center[i].y);
    }
    printf("\n");
    
    //run algorithm
    while(iters<10){           //run for 10 iterations
        //assign data points to clusters
        printf("Assigning data points to clusters...\n");
        for(i=0; i<N; i++){
            min_d = distance(data[i], center[0]);
            cluster[i] = 1;          //assume data point belongs to first cluster
            for(j=1; j<K; j++){
                d = distance(data[i], center[j]);
                if(d<min_d){
                    min_d = d;
                    cluster[i] = j+1;   //data point belongs to j+1th cluster
                }
            }
        }
        printf("Data points assigned to clusters.\n\n");
        
        //recompute centers of clusters
        printf("Recomputing centers of clusters...\n");
        for(i=0; i<K; i++){
            double sumx = 0, sumy =0;
            int count = 0;
            for(j=0; j<N; j++){
                if(cluster[j] == i+1){     //if data point belongs to cluster i+1
                    sumx += data[j].x;
                    sumy += data[j].y;
                    count++;
                }
            }
            center[i].x = sumx/count;
            center[i].y = sumy/count;
            printf("Cluster %d center: (%.2f, %.2f)\n", i+1, center[i].x, center[i].y);
        }
        printf("Centers of clusters recomputed.\n\n");
        
        iters++;   //increment iteration count
    }
    
    //print final cluster assignments
    printf("Final cluster assignments:\n");
    for(i=0; i<N; i++){
        printf("Data point (%.2f, %.2f) belongs to cluster %d\n", data[i].x, data[i].y, cluster[i]);
    }
    
    return 0;
}