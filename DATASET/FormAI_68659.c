//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 1000
#define D 5

struct Euc_data_point{
    double data[D]; //Data points, can be multi-dimensional
    int cluster_id; //Cluster id to which data point belongs
    double min_distance; //Distance from the closest centroid
};

//Generates random data points
void generate_data(struct Euc_data_point *data, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<D; j++){
            data[i].data[j] = ((double)rand()/RAND_MAX)*10;
        }
        data[i].cluster_id = -1; //initially no cluster assigned
        data[i].min_distance = INFINITY; //Initially distance from closest centroid set to infinity
    }
}

//Calculates Euclidean distance between two data points
double euclidean_distance(struct Euc_data_point a, struct Euc_data_point b){
    double distance = 0;
    for(int i=0; i<D; i++){
        distance += (a.data[i] - b.data[i])*(a.data[i] - b.data[i]);
    }
    return sqrt(distance);
}

//Initializes centroids randomly
void initialize_centroids(struct Euc_data_point *data, int n, struct Euc_data_point *centroids, int k){
    centroids[0] = data[rand()%n]; //First centroid chosen randomly
    double dist_sq[n];
    for(int i=1; i<k; i++){ //For rest of the centroids
        double total_distance_sq = 0;
        for(int j=0; j<n; j++){ //For each data point
            double min_distance_sq = pow(euclidean_distance(data[j], centroids[0]), 2);
            for(int l=1; l<i; l++){ //For previously chosen centroids
                double dist_sq = pow(euclidean_distance(data[j], centroids[l]), 2);
                min_distance_sq = fmin(min_distance_sq, dist_sq); //Getting the squared distance from the closest centroid
            }
            total_distance_sq += min_distance_sq;
        }
        double r = ((double)rand()/RAND_MAX)*total_distance_sq; //Choosing a random number in [0, total_distance_sq)
        double sum = 0;
        for(int j=0; j<n; j++){ //choosing the data point that corresponds to the chosen random number
            double min_distance_sq = pow(euclidean_distance(data[j], centroids[0]), 2);
            for(int l=1; l<i; l++){ //For previously chosen centroids
                double dist_sq = pow(euclidean_distance(data[j], centroids[l]), 2);
                min_distance_sq = fmin(min_distance_sq, dist_sq); //Getting the squared distance from the closest centroid
            }
            sum += min_distance_sq; 
            if(sum > r){
                centroids[i] = data[j];
                break;
            }
        }
    }
}

//Assigns each data point to the closest cluster
void assign_clusters(struct Euc_data_point *data, int n, struct Euc_data_point *centroids, int k){
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            double distance = euclidean_distance(data[i], centroids[j]);
            if(distance < data[i].min_distance){
                data[i].min_distance = distance;
                data[i].cluster_id = j;
            }
        }
    }
}

//Updates the centroids of each cluster
void update_centroids(struct Euc_data_point *data, int n, struct Euc_data_point *centroids, int k){
    int count[k]; //To keep track of number of data points belonging to each cluster
    for(int i=0; i<k; i++){
        count[i] = 0;
        for(int j=0; j<D; j++){
            centroids[i].data[j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        count[data[i].cluster_id]++;
        for(int j=0; j<D; j++){
            centroids[data[i].cluster_id].data[j] += data[i].data[j];
        }
    }
    for(int i=0; i<k; i++){
        if(count[i] > 0){
            for(int j=0; j<D; j++){
                centroids[i].data[j] /= count[i];
            }
        }
    }
}

//Checks whether two sets of centroids are identical
int check_centroids(struct Euc_data_point *centroids1, struct Euc_data_point *centroids2, int k){
    for(int i=0; i<k; i++){
        for(int j=0; j<D; j++){
            if(centroids1[i].data[j] != centroids2[i].data[j]){
                return 0;
            }
        }
    }
    return 1;
}

//Prints the data points with their cluster ids and the final centroids
void print_clusters(struct Euc_data_point *data, int n, struct Euc_data_point *centroids, int k){
    for(int i=0; i<n; i++){
        printf("Data point %d: [", i+1);
        for(int j=0; j<D; j++){
            printf("%lf, ", data[i].data[j]);
        }
        printf("] belongs to cluster %d\n", data[i].cluster_id+1);
    }
    printf("\nFinal centroids:\n");
    for(int i=0; i<k; i++){
        printf("Centroid %d: [", i+1);
        for(int j=0; j<D; j++){
            printf("%lf, ", centroids[i].data[j]);
        }
        printf("]\n");
    }
}

int main(){
    srand(1);
    struct Euc_data_point data[N];
    generate_data(data, N);
    int k = 5;
    struct Euc_data_point centroids[k];
    initialize_centroids(data, N, centroids, k);
    struct Euc_data_point old_centroids[k];
    int iterations = 0;
    do{
        for(int i=0; i<k; i++){
            old_centroids[i] = centroids[i];
        }
        assign_clusters(data, N, centroids, k);
        update_centroids(data, N, centroids, k);
        iterations++;
    }while(!check_centroids(centroids, old_centroids, k));
    printf("Converged after %d iterations!\n", iterations);
    print_clusters(data, N, centroids, k);
    return 0;
}