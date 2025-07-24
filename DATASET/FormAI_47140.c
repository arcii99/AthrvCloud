//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: decentralized
#include<stdio.h>

#define BUFFER_SIZE 1024
#define NUM_CLUSTERS 3
#define NUM_DIMENSIONS 2
#define NUM_ITERATIONS 100

typedef struct {
    int id;
    float coords[NUM_DIMENSIONS];
} datapoint;

// function to initialize datapoints with random coordinates
void init_datapoints(datapoint data[], int num_points) {
    int i, j;
    for(i=0; i<num_points; i++) {
        data[i].id = i;
        for(j=0; j<NUM_DIMENSIONS; j++) {
            data[i].coords[j] = (float)(rand() % BUFFER_SIZE);
        }
    }
}

// function to calculate euclidean distance between two datapoints
float euclidean_distance(datapoint d1, datapoint d2) {
    int i;
    float sum = 0;
    for(i=0; i<NUM_DIMENSIONS; i++) {
        sum += pow(d1.coords[i] - d2.coords[i], 2);
    }
    return sqrt(sum);
}

// function to assign datapoints to initial random clusters
void assign_clusters(datapoint data[], int num_points, datapoint clusters[]) {
    int i, j;
    for(i=0; i<NUM_CLUSTERS; i++) {
        clusters[i] = data[rand()%num_points];
    }

    for(i=0; i<num_points; i++) {
        float min_distance = BUFFER_SIZE*NUM_DIMENSIONS;
        int cluster_id = 0;
        for(j=0; j<NUM_CLUSTERS; j++) {
            float distance = euclidean_distance(data[i], clusters[j]);
            if(distance < min_distance) {
                min_distance = distance;
                cluster_id = j;
            }
        }
        data[i].id = cluster_id;
    }
}

// function to calculate mean coordinates of datapoints in a given cluster
datapoint get_cluster_mean(datapoint cluster[], int num_points) {
    int i, j;
    datapoint mean;
    mean.id = -1;
    for(j=0; j<NUM_DIMENSIONS; j++) {
        mean.coords[j] = 0;
    }
    for(i=0; i<num_points; i++) {
        for(j=0; j<NUM_DIMENSIONS; j++) {
            mean.coords[j] += cluster[i].coords[j];
        }
    }
    for(j=0; j<NUM_DIMENSIONS; j++) {
        mean.coords[j] /= num_points;
    }
    return mean;
}

// function to update cluster centers based on mean coordinates of their datapoints
void update_clusters(datapoint data[], int num_points, datapoint clusters[]) {
    int i, j;
    for(i=0; i<NUM_CLUSTERS; i++) {
        int num_points_in_cluster = 0;
        datapoint cluster_mean = get_cluster_mean(&data[0], num_points);
        for(j=0; j<num_points; j++) {
            if(data[j].id == i) {
                num_points_in_cluster++;
                for(int k=0; k<NUM_DIMENSIONS; k++) {
                    cluster_mean.coords[k] += data[j].coords[k];
                }
            }
        }
        if(num_points_in_cluster > 0) {
            for(int k=0; k<NUM_DIMENSIONS; k++) {
                cluster_mean.coords[k] /= num_points_in_cluster;
            }
            clusters[i] = cluster_mean;
        } else {
            clusters[i] = data[rand()%num_points];
        }
    }
}

int main() {
    int i, j;

    // generate random datapoints
    datapoint data[BUFFER_SIZE];
    init_datapoints(&data[0], BUFFER_SIZE);

    // randomly assign datapoints to initial clusters
    datapoint clusters[NUM_CLUSTERS];
    assign_clusters(&data[0], BUFFER_SIZE, &clusters[0]);

    // perform clustering iterations
    for(i=0; i<NUM_ITERATIONS; i++) {
        update_clusters(&data[0], BUFFER_SIZE, &clusters[0]);
        for(j=0; j<BUFFER_SIZE; j++) {
            float min_distance = BUFFER_SIZE*NUM_DIMENSIONS;
            int cluster_id = 0;
            for(int k=0; k<NUM_CLUSTERS; k++) {
                float distance = euclidean_distance(data[j], clusters[k]);
                if(distance < min_distance) {
                    min_distance = distance;
                    cluster_id = k;
                }
            }
            data[j].id = cluster_id;
        }
    }

    return 0;
}