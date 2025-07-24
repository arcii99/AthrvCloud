//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define K 3          //number of clusters to be formed
#define n 100        //number of data points
#define d 2          //number of attributes for each data point


double data[n][d], centroids[K][d], distances[n][K], sse, prev_sse=999999.0;

/*Function to initialize the data*/
void initialize_data()
{
    int i,j;
    srand(time(0));    //seed for random number generator
    
    //Data points are represented as x,y coordinates in a 2D space
    for(i=0;i<n;i++)
    {
        for(j=0;j<d;j++)
        {
            data[i][j] = rand()%100;
        }
    }
}

/*Function to initialize the centroids*/
void initialize_centroids()
{
    int i, j, k;

    //Selecting first k number of data points as the initial centroids
    for(i=0;i<K;i++)
    {
        for(j=0;j<d;j++)
        {
            centroids[i][j] = data[i][j];
        }
    }
}

/*Function to calculate distance between two data points*/
double euclidean_distance(double* a, double* b)
{
    double distance = 0.0;
    int i;

    for (i=0; i<d; i++)
    {
        distance += pow((a[i]-b[i]), 2);
    }

    return sqrt(distance);
}

/*Function to calculate distance between each data point and each centroid*/
void calculate_distances()
{
    int i, j, k;
    for (i=0; i<n; i++)
    {
        for (j=0; j<K; j++)
        {
            distances[i][j] = euclidean_distance(data[i], centroids[j]);
        }
    }
}

/*Function to assign each data point to a cluster*/
void assign_cluster()
{
    int i, j, min_index;
    double min_distance;

    for (i=0; i<n; i++)
    {
        min_index = 0;
        min_distance = distances[i][0];

        for (j=1; j<K; j++)
        {
            if (distances[i][j] < min_distance)
            {
                min_distance = distances[i][j];
                min_index = j;
            }
        }
        
        //Assigning the data point to the closest centroid
        for (j=0; j<d; j++)
        {
            data[i][j] = min_index;
        }
    }
}

/*Function to update centroids*/
void update_centroids()
{
    int i, j, k, count;
    double new_centroids[K][d];
    
    //Initializing the new centroids matrix
    for (i=0; i<K; i++)
    {
        for (j=0; j<d; j++)
        {
            new_centroids[i][j] = 0.0;
        }
    }

    //Summing up the attributes of all the data points assigned to a cluster
    //and calculating the mean to get the new centroid
    for (i=0; i<K; i++)
    {
        count = 0;

        for (j=0; j<n; j++)
        {
            if (data[j][d] == i)
            {
                count++;
                for (k=0; k<d; k++)
                {
                    new_centroids[i][k] += data[j][k];
                }
            }
        }

        if(count!=0)
        {
            for (k=0; k<d; k++)
            {
                new_centroids[i][k] /= count; 
            }

            //Updating the old centroid with the new centroid
            for (k=0; k<d; k++)
            {
                centroids[i][k] = new_centroids[i][k];
            }
        }
    }
}

/*Function to calculate the SSE (sum of squared errors)*/
void calculate_sse()
{
    int i,j;

    sse = 0.0;

    for (i=0; i<n; i++)
    {
        for (j=0; j<K; j++)
        {
            if (data[i][d] == j)
            {
                sse += pow(distances[i][j], 2);
            }
        }
    }
}

int main()
{
    int i,j,k,iteration=0;
    initialize_data();
    initialize_centroids();

    while (fabs(sse - prev_sse) > 0.00001)
    {
        iteration++;
        prev_sse = sse;

        calculate_distances();
        assign_cluster();
        update_centroids();
        calculate_sse();
    }

    printf("Number of iterations: %d\n\n", iteration);
    printf("Final Centroids:\n");

    for (i=0; i<K; i++)
    {
        printf("Centroid %d: [", i+1);

        for (j=0; j<d; j++)
        {
            printf("%lf, ", centroids[i][j]);
        }

        printf("]\n");
    }

    printf("\nSSE: %lf\n\n", sse);

    return 0;
}