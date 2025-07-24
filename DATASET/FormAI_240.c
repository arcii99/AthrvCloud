//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: cheerful
/* Let's write a fun and unique C Clustering Algorithm implementation program
 * that will bring an immediate smile to the face of the user! 
 * This program is designed to cluster different color dots on the screen, 
 * mimicking the behavior of a happy group of kittens playing with colorful toys. 
 * Enjoy!
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DOTS 100
#define MAX_STEPS 20

struct dot {
    int x, y;
    int color;
} dots[MAX_DOTS];

/* Function to generate random dots */
void generate_dots() {
    for (int i = 0; i < MAX_DOTS; i++) {
        dots[i].x = rand() % 80; // random position on x axis
        dots[i].y = rand() % 25; // random position on y axis
        dots[i].color = rand() % 6; // random color code (0-5)
    }
}

/* Function to calculate distance between two dots */
double get_distance(struct dot d1, struct dot d2) {
    return sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2));
}

/* Function to assign clusters to all dots */
void assign_clusters() {
    // initialize all clusters to -1 (unassigned)
    int cluster[MAX_DOTS];
    for (int i = 0; i < MAX_DOTS; i++) {
        cluster[i] = -1;
    }

    // randomly choose starting dot and assign it to cluster 0
    int start = rand() % MAX_DOTS;
    cluster[start] = 0;

    // iterate through each dot and assign to nearest cluster
    for (int i = 0; i < MAX_DOTS; i++) {
        if (cluster[i] == -1) {
            int nearest_cluster = -1;
            double min_distance = 9999.0;

            // iterate through each existing cluster to find nearest one
            for (int j = 0; j < MAX_DOTS; j++) {
                if (cluster[j] != -1) {
                    double distance = get_distance(dots[i], dots[j]);
                    if (distance < min_distance) {
                        min_distance = distance;
                        nearest_cluster = cluster[j];
                    }
                }
            }

            // assign dot to nearest cluster
            cluster[i] = nearest_cluster;
        }
    }

    // print results
    printf("Dot      Cluster\n");
    printf("-----------------\n");
    for (int i = 0; i < MAX_DOTS; i++) {
        printf("%3d        %3d\n", i, cluster[i]);
    }
}

int main() {
    srand(time(NULL)); // initialize random seed
    generate_dots();
    assign_clusters();
    return 0;
}