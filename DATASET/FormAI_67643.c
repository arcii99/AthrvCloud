//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<time.h>

#define NUM_THREADS 4 // Setting number of threads

#define K 3 // Number of Clusters
#define N 20000 // Number of Data Points
#define D 2 // Number of Features

double data[N][D]; // Store Data points
int cluster[N]; // Store Cluster Number

double centroid[K][D]; // Store Centroids

double distance(double *x, double *y, int d) // Euclidean Distance Function
{
    double dist = 0.0;
    for(int i=0;i<d;++i)
    {
        dist += pow(x[i]-y[i],2);
    }
    return sqrt(dist);
}

void* threadComputeCentroids(void *arg) // Thread Function for Computing Centroids
{
    int id = (int)arg; // Thread ID
    int lower = (N/NUM_THREADS)*id; // Lower Bound of Data Points to process
    int upper = (N/NUM_THREADS)*(id+1); // Upper Bound of Data Points to process
    for(int i=lower;i<upper;++i)
    {
        int c = cluster[i];
        for(int j=0;j<D;++j)
        {
            centroid[c][j] += data[i][j];
        }
    }
    pthread_exit(NULL);
}

void kmeans() // K-Means Clustering Function
{
    srand(time(NULL));

    // Randomly Initialize Centroids
    for(int i=0;i<K;++i)
    {
        for(int j=0;j<D;++j)
        {
            centroid[i][j] = (double)rand()/(double)RAND_MAX;
        }
    }

    int changed;
    int iter = 0;
    do{
        // Reset Centroids
        for(int i=0;i<K;++i)
        {
            for(int j=0;j<D;++j)
            {
                centroid[i][j] = 0.0;
            }
        }

        // Compute Distance from each Data Point to Centroids and assign Cluster
        changed = 0;
        for(int i=0;i<N;++i)
        {
            double minDist = distance(data[i],centroid[0],D);
            int minIndex = 0;
            for(int j=1;j<K;++j)
            {
                double dist = distance(data[i],centroid[j],D);
                if(dist<minDist)
                {
                    minDist = dist;
                    minIndex = j;
                }
            }
            if(cluster[i]!=minIndex)
            {
                cluster[i] = minIndex;
                changed = 1;
            }
        }

        // Compute Centroids
        pthread_t threads[NUM_THREADS];
        for(int i=0;i<NUM_THREADS;++i)
        {
            pthread_create(&threads[i],NULL,threadComputeCentroids,(void*)i);
        }

        for(int i=0;i<NUM_THREADS;++i)
        {
            pthread_join(threads[i],NULL);
        }

        for(int i=0;i<K;++i)
        {
            for(int j=0;j<D;++j)
            {
                centroid[i][j] /= N;
            }
        }

        iter++;
    }while(changed && iter<=1000);
}

int main()
{
    // Generate 2D Data Points
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<D;++j)
        {
            data[i][j] = (double)rand()/(double)RAND_MAX;
        }
    }

    // Initialize Cluster Number
    for(int i=0;i<N;++i)
    {
        cluster[i] = 0;
    }

    kmeans(); // Call K-Means Clustering Function

    printf("Clustering Done.\n");

    return 0;
}