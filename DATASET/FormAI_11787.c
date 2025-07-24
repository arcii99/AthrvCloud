//FormAI DATASET v1.0 Category: Data mining ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#define MAX_LINE_LEN 1024

int main(){
    FILE *fp;
    char line[MAX_LINE_LEN];

    fp = fopen("data.txt", "r"); // open file for reading

    if(fp==NULL){
        printf("Failed to open file!\n");
        exit(1);
    }

    int num_records = 0;
    while(fgets(line, MAX_LINE_LEN, fp) != NULL){
        num_records ++; // count the number of lines in the file
    }
    fclose(fp);

    int num_features = 5; // assume 5 features for the data

    float **data;
    data = (float **) malloc(num_records*sizeof(float *));
    for(int i=0;i<num_records;i++){
        data[i] = (float *) malloc(num_features*sizeof(float));
    }

    fp = fopen("data.txt", "r");

    printf("\nOriginal Data Set\n");
    printf("----------------------------\n");
    for(int i=0;i<num_records;i++){
        for(int j=0;j<num_features;j++){
            fscanf(fp,"%f", &data[i][j]); // read data from file
            printf("%f ", data[i][j]); // print the original dataset
        }
        printf("\n");
    }
    fclose(fp);

    // assume we want to cluster the data into 2 clusters (k=2)
    int k = 2;
    float **centroids;
    centroids = (float **) malloc(k*sizeof(float *));
    for(int i=0;i<k;i++){
        centroids[i] = (float *) malloc(num_features*sizeof(float));
    }

    // randomly initialize the centroids
    for(int i=0;i<k;i++){
        for(int j=0;j<num_features;j++){
            centroids[i][j] = (float)rand()/(float)(RAND_MAX);
        }
    }

    int num_iterations = 10;
    int *cluster_assignments = (int *) malloc(num_records*sizeof(int));
    float *min_dists = (float *) malloc(num_records*sizeof(float));
    float dist;
    for(int i=0;i<num_iterations;i++){
        for(int j=0;j<num_records;j++){
            // initialize minimum distance to large value
            min_dists[j] = 1000000.0;
            cluster_assignments[j] = -1;

            for(int l=0;l<k;l++){
                dist = 0.0;
                for(int m=0;m<num_features;m++){
                    dist += (data[j][m]-centroids[l][m])*(data[j][m]-centroids[l][m]);
                }
                if(dist<min_dists[j]){
                    min_dists[j] = dist;
                    cluster_assignments[j] = l;
                }
            }
        }

        // re-compute the centroids for each cluster
        float *c_sum;
        c_sum = (float *) malloc(num_features*sizeof(float));
        for(int j=0;j<k;j++){
            for(int l=0;l<num_features;l++){
                c_sum[l] = 0.0;
                int num_assigned = 0;

                for(int m=0;m<num_records;m++){
                    if(cluster_assignments[m]==j){
                        c_sum[l] += data[m][l];
                        num_assigned++;
                    }
                }
                if(num_assigned>0) {
                    centroids[j][l] = c_sum[l]/(float)num_assigned; // recompute centroids
                }
            }
        }
        free(c_sum);
    }
    printf("\nCluster Assignments for Each Record\n");
    printf("----------------------------\n");
    for(int i=0;i<num_records;i++){
        printf("%d ", cluster_assignments[i]); // print the cluster assignments for each record
    }

    free(cluster_assignments);
    free(min_dists);

    printf("\nCluster Centroids\n");
    printf("----------------------------\n");
    for(int i=0;i<k;i++){
        for(int j=0;j<num_features;j++){
            printf("%f ", centroids[i][j]); // print the final cluster centroids
        }
        printf("\n");
    }

    // free memory
    for(int i=0;i<num_records;i++){
        free(data[i]);
    }
    for(int i=0;i<k;i++){
        free(centroids[i]);
    }
    free(data);
    free(centroids);
    return 0;
}