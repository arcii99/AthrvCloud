//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: happy
#include <stdio.h>

void generate_happy_clusters () {

    printf("Yay! Let's start clustering!\n");

    // First Step: Set initial centroids
    int centroid1[2] = {4, 3};
    int centroid2[2] = {6, 1};
    int centroid3[2] = {8, 9};

    // Second Step: Provide data points 
    int data_points[10][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {1, 9}, {4, 2}, {8, 5}, {10, 9}, {6, 3}};

    // Third Step: Initialize clustering metrics
    int cluster1_count = 0, cluster2_count = 0, cluster3_count = 0;
    int cluster1_total_x = 0, cluster2_total_x = 0, cluster3_total_x = 0;
    int cluster1_total_y = 0, cluster2_total_y = 0, cluster3_total_y = 0;

    // Fourth Step: Assign data points to nearest centroids
    for (int i = 0; i < 10; i++) {
        
        int distance_to_centroid1 = sqrt(pow(data_points[i][0] - centroid1[0], 2) + pow(data_points[i][1] - centroid1[1], 2));
        int distance_to_centroid2 = sqrt(pow(data_points[i][0] - centroid2[0], 2) + pow(data_points[i][1] - centroid2[1], 2));
        int distance_to_centroid3 = sqrt(pow(data_points[i][0] - centroid3[0], 2) + pow(data_points[i][1] - centroid3[1], 2));

        if (distance_to_centroid1 <= distance_to_centroid2 && distance_to_centroid1 <= distance_to_centroid3) {
            printf("Data point %d is closest to centroid 1!\n", i+1);
            cluster1_count += 1;
            cluster1_total_x += data_points[i][0];
            cluster1_total_y += data_points[i][1];
        }

        else if (distance_to_centroid2 <= distance_to_centroid1 && distance_to_centroid2 <= distance_to_centroid3) {
            printf("Data point %d is closest to centroid 2!\n", i+1);
            cluster2_count += 1;
            cluster2_total_x += data_points[i][0];
            cluster2_total_y += data_points[i][1];
        }

        else {
            printf("Data point %d is closest to centroid 3!\n", i+1);
            cluster3_count += 1;
            cluster3_total_x += data_points[i][0];
            cluster3_total_y += data_points[i][1];
        }
    }

    // Fifth Step: Recalculate centroids after reassigning data points
    int new_centroid1[2] = {cluster1_total_x/cluster1_count, cluster1_total_y/cluster1_count};
    int new_centroid2[2] = {cluster2_total_x/cluster2_count, cluster2_total_y/cluster2_count};
    int new_centroid3[2] = {cluster3_total_x/cluster3_count, cluster3_total_y/cluster3_count};

    // Sixth Step: Check if final centroids match initial ones
    if ((new_centroid1[0] == centroid1[0]) && (new_centroid1[1] == centroid1[1]) && (new_centroid2[0] == centroid2[0]) && (new_centroid2[1] == centroid2[1]) && (new_centroid3[0] == centroid3[0]) && (new_centroid3[1] == centroid3[1])) {
        printf("Yay! Clustering done successfully!\n");
    }

    else {
        printf("Hmm.. the final centroids and initial centroids don't match. Let's try again!\n");
        generate_happy_clusters();
    }
}

int main() {
    
    generate_happy_clusters();

    return 0;
}